#include <iostream>
using namespace std;

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

void insert(Node *&head, int d)
{

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insert_tail(Node *&tail, int d)
{

    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_position(Node *&tail, Node *&head, int pos, int d)
{

    Node *temp = head;
    int count = 1;

    if (pos == 1)
    {

        return insert(head, d);
    }

    while (count < (pos - 1))
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        return insert_tail(tail, d);
    }
    Node *nodinsert = new Node(d);
    nodinsert->next = temp->next;
    temp->next = nodinsert;
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;
    print(head);

    insert_tail(tail, 12);
    print(head);

    insert_tail(tail, 13);
    print(head);

    insert_position(tail, head, 3, 16);
    print(head);

    insert_position(tail, head, 5, 17);
    print(head);

    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    return 0;
}