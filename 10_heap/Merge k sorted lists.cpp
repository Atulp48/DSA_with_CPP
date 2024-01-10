#include<bits/stdc++.h>


/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

class check {
public:
  bool operator()(Node<int> *x, Node<int> *y) { return x->data > y->data; }
};

Node<int> *
mergeKLists(vector<Node<int> *> &listArray) {
  priority_queue<Node<int>*,vector<Node<int>*>,check>flag;

  for(int i=0;i<listArray.size();i++){
      if(listArray[i]!=NULL){
          flag.push(listArray[i]); 
      }
  }

  Node<int>*head=NULL;
  Node<int>*tail=NULL;

  while(flag.size()>0){
      Node<int>*temp=flag.top();
      flag.pop();

      if(temp->next!=NULL){
          flag.push(temp->next);
      }

      if(head==NULL){
          head=temp;
          tail=temp;
      }
      else{
          tail->next=temp;
          tail=temp;
      }
  }

  return head;

}
