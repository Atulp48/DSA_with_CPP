#include <iostream>
#include <map>
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

bool floyd_deetect_1(Node *head)
{

    if (head == NULL)
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

Node *floyd_deetect(Node *head)
{
 
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "loop present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *startnode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *flag = floyd_deetect(head);
    Node *slow = head;
    while (slow != flag)
    {
        slow = slow->next;
        flag = flag->next;
    }
    return slow;
}

void removeloop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *d = startnode(head);
    Node *flag = d;
    while (flag->next != d)
    {
        flag = flag->next;
    }
    flag->next = NULL;
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    insert_tail(tail, 12);

    insert_tail(tail, 13);

    insert_position(tail, head, 3, 16);

    // we point the last node  to first node for create the loop in the following line of the code//

    tail->next = head->next;

    if (floyd_deetect(head) != NULL)
    {
        cout << "loop is present" << endl;
    }
    else
    {
        cout << "nahi" << endl;
    }

    if (floyd_deetect(head) != NULL)
    {
        cout << "loop is present" << endl;
    }
    else
    {
        cout << "nahi" << endl;
    }
    Node *d = startnode(head);
    cout << "starting node of loop  is " << d->data << endl;

    removeloop(head);
    print(head);

    // for chaking the loop is removed or not //

    if (floyd_deetect(head) != NULL)
    {
        cout << "loop is present" << endl;
    }
    else
    {
        cout << "nahi" << endl;
    }

    return 0;
}