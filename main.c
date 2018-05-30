/*
 * This test module and the code herein were provided by Prof. Donald
 * Bailey, Carleton University 2014. It was received without any
 * additional copywright indications. It is included here without any
 * modification, and should be treated as a related but individually
 * licensed work.
 */

/* Test Singly-Linked-List of IntNodes */

/* A bit of code to exercise the functions added to singly_linked_list.c
 * during Lab 10.
 * Version 1.03 - dlb
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

void print_boolean(_Bool a_boolean)
{
    if (a_boolean)
        printf("true");
    else
        printf("false");
}

int main(void)
{
    IntNode *empty = NULL; // An empty linked list.

    printf("=== Testing insert ===\n\n");

    IntNode *list1 = NULL;  // An empty linked list.

    printf("Calling insert with list: ");
    print_linked_list(list1);
    printf("\nInserting 10 at index 0.\n");
    list1 = insert(list1, 0, 10);
    printf("Expected list:\t10\n");
    printf("Actual list:\t");
    print_linked_list(list1);
    printf("\n\n");
    printf("Calling insert with list: ");
    print_linked_list(list1);
    printf("\nInserting 20 value at index 0.\n");
    list1 = insert(list1, 0, 20);
    printf("Expected list:\t20 -> 10\n");
    printf("Actual list:\t");
    print_linked_list(list1);
    printf("\n\n");

    printf("Calling insert with list: ");
    print_linked_list(list1);
    printf("\nInserting 30 at index 1.\n");
    list1 = insert(list1, 1, 30);
    printf("Expected list:\t20 -> 30 -> 10\n");
    printf("Actual list:\t");
    print_linked_list(list1);
    printf("\n\n");

    printf("Calling insert with list: ");
    print_linked_list(list1);
    printf("\nInserting 40 at index 3.\n");
    list1 = insert(list1, 3, 40);
    printf("Expected list:\t20 -> 30 -> 10 -> 40\n");
    printf("Actual list:\t");
    print_linked_list(list1);
    printf("\n\n");

    printf("=== Testing delete ===\n\n");

    printf("Building linked list 10\n\n");

    IntNode *list2 = NULL;
    list2 = intnode_construct(10, list2);

    printf("Calling delete with list: ");
    print_linked_list(list2);
    printf("\nDeleting element at index 0.\n");
    list2 = delete(list2, 0);
    printf("Expected list:\tempty list\n");
    printf("Actual list:\t");
    print_linked_list(list2);
    printf("\n\n");

    printf("Building linked list 10 -> 20 -> 30 -> 40 -> 50\n\n");

    list2 = NULL;
    list2 = intnode_construct(50, list2);
    list2 = intnode_construct(40, list2);
    list2 = intnode_construct(30, list2);
    list2 = intnode_construct(20, list2);
    list2 = intnode_construct(10, list2);

    printf("Calling delete with list: ");
    print_linked_list(list2);
    printf("\nDeleting element at index 0.\n");
    list2 = delete(list2, 0);
    printf("Expected list:\t20 -> 30 -> 40 -> 50\n");
    printf("Actual list:\t");
    print_linked_list(list2);
    printf("\n\n");

    printf("Calling delete with list: ");
    print_linked_list(list2);
    printf("\nDeleting element at index 2.\n");
    list2 = delete(list2, 2);
    printf("Expected list:\t20 -> 30 -> 50\n");
    printf("Actual list:\t");
    print_linked_list(list2);
    printf("\n\n");

    printf("Calling delete with list: ");
    print_linked_list(list2);
    printf("\nDeleting element at index 2.\n");
    list2 = delete(list2, 2);
    printf("Expected list:\t20 -> 30\n");
    printf("Actual list:\t");
    print_linked_list(list2);
    printf("\n\n");

    printf("Calling delete with list: ");
    print_linked_list(list2);
    printf("\nDeleting element at index 0.\n");
    list2 = delete(list2, 0);
    printf("Expected list:\t30\n");
    printf("Actual list:\t");
    print_linked_list(list2);
    printf("\n\n");

    printf("=== Testing delete_target ===\n\n");

    _Bool success;

    printf("Calling delete_target with list: ");
    print_linked_list(empty);
    printf("\nDeleting 5 from list.\n");
    list2 = delete_target(empty, 5, &success);
    printf("Expected list:\tempty_list\n");
    printf("Actual list:\t");
    print_linked_list(list2);
    printf("\nExpected value returned via parameter remove: false\n");
    printf("Actual value returned via parameter remove: ");
    print_boolean(success);
    printf("\n\n");

    printf("Building linked list 10\n\n");

    IntNode *list3 = NULL;
    list3 = intnode_construct(10, list3);

    printf("Calling delete_target with list: ");
    print_linked_list(list3);
    printf("\nDeleting 5 from list.\n");
    list3 = delete_target(list3, 5, &success);
    printf("Expected list:\t10\n");
    printf("Actual list:\t");
    print_linked_list(list3);
    printf("\nExpected value returned via parameter remove: false\n");
    printf("Actual value returned via parameter remove: ");
    print_boolean(success);
    printf("\n\n");

    printf("Calling delete_target with list: ");
    print_linked_list(list3);
    printf("\nDeleting 10 from list.\n");
    list3 = delete_target(list3, 10, &success);
    printf("Expected list:\tempty list\n");
    printf("Actual list:\t");
    print_linked_list(list3);
    printf("\nExpected value returned via parameter remove: true\n");
    printf("Actual value returned via parameter remove: ");
    print_boolean(success);
    printf("\n\n");

    printf("Building linked list 10 -> 20 -> 30 -> 40 -> 50\n\n");

    list3 = NULL;
    list3 = intnode_construct(50, list3);
    list3 = intnode_construct(40, list3);
    list3 = intnode_construct(30, list3);
    list3 = intnode_construct(20, list3);
    list3 = intnode_construct(10, list3);

    printf("Calling delete_target with list: ");
    print_linked_list(list3);
    printf("\nDeleting 5 from list.\n");
    list3 = delete_target(list3, 5, &success);
    printf("Expected list:\t10 -> 20 -> 30 -> 40 -> 50\n");
    printf("Actual list:\t");
    print_linked_list(list3);
    printf("\nExpected value returned via parameter remove: false\n");
    printf("Actual value returned via parameter remove: ");
    print_boolean(success);
    printf("\n\n");

    printf("Calling delete_target with list: ");
    print_linked_list(list3);
    printf("\nDeleting 10 from list.\n");
    list3 = delete_target(list3, 10, &success);
    printf("Expected list:\t20 -> 30 -> 40 -> 50\n");
    printf("Actual list:\t");
    print_linked_list(list3);
    printf("\nExpected value returned via parameter remove: true\n");
    printf("Actual value returned via parameter remove: ");
    print_boolean(success);
    printf("\n\n");

    printf("Calling delete_target with list: ");
    print_linked_list(list3);
    printf("\nDeleting 40 from list.\n");
    list3 = delete_target(list3, 40, &success);
    printf("Expected list:\t20 -> 30 -> 50\n");
    printf("Actual list:\t");
    print_linked_list(list3);
    printf("\nExpected value returned via parameter remove: true\n");
    printf("Actual value returned via parameter remove: ");
    print_boolean(success);
    printf("\n\n");

    printf("Calling delete_target with list: ");
    print_linked_list(list3);
    printf("\nDeleting 50 from list.\n");
    list3 = delete_target(list3, 50, &success);
    printf("Expected list:\t20 -> 30\n");
    printf("Actual list:\t");
    print_linked_list(list3);
    printf("\nExpected value returned via parameter remove: true\n");
    printf("Actual value returned via parameter remove: ");
    print_boolean(success);
    printf("\n\n");
}
