#include <iostream>
       class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
               this->data = data;
              this->next = NULL;
            }
        };



int l(Node *head) {
  int x = 0;
  while (head != NULL) {
    x++;
    head = head->next;
  }
  return x;
}

Node *findMiddle(Node *head) {
  int y = l(head);
  int mid = y / 2;
  Node *node = head;
  int p = 0;
  while (p < mid) {
    p++;
    node = node->next;
  }
  return node;
}