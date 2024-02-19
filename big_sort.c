/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:42:38 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/19 18:38:11 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack   *copy_stack_a(t_stack **a)
{
    t_stack *new;
    t_stack *head;
    t_stack *prev_node;
    // if (!a)
    //     return (NULL); already covered
    head = NULL;
    prev_node = NULL;
    while ((*a))
    {
        new = (t_stack*)malloc(sizeof(t_stack)); 
        if (!new)
            return (NULL);
        new->data = (*a)->data;
        new->index = (*a)->index;
        // new->next = (*a)->next; this is not true as new->next should follow the following node of new of a
        new->next = NULL;
        if (!head)
            head = new; // in order to return the first address of t_stack
        else // this way of course it should has the previou node! if head is empty then no previous node needed
            prev_node -> next = new; // first node -> next = the seconde node.
        prev_node = new; // when the first approach of this code will point to the first node
        (*a) = (*a)->next;
    }
    return (head);
}


t_stack *divide_merge_sort(t_stack **copy)
{
    long long i;
    t_stack *head;
    
    i = ft_lstsize((*copy));
    if (i <= 1)
        return (head);
    if (i / 2) 
    /*
    we have index elements in the struct, so i will use this
    by not using the index part, you can use 
    We initialize two pointers, let's call them slow and fast, both initially pointing to the head of the linked list.
    In each iteration of the loop, the slow pointer moves one step forward by setting slow = slow.next.
    At the same time, the fast pointer moves two steps forward by setting fast = fast.next.next.
    By doing this, when the fast pointer reaches the end of the list (i.e., fast.next is None), the slow pointer will be at the middle node of the list.

    def find_middle(head):
    slow = head
    fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    return slow
    */
   {
    
   }
        
        
}

t_stack * merge(t_stack **copy)
{

}

/*
def merge_sort(arr):
   # Base case: If the array has one or zero element, it's already sorted
  if len(arr) <= 1:
      return arr

  # Divide the array into two halves
  mid = len(arr) // 2
  left_half = arr[:mid]
  right_half = arr[mid:]

  # Recursively sort both halves
  left_half = merge_sort(left_half)
  right_half = merge_sort(right_half)

  # Merge the sorted halves
  return merge(left_half, right_half)
  
def merge(left, right):
  result = []
  left_index, right_index = 0, 0

  # Traverse both left and right arrays
  while left_index < len(left) and right_index < len(right):
      if left[left_index] < right[right_index]:
          result.append(left[left_index])
          left_index += 1
      else:
          result.append(right[right_index])
          right_index += 1

  # If left array still has elements, add them to result
  while left_index < len(left):
      result.append(left[left_index])
      left_index += 1

  # If right array still has elements, add them to result
  while right_index < len(right):
      result.append(right[right_index])
      right_index += 1

  return result
*/