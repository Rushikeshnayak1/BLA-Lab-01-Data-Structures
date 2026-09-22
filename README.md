<div align="center">
BLA Lab 01 — Data Structures & Algorithms II
C++ Implementations of Stack, Circular Queue, Binary Trees, and Binary Search Trees
Rushikesh Nayak  
CSC-6021 — Data Structures and Algorithms II  
Professor Victor Govindaswamy (Dr. G)  
Concordia University Chicago
</div>
---
Project Overview
This repository documents my work for BLA Lab 01 in CSC-6021 — Data Structures and Algorithms II. The project combines conceptual study, visual explanations, C++ implementation, testing, and video demonstrations of foundational data structures.
The project focuses on three major areas:
Stack — LIFO behavior, core operations, overflow, underflow, and static-array implementation.
Queue & Circular Queue — FIFO behavior, FRONT/REAR management, circular indexing, and wrap-around.
Binary Trees & Binary Search Trees (BST) — tree terminology, BST construction, duplicate handling, pointers, recursion, and traversals.
The goal of this work is not only to implement the structures in C++, but also to explain how they work, why their rules matter, and how the code represents the underlying theory.
---
Repository Structure
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
> The folder structure above is intended to keep the source code, presentation material, diagrams, screenshots, and video documentation organized by topic.
---
1. Stack
Concept
A Stack is a linear data structure that follows the LIFO — Last In, First Out principle. The most recently inserted element is the first element removed.
For example, if the values are inserted in this order:
```text
10 → 20 → 30
```
`30` becomes the TOP of the Stack and is the first value removed.
A simple real-life comparison is a stack of trays: the last tray placed on top is normally the first tray taken off.
Core Operations
Operation	Purpose
`Push`	Adds a new value to the TOP
`Pop`	Removes the current TOP value
`Peek / Top`	Views the TOP value without removing it
`Empty Check`	Determines whether the Stack has no active elements
`Full Check`	Determines whether the fixed-size Stack has reached capacity
`Display`	Shows active values from TOP to BOTTOM
Overflow and Underflow
Stack Overflow occurs when an insertion is attempted after the fixed-size Stack has reached its maximum capacity.
Stack Underflow occurs when a removal is attempted while the Stack is empty.
Implementation Approach
The C++ implementation uses a static integer array with capacity 5 and a `top` variable.
```cpp
const int MAX_SIZE = 5;
int stack[MAX_SIZE];
int top = -1;
```
`top = -1` represents an empty Stack. A successful Push moves `top` forward before storing the new value, while Pop moves `top` backward after removing the current value.
---
2. Queue & Circular Queue
Concept
A Queue is a linear data structure based on the FIFO — First In, First Out principle. The first value inserted is the first value removed.
Insertion occurs at the REAR, while removal occurs at the FRONT.
Example:
```text
FRONT → 15 → 25 → 35 ← REAR
```
If one element is removed, `15` leaves first because it entered first.
A checkout line is a practical example of FIFO behavior.
Core Operations
Operation	Purpose
`Enqueue`	Adds an element at the REAR
`Dequeue`	Removes an element from the FRONT
`Peek`	Views the FRONT element without removing it
`isEmpty()`	Checks whether the Queue is empty
`isFull()`	Checks whether the Circular Queue is full
`Display`	Shows the active elements in logical FIFO order
Why Use a Circular Queue?
With a basic linear array Queue, positions at the beginning of the array may become unused after Dequeue operations even though the REAR has reached the final array position.
A Circular Queue solves this limitation by allowing FRONT and REAR to wrap back to the beginning of the array.
The implementation uses modulo arithmetic:
```cpp
(rear + 1) % MAX_SIZE
```
If `rear = 4` and `MAX_SIZE = 5`:
```text
(4 + 1) % 5 = 0
```
REAR therefore wraps from index `4` back to index `0`.
Wrap-Around Example
Initial Queue:
```text
15 → 25 → 35 → 45 → 55
```
After removing `15` and `25`, the first two physical array positions become available. New values `65` and `75` can reuse those positions through circular indexing.
Logical FIFO order:
```text
35 → 45 → 55 → 65 → 75
```
This demonstrates how a Circular Queue uses a fixed-size array more efficiently without shifting all remaining elements.
---
3. Binary Trees & Binary Search Trees
Binary Tree
A Binary Tree is a hierarchical data structure in which each node can have at most two children:
Left child
Right child
A general Binary Tree does not require the values to follow a numerical ordering rule.
Binary Search Tree
A Binary Search Tree (BST) adds an ordering rule:
```text
Smaller value → LEFT
Larger value  → RIGHT
```
The comparison is repeated from node to node until an available position is found.
Important Terminology
Term	Meaning
Node	Individual element in the tree
Root	First/top node of the tree
Parent	Node connected above another node
Child	Node connected below another node
Leaf	Node with no children
Subtree	A smaller tree beginning from a node
Predecessor	Next smaller value in sorted order
Successor	Next larger value in sorted order
Dataset Used
The BST is constructed using the following unique values:
```text
52, 31, 74, 18, 43, 63, 86, 27, 47, 59, 68, 79, 92
```
The implementation also tests duplicate occurrences of:
```text
31, 74
```
These duplicate values are detected and ignored.
Tree Details
Property	Result
Root	`52`
Unique values	`13`
Leaf nodes	`27, 47, 59, 68, 79, 92`
Predecessor of `63`	`59`
Successor of `63`	`68`
---
Tree Traversals
Tree traversal determines the order in which nodes are visited.
Inorder Traversal
Rule: `LEFT → ROOT → RIGHT`
```text
18, 27, 31, 43, 47, 52, 59, 63, 68, 74, 79, 86, 92
```
For this BST, Inorder traversal produces the values in ascending order.
Preorder Traversal
Rule: `ROOT → LEFT → RIGHT`
```text
52, 31, 18, 27, 43, 47, 74, 63, 59, 68, 86, 79, 92
```
Postorder Traversal
Rule: `LEFT → RIGHT → ROOT`
```text
27, 18, 47, 43, 31, 59, 68, 63, 79, 92, 86, 74, 52
```
The position at which the current node is processed is the key difference among these three traversal methods.
---
C++ Implementations
This repository contains three primary C++ programs.
`Stack.cpp`
Demonstrates:
Static-array Stack
Push
Pop
Peek
Display
Overflow handling
Underflow handling
`CircularQueue.cpp`
Demonstrates:
Array-based Circular Queue
Enqueue
Dequeue
Peek
Empty/full conditions
FRONT and REAR management
Modulo-based wrap-around
Logical Queue display
`BST.cpp`
Demonstrates:
Class-based Node structure
Pointer-based child connections
Recursive BST insertion
Duplicate detection
Inorder traversal
Preorder traversal
Postorder traversal
---
Compilation & Execution
Requirements
A C++ compiler such as GNU g++ is required.
Check the compiler installation:
```bash
g++ --version
```
Stack
```bash
g++ Stack.cpp -o stack
./stack
```
Circular Queue
```bash
g++ CircularQueue.cpp -o queue
./queue
```
Binary Search Tree
```bash
g++ BST.cpp -o bst
./bst
```
> If the `.cpp` files are stored inside the topic folders shown in this repository structure, open the appropriate folder in the terminal before using the commands above.
---
Diagrams & Program Evidence
Visual diagrams are included to support the theoretical explanations and show the progression of each data structure.
The project documentation includes diagrams for:
Stack Push and Pop
Stack Overflow and Underflow
Queue FIFO behavior
Circular Queue wrap-around
Binary Tree terminology
BST construction
Inorder traversal
Preorder traversal
Postorder traversal
Program screenshots are included to document compilation, execution, and output.
---
Video Demonstrations
The project is supported by video explanations covering the theory, diagrams, C++ implementation, and program output.
Video 1 — Stack Data Structure
YouTube: `[ADD STACK VIDEO LINK HERE]`
Covers LIFO, Stack operations, TOP management, Overflow, Underflow, diagrams, C++ implementation, and program demonstration.
Video 2 — Queue & Circular Queue
YouTube: `[ADD QUEUE VIDEO LINK HERE]`
Covers FIFO, Enqueue, Dequeue, FRONT/REAR management, Circular Queue wrap-around, modulo arithmetic, C++ implementation, and output.
Video 3 — Binary Trees & BST
YouTube: `[ADD BST VIDEO LINK HERE]`
Covers Binary Tree terminology, BST rules and construction, duplicate handling, predecessor/successor, Inorder, Preorder, Postorder, C++ implementation, and program output.
---
Learning Outcomes
Completing this project helped me connect theoretical Data Structure concepts with practical C++ implementation.
Through the Stack, I developed a clearer understanding of LIFO behavior, TOP management, and boundary conditions such as Overflow and Underflow.
The Queue and Circular Queue strengthened my understanding of FIFO behavior, FRONT/REAR management, fixed-size array limitations, and the use of modulo arithmetic for circular indexing.
The Binary Tree and BST section helped me understand hierarchical data organization, node relationships, pointers, recursive insertion, duplicate handling, and traversal algorithms. Implementing the traversals also helped me see how changing the position at which a node is processed changes the traversal order.
---
References & Acknowledgment
Professor Victor Govindaswamy (Dr. G)
The primary academic guidance for this BLA project came from Professor Victor Govindaswamy through his classroom lectures, explanations, examples, quizzes, lab instructions, and practical programming activities.
His step-by-step approach helped me develop a clearer understanding of Stacks, Queues, Circular Queues, Binary Trees, Binary Search Trees, and tree traversals. The combination of theoretical explanations and hands-on programming activities was especially helpful in connecting Data Structure concepts with their actual C++ implementations.
I sincerely appreciate Professor Victor Govindaswamy for his continued guidance, support, and encouragement throughout this learning process. His instruction has helped me strengthen both my conceptual understanding and my ability to apply these topics through programming.
Additional Resources
GitHub — Used to organize, document, and present the project source code, diagrams, screenshots, presentation material, and supporting files.
W3Schools — Used as an additional learning/reference resource while reviewing C++ concepts and syntax.
---
<div align="center">
Author
Rushikesh Nayak  
CSC-6021 — Data Structures and Algorithms II  
BLA Lab 01  
Concordia University Chicago
</div>
