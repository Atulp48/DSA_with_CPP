#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void inshead(Node *&head, Node *&tail, int data)
{ 
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp; 
    }

    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void instail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }

    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void inspos(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        return inshead(head,tail, data);
    }

    Node *temp = head;
    int count = 1;

    while (count < (pos - 1))
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        return instail(head,tail, data);
    }
    Node *nodinsert = new Node(data);
    nodinsert->next = temp->next;
    temp->next->prev = nodinsert;
    temp->next = nodinsert;
    nodinsert->prev = temp;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    
    print(head);

    inshead(head,tail, 13);
    print(head);

    inshead(head,tail, 14);
    print(head);

    inshead(head,tail, 15);
    print(head);

    instail(head,tail, 16);
    print(head);

    inspos(head, tail, 3, 100);
    print(head);

    inspos(head, tail, 5, 120);
    print(head);

    inspos(head, tail, 7, 125);
    print(head);

    return 0;
}