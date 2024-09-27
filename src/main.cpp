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

    if (argc > 1)
    {
        if (std::string(argv[1]) == "/F")
        {
            show_files = true;
            if (argc == 2)
            {
                target_path = fs::current_path();
            }
        }
        else
        {
            target_path = fs::path(argv[1]);
            if (argc > 2 && std::string(argv[2]) == "/F")
            {
                show_files = true;
            }
        }
    }

    if (!fs::exists(target_path))
    {
        std::cerr << "Error: The specified path does not exist: " << target_path << std::endl;
        return 1;
    }

    if (!fs::is_directory(target_path))
    {
        std::cerr << "Error: The specified path is not a directory: " << target_path << std::endl;
        return 1;
    }

    std::cout << target_path.string() << std::endl;

    print_tree(target_path, "", true, show_files);

    return 0;
}
