Singly Linked List
==================

# About

An SLL of IntNodes defined in singly_linked_list.h.

This repo includes the project files for Pelles C, a singly linked list implementation, and a test suite for testing the functions involved with manipulating, creating, and deleting nodes. An example output from the test harness is included in the output folder where Pelles C creates the .obj files.

# IntNode

An IntNode consists of an int element, and a next element (of type IntNode).

# List

The List will follow the convention of the "head" node being passed as a reference to the list, It is assumed that there are no IntNodes which contain next elements which point to the head node. The body of the list is made up of consecutive elements linked together with next references. Since there are no references back to previous nodes, the reference to the head node must be maintained so that the list can be traversed again, or passed, etc. The last node in the list is denoted by a null next reference.

ex. 
```  
  IntNode a1: {value: 10, next: a2}
  IntNode a2: {value: 7, next: a3}
  IntNode a3: {value: 12, next: null}
  
  head
   |
   v
  a1:10 ---> a2:7 ---> a3:12
```

# Primitive SLL Operations

Since this list contains uni-directional references, the head reference must be preserved so that you can work further with that list.

When traversing a SLL a temp node pointer is moved from node to node by setting it to the next attribute.
