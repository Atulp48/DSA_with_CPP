/********************************
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

********************************/

Node *sort(Node *head)
{
    // Write your code here.
    int N1 = 0;
    int N2 = 0;
    int N3 = 0;
    Node *flag = head;
    while (flag != NULL)
    {
        if (flag->data == 0)
        {
            N1++;
        }
        else if (flag->data == 1)
        {
            N2++;
        }
        else if (flag->data == 2)
        {
            N3++;
        }
        flag = flag->next;
    }

    flag = head;

    while (flag != NULL)
    {
        if (N1 != 0)
        {
            flag->data = 0;
            N1--;
        }
        else if (N2 != 0)
        {
            flag->data = 1;
            N2--;
        }
        else if (N3 != 0)
        {
            flag->data = 2;
            N3--;
        }
        flag = flag->next;
    }
    return head;
}
