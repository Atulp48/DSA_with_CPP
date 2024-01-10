#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *solve(Node<int> *first, Node<int> *second)
{

    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node<int> *d1 = first;
    Node<int> *nx1 = d1->next;

    Node<int> *d2 = second;
    Node<int> *nx2 = d2->next;

    while (nx1 != NULL && d2 != NULL)
    {

        if ((d2->data >= d1->data) && (d2->data <= nx1->data))
        {

            d1->next = d2;
            nx2 = d2->next;
            d2->next = nx1;
            d1 = d2;
            d2 = nx2;
        }
        else
        {
            d1 = nx1;
            nx1 = nx1->next;
            if (nx1 == NULL)
            {
                d1->next = d2;
                return first;
            }
        }
    }
    return first;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
