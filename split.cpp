/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

// base case - if list is empty
if ( in == nullptr){
  return;}
//saves next
  Node* nextnode = in->next;
// if value at in is odd
if (in -> value % 2 == 1){
  // set next to points to odds list basically 
  in->next = odds;
  // set to in
  odds = in;
}
else { in->next = evens;
  evens = in;}
  

  // returns next to continue traversing trhough in list
  in = nextnode;

split(in, odds, evens);}

/* If you needed a helper function, write it here */
