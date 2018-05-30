/*
 * Copyright (C) 2018 William Keane Hickey.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License and GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 * or write the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* Written by William Hickey */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

/* Construct an intnode defined in singly_linked_list.h
 */
IntNode *intnode_construct(int value, IntNode *next)
{
    IntNode *p = malloc(sizeof(IntNode));
    assert (p != NULL);
    p->value = value;
    p->next = next;
    return p;
}

/* Print the linked list pointed to by p.
 */
void print_linked_list(IntNode *p)
{
    if (p == NULL) {
        printf("empty list");
        return;
     }

    /* Print every node in the linked list except the last one,
       using the format: value1 -> value2 -> value3 -> ...
     */
    for (; p->next != NULL; p = p->next) {
        printf("%d -> ", p->value);
    }

    /* Print the last node. */
    printf("%d", p->value);
}

/* Return true if the linked list pointed to by head contains the
   specified value; otherwise return false.
 */
_Bool contains(IntNode *head, int value)
{
    IntNode *p;

    for (p = head; p != NULL; p = p->next) {
        if (value == p->value) {
            return true;
        }
    }
    return false;
}

/* A version of contains that eliminates local variable p.
 */
_Bool contains_shorter(IntNode *head, int value)
{
    for ( ; head != NULL; head = head->next) {
        if (value == head->value) {
            return true;
        }
    }
    return false;
}

/* Insert a node containing the specified integer value at the front
   of the linked list pointed to by head, and return a pointer to the
   first node in the modified list.
 */
IntNode *insert_front(IntNode *head, int value)
{
    return intnode_construct(value, head);
}

/* Append a node containing the specified integer value at the rear
   of the linked list pointed to by head, and return a pointer to the
   first node in the modified list.
 */
IntNode *append_rear(IntNode *head, int value)
{
    if (head == NULL) {
        /* Appending a node to the end of an empty linked list
         * is the same as inserting a node at the front of an
         * empty linked list.
         */
        head = intnode_construct(value, head /* NULL */);
    } else {
        IntNode *p;

        // Traverse the linked list until p points to the last node.

        for (p = head; p->next != NULL; p = p->next)
        {}

        p->next = intnode_construct(value, p->next /* NULL */);
    }
    return head;
}

/* Remove the node at the front of the linked list pointed to by head,
   and return a pointer to the first node in the modified list.
   Terminate (via assert) if asked to remove a node from an empty
   linked list.
 */
IntNode *remove_first(IntNode *head)
{
    assert(head != NULL);

    /* We need to retrieve the pointer to the second node (or NULL, if the
       list contains one node) BEFORE we free the first node.
       Remember, the result of accessing a node after it has been
       freed in undefined.
     */
    IntNode *p = head;
    head = head->next;
    free(p);
    return head;
}

/* Remove the node at the rear of the linked list pointed to by head,
   and return a pointer to the first node in the modified list.
   Terminate (via assert) if asked to remove a node from an empty
   linked list.
 */
IntNode *remove_last(IntNode *head)
{
    assert(head != NULL);

    if (head->next == NULL) {
        /* There is exactly one node in the linked list. */
        free(head);
        head = NULL;
    } else {
        IntNode *p1, *p2 = NULL;
        for (p1 = head; p1->next != NULL; p1 = p1->next) {
            p2 = p1;
        }

        /* Now p1 points to the last node and p2 points to the node before
         * the last node.
         */
        free(p1);
        p2->next = NULL;
    }
    return head;
}

/* Parameter head points to the first node in a linked list, or is
 * null if the list is empty.
 * Count the number of nodes in the linked list that contain an integer
 * equal to target, and return that count.
 * Return 0 if the linked list is empty.
 */
int count(IntNode *head, int target)
{
    int count = 0;
    if (head == NULL) {
        return 0;
    } else {
        for (IntNode *p = head; p != NULL; p=p->next) {
            if (p->value == target) {
                count++;
            }
        }
    }
    return count;
}

/* Parameter head points to the first node in a linked list, or is
 * null if the list is empty.
 * Return the index (position) of the first node that contains an
 * integer equal to target. The first node is at index 0, the second node
 * is at index 1, etc.
 * Return -1 if target is not in the linked list, or if the linked list
 * is empty.
 */
int index(IntNode *head, int target)
{
    int i = 0;
    if (head == NULL) {
        return -1;
    } else {
        for (IntNode *p = head; p != NULL; p=p->next) {
            if (p->value == target) {
                return i;
            }
            i++;
        }
    }
    return -1;
}

/* Parameter head points to the first node in a linked list, or is
 * null if the list is empty.
 * Return the integer stored in the node at the specified index.
 * The first node is at index 0, the second node is at index 1, etc.
 * The function terminates (via assert) if the linked list is empty or
 * if parameter index is invalid (negative or greater than the number
 * of nodes in the linked list).
 */
int fetch(IntNode *head, int index)
{
    int i = 0;
    assert(head != NULL);
    assert(index >= 0);
    for (IntNode *p = head; p != NULL; p=p->next) {
        if (i == index) {
            return p->value;
        }
        i++;
    }
    return -1;
}

/* This is a modified version of the remove_last function (see above)
 */
IntNode *remove_last_one_pointer(IntNode *head)
{
    assert(head != NULL);

    if (head->next == NULL) {
        /* There is exactly one node in the linked list. */
        free(head);
        head = NULL;
    } else {
        IntNode *p = NULL;
        for (p = head; p->next->next != NULL; p = p->next) {}

        /* Now p1 points to the last node and p2 points to the node before
         * the last node.
         */
        free(p->next);
        p->next = NULL;
    }
    return head;
}

/* Insert a node at specified index, with value x, from ll of head.
 */
IntNode *insert(IntNode *head, int index, int x)
{
    if (head == NULL && index == 0) { // list doesnt exist
        return intnode_construct(x, NULL);
    } else if (index == 0) { // insert at head
        head = intnode_construct(x, head);
    } else if (index > 0) { // insert past beginning of list
        int i = 0;
        for (IntNode *p = head; p != NULL; p=p->next) {
            i += 1;
            if (i == index) { // insert location found
                if (p->next != NULL) {
                    p->next = intnode_construct(x, p->next);
                } else {
                    p->next = intnode_construct(x, NULL);
                }
            }
        }
    }
    return head;
}

/* Delete a node at specified index from ll of head.
 */
IntNode *delete(IntNode *head, int index)
{
    assert (head != NULL); // list not empty
    if (head->next == NULL && index == 0) { // one item in list
        free(head);
        return NULL;
    } else if (index == 0) { // delete head
        IntNode *p = head;
        head = head->next;
        free(p);
    } else { // delete after beginning of list
        int i = 0;
        for (IntNode *p = head; p != NULL; p=p->next) {
            i += 1;
            if (i == index) { // delete location found
                if (p->next->next != NULL) { // second last
                    IntNode *temp = p->next;
                    p->next = temp->next;
                    free(temp);
                } else {
                    IntNode *temp = p->next;
                    p->next = NULL;
                    free(temp);
                }
            }
        }
    }
    return head;
}

/* Delete node with value target, from list head,
   if there is a removal then set removed to true.
 */
IntNode *delete_target(IntNode *head, int target, _Bool *removed)
{
    int _index = index(head, target); // first occurance of target
    if (_index == -1) { // not found
        *removed = false;
        return head;
    }
    *removed = true;
    return delete(head, _index);
}
