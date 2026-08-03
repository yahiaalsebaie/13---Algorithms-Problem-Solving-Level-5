# 🚀 C++ Data Data Structures & Algorithms From Scratch

CppDataStructuresFromScratch
> A complete educational repository documenting my journey through **Programming Advices – Course 13 (Algorithms & Problem Solving Level 5)**.

<p align="center">
    

</p>

---

## 📖 About

This repository contains all my implementations, exercises, and projects created while studying:

**Programming Advices – Course 13: Algorithms & Problem Solving Level 5**

https://programmingadvices.com/courses/13-algorithms-problem-solving-level-5/

The goal of this repository is **learning, practicing, and documenting** different Data Structures and Algorithms implementations using modern C++.

Many projects include **multiple implementations** of the same idea so you can compare different design approaches.

---

# 📂 Repository Structure

Each project usually contains:

- Source files
- Header files
- Example/Test files

> **Important**
>
> Every `.h` file has a corresponding **test `.cpp` file** demonstrating how to use it.
>
> The code examples shown inside the library files are **NOT** a replacement for exploring and running the test files.

---

# 📌 Multiple Versions

Many projects were intentionally implemented more than once.

For example:

- Version using my own custom Data Structures.
- Version using STL.
- Version using different OOP designs.
- Version using Structs.
- Version using Classes.

This allows comparing implementations and understanding design trade-offs.

Whenever you find an implementation that uses the **STL**, check the commit immediately before it to see the same solution implemented **without STL**.

Example:

| Version | Commit |
|---------|--------|
| Project 8 – QueueLine v1 | `8de42623` |
| Project 8 – QueueLine v2 (Custom Queue + struct) | `706110db` |
| Project 8 – QueueLine v3 (STL queue & stack + clsTicket) | `b64e10e4` |

<img width="1729" height="964" alt="Queue Line Test Example" src="https://github.com/user-attachments/assets/e3a12af5-d0fa-4380-a7a4-b5ad34ace672" />

---

# 🛠 Topics Covered

- Algorithms
- Problem Solving
- Big O Analysis
- Linked List
- Doubly Linked List
- Stack
- Queue
- Deque
- STL Containers
- Templates
- OOP
- Custom Data Structures
- Memory Management
- Generic Programming

---

# ▶️ Running the Test Files

Each data structure or class in this repository has its own dedicated test file.

For example:

| Class                | Test File                       |
| -------------------- | ------------------------------- |
| `clsDblLinkedList.h` | `DoublyLinkedListClassTest.cpp` |
| `clsDynamicArray.h`  | `DynamicArrayClassTest.cpp`     |
| `clsMyQueue.h`       | `MyQueueClassTest.cpp`          |
| `clsMyQueueArr.h`    | `MyQueueArrayClassTest.cpp`     |
| `clsMyStack.h`       | `MyStackClassTest.cpp`          |
| `clsMyStackArr.h`    | `MyStackClassArrTest.cpp`       |
| `clsMyString.h`      | `UndoRedoStringClassTest.cpp`   |
| `clsQueueLine.h`     | `QueueLineClassTestcpp.cpp`     |

> **Important:**
> Only **one** test file should be compiled at a time because every test file contains its own `main()` function.

## Method 1 (Recommended)

Right-click the desired test file (`*.cpp`)

→ **Properties**

→ **General**

→ **Excluded From Build**

Set it to:

* **No** → to run this test.
* **Yes** → for all other test files.

After that simply press **F5** (or **Ctrl + F5**) to run.

Example:

If you want to test **QueueLine**:

* `QueueLineClassTestcpp.cpp` → **Excluded From Build = No**
* Every other `*Test.cpp` → **Excluded From Build = Yes**
  
  <img width="1920" height="1020" alt="Screenshot 2026-08-03 210245" src="https://github.com/user-attachments/assets/b93301cc-9bff-45fc-b6eb-202de7136d4d" />

---

# 📚 Learning Notes

The repository is designed as a learning reference.

Many commits intentionally preserve intermediate implementations instead of replacing them.

This allows tracking:

- Different design decisions
- Performance improvements
- Code refactoring
- Evolution of each project

---

# 💻 Related Projects

If you'd like to see more of my C++ journey and the custom libraries built from scratch, check these repositories.

## 🔧 MyCppToolboxLibraries

My personal C++ library built completely from scratch.

Many of the projects below are built on top of these libraries.

https://github.com/yahiaalsebaie/MyCppToolboxLibraries

---

## 🏦 Bank System (OOP)

Object-Oriented implementation of a complete banking system.

Includes the Currency Exchange project.

https://github.com/yahiaalsebaie/Bank-System-OOP

---

## 🏦 Bank Management System (Procedural Programming)

The same banking system implemented using Procedural Programming.

https://github.com/yahiaalsebaie/Bank-Management-System-Cpp

---

## 🏧 ATM System

Complete ATM simulation.

https://github.com/yahiaalsebaie/ATM-System-Course08

---

## 📅 Dual Calendar System

Gregorian & Hijri Calendar Library.

Features:

- Date calculations
- Date arithmetic
- Historical dates
- Astronomical calculations
- Date differences

https://github.com/yahiaalsebaie/Dual-Calendar-System-MiladiAndHijiri

---

## 🎮 Math Game

Console Math Game.

https://github.com/yahiaalsebaie/cpp-Math-Game

---

## ✂️ Stone Paper Scissors Game

Console implementation of the classic game.

https://github.com/yahiaalsebaie/stone-paper-scissors-cpp-game

---

# 🎯 Purpose

This repository is mainly intended for:

- Students learning Data Structures
- Beginners learning C++
- Anyone interested in seeing how Data Structures can be implemented from scratch
- Comparing STL implementations with custom implementations

---

# ⭐ If you find this repository useful...

Please consider giving it a ⭐.

It helps others discover the project and motivates me to continue improving it.
