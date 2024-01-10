#include <bits/stdc++.h>
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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

    Trie() { root = new TrieNode('\0'); }

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

    void insert(string word) { insertT(root, word); }

    bool searchT(TrieNode *root, string val)
    {
        if (val.length() == 0)
        {
            return root->isTerminal;
        }

        int ind = val[0] - 'a';
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

    bool search(string word) { return searchT(root, word); }

    bool PsearchT(TrieNode *root, string val)
    {
        if (val.length() == 0)
        {
            return true;
        }

        int ind = val[0] - 'a';
        TrieNode *child;

        if (root->children[ind] != NULL)
        {
            child = root->children[ind];
        }
        else
        {
            return false;
        }

        return PsearchT(child, val.substr(1));
    }

    bool startsWith(string prefix) { return PsearchT(root, prefix); }
};