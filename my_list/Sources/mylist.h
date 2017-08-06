#ifndef MYLIST_H_
#define MYLIST_H_

//#define LIST_EXTRA

extern int list_errno;

/*
 * definition of error codes
 * */
#define LIST_NO_ERROR 0
#define LIST_MEMORY_ERROR 1 // error due to mem alloc failure
#define LIST_EMPTY_ERROR 2  //error due to an operation that can't be executed on an empty list
#define LIST_INVALID_ERROR 3 //error due to a list operation applied on a NULL list 
#define ELEMENT_INVALID_ERROR 4 //error due to a NULL element

typedef void *list_elm_pt;
typedef struct list_node list_node_t;
typedef list_node_t *list_node_pt;

//*define CALLBACK function (function pointer)
typedef void element_copy_func(list_elm_pt *, list_elm_pt);
typedef void element_free_func(list_elm_pt *);
typedef int element_compare_func(list_elm_pt, list_elm_pt);
typedef void element_print_func(list_elm_pt);

typedef struct list list_t; // list_t is a struct containing at least a head pointer to the start of the list; 
typedef list_t *list_pt;

/*
 **  Creates (memory allocation!) and initializes the list and prepares it for usage
 **  Return a pointer to the newly created list
 **  Returns NULL if list creation failed and list_errno is set to LIST_MEMORY_ERROR
 */
list_pt mylist_create(element_copy_func *element_copy, element_free_func *element_free, element_compare_func *element_compare, element_print_func *element_print);

/*
 **  Every list node and node element of the list needs to be deleted (free memory)
 **  The list itself also needs to be deleted (free all memory) and set to NULL
 */
void mylist_free( list_pt* list );

/*
 **  Returns the number of elements in 'list'.
 **  Returns -1 if error
 */
int mylist_size( list_pt list );

/*
** Inserts a new list node containing 'element' in 'list' at position 'index'  and returns a pointer to the new list.
** Remark: the first list node has index 0.
** If 'index' is 0 or negative, the list node is inserted at the start of 'list'.
** If 'index' is bigger than the number of elements in 'list', the list node is inserted at the end of 'list'.
** Returns NULL if memory allocation failed and list_errno is set to LIST_MEMORY_ERROR
 */
list_pt mylist_insert_at_index( list_pt list, list_elm_pt element, int index);

/*
 ** Removes the list node at index 'index' from 'list'. NO free() is called on the element pointer of the list node.
 ** If 'index' is 0 or negative, the first list node is removed.
 ** If 'index' is bigger than the number of elements in 'list', the last list node is removed.
 ** If the list is empty, return list and list_errno is set to LIST_EMPTY_ERROR (to see the difference with removing the last element from a list)
 */
list_pt mylist_remove_at_index( list_pt list, int index);

/*
** Deletes the list node at index 'index' in 'list'.
** A free() is called on the element pointer of the list node to free any dynamic memory allocated to the element pointer.
** If 'index' is 0 or negative, the first list node is deleted.
** If 'index' is bigger than the number of elements in 'list', the last list node is deleted.
** If the list is empty, return list and list_errno is set to LIST_EMPTY_ERROR (to see the difference with freeing the last element from a list)
 */
list_pt mylist_free_at_index( list_pt list, int index);

/*
** Returns a reference to the list node with index 'index' in 'list'.
** If 'index' is 0 or negative, a reference to the first list node is returned.
** If 'index' is bigger than the number of list nodes in 'list', a reference to the last list node is returned.
** If the list is empty, NULL is returned.
*/
list_node_pt mylist_get_reference_at_index( list_pt list, int index );

/*
** Returns the list element contained in the list node with index 'index' in 'list'.
** If 'index' is 0 or negative, the element of the first list node is returned.
** If 'index' is bigger than the number of elements in 'list', the element of the last list node is returned.
** If the list is empty, NULL is returned.
*/
list_elm_pt mylist_get_element_at_index( list_pt list, int index );

/*
** Returns an index to the first list node in 'list' containing 'element'.
** If 'element' is not found in 'list', -1 is returned.
*/
int mylist_get_index_of_element( list_pt list, list_elm_pt element );

/*
** for testing purposes: print the entire list on screen
*/
void mylist_print( list_pt list );


#ifdef LIST_EXTRA
  list_pt list_insert_at_reference( list_pt list, list_elm_pt element, list_node_pt reference );
  // Inserts a new list node containing 'element' in the 'list' at position 'reference'  and returns a pointer to the new list. 
  // If 'reference' is NULL, the element is inserted at the end of 'list'.

  list_pt list_insert_sorted( list_pt list, list_elm_pt element );
  // Inserts a new list node containing 'element' in the sorted 'list' and returns a pointer to the new list. 
  // The 'list' must be sorted before calling this function. 
  // The sorting is done in ascending order according to a comparison function.  
  // If two members compare as equal, their order in the sorted array is undefined.

  list_pt list_remove_at_reference( list_pt list, list_node_pt reference );
  // Removes the list node with reference 'reference' in 'list'. 
  // NO free() is called on the element pointer of the list node. 
  // If 'reference' is NULL, the last list node is removed.
  // If the list is empty, return list and list_errno is set to LIST_EMPTY_ERROR

  list_pt list_free_at_reference( list_pt list, list_node_pt reference );
  // Deletes the list node with position 'reference' in 'list'. 
  // A free() is called on the element pointer of the list node to free any dynamic memory allocated to the element pointer. 
  // If 'reference' is NULL, the last list node is deleted.
  // If the list is empty, return list and list_errno is set to LIST_EMPTY_ERROR

  list_pt list_remove_element( list_pt list, list_elm_pt element );
  // Finds the first list node in 'list' that contains 'element' and removes the list node from 'list'. 
  // NO free() is called on the element pointer of the list node.
  // If the list is empty, return list and list_errno is set to LIST_EMPTY_ERROR
  
  list_node_pt list_get_first_reference( list_pt list );
  // Returns a reference to the first list node of 'list'. 
  // If the list is empty, NULL is returned.

  list_node_pt list_get_last_reference( list_pt list );
  // Returns a reference to the last list node of 'list'. 
  // If the list is empty, NULL is returned.

  list_node_pt list_get_next_reference( list_pt list, list_node_pt reference );
  // Returns a reference to the next list node of the list node with reference 'reference' in 'list'. 
  // If the next element doesn't exists, NULL is returned.

  list_node_pt list_get_previous_reference( list_pt list, list_node_pt reference );
  // Returns a reference to the previous list node of the list node with reference 'reference' in 'list'. 
  // If the previous element doesn't exists, NULL is returned.

  list_elm_pt list_get_element_at_reference( list_pt list, list_node_pt reference );
  // Returns the element pointer contained in the list node with reference 'reference' in 'list'. 
  // If 'reference' is NULL, the element of the last element is returned.

  list_node_pt list_get_reference_of_element( list_pt list, list_elm_pt element );
  // Returns a reference to the first list node in 'list' containing 'element'. 
  // If 'element' is not found in 'list', NULL is returned.

  int list_get_index_of_reference( list_pt list, list_node_pt reference );
  // Returns the index of the list node in the 'list' with reference 'reference'. 
  // If 'reference' is NULL, the index of the last element is returned.

  list_pt list_free_element( list_pt list, list_elm_pt element );
  // Finds the first list node in 'list' that contains 'element' and deletes the list node from 'list'. 
  // A free() is called on the element pointer of the list node to free any dynamic memory allocated to the element pointer.  
#endif

#endif  //MYLIST_H_

