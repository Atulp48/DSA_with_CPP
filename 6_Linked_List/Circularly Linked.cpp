#include <bits/stdc++.h>
using namespace std;
/*************************************************
        Following is the structure of class Node:

        class Node{
        public:
            int data;
            Node* next;

            Node(int data){
                this->data = data;
                this->next = NULL;
            }

        }
**************************************************/

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *d = head->next;

    while (d != NULL && d != head)
    {
        d = d->next;
    }

    if (head != d)
    {
        return false;
    }

    return true;
}
