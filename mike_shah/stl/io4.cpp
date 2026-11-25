#include <iostream> // std::cin, std::wcin, std::cout, std::wcout
#include <istream>  // std::basic_istream, std::istream, std::wistream, std::ws
#include <limits>   // std::numeric_limits
#include <sstream>  // std::istringstream, std::wistringstream
#include <string>   // std::string, std::wstring, std::getline

int main() {
    // 1. Typedefs & Global Objects (<istream>, <iostream>)
    std::cout << "--- 1. Typedefs & Global Objects ---\n";
    auto* cin_buf  = std::cin.rdbuf();   // std::istream  (std::basic_istream<char>)
    auto* wcin_buf = std::wcin.rdbuf();  // std::wistream (std::basic_istream<wchar_t>)
    (void)cin_buf; (void)wcin_buf;

    // 2. Member Types (char_type, traits_type, int_type, pos_type, off_type)
    using IStream   = std::istream;
    using CharT     = IStream::char_type;
    using Traits    = IStream::traits_type;
    using IntT      = IStream::int_type;
    using PosT      = IStream::pos_type;
    using OffT      = IStream::off_type;

    // 3. Formatted Input: operator>> & std::ws
    std::cout << "--- 2. Formatted Input (operator>>) ---\n";
    std::istringstream fmt_in("   true 42 -99 3.14159 Hello");
    bool b{};
    int i{};
    long l{};
    double d{};
    std::string str;

    fmt_in >> std::ws >> b >> i >> l >> d >> str;
    std::cout << "Parsed: " << std::boolalpha << b << ", " << i << ", " << l << ", " << d << ", " << str << '\n';

    // 4. Unformatted Input Methods
    std::cout << "\n--- 3. Unformatted Input Methods ---\n";
    std::istringstream raw_in("ABCDE\nLineTwo|RestOfBuffer");

    // peek() & get() (single char)
    IntT next_ch = raw_in.peek();
    std::cout << "peek(): '" << Traits::to_char_type(next_ch) << "'\n";

    CharT c1 = static_cast<CharT>(raw_in.get());
    CharT c2{};
    raw_in.get(c2);
    std::cout << "get(): '" << c1 << "', '" << c2 << "'\n";

    // get(char*, count, delim) - stops BEFORE delimiter
    CharT buf1[16]{};
    raw_in.get(buf1, sizeof(buf1), '\n');
    std::cout << "get(buf, delim): \"" << buf1 << "\" (gcount=" << raw_in.gcount() << ")\n";

    // ignore(count, delim) - discards the '\n'
    raw_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // getline(char*, count, delim) - extracts AND consumes delimiter '|'
    CharT buf2[16]{};
    raw_in.getline(buf2, sizeof(buf2), '|');
    std::cout << "getline(buf, '|'): \"" << buf2 << "\" (gcount=" << raw_in.gcount() << ")\n";

    // read(char*, count) & readsome(char*, count)
    CharT buf3[5]{};
    raw_in.read(buf3, 4);
    std::cout << "read(4): \"" << buf3 << "\" (gcount=" << raw_in.gcount() << ")\n";

    CharT buf4[16]{};
    std::streamsize avail = raw_in.readsome(buf4, sizeof(buf4) - 1);
    std::cout << "readsome(): \"" << buf4 << "\" (extracted=" << avail << ")\n";

    // 5. Putback & Unget (putback, unget)
    std::cout << "\n--- 4. Putback & Unget ---\n";
    std::istringstream pb_in("XYZ");
    CharT x{};
    pb_in.get(x);               // Reads 'X'
    pb_in.unget();              // Backs up by 1 -> 'X' is back
    pb_in.get(x);               // Reads 'X' again
    pb_in.putback('Q');         // Puts 'Q' back into buffer
    pb_in.get(x);               // Reads 'Q'
    std::cout << "After unget() + putback('Q'): '" << x << "'\n";

    // 6. Positioning & Synchronization (tellg, seekg, sync)
    std::cout << "\n--- 5. Positioning & Sync (tellg, seekg, sync) ---\n";
    std::istringstream pos_in("0123456789");
    pos_in.seekg(4, std::ios_base::beg); // Move get pointer to index 4
    PosT current_pos = pos_in.tellg();   // Record position
    pos_in.seekg(OffT(-2), std::ios_base::cur); // Relative seek back 2 bytes
    pos_in.sync();                       // Synchronize with underlying streambuf
    std::cout << "tellg() was " << current_pos << ", after seekg(-2): '"
              << static_cast<CharT>(pos_in.get()) << "'\n";

    // 7. Helper Class: std::basic_istream::sentry
    std::cout << "\n--- 6. std::basic_istream::sentry ---\n";
    std::istringstream sentry_in("   999");
    IStream::sentry ok(sentry_in); // Skips leading whitespace & flushes tied stream
    if (ok) {
        int val = 0;
        sentry_in >> val;
        std::cout << "sentry succeeded, extracted: " << val << '\n';
    }

    // 8. Wide Character Stream (std::wistream)
    std::wistringstream win(L"WideToken");
    std::wstring wword;
    win >> wword;
    std::wcout << L"\n--- 7. std::wistream ---\nExtracted: " << wword << L'\n';

    return 0;
}
