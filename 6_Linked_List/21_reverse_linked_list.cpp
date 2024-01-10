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

Node *reverseLinkedList(Node *head) {
  Node *data = NULL;
  Node *A = NULL;
  Node *B = head;

  if (head == NULL) {
    return head;
  }
  else if (head->next == NULL) {
    return head;
  }

  while(B!=NULL){
	  data=B->next;
	  B->next=A;
	  A=B;
	  B=data;
  }
  return A;
}
