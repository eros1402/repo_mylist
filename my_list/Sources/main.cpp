//============================================================================
// Name        : main.cpp
// Author      : Pham Hoang Chi
// Version     :
// Copyright   : Copyright from Pham Hoang Chi
// Description : Test mylist.cpp
//============================================================================

#include <iostream>
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "mylist.h"
using namespace std;

void element_print(list_elm_pt element);
void element_copy(list_elm_pt *dest_element, list_elm_pt src_element);
void element_free(list_elm_pt *element);
int element_compare(list_elm_pt x, list_elm_pt y);

int list_errno;

int main( void )
{
  list_pt list = NULL;
  printf("\n=========================================\n");

  int* a = (int *)malloc(sizeof(int));
  *a = 3;
  int* b = (int *)malloc(sizeof(int));
  *b = 6;
  int* c = (int *)malloc(sizeof(int));
  *c = 9;
  int* d = (int *)malloc(sizeof(int));
  *d = 1;
  int* e = (int *)malloc(sizeof(int));
  *e = 2;

//  list_insert_at_index(NULL,a,0);
//  printf("size: %d\n", list_size(list));
//
//  list = list_create( &element_copy, &element_free, &element_compare, &element_print);
//  printf("size: %d\n", list_size(list));
//  list_print(list);
//
//  printf("\n=========================================\n");
//  list_insert_at_index(list,a,0);
//
//  printf("\n=========================================\n");
//  list_insert_at_index(list,b,0);
//
//  printf("\n=========================================\n");
//  list_insert_at_index(list,c,0);
//
//  printf("\n=========================================\n");
//  list_insert_at_index(list,d,4);
//
//  printf("\n=========================================\n");
//  list_insert_at_index(list,e,2);
//  printf("size: %d\n", list_size(list));
//  list_print(list);
//
//  element_print(list_get_element_at_index(list, -3));
//  element_print(list_get_element_at_index(list, 0));
//  element_print(list_get_element_at_index(list, 1));
//  element_print(list_get_element_at_index(list, 2));
//  element_print(list_get_element_at_index(list, 3));
//  element_print(list_get_element_at_index(list, 4));
//  element_print(list_get_element_at_index(list, 5));
//
//  printf("\n=========================================\n");
//  list_remove_at_index(list,0);
//  printf("size: %d\n", list_size(list));
//  list_print(list);
//
//  printf("\n=========================================\n");
//  list_free_at_index(list,3);
//  printf("size: %d\n", list_size(list));
//  list_print(list);

  #ifdef LIST_EXTRA
  printf("\n=========================================\n");
  element_print(list_get_element_at_reference(list, list_get_first_reference(list))); //print first element
  element_print(list_get_element_at_reference(list, list_get_last_reference(list)));  //print last element

  printf("\n=========================================\n");
  list_node_ptr_t temp = list_get_next_reference(list, list_get_first_reference(list)); //get 2nd node
  printf("index = %d\n", list_get_index_of_reference(list, temp));
  element_print(list_get_element_at_reference(list, temp));							//print next element of 2nd node

  printf("\n=========================================\n");
  temp = list_get_next_reference(list, temp); //get 3rd node
  printf("index = %d\n", list_get_index_of_reference(list, temp));
  element_print(list_get_element_at_reference(list, temp)); //print next element of 3rd node
  //element_print(list_get_element_at_reference(list, list_get_previous_reference(list, temp))); //print 2nd node

  list_remove_at_reference(list, temp);
  list_print(list);
  #endif

//  list_free(&list);

  free(a);
  free(b);
  free(c);
  free(d);
  free(e);

  return 0;
}

/*
 * Copy the 'content' of src_element to dst_element.
 */
void element_copy(list_elm_pt *dest_element, list_elm_pt src_element)
{
  //...
  //*dest_element = src_element; // ok if element_t is int
}


/*
 * Clean up element, including freeing memory if needed
 */
void element_free(list_elm_pt *element)
{
  // ...
  // nothing to do if element_t is int
}

/*
 * Print 1 element to stdout.
 */
void element_print(list_elm_pt element)
{
	printf("%5d\n", *(int *)element); // ok if element_t is int
}

/*
 * Compare two element elements; returns -1, 0 or 1
 */
int element_compare(list_elm_pt x, list_elm_pt y)
{
  // ...
  if(*(int *)x == *(int *)y) { return 1; }
  else { return 0;}

}
