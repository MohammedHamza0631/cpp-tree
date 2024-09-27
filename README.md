# cpp_tree

A C++ implementation of the `tree` command for Windows and Linux environments.

## Description

`cpp_tree` is a command-line utility that displays the directory structure of a given path in a tree-like format. It mimics the functionality of the `tree` command found in CMD (Windows) and Linux terminals.

## Features

- Display directory structure in a tree format
- Option to show or hide files
- Cross-platform compatibility (Windows and Linux)

## Prerequisites

To build and run this project, you'll need:

- C++17 compatible compiler
- CMake (3.10 or higher)
- MSYS2 (for Windows users)

## Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/MohammedHamza0631/cpp_tree.git
   cd cpp_tree
   ```

2. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```

3. Generate the build files with CMake:
   ```c++
   cmake ..
   ```

4. Build the project:
   ```c++
   cmake --build .
   ```

## Usage

After building the project, you can run the `cpp_tree` executable from the command line:

```bash
./cpp_tree [path] [/F]
```

- `[path]`: Optional. The directory path to display. If not provided, the current directory will be used.
- `/F`: Optional. Include this flag to display files in addition to directories.

### Examples

1. Display the structure of the current directory (directories only):
   ```bash
   ./cpp_tree
   ```

2. Display the structure of a specific directory (directories only):
   ```bash
   ./cpp_tree "D:\Development\MongoDB"
   ```

   Output:
   ```lua
   D:\Development\MongoDB 
   |-- CRUD 
   |-- Exercise 
   |   |-- models 
   |   `-- views 
   `-- mongoose 
       `-- models
   ```

3. Display the structure of a specific directory, including files:
   ```bash
   ./cpp_tree "D:\Development\MongoDB" /F
   ```

   Output:
   ```lua
   D:\Development\MongoDB 
   |-- CRUD 
   |   |-- create.js 
   |   `-- Crud.mongodb.js 
   |-- Exercise 
   |   |-- main.js 
   |   |-- models 
   |   |   `-- Employee.js 
   |   `-- views 
   |       `-- index.ejs 
   `-- mongoose 
       |-- main.js 
       `-- models 
           `-- Todo.js
   ```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is open source and available under the [MIT License](LICENSE).

## Author

[MohammedHamza0631](https://github.com/MohammedHamza0631)