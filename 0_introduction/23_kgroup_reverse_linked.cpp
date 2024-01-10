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

Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *next = NULL;
    Node *B = head;
    Node *A = NULL;
    int flag = 0;

    while (B != NULL && flag < k)
    {
        next = B->next;
        B->next = A;
        A = B;
        B = next;
        flag = flag + 1;
    }

    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }
    return A;
}