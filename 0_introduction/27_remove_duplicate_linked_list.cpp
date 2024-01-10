#include<iostream>
using namespace std;

 class Node
    {
        public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node *uniqueSortedList(Node *head) {
  if (head == NULL) {
    return NULL;
  }
  Node *d = head;

  while (d != NULL) {
    if (d->next != NULL&& d->data == d->next->data) {
      Node * d1=d->next->next;
      Node * d2=d->next;
      delete(d2);
      d->next=d1;
    } 
    else {


      d = d->next;
    }
  }
  return  head;
}