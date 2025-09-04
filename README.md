### 📂 Repository Name

```
cpp-directory-management-system
```

---

### 📝 README.md

````markdown
# 📂 Directory Management System (C++)

A simple **C++ console-based application** for managing directories and files using the `<filesystem>` library.  
This project demonstrates basic file handling, directory manipulation, and user interaction through a menu-driven system.  

---

## 🚀 Features
- ✅ List files in the current directory
  - List all files
  - List files by extension (e.g., `.txt`)
  - List files by starting pattern (e.g., `moha`)
- ✅ Create new directories
- ✅ Change current working directory
- ✅ Simple menu-driven interface

---

## 📖 How It Works
1. The program starts with a main menu:
   - `[1] List Files`
   - `[2] Create Directory`
   - `[3] Change Directory`
   - `[4] Exit`
2. Based on user input, it performs file or directory operations using `std::filesystem`.

---

## 🛠️ Requirements
- C++17 or later (for `<filesystem>`)
- A C++ compiler such as:
  - `g++` (MinGW / Linux)
  - `clang++`
  - MSVC (Visual Studio)

---

## ⚙️ Compilation & Run

### Linux / macOS
```bash
g++ -std=c++17 main.cpp -o directory_manager
./directory_manager
````

### Windows (MinGW)

```bash
g++ -std=c++17 main.cpp -o directory_manager.exe
directory_manager.exe
```

---

## 📂 Example Usage

```
=== Directory Management System ===
[1] List Files
[2] Create Directory
[3] Change Directory
[4] Exit
Enter your choice: 1

--- List Files ---
[1] List All Files
[2] List Files by Extension (e.g., .txt)
[3] List Files by Pattern (e.g., moha)
Enter option: 1

Files in current directory:
 - main.cpp
 - README.md
```

---

## 📌 Notes

* Ensure you run the program in a directory where you have **read/write permissions**.
* The program will update the current working directory when `Change Directory` is used.
