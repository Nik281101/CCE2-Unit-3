 1.Aim

To develop a C++ application using a Singly Linked List to manage medicine inventory, search medicines, update stock, and identify medicines nearing expiry.

2. Problem Statement

Managing medicine stock manually can make it difficult to track quantities and expiry dates. This project provides a menu-driven system to manage medicine records using a Singly Linked List.

3.Algorithm

Start the program.
Define a Medicine structure with medicine details and a pointer to the next node.
Initialize the head pointer to NULL.
Display the menu.

4.Objective

To develop a Medicine Inventory and Expiry Management System using a Singly Linked List in C++ to manage medicine records, search medicines, update stock quantities, and identify expired or soon-to-expire medicines.
To add a medicine, create a new node and link it to the list.
To search, traverse the list and compare medicine IDs.
To update stock, find the medicine and change its quantity.
To display inventory, traverse and print each node.

5.Project Overview

The Medicine Inventory and Expiry Management System is a menu-driven C++ application that helps maintain medicine records efficiently. It uses a singly linked list to store medicine details dynamically, allowing records to be added and managed without a fixed-size array.
Each node stores the medicine ID, name, quantity, expiry date, and a pointer to the next node. The system simplifies inventory management and helps monitor medicine stock and expiry status.

6.Operations

1. Add Medicine: Insert a new medicine record into the inventory.
2. Search Medicine: Find a medicine using its unique ID.
3. Update Stock: Modify the quantity of an existing medicine.
4. Display Inventory: Display all available medicine records.
5. Check Expiry: Identify expired medicines and medicines nearing expiry.
6. Exit: Close the application.

Technologies Used

- Programming Language: C++
- Data Structure: Singly Linked List
- Concepts: Structures, Pointers, Dynamic Memory Allocation, and Menu-Driven Programming

 7.Conclusion

This project demonstrates the practical implementation of a singly linked list in C++. It provides essential inventory management operations and helps monitor medicine quantities and expiry dates. The project improves understanding of dynamic data structures and their applications in real-world inventory management.
To check expiry, compare each medicine's expiry date with the current date.
Repeat the menu until the user selects Exit.
Free the allocated nodes and stop the program.
