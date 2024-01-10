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

Node *floyd_deetect(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

bool isdetect(Node *head)
{

    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visit;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visit[temp] == true)
        {
            cout << "element present at " << temp->data << endl;
            return true;
        }
        visit[temp] = true;
        temp = temp->next;
    }
    return false;
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

    // tail->next = head->next;

    // if (isdetect(head))
    // {
    //     cout << "loop is present" << endl;
    // }
    // else
    // {
    //     cout << "nahi" << endl;
    // }

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