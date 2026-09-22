# BLA Lab 01 — Data Structures & Algorithms II

### C++ Implementation of Stack, Circular Queue, Binary Trees & Binary Search Trees

**Student:** Rushikesh Nayak  
**Course:** CSC-6021 — Data Structures and Algorithms II  
**Professor:** Victor Govindaswamy (Dr. G)  
**Institution:** Concordia University Chicago  
**Assignment:** BLA — Lab 01  

---

## 📘 Project Overview

This repository contains my work for **BLA Lab 01** in **CSC-6021 — Data Structures and Algorithms II**.

The project combines theoretical understanding, diagrams, C++ implementation, testing, program output, and video demonstrations of important Data Structure concepts.

The project focuses on three major areas:

- **Stack** — LIFO behavior, Push, Pop, Peek, Overflow, Underflow, and static-array implementation.
- **Queue & Circular Queue** — FIFO behavior, Enqueue, Dequeue, FRONT/REAR management, circular indexing, and wrap-around.
- **Binary Trees & Binary Search Trees (BST)** — tree terminology, BST construction, duplicate handling, pointers, recursion, and tree traversals.

The main goal of this project is to understand not only **how to implement these Data Structures in C++**, but also **how the code connects with the theoretical concepts studied in class**.

---

## 📂 Repository Structure

```text
BLA-Lab-01-Data-Structures/
│
├── README.md
│
├── Stack/
│   ├── Stack.cpp
│   ├── PPT/
│   └── Diagrams/
│
├── Queue-Circular-Queue/
│   ├── CircularQueue.cpp
│   ├── PPT/
│   └── Diagrams/
│
├── Binary-Tree-BST/
│   ├── BST.cpp
│   ├── PPT/
│   └── Diagrams/
│
├── Screenshots/
│
└── Video-Transcripts/
    ├── Stack-Script.pdf
    ├── Queue-Circular-Queue-Script.pdf
    └── BST-Script.pdf
```

---

# 1️⃣ Stack Data Structure

## What is a Stack?

A **Stack** is a linear Data Structure that follows the **LIFO — Last In, First Out** principle.

This means the **last element inserted is the first element removed**.

For example:

```text
Push 10
Push 20
Push 30

TOP
 ↓
30
20
10
```

If I perform a **Pop**, the value `30` is removed first.

A simple real-life example is a **stack of trays**. The last tray placed on top is normally the first tray removed.

### Main Stack Operations

| Operation | Description |
|---|---|
| **Push** | Adds a new element to the TOP |
| **Pop** | Removes the current TOP element |
| **Peek / Top** | Displays the TOP element without removing it |
| **Empty Check** | Checks whether the Stack contains no active elements |
| **Full Check** | Checks whether the fixed-size Stack reached its capacity |
| **Display** | Shows active elements from TOP to BOTTOM |

### Stack Overflow

**Overflow** occurs when we try to Push another value after the Stack has reached its maximum capacity.

### Stack Underflow

**Underflow** occurs when we try to Pop a value from an empty Stack.

### C++ Implementation

My Stack implementation uses a **static integer array with capacity 5**.

```cpp
const int MAX_SIZE = 5;
int stack[MAX_SIZE];
int top = -1;
```

The value:

```cpp
top = -1;
```

represents an empty Stack.

When a value is pushed, `top` moves forward. When a value is popped, `top` moves backward.

---

# 2️⃣ Queue & Circular Queue

## What is a Queue?

A **Queue** is a linear Data Structure that follows the **FIFO — First In, First Out** principle.

The first element inserted is the first element removed.

New values enter from the **REAR**, while values leave from the **FRONT**.

Example:

```text
FRONT → 15 → 25 → 35 ← REAR
```

Here, `15` will be removed first because it entered the Queue first.

A simple real-life example is a **checkout line**, where the first customer in line is normally served first.

### Main Queue Operations

| Operation | Description |
|---|---|
| **Enqueue** | Adds an element at the REAR |
| **Dequeue** | Removes an element from the FRONT |
| **Peek** | Displays the FRONT element without removing it |
| **isEmpty()** | Checks whether the Queue is empty |
| **isFull()** | Checks whether the Circular Queue is full |
| **Display** | Displays active Queue elements |

---

## Why Use a Circular Queue?

A normal array-based Queue can leave unused positions at the beginning of the array after Dequeue operations.

A **Circular Queue** solves this limitation by allowing the FRONT and REAR indexes to wrap around to the beginning of the array.

The important expression used in my implementation is:

```cpp
(rear + 1) % MAX_SIZE
```

For example, if:

```text
rear = 4
MAX_SIZE = 5
```

then:

```text
(4 + 1) % 5
= 5 % 5
= 0
```

This means REAR wraps from index `4` back to index `0`.

### Circular Queue Example

Initial Queue:

```text
15 → 25 → 35 → 45 → 55
```

After removing `15` and `25`, the first two positions become available.

New values `65` and `75` can reuse those positions through circular indexing.

The logical Queue becomes:

```text
35 → 45 → 55 → 65 → 75
```

This demonstrates how Circular Queue can efficiently reuse positions in a fixed-size array.

---

# 3️⃣ Binary Trees & Binary Search Trees

## Binary Tree

A **Binary Tree** is a hierarchical Data Structure where each node can have a maximum of two children:

- **Left Child**
- **Right Child**

A normal Binary Tree does not require the values to follow a numerical ordering rule.

---

## Binary Search Tree (BST)

A **Binary Search Tree** is a special type of Binary Tree that follows an ordering rule:

```text
Smaller Value → LEFT
Larger Value  → RIGHT
```

This comparison is repeated until the correct empty position is found.

---

## Important Tree Terminology

| Term | Meaning |
|---|---|
| **Node** | An individual element in the tree |
| **Root** | The first/top node |
| **Parent** | A node connected above another node |
| **Child** | A node connected below another node |
| **Leaf** | A node with no children |
| **Subtree** | A smaller tree beginning from a node |
| **Predecessor** | The next smaller value in sorted order |
| **Successor** | The next larger value in sorted order |

---

## BST Dataset Used

The values used to construct my BST are:

```text
52, 31, 74, 18, 43, 63, 86, 27, 47, 59, 68, 79, 92
```

I also tested duplicate values:

```text
31 and 74
```

My program detects these duplicate values and ignores them.

### BST Information

| Property | Result |
|---|---|
| **Root** | 52 |
| **Unique Values** | 13 |
| **Leaf Nodes** | 27, 47, 59, 68, 79, 92 |
| **Predecessor of 63** | 59 |
| **Successor of 63** | 68 |

---

# 🌳 Tree Traversals

## Inorder Traversal

**Rule:**

```text
LEFT → ROOT → RIGHT
```

**Output:**

```text
18, 27, 31, 43, 47, 52, 59, 63, 68, 74, 79, 86, 92
```

For this BST, Inorder traversal produces the values in **ascending order**.

---

## Preorder Traversal

**Rule:**

```text
ROOT → LEFT → RIGHT
```

**Output:**

```text
52, 31, 18, 27, 43, 47, 74, 63, 59, 68, 86, 79, 92
```

---

## Postorder Traversal

**Rule:**

```text
LEFT → RIGHT → ROOT
```

**Output:**

```text
27, 18, 47, 43, 31, 59, 68, 63, 79, 92, 86, 74, 52
```

The location of the **ROOT operation** is the main difference between Inorder, Preorder, and Postorder traversal.

---

# 💻 C++ Programs

This repository contains three main C++ implementations.

### Stack.cpp

Demonstrates:

- Push
- Pop
- Peek
- Display
- Overflow
- Underflow
- Static-array Stack implementation

### CircularQueue.cpp

Demonstrates:

- Enqueue
- Dequeue
- Peek
- Display
- Empty condition
- Full condition
- FRONT and REAR management
- Circular wrap-around

### BST.cpp

Demonstrates:

- Class-based Node structure
- Pointers
- Recursive insertion
- Duplicate detection
- Inorder traversal
- Preorder traversal
- Postorder traversal

---

# ⚙️ Compilation & Execution

The programs can be compiled using the **GNU C++ compiler (g++)**.

## Stack

Compile:

```bash
g++ Stack.cpp -o stack
```

Run:

```bash
./stack
```

## Circular Queue

Compile:

```bash
g++ CircularQueue.cpp -o queue
```

Run:

```bash
./queue
```

## Binary Search Tree

Compile:

```bash
g++ BST.cpp -o bst
```

Run:

```bash
./bst
```

> If the `.cpp` files are stored inside separate folders, open the appropriate folder in the terminal before using the corresponding commands.

---

# 🖼️ Diagrams & Screenshots

Diagrams are included to provide visual explanations of the Data Structures covered in this project.

The project includes diagrams for:

- Stack Push and Pop
- Stack Overflow and Underflow
- Queue FIFO behavior
- Circular Queue wrap-around
- Binary Tree terminology
- BST construction
- Inorder traversal
- Preorder traversal
- Postorder traversal

Program screenshots are also included to provide evidence of **compilation, execution, and output**.

---

# 🎥 Video Demonstrations

I created video explanations to demonstrate the theory, diagrams, C++ code, and program output for each major topic.

## Video 1 — Stack Data Structure

**YouTube:** https://youtu.be/JZTU6inQm_g?si=YSow8dMXtykGAfTZ

Topics include **LIFO, Push, Pop, Peek, Overflow, Underflow, diagrams, C++ implementation, and program output**.

---

## Video 2 — Queue & Circular Queue

**YouTube:** https://youtu.be/iTMKbsSJSr0?si=ASiwkU0hqkfaStuo

Topics include **FIFO, Enqueue, Dequeue, FRONT, REAR, Circular Queue wrap-around, modulo arithmetic, C++ implementation, and output**.

---

## Video 3 — Binary Trees & BST

**YouTube:** https://youtu.be/XZJbFwljFFU?si=ENnbXFN2MjrXhTVh

Topics include **Binary Tree terminology, BST construction, duplicate handling, predecessor, successor, Inorder, Preorder, Postorder, C++ implementation, and output**.

---

# 🎯 What I Learned

Completing this BLA helped me connect the theoretical concepts studied in class with practical **C++ implementation**.

Through the **Stack**, I developed a clearer understanding of LIFO behavior, TOP management, Push, Pop, Overflow, and Underflow.

Through the **Queue and Circular Queue**, I learned more about FIFO behavior, FRONT and REAR management, fixed-size array limitations, and how modulo arithmetic allows circular indexing and position reuse.

The **Binary Tree and BST** section helped me understand hierarchical Data Structures, nodes, pointers, recursive insertion, duplicate handling, predecessor/successor relationships, and tree traversal algorithms.

Implementing these concepts helped me better understand **how Data Structures work internally instead of only learning their definitions**.

---

# 📚 References & Acknowledgment

## Professor Victor Govindaswamy (Dr. G)

The primary academic guidance for this BLA project came from **Professor Victor Govindaswamy** through his classroom lectures, explanations, examples, quizzes, lab instructions, and practical programming activities.

His step-by-step teaching helped me develop a clearer understanding of **Stacks, Queues, Circular Queues, Binary Trees, Binary Search Trees, and tree traversals**. His classroom explanations helped me understand the theoretical concepts, while the programming activities helped me see how those concepts are implemented practically using C++.

I sincerely appreciate **Professor Victor Govindaswamy** for his continued guidance, support, and encouragement throughout this learning process. His instruction has helped me strengthen both my conceptual understanding of Data Structures and my confidence in applying these concepts through programming.

### Additional Resources

- **GitHub** — Used to organize and present the source code, project documentation, diagrams, screenshots, presentations, and supporting materials.
- **W3Schools** — Used as an additional learning and reference resource while reviewing C++ programming concepts and syntax.

---

# 👤 Author

**Rushikesh Nayak**  
**CSC-6021 — Data Structures and Algorithms II**  
**BLA Lab 01**  
**Concordia University Chicago**
