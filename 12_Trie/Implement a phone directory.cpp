#include<bits/stdc++.h>

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

        int ind = val[0] - 'a';
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

    void printS(TrieNode *curr, vector<string> &temp, string pref)
    {
        if (curr->isTerminal)
        {
            temp.push_back(pref);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                pref.push_back(ch);
                printS(next, temp, pref);
                pref.pop_back();
            }
        }
    }

    vector<vector<string>> getS(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> store;
        string pref = "";
        for (int i = 0; i < str.length(); i++)
        {
            char lstchar = str[i];
            pref.push_back(lstchar);

            TrieNode *curr = prev->children[lstchar - 'a'];

            if (curr == NULL)
            {
                break;
            }
            vector<string> temp;
            printS(curr, temp, pref);

            store.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return store;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *T = new Trie();
    //    Write your code here.
    for (int i = 0; i < contactList.size(); i++)
    {
        string ch = contactList[i];
        T->insetval(ch);
    }

    return T->getS(queryStr);
}