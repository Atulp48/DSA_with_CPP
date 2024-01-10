#include<iostream>
using namespace std;

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

node *M(node *head) {
  node *n1 = head;
  node *n2 = head->next;
  while (n2 != NULL && n2->next != NULL) {
    n1 = n1->next;
    n2 = n2->next->next;
  }
  return n1;
}

node * final(node * l ,node * r){
     node * flag=new node(-1);
     node *flag1=flag;
     if(l==NULL){
         return  r;
     }
     if(r==NULL){
         return l;
     }
      while(l!=NULL && r!=NULL){
          if(l->data<r->data){
              flag1->next=l;
              flag1=l;
              l=l->next;
          }
          else{
              flag1->next=r;
              flag1=r;
              r=r->next;
          }
      }
      while(l!=NULL){
          flag1->next=l;
              flag1=l;
              l=l->next;
          }
          
      while(r!=NULL){
          flag1->next=r;
              flag1=r;
              r=r->next;
          }
          flag=flag->next;
return flag;
}


node *mergeSort(node *head) {
 
  if (head == NULL) {
    return head;
  }

  if (head->next == NULL) {
    return head;
  }

  node *m = M(head);
  node *l = head;
  node *r = m->next;
  m->next = NULL;

  l = mergeSort(l);
  r = mergeSort(r);

  node *f = final(l, r);
  return f;
}
