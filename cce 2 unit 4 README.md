CCE-2-Unit-4

Title 

Develop an inventory management system using AVL tree. Insert product IDs,apply 
LL,RR,LR and RL rotations when required,and display the balance factor.
Aim

A C++ Inventory Management System using an AVL Tree to store and manage product IDs efficiently. The project implements LL, RR, LR, and RL rotations to maintain tree balance, displays balance factors, supports product insertion and searching, and displays inventory in sorted order.

Problem Statement

The Inventory Management System using an AVL Tree is designed to efficiently manage product records using a self-balancing Binary Search Tree. The system allows users to insert products with unique Product IDs, search for products, and display inventory records in sorted order along with their balance factors. It automatically performs LL, RR, LR, and RL rotations whenever required to maintain tree balance and ensure efficient insertion and searching operations.

Objectives

To implement an AVL tree using C++. To manage inventory products using unique Product IDs. To demonstrate LL, RR, LR, and RL rotations. To calculate and display the balance factor of each node. To perform efficient product insertion and searching. To display inventory records in ascending order of Product IDs.

Algorithm

If the node becomes unbalanced, apply the appropriate rotation: LL: Right rotation RR: Left rotation LR: Left rotation followed by right rotation RL: Right rotation followed by left rotation Reject duplicate Product IDs. Step 5: Display Inventory Traverse the tree using inorder traversal. Display Product ID, Product Name, Quantity, and Balance Factor in ascending order of Product IDs. Step 6: Search Product Accept a Product ID. Compare it with the current node. Search the left or right subtree as required. Display the product details if found; otherwise, display “Product not found.” Step 7: Check the user's choice. If the choice is Exit, terminate the program. Otherwise, return to the menu. Step 8: Stop the program.

Features

Insert a product using a unique integer Product ID, product name, and quantity. Automatically rebalance the tree using LL, RR, LR, and RL rotations. Display products in ascending Product ID order. Display each node's balance factor. Search for a product by ID. Reject duplicate Product IDs.

Project overview

Language: C++ Data structure: AVL Tree (self-balancing Binary Search Tree) Product ID: Used as the unique key for each product Features: Insert products, perform LL, RR, LR and RL rotations, display balance factors, and show products in sorted order.

Conclusion

This project demonstrates the practical application of AVL trees in inventory management. It combines product handling with self-balancing tree operations to maintain efficient insertion and searching while providing a clear demonstration of all four AVL rotation cases.
