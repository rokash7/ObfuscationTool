# Environment
    Programming language: C++
    Compiler: gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
    Used IDE: Visual Studio Code

# Description
    "obfuscation_tool.exe" replaces characters in various textual files. JSON files are detected automatically and string values are replaced. If the file is not a JSON, then it replaces all of the characters. Program does not overwrite input file, instead it creates a new output file. The program can be run without parameters to use default input and output. If user prefers, input and output files can be provided as parameters when starting the application (refer to "How to Run" chapter below).

# Deliverables
    ■   Replaces the strings in a file with their respective Unicode escape sequence in a JSON file.

    ■   Replaces all characters with their respective Unicode codes if the file is not a JSON.

# Past versions
    Previous implementations are not deleted and their usages are commented out (see lines 33-41 in "main.cpp") and left unused (see "unicode_map.cpp", "unicode_map.hpp" files and "encode" method in "main.cpp").

# How to Run
    1. Navigate to root folder called "obfuscation_tool".
    2. Open "data" folder.
    3. Create a file that will be used as input. Currently there are 2 input and 2 output files that can be used as an example.
    4. Return to root folder "obfuscation_tool".
    5. Open terminal in this location.
   
    6. Type "obfuscation_tool.exe" to run the program without parameters.
    ALTERNATIVELY:
    6. Type "obfuscation_tool.exe <input_file>* <output_file>*".
   
    7. Click enter
    8. Output file is created in the provided location (or "data" folder as output.json by default).
    
    *If full file name is not provided, the root folder "obfuscation_tool" is the directory where program expects the input file and creates the output file. Relative names can also be used, for example: "obfuscation_tool.exe data/input.json data/output.json".

Author: Rokas Petrauskas\
Year: 2024