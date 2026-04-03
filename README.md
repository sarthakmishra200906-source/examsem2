# Data Structures in C

This repository contains basic Data Structure and Sorting implementations in C.
Each program is kept as a separate source file so it can be compiled and practiced independently.

## Folder Structure

- `linklist/` : Singly and doubly linked list operations (create, insert, delete, reverse, length).
- `queue/` : Queue implementations using arrays and linked lists (linear and circular).
- `stack/` : Stack implementations using arrays and linked lists.
- `sorting/` : Sorting algorithms such as merge sort and quick sort.
- `graph/` : Graph-related programs (add your files here).
- `tree/` : Tree-related programs (add your files here).

## How to Compile and Run

Use GCC (MinGW on Windows).

Compile a file:

```bash
gcc path/to/file.c -o path/to/file.exe
```

Example:

```bash
gcc sorting/mergshort.c -o sorting/mergshort.exe
```

Run:

```bash
./sorting/mergshort.exe
```

## Notes

- Most programs are menu-driven and take input from terminal.
- Programs are written for learning and practice, so each file focuses on one topic.
- You can extend each file by adding input validation, edge-case handling, and more test cases.
