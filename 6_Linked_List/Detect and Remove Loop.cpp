/*************************************************

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

**************f***********************************/

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

            return slow;
        }
    }
    return NULL;
}

Node *start(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *flag = floyd_deetect(head);
    if (flag == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != flag)
    {
        slow = slow->next;
        flag = flag->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *d = start(head);
    if (d == NULL)
    {
        return head;
    }
    Node *flag = d;
    while (flag->next != d)
    {
        flag = flag->next;
    }
    flag->next = NULL;
    return head;
}