#include <iostream>
#include <fstream>
#include <sstream>
#include <print>      // C++23
#include <cstdio>     // C-style I/O
#include <iomanip>    // Manipulators
#include <array>
#include <string>
#include <algorithm>

int main() {
    // =========================================================================
    // 1. C++23 PRINT FUNCTIONS
    // =========================================================================
    std::println("--- 1. C++23 Print Functions ---");
    std::print("Hello via std::print! ");
    std::println("Hello via std::println!");
    std::println("Formatted values: Decimal={}, Float={:.2f}, Hex=0x{:X}", 42, 3.14159, 255);
    std::println(std::cout, "Targeted custom stream print check.");
    std::println("");

    // =========================================================================
    // 2. STREAM-BASED I/O & MANIPULATORS
    // =========================================================================
    std::println("--- 2. Stream-based I/O & Manipulators ---");
    std::cout << "Boolean state: " << std::boolalpha << true << "\n";
    std::cout << "Integer base conversion: " << std::hex << 255 << " (Hex) " << std::dec << "\n"; 
    std::cout << "Custom width padding: [" << std::setw(8) << std::setfill('-') << 77 << "]\n\n";

    // =========================================================================
    // 3. FILE I/O IMPLEMENTATION
    // =========================================================================
    std::println("--- 3. File I/O ---");
    const std::string textFile = "io_demo_output.txt";
    {
        std::ofstream outFile(textFile);
        if (outFile.is_open()) {
            outFile << "Line 1: High-level streaming abstraction.\n";
            outFile << "Line 2: File stream testing.\n";
            outFile.close();
            std::println("Output successfully saved to '{}'", textFile);
        }
    }
    {
        std::ifstream inFile(textFile);
        if (inFile.is_open()) {
            std::string lineStr;
            std::println("Reading data back from file:");
            while (std::getline(inFile, lineStr)) {
                std::println("  > {}", lineStr);
            }
            inFile.close();
        }
    }
    std::println("");

    // =========================================================================
    // 4. STRING I/O IMPLEMENTATION
    // =========================================================================
    std::println("--- 4. String I/O (stringstream) ---");
    std::stringstream stringMemoryStream;
    stringMemoryStream  identityKey >> sensorId >> criticalReading;
    
    std::println("Extracted fields: Key='{}', ID={}, Metric={}", identityKey, sensorId, criticalReading);
    std::println("");

    // =========================================================================
    // 5. FIXED ARRAY BUFFER I/O
    // =========================================================================
    std::println("--- 5. Fixed Array/Buffer I/O Fallback ---");
    std::array<char, 64> manualBuffer{};
    std::string alternativeContent = "Simulated buffer write block sequence";
    std::copy_n(alternativeContent.begin(), std::min(alternativeContent.size(), manualBuffer.size() - 1), manualBuffer.begin());
    std::println("Buffer value layout: {}", manualBuffer.data());
    std::println("");

    // =========================================================================
    // 6. C-STYLE I/O LEGACY COMPATIBILITY
    // =========================================================================
    std::println("--- 6. C-Style I/O Functionality ---");
    const char* legacyFilename = "c_legacy_demo.dat";
    
    FILE* targetFilePtr = std::fopen(legacyFilename, "w");
    if (targetFilePtr != nullptr) {
        std::fprintf(targetFilePtr, "C-Style formatting marker: %d\n", 9999);
        std::fclose(targetFilePtr);
    }
    
    targetFilePtr = std::fopen(legacyFilename, "r");
    if (targetFilePtr != nullptr) {
        std::array<char, 128> extractionBuffer{};
        if (std::fgets(extractionBuffer.data(), extractionBuffer.size(), targetFilePtr) != nullptr) {
            std::print("Extracted via fgets: {}", extractionBuffer.data());
        }
        std::fclose(targetFilePtr);
    }

    return 0;
}

