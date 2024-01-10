#include <bits/stdc++.h>

string longestCommonPrefix(vector<string> &arr, int n)
{
    bool flag = true;
    string result = "";
    for (int i = 0; i < arr[0].length(); i++)
    {
        char val = arr[0][i];

        for (int j = 1; j < n; j++)
        {
            if (arr[j].size() < i || arr[j][i] != val)
            {
                flag = false;
                break;
            }
        }

        if (flag == false)
        {
            break;
        }
        else
        {
            result.push_back(val);
        }
    }
    return result;
}

//  THE ABOVE PROBLEM SOLVED BY USING TRIE  IN FOLLOWING METHOD BUT ONE TEST CASE NOT PASSED AFTER SUBMISSION  OF THE CODE

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCheck;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCheck = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch) { root = new TrieNode(ch); }

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
            root->childCheck++;
            root->children[ind] = child;
        }

        insertT(child, val.substr(1));
    }

    void insetval(string val) { insertT(root, val); }

    void longest(string str, string &result)
    {

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCheck == 1)
            {
                result.push_back(ch);
                int ind = ch - 'a';
                root = root->children[ind];
            }
            else
            {
                break;
            }
            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');
    for (int i = 0; i < n; i++)
    {
        t->insetval(arr[i]);
    }

    string primery = arr[0];
    string result = "";
    t->longest(primery, result);
    return result;
}
