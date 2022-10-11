#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  smaller = NULL;
  larger = NULL;
  Node* smallPoint = NULL;
  Node* largePoint =  NULL;
  split(head, smaller, larger, pivot, smallPoint, largePoint);
  return;
}

void split(Node *&head, Node *&smaller, Node *&larger, int pivot, Node *&smallPoint, Node *&largePoint){
  if (head == nullptr){
    return;
  }
  if (head->val > pivot){
    // means we are dealing with "larger"
    if (larger == nullptr || larger == NULL){
      larger = head;
      largePoint = head;
      // updating the next largepoint and head
      largePoint->next = NULL;
      head = head->next;
      // recursive call to split
      split(head, smaller, larger, pivot, smallPoint, largePoint);
    }
    else{
      largePoint = head;
      largePoint->next = head;
      // updating the next largepoint and head
      largePoint->next = NULL;
      head = head->next;
      // recursive call to split
      split(head, smaller, larger, pivot, smallPoint, largePoint);
    }
  }
  else if (head->val <= pivot){
    // means we are dealing with "smaller"
    if (smaller == nullptr || smaller == NULL){
      smaller = head;
      smallPoint = head;
      // updating the next smallpoint and head
      head = head->next;
      smallpoint->next = NULL;
      // recursive call to split
      split(head, smaller, larger, pivot, smallPoint, largePoint);
    }
    else{
      smallPoint = head; 
      smallPoint->next = head;
      // updating the next smallpoint and head
      head = head->next;
      smallpoint->next = NULL;
      // recursive call to split
      split(head, smaller, larger, pivot, smallPoint, largePoint);
    }
  }
}

