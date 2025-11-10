# Binary-Search_Tree-Strings
String-BST-Cpp

A Binary Search Tree (BST) implementation in C++ that stores strings and supports duplicates. This project demonstrates key concepts of data structures, recursion, and memory management in C++.

Features

Insert strings into the BST (duplicates are counted).

Search for strings in the tree.

Remove strings, handling duplicates and node replacement.

Find the smallest and largest strings.

Compute the height of a node or the tree.

Tree traversal methods: in-order, pre-order, post-order.

Implementation Details

Node Class (Node.h / Node.cpp): Represents a tree node containing a string, its duplicate count, and pointers to left and right children.

BSTree Class (BSTree.h / BSTree.cpp): Implements the BST with recursive methods for insertion, search, deletion, height calculation, and traversal.

Handles memory management using destructors to avoid memory leaks.


Example:

BSTree tree;
tree.insert("apple");
tree.insert("banana");
tree.insert("apple"); // duplicate
tree.inOrder(); // Output: apple(2), banana(1)

Learning Outcomes

Understand Binary Search Tree operations: insertion, search, deletion.

Practice recursive algorithms for tree manipulation.

Learn memory management with dynamic allocation and destructors.
