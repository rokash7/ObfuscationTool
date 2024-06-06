#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "unicode_map.hpp"

using namespace std;

bool isJson (string fileName);
string encode (string line);
void toUnicode (ifstream& inputFile, ofstream& outputFile, bool isJson);

int main(int argc, char* argv[]) {
    string inputFileName;
    string outputFileName;

    // checks if input and output file names are provided. If not, uses default input and output files.
    if (argc != 3) {
        inputFileName = "data/input.json";
        outputFileName = "data/output.json";

        cout << "Consider using: obfuscation_tool.exe <input_file> <output_file>\n";
        cout << "Since no parameters provided, using data/input.json and data/output.json as default parameters.\n";
    } else {
        inputFileName = argv[1];
        outputFileName = argv[2];
    }

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    toUnicode(inputFile, outputFile, isJson(inputFileName));

    inputFile.close();
    outputFile.close();

    cout << "TASK FINISHED. Output avaulable at " << outputFileName << ".\n";

    return 0;
}

/**
 * @brief Encodes a line by mapping values from "unicode_map.cpp".
 *
 * It encodes by checking if the element is inside quotes. If it is, then the element is replaced by the string value inside "unicode_map.cpp".
 * The method is not used because: 1) uses map for encoding 2) translates line by line, which is faulty if input file is formatted according to a standart 3) functionality for non JSON files not implemented.
 *
 * @param line The string value to be encoded.
 * @return The encoded string.
 */
string encode(string line) {
    string outputLine = "";
    bool insideQuotes = false;

    for (char element : line) {
        if (element == '"') {
            insideQuotes = !insideQuotes;
        }

        if (insideQuotes) {
            auto it = unicodeMap.find(element);
            if (it != unicodeMap.end()) {
                outputLine += unicodeMap[element];
            } else {
                outputLine += element;
            }
        } else {
            outputLine += element;
        }
    }

    return outputLine;
}

/**
 * @brief Checks if provided file name is a JSON file.
 *
 * It sets the name to lower case, selects last 5 characters of the file name and compares it to ".json".
 *
 * @param fileName The file name to be checked whether it is a JSON file.
 * @return true if file is JSON, false if not.
 */
bool isJson (string fileName) {
    string lowercaseName = "";

    for (auto symbol : fileName) {
        lowercaseName += (char)tolower(symbol);
    }

    return ".json" == lowercaseName.substr(lowercaseName.length() - 5);
}

/**
 * @brief Encodes characters from input file to unicode values.
 *
 * Iterates through every element and replaces each character to unicode hexadecimal code in the output file.
 * Only changes the symbols inside quotation marks if it is a JSON file.
 * If JSON file is not valid, this method may not return an expected output.
 *
 * @param inputFile The input file.
 * @param outputFile The output file.
 * @param isJson True if input file is a JSON, false if of other type.
 */
void toUnicode (ifstream& inputFile, ofstream& outputFile, bool isJson) {
    char element;
    bool insideQuotes = false;

    while (inputFile.get(element)) {
        if (element == '"') {
            insideQuotes = !insideQuotes;
        }

        if (insideQuotes && element != '"' && isJson) {
            outputFile << "\\u" << hex << setw(4) << setfill('0') << static_cast <int> (element);
        } else if (!isJson) {
            outputFile << "\\x" << hex << setw(2) << setfill('0') << static_cast <int> (element);
        } else {
            outputFile << element;
        }
    }
}