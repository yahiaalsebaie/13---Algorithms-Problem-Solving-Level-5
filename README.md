# 13 - Algorithms & Problem Solving Level 5: Custom Data Structures Library

## Overview

This repository contains a comprehensive implementation of **fundamental data structures and algorithms** built **completely from scratch** using modern C++ (C++14). Every data structure is implemented without relying on STL container shortcuts, providing deep insights into memory management, algorithmic complexity, and object-oriented design principles.

This project is part of **Course #13: Algorithms & Problem Solving Level 5** from [Programming Advices](https://programmingadvices.com/courses/13-algorithms-problem-solving-level-5/).

## ? Features

- **8 Core Data Structures** - All implemented from scratch without STL dependencies
- **Template-Based Design** - Generic implementations supporting any data type
- **Memory Management** - Explicit memory allocation and deallocation with proper cleanup
- **OOP Principles** - Encapsulation, inheritance, and polymorphism throughout
- **Interactive Demo Application** - Menu-driven interface to explore all data structures
- **Comprehensive Test Files** - Individual test files for each data structure with detailed examples
- **Custom String Engine** - String manipulation with Undo/Redo capabilities
- **Queue Line Simulation** - Real-world application demonstrating queue usage

## ?? Learning Objectives

By studying this project, you will understand:

- How dynamic arrays handle automatic memory resizing
- Linked list node-based storage and bidirectional traversal
- FIFO (First-In-First-Out) queue operations and use cases
- LIFO (Last-In-First-Out) stack operations and use cases
- Template programming in C++ for generic data structures
- Memory management and pointer manipulation
- Time and space complexity analysis
- Practical applications of data structures (queue line simulation)

## ?? Data Structures Implemented

### 1. **Dynamic Array** (`clsDynamicArray`)
- Automatic memory resizing as elements are added
- Random access in O(1) time
- Template-based generic implementation
- Proper memory cleanup in destructor

### 2. **Doubly Linked List** (`clsDblLinkedList`)
- Bidirectional node traversal (forward and backward)
- O(n) search, O(1) insertion/deletion at known position
- Head and tail pointer management
- Node-based architecture with previous/next pointers

### 3. **Queue - LinkedList-Based** (`clsMyQueue`)
- FIFO data structure using doubly linked list backend
- O(1) enqueue and dequeue operations
- Generic template implementation
- Perfect for sequential processing

### 4. **Queue - Array-Based** (`clsMyQueueArr`)
- FIFO implementation using circular array
- Fixed capacity with wrap-around indexing
- Memory-efficient alternative to linked list
- Suitable for size-constrained scenarios

### 5. **Stack - LinkedList-Based** (`clsMyStack`)
- LIFO data structure using doubly linked list backend
- O(1) push and pop operations
- Generic template implementation
- Natural choice for recursion and backtracking

### 6. **Stack - Array-Based** (`clsMyStackArr`)
- LIFO implementation using dynamic array
- Growing capacity as needed
- Efficient for simple use cases
- Reduced pointer overhead compared to linked lists

### 7. **Custom String** (`clsString`)
- Full string manipulation capabilities
- Undo/Redo engine for text operations
- Insert, delete, and replace functionality
- Built completely from scratch without std::string shortcuts

### 8. **Queue Line System** (`clsQueueLine`)
- Real-world queue simulation
- Automatic ticket generation with prefixes
- Customer arrival and service tracking
- Queue statistics and analytics
- Multiple versions demonstrating evolution of implementation

## ??? Technologies Used

- **Language:** C++14
- **Compiler:** MSVC (Visual Studio 2022 compatible)
- **Standard Library:** Minimal STL usage; custom implementations preferred
- **Platform:** Windows (Visual Studio .vcxproj project)
- **Programming Paradigm:** Object-Oriented Programming (OOP)

## ?? Project Structure

    13 - Algorithms & Problem Solving Level 5/
    ??? README.md                               # This file
    ??? 13 - Algorithms & Problem Solving Level 5.cpp  # Main demo application
    ??? 13 - Algorithms & Problem Solving Level 5.vcxproj
    ??? 13 - Algorithms & Problem Solving Level 5.vcxproj.filters
    ?
    ??? Core Data Structure Headers:
    ??? clsDynamicArray.h                      # Dynamic array template
    ??? clsDblLinkedList.h                     # Doubly linked list template
    ??? clsMyQueue.h                           # LinkedList-based queue
    ??? clsMyQueueArr.h                        # Array-based queue
    ??? clsMyStack.h                           # LinkedList-based stack
    ??? clsMyStackArr.h                        # Array-based stack
    ??? clsString.h                            # Custom string with undo/redo
    ??? clsQueueLine.h                         # Queue line simulation
    ?
    ??? Individual Test/Demo Files:
    ??? DynamicArrayClassTest.cpp              # Dynamic array examples
    ??? DoublyLinkedListClassTest.cpp          # Linked list examples
    ??? MyQueueClassTest.cpp                   # LinkedList queue examples
    ??? MyQueueArrayClassTest.cpp              # Array queue examples
    ??? MyStackClassTest.cpp                   # LinkedList stack examples
    ??? MyStackArrayClassTest.cpp              # Array stack examples
    ??? StringClassTest.cpp                    # String manipulation examples
    ??? QueueLineTest.cpp                      # Queue line system examples
    ?
    ??? Utility Files:
        ??? clsUtil.h                          # Helper functions

## ?? How to Build and Run

### Prerequisites
- Visual Studio 2022 or later
- C++14 support
- Windows OS

### Build Steps

1. **Clone the Repository**

        git clone https://github.com/yahiaalsebaie/13---Algorithms-Problem-Solving-Level-5.git
        cd "13 - Algorithms & Problem Solving Level 5"

2. **Open in Visual Studio**
- Open `13 - Algorithms & Problem Solving Level 5.vcxproj` in Visual Studio 2022

3. **Build the Project**
- Press `Ctrl+Shift+B` to build the entire solution
- Or navigate to: **Build > Build Solution**

4. **Run the Application**
- Press `Ctrl+F5` to run without debugging
- Or press `F5` to run with debugging

### Running Individual Tests

Each data structure has a dedicated test file that can be set as the startup project:

1. Right-click the test file in Solution Explorer
2. Select **Set as Startup Item**
3. Run the project (`Ctrl+F5` or `F5`)

### Main Demo Application

The main application (`13 - Algorithms & Problem Solving Level 5.cpp`) provides an interactive menu:

    MAIN MENU - SELECT A DATA STRUCTURE TO EXPLORE
    ?????????????????????????????????????????????????????????????????????
                                                    
      [1] Dynamic Array
      [2] Doubly Linked List
      [3] Queue (LinkedList-based)
      [4] Queue (Array-based)
      [5] Stack (LinkedList-based)
      [6] Stack (Array-based)
      [7] Custom String with Undo/Redo
      [8] Queue Line System Simulation
      [9] About This Project
      [10] Exit

## ?? Algorithms Covered

### Array Algorithms
- Linear search
- Element insertion and removal
- Dynamic resizing with capacity management

### Linked List Algorithms
- Traversal (forward and backward)
- Node insertion at specific positions
- Node deletion and cleanup
- Circular list operations

### Queue Algorithms
- Enqueue operation (append)
- Dequeue operation (remove from front)
- FIFO processing
- Circular array indexing (array-based)

### Stack Algorithms
- Push operation (add to top)
- Pop operation (remove from top)
- LIFO processing
- Recursion support

### String Algorithms
- String searching and replacement
- Character manipulation
- Undo/Redo state management using stacks

### Queue Line Algorithms
- Ticket generation with unique prefixes
- Customer arrival simulation
- Service time tracking
- Queue statistics calculation

## ?? Detailed Implementation Notes

### Custom Implementations Philosophy

Every data structure is built from the ground up to provide:
- **Deep understanding** of how data structures work internally
- **Memory management** awareness through explicit allocation/deallocation
- **Performance insights** by understanding pointer manipulation and indexing
- **Educational value** through clean, well-commented code

### LinkedList vs Array-Based Comparison

| Aspect | LinkedList-Based | Array-Based |
|--------|-----------------|------------|
| **Access Time** | O(n) | O(1) |
| **Insertion/Deletion** | O(1) at known position | O(n) worst case |
| **Memory Overhead** | Extra pointers per node | Single capacity allocation |
| **Use Case** | Unknown size, frequent insertions | Fixed/bounded size |
| **Cache Locality** | Poor | Good |

### Template Design Pattern

All data structures use C++ templates to support any data type:

    clsDynamicArray<int> intArray(10);
    clsDynamicArray<string> stringArray(5);
    clsMyQueue<double> doubleQueue;
    clsMyStack<char> charStack;

## ?? Project Evolution: Queue Line System

The Queue Line System demonstrates three different implementation approaches across commits:

### Version 1 - Basic Queue (Commit 8de42623)
- Simple queue-based ticket system
- Basic customer tracking
- Foundation implementation

### Version 2 - Enhanced Custom Queue (Commit 706110db)
- Custom queue implementation without STL
- Ticket structure (struct stTicket)
- Improved service time tracking

### Version 3 - Full Object-Oriented (Commit b64e10e4)
- Dedicated clsTicket class
- STL queue/stack usage
- Production-ready features

This evolution shows how the same system can be implemented with increasing sophistication.

## ?? Repository Structure Explanation

### Header Files (`.h`)
Each header contains a complete template class definition:
- Template class declaration and implementation
- Member functions and data members
- Documentation and comments
- No separate `.cpp` files needed for templates

### Test Files (`.cpp`)
Individual test files for comprehensive testing:
- Example usage for each data structure
- Edge case handling
- Performance demonstrations
- Multiple test scenarios

### Main Application
`13 - Algorithms & Problem Solving Level 5.cpp` provides:
- Interactive menu system
- Quick demonstrations of all data structures
- Project information and course details
- Educational overview

## ?? Course Information

This project is from **Course #13: Algorithms & Problem Solving Level 5** by Programming Advices.

- **Course Link:** [https://programmingadvices.com/courses/13-algorithms-problem-solving-level-5/](https://programmingadvices.com/courses/13-algorithms-problem-solving-level-5/)
- **Target Audience:** Intermediate to Advanced C++ learners
- **Prerequisites:** Understanding of basic data types, pointers, and OOP concepts
- **Duration:** Self-paced learning with practical implementations

## ?? Screenshots & Output Examples

### Main Menu
The interactive application displays a formatted menu with options to explore each data structure.

### Dynamic Array Output
    Dynamic Array demonstration complete!
    Array Size: 5
    Printing array elements:
    10 20 30 40 50

### Queue Simulation Output
    Queue (LINKEDLIST-BASED) DEMONSTRATION
    Queue Size: 3
    Queue contents (FIFO order):
    100 -> 200 -> 300
    Remaining queue after dequeue:
    200 -> 300
    Queue Size: 2

### Stack Simulation Output
    Stack (LINKEDLIST-BASED) DEMONSTRATION
    Stack Size: 4
    Stack contents (LIFO order):
    D -> C -> B -> A
    Remaining stack after pop:
    C -> B -> A
    Stack Size: 3

## ?? Related Projects

Explore more of my C++ learning journey through these related repositories:

### [MyCppToolboxLibraries](https://github.com/yahiaalsebaie/MyCppToolboxLibraries)
Custom C++ libraries and reusable components built from scratch. Includes utility classes, helper functions, and common patterns used across projects.

### [Bank System (OOP)](https://github.com/yahiaalsebaie/Bank-System-OOP)
Object-Oriented Banking System with integrated Currency Exchange. Demonstrates advanced OOP principles, inheritance hierarchies, and real-world application design.

### [Bank Management System (Procedural)](https://github.com/yahiaalsebaie/Bank-Management-System-Cpp)
Banking System implemented using Procedural Programming. Shows procedural approaches to the same problem domain as the OOP version.

### [ATM System](https://github.com/yahiaalsebaie/ATM-System-Course08)
ATM simulation project from Course #8. Demonstrates practical application of data structures and control flow in a real-world scenario.

### [Dual Calendar System](https://github.com/yahiaalsebaie/Dual-Calendar-System-MiladiAndHijiri)
Gregorian & Hijri calendar system with date calculations, astronomical conversions, date arithmetic, and comparisons. Shows complex date handling algorithms.

### [Math Game](https://github.com/yahiaalsebaie/cpp-Math-Game)
Console-based educational math game demonstrating game logic, user interaction, and scoring systems.

### [Stone Paper Scissors Game](https://github.com/yahiaalsebaie/stone-paper-scissors-cpp-game)
Classic console game implementation in C++ with AI opponent and game mechanics.

## ?? Future Improvements

Potential enhancements and extensions for this project:

- **Balanced Binary Search Trees** - Red-Black trees or AVL trees
- **Graph Implementations** - Adjacency list and matrix representations
- **Advanced Sorting Algorithms** - QuickSort, MergeSort with performance comparisons
- **Hashing Implementations** - Hash tables and collision resolution strategies
- **Recursion Examples** - Tower of Hanoi, Tree traversals, Backtracking problems
- **Performance Benchmarks** - Detailed timing comparisons between implementations
- **Memory Profiling** - Analysis of memory usage patterns
- **Algorithm Visualizations** - Step-by-step operation demonstrations
- **Thread-Safe Versions** - Concurrent data structure implementations
- **Unit Tests** - Comprehensive automated testing framework

## ?? License

This project is provided as educational material from the Programming Advices course. Please refer to the course terms for usage rights.

## ?? Author

**Yahia Al-Sebaie**
- GitHub: [@yahiaalsebaie](https://github.com/yahiaalsebaie)
- Repository: [13---Algorithms-Problem-Solving-Level-5](https://github.com/yahiaalsebaie/13---Algorithms-Problem-Solving-Level-5)

## ?? Tips for Learning

1. **Start with the simplest structures** - Begin with Dynamic Array, then progress to Linked Lists
2. **Run individual test files** - Don't just use the main demo; explore detailed test files
3. **Modify and experiment** - Change the code, break things, and rebuild your understanding
4. **Compare implementations** - Study both LinkedList and Array-based versions to understand tradeoffs
5. **Review git history** - Use `git log` to see the evolution of implementations
6. **Draw diagrams** - Visualize how pointers and nodes connect in linked structures
7. **Analyze complexity** - Understand why certain operations have specific time complexities

## ? FAQ

**Q: Why are STL containers not used?**  
A: STL containers are powerful production tools, but understanding how they work internally is essential for mastery. This project builds these structures from scratch for educational purposes.

**Q: Can I use these implementations in production?**  
A: These are primarily educational implementations. For production code, use well-tested STL containers. However, the knowledge gained is invaluable.

**Q: What if I find an implementation using STL?**  
A: Check previous commits in git history. Earlier versions demonstrate the same functionality using only custom data structures. Use `git log` to navigate commits.

**Q: How do I switch between versions of QueueLine?**  
A: Use git checkout to view previous implementations:
    git checkout b64e10e4  # QueueLine v3 (STL-based)
    git checkout 706110db  # QueueLine v2 (Custom Queue)
    git checkout 8de42623  # QueueLine v1 (Basic)
    git checkout master    # Return to latest

---

**Happy Learning! ??**

For questions, discussions, or contributions, feel free to open an issue or pull request on the GitHub repository.