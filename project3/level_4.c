/*
 * author: Christian Miljkovic
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"


// Implement a C function called level_4_opt. It should perform the same 
// task as the implemented level_4 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//


// Note: Data structures like linked lists are not very
// cache friendly (their nodes can be scattered all over
// the heap). The following method compacts the nodes of a linked 
// list into adjacent memory locations in an array and it also
// preserves the traditional linked list connections. 
// Your own code needs to accomplish the same. 
 

void level_4(node** head, int length)
{
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.
    node* new_list = malloc(sizeof(node) * length);

    // go through the list and make a copy of all the 
    // nodes and place them into the contiguous block in order
    node* n = *head;
    int i;
    for(i = 0 ; i < length ; ++i) {
        node copy = { n->value, NULL };
        new_list[i] = copy;
        n = n->next;
    }

    // go through the list again and "link" each node in 
    // the contiguous block to the next node in memory; 
    // free all the nodes in the old list
    n = *head;
    for(i = 0 ; i < length - 1 ; ++i) {
        // link each node in the new list
        new_list[i].next = &new_list[i+1];
        // free the old nodes
        node* free_me = n;
        n = n->next;
        free(free_me);
    }

    // free the last node of the old list
    free(n);

    // point head at the new packed list
    *head = new_list;
}


/*
This function is an optimized version of the above function level_4 because
it minimizes the number of cache misses by condensing the two for loops located
in the above function, and then performing the neccesary operations within the single
for loop. This method takes advantage of temporal locality in order to minimize cache misses.
*/
void level_4_opt(node** head, int length)
{
    
    // malloc a contiguous block of memory on the heap
    // that is big enough for the entire list.
    node* new_list = malloc(sizeof(node) * length);

    //get the reference to the head of the list we are going to copy
    node * n = *head;

    int i;
    int length_minus = length -1; //we do this so we don't calculate this over and over again in the loop

    //compress the two for loops into one so that we can work
    //with the data that is already in the cache thus increasing
    //our temporal locality
    for(i=0; i < length; ++i) {

        node copy = {n->value, NULL}; //create the copied node

        //since we are going to copy and link this node in one loop we need to
        //save the reference to it so that we can do this for the other
        //nodes in the linked list. This improves or temporal locality
        node * saved_n = n;

        //now add the copy to the list
        new_list[i] = copy;

        //now we will link the nodes even though we don't have the next node created
        //we know what address it will be placed in which means we can
        //point the current node to the correct address
        if(i < length_minus) { //this is to prevent any access past the memory location we allocated

            // link each node in the new list
            new_list[i].next = &new_list[i+1];

        }

        //move onto the next node and repeat the process
        n = n -> next; 

        //now we have to free the pointer that we created before
        free(saved_n);


    }
    // free the last node of the old list
    free(n);

    // point head at the new packed list
    *head = new_list;

}


/* DO NOT MODIFY THE FUNCTION THAT FOLLOWS */


void addFront(data * s,  node ** head) {
    if (head == 0 ) return;
    if (s == 0 ) return; 
    
    //allocate memory for storing the node 
    node *n = ( node *)malloc(sizeof( node));
    //make sure that the memory was allocated,
    //if not, just quit
    if (n == NULL) return;
    n->value = *s;
    
    n->next = (*head);
    (*head) = n;
}


