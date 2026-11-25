#include <iostream>
#include <fstream>
#include <sstream>
#include <print>      
#include <cstdio>     
#include <iomanip>    
#include <array>

// Check for true feature support using standard library feature-test macros
#if defined(__has_include)
    #if __has_include(<spanstream>)
        #include <spanstream>
    #endif
    #if __has_include(<syncstream>)
        #include <syncstream>
    #endif
#endif

int main() {
    // =========================================================================
    // 1. C++23 PRINT FUNCTIONS
    // =========================================================================
    std::println("--- 1. C++23 Print Functions ---");
    std::print("Hello from std::print! ");
    std::println("Hello from std::println with a clean new line!");
    std::println("Formatting example: Pi is roughly {:.2f}, Hex: {:x}", 3.14159, 255);
    std::println(std::cout, "Using std::println directly on std::cout: {}", 2026);
    std::println("");

    // =========================================================================
    // 2. STREAM-BASED I/O & MANIPULATORS
    // =========================================================================
    std::println("--- 2. Stream-based I/O & Manipulators ---");
    std::cout << "Boolean true: " << std::boolalpha << true << "\n";
    std::cout << "Decimal 42 in Hex: " << std::hex << 42 << std::dec << "\n"; 
    std::cout << "Padded width: [" << std::setw(10) << std::setfill('*') << 123 << "]\n\n";

    // =========================================================================
    // 3. FILE I/O IMPLEMENTATION
    // =========================================================================
    std::println("--- 3. File I/O ---");
    const std::string filename = "io_demo_output.txt";
    {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "Line 1: Writing data to a file stream.\n";
            outFile << "Line 2: Modern C++ is robust.\n";
            outFile.close();
            std::println("Successfully wrote data to '{}'", filename);
        }
    }
    {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            std::string line;
            std::println("Reading back from '{}':", filename);
            while (std::getline(inFile, line)) {
                std::println("  > {}", line);
            }
            inFile.close();
        }
    }
    std::println("");

    // =========================================================================
    // 4. STRING I/O IMPLEMENTATION
    // =========================================================================
    std::println("--- 4. String I/O ---");
    std::stringstream ss;
    ss << "Scores " << 98 << " " << 87.5;
    std::string label;
    int intScore;
    double doubleScore;
    ss >> label >> intScore >> doubleScore;
    std::println("Parsed from stringstream: label='{}', int={}, double={}", label, intScore, doubleScore);
    std::println("");

    // =========================================================================
    // 5. ARRAY I/O IMPLEMENTATIONS (Conditionally compiled via feature-test)
    // =========================================================================
    std::println("--- 5. Array/Fixed Buffer I/O ---");
#if defined(__cpp_lib_spanstream)
    std::array<char, 64> buffer;
    std::ospanstream osp(buffer); 
    osp << "C++23 Spanstream writing directly to a flat array!";
    buffer[osp.span().size()] = '\0'; 
    std::println("Buffer contents: {}", buffer.data());
#else
    std::println("Note: std::ospanstream is not fully available in this toolchain configuration.");
#endif
    std::println("");

    // =========================================================================
    // 6. SYNCHRONIZED OUTPUT (Conditionally compiled via feature-test)
    // =========================================================================
    std::println("--- 6. Synchronized Output ---");
#if defined(__cpp_lib_syncstream)
    {
        std::osyncstream syncedStream(std::cout);
        syncedStream << "This output block is guaranteed to be atomic.\n";
    }
#else
    std::println("Note: std::osyncstream is locked or unsupported without runtime flags.");
#endif
    std::println("");

    // =========================================================================
    // 7. C-STYLE I/O
    // =========================================================================
    std::println("--- 7. C-Style I/O ---");
    const char* c_filename = "c_style_demo.txt";
    FILE* pFile = std::fopen(c_filename, "w");
    if (pFile != nullptr) {
        std::fprintf(pFile, "Formatted string via fprintf: %d %s\n", 2026, "Success");
        std::fclose(pFile);
    }
    pFile = std::fopen(c_filename, "r");
    if (pFile != nullptr) {
        char fileBuffer[128];
        if (std::fgets(fileBuffer, sizeof(fileBuffer), pFile) != nullptr) {
            std::print("Read using fgets: {}", fileBuffer);
        }
        std::fclose(pFile);
    }

    return 0;
}

