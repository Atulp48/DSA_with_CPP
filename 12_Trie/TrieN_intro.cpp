#include <iostream>
using namespace std;

class TrieNode
{

public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; 
        }
        isTerminal = false;
    }
};

class Trie
{
 
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertT(TrieNode *root, string val)
    {
        if (val.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int ind = val[0] - 'A';
        TrieNode *child;

        if (root->children[ind] != NULL)
        {
            child = root->children[ind];
        }
        else
        {
            child = new TrieNode(val[0]);
            root->children[ind] = child;
        }

        insertT(child, val.substr(1));
    }

    void insetval(string val)
    {
        insertT(root, val);
    }

    bool searchT(TrieNode *root, string val)
    {
        if (val.length() == 0)
        {
            return root->isTerminal;
        }

        int ind = val[0] - 'A';
        TrieNode *child;

        if (root->children[ind] != NULL)
        {
            child = root->children[ind];
        }
        else
        {
            return false;
        }

        return searchT(child, val.substr(1));
    }

    bool searchV(string val)
    {
        return searchT(root, val);
    }
};

int main()
{

    Trie *T = new Trie();
    T->insetval("ABCD");
    T->insetval("ABCM");
    T->insetval("ABCN");
    T->insetval("ABCR");

    cout << "the stirng is present or Not " << T->searchV("ABCD") << endl;
    cout << "the stirng is present or Not " << T->searchV("ABCM") << endl;
    cout << "the stirng is present or Not " << T->searchV("ABCN") << endl;

    return 0;
}
