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

/* IntNode Definition */

/* A node in a singly-linked list that stores values of type int. */
struct intnode {
    int value;
    struct intnode *next;
};

typedef struct intnode IntNode;

/* IntNode function prototypes */
IntNode *intnode_construct(int value, IntNode *next);

void print_linked_list(IntNode *p);
_Bool contains(IntNode *head, int value);
_Bool contains_shorter(IntNode *head, int value);
IntNode *insert_front(IntNode *head, int value);
IntNode *append_rear(IntNode *head, int value);
IntNode *remove_first(IntNode *head);
IntNode *remove_last(IntNode *head);

int count(IntNode *head, int target);
int index(IntNode *head, int target);
int fetch(IntNode *head, int index);
int traverse_count(IntNode *head);
IntNode *remove_last_one_pointer(IntNode *head);
IntNode *insert(IntNode *head, int index, int x);
IntNode *delete(IntNode *head, int index);
IntNode *delete_target(IntNode *head, int target, _Bool *removed);

