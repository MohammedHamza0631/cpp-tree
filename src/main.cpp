#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

void print_tree(const fs::path &path, const std::string &prefix = "", bool is_last = true, bool show_files = false)
{
    std::cout << prefix << (is_last ? "`-- " : "|-- ") << path.filename().string() << std::endl;

    if (fs::is_directory(path))
    {
        std::vector<fs::path> entries;
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (fs::is_directory(entry) || (show_files && fs::is_regular_file(entry)))
            {
                entries.push_back(entry.path());
            }
        }

        std::sort(entries.begin(), entries.end());

        std::string new_prefix = prefix + (is_last ? "    " : "|   ");

        for (size_t i = 0; i < entries.size(); ++i)
        {
            bool is_last_entry = (i == entries.size() - 1);
            print_tree(entries[i], new_prefix, is_last_entry, show_files);
        }
    }
}

int main(int argc, char *argv[])
{
    bool show_files = false;
    fs::path target_path = fs::current_path();

    // Check if arguments are provided
    if (argc > 1)
    {
        // Check if the first argument is the /F flag
        if (std::string(argv[1]) == "/F")
        {
            show_files = true;
            // Default to current directory if /F is the only argument
            if (argc == 2)
            {
                target_path = fs::current_path();
            }
        }
        else
        {
            // Otherwise, treat the first argument as the path
            target_path = fs::path(argv[1]);
            // Check if the second argument is /F
            if (argc > 2 && std::string(argv[2]) == "/F")
            {
                show_files = true;
            }
        }
    }

    // Print the root directory name
    std::cout << target_path.string() << std::endl;

    // Start printing the tree from the target path
    print_tree(target_path, "", true, show_files);

    return 0;
}
