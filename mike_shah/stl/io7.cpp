#include <chrono>
#include <filesystem> // path, filesystem_error, directory_entry, directory_iterator, recursive_directory_iterator, file_status, space_info, file_type, perms, perm_options, copy_options, directory_options, file_time_type, and free functions
#include <fstream>
#include <iostream>
#include <system_error>

namespace fs = std::filesystem;

int main() {
    // Clean sandbox directory in system temp_directory_path()
    fs::path sandbox = fs::temp_directory_path() / "cpp_fs_demo";
    std::error_code ec;
    fs::remove_all(sandbox, ec);

    // 1. fs::path (construction, concatenation, decomposition, lexical normalization)
    std::cout << "=== 1. std::filesystem::path ===\n";
    fs::path dir_path  = sandbox / "sub_a" / "sub_b";
    fs::path file_path = dir_path / "example.tar.gz";

    std::cout << "Full path:      " << file_path << '\n'
              << "root_name:      " << file_path.root_name() << '\n'
              << "root_directory: " << file_path.root_directory() << '\n'
              << "parent_path:    " << file_path.parent_path() << '\n'
              << "filename:       " << file_path.filename() << '\n'
              << "stem:           " << file_path.stem() << '\n'
              << "extension:      " << file_path.extension() << '\n'
              << "lexically_normal: " << (sandbox / "a/../b/./c").lexically_normal() << '\n';

    // 2. Directory & File Creation (create_directories, current_path, canonical, relative)
    std::cout << "\n=== 2. Directories, Paths & Regular Files ===\n";
    fs::create_directories(dir_path);

    fs::path txt_file = sandbox / "notes.txt";
    {
        std::ofstream ofs(txt_file);
        ofs << "Hello std::filesystem!\n";
    }

    std::cout << "exists:     " << std::boolalpha << fs::exists(txt_file) << '\n'
              << "canonical:  " << fs::canonical(txt_file) << '\n'
              << "relative:   " << fs::relative(txt_file, sandbox) << '\n'
              << "file_size:  " << fs::file_size(txt_file) << " bytes\n";

    // 3. Copying, Renaming, Hard Links & Symbolic Links
    std::cout << "\n=== 3. Copy, Rename, Hard Links & Symlinks ===\n";
    fs::path copied_file = sandbox / "notes_copy.txt";
    fs::copy_file(txt_file, copied_file, fs::copy_options::overwrite_existing);

    fs::path renamed_file = sandbox / "notes_renamed.txt";
    fs::rename(copied_file, renamed_file);

    fs::path hard_link = sandbox / "notes_hardlink.txt";
    fs::create_hard_link(txt_file, hard_link, ec);
    if (!ec) {
        std::cout << "hard_link_count: " << fs::hard_link_count(txt_file) << '\n';
    }

    fs::path sym_link = sandbox / "notes_symlink.txt";
    fs::create_symlink(txt_file, sym_link, ec);
    if (!ec) {
        std::cout << "is_symlink: " << fs::is_symlink(sym_link)
                  << " -> target: " << fs::read_symlink(sym_link) << '\n';
    }

    // 4. File Status, Permissions & Timestamps (file_status, file_type, perms, file_time_type)
    std::cout << "\n=== 4. Status, Permissions & Timestamps ===\n";
    fs::file_status st = fs::status(txt_file);
    std::cout << "is_regular_file: " << fs::is_regular_file(st)
              << " | is_directory: " << fs::is_directory(dir_path)
              << " | is_empty: " << fs::is_empty(dir_path) << '\n';

    fs::permissions(txt_file, fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::replace);
    fs::perms p = fs::status(txt_file).permissions();
    std::cout << "Owner write enabled: " << ((p & fs::perms::owner_write) != fs::perms::none) << '\n';

    fs::file_time_type ftime = fs::last_write_time(txt_file);
    fs::last_write_time(txt_file, ftime); // Round-trip timestamp update
    std::cout << "Timestamp updated successfully.\n";

    // 5. Directory Iteration (directory_entry, directory_iterator, recursive_directory_iterator)
    std::cout << "\n=== 5. Directory & Recursive Iteration ===\n";
    for (const fs::directory_entry& entry : fs::directory_iterator(sandbox)) {
        std::cout << "[flat] " << entry.path().filename()
                  << " (dir=" << entry.is_directory() << ")\n";
    }

    for (const fs::directory_entry& entry :
         fs::recursive_directory_iterator(sandbox, fs::directory_options::skip_permission_denied)) {
        std::cout << "[recursive] " << fs::relative(entry.path(), sandbox) << '\n';
    }

    // 6. Disk Space Info (space_info) & Exception Handling (filesystem_error)
    std::cout << "\n=== 6. Space Info & filesystem_error ===\n";
    fs::space_info sp = fs::space(sandbox);
    std::cout << "Capacity: " << (sp.capacity / (1024 * 1024)) << " MB"
              << " | Available: " << (sp.available / (1024 * 1024)) << " MB\n";

    try {
        // Intentionally trigger fs::filesystem_error on non-existent file
        (void)fs::file_size(sandbox / "does_not_exist.bin");
    } catch (const fs::filesystem_error& err) {
        std::cout << "Caught filesystem_error: " << err.what()
                  << " | path1: " << err.path1().filename() << '\n';
    }

    // 7. Cleanup (remove & remove_all)
    fs::remove(sym_link, ec);
    std::uintmax_t removed_count = fs::remove_all(sandbox);
    std::cout << "\nCleaned up " << removed_count << " filesystem entries.\n";

    return 0;
}
