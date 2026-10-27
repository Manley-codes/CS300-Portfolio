# CS 300 — Data Structures and Algorithms Portfolio

This repository contains two projects from **CS 300: Data Structures and Algorithms** at Southern New Hampshire University. Both projects focus on a course advising program that organizes computer science courses, prints them in alphanumeric order, and lets a user look up a course and its prerequisites.

## Portfolio Artifacts

- **[Project One: Run-Time and Memory Analysis](Project-One/Runtime-and-Memory-Analysis.md)** — My comparison of vectors, hash tables, and binary search trees, including their run-time costs, advantages, disadvantages, and memory considerations.
- **[Project Two: C++ Course Planner](Project-Two/ProjectTwo.cpp)** — My working course planner, which uses a binary search tree to load course data, print a sorted course list, and search for individual courses and their prerequisites.

## Reflection

### What was the problem I was solving in these projects?

The goal was to build a program that could organize course information and help a student look up the courses they need, including prerequisites. In Project One, I compared three data structures to decide which would work best for this task. In Project Two, I put that decision into practice by building the course planner in C++ using a binary search tree.

### How did I approach the problem, and why are data structures important?

I started by looking at what the program needed to do, rather than jumping straight into writing code. I compared vectors, hash tables, and binary search trees based on how they store, search, and organize information. This helped me see that choosing a data structure can affect how efficiently a program works. I chose a binary search tree because it lets me print courses in alphanumeric order through an in-order traversal, without a separate sorting step.

### How did I overcome roadblocks?

One of my challenges was keeping track of how the different parts of the program connected, especially when working with C++ and the binary search tree. I worked through the program in smaller pieces, checking functions such as loading the file, inserting courses, and searching for course information. Compiling and testing the program helped me see what needed to be fixed and build a better understanding of how everything worked together.

### How did this work change my approach to designing software?

These projects taught me to spend more time thinking about the structure of a program before building it. I learned that a program can give the correct result but still have different strengths and weaknesses depending on how it is designed. Going forward, I want to think more carefully about how data will be stored and used, not just how to make a feature work.

### How has this work changed the way I write maintainable, readable, and adaptable programs?

I have a better appreciation for breaking a program into smaller functions with clear responsibilities. In Project Two, I separated the tree operations, file loading, course display, and menu logic, which makes the code easier to follow and change. I also used comments and meaningful names to explain what different parts of the program do. These are habits I want to carry into future software projects.

## Running Project Two

The course planner is a C++ console application. From the repository root, compile it with a C++ compiler such as `g++`:

```bash
g++ -std=c++17 Project-Two/ProjectTwo.cpp -o course-planner
```

Run it using `./course-planner` (or `.\course-planner.exe` in Windows PowerShell). Choose **1** to load a course CSV file, **2** to print all courses in alphanumeric order, **3** to look up a course and its prerequisites, or **9** to exit.

The input CSV should have one course per line, with a course number, a course name, and any prerequisite course numbers separated by commas:

```text
CS100,Introduction to Programming
CS200,Data Structures,CS100
```

This sample demonstrates the expected file format; it is not an included course catalog.
