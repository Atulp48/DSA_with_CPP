#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "free value is  " << value << endl;
    }
};

void insertNode(Node *&tail, int ele, int d)
{
    if (tail == NULL)
    {
        Node *nNode = new Node(d);
        tail = nNode;
        nNode->next = nNode;
    }

    else
    {
        Node *curr = tail;
        while (curr->data != ele)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteN(Node *&tail, int d)
{
    if (tail == NULL)
    {
        cout << "empty" << endl;
        return;
    }

    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != d)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (tail = curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 6);
    print(tail);

    insertNode(tail, 6, 9);
    print(tail);

    insertNode(tail, 6, 10);
    print(tail);

    insertNode(tail, 9, 13);
    print(tail);

    deleteN(tail, 9);
    print(tail);

    deleteN(tail, 13);
    print(tail);

    return 0;
}