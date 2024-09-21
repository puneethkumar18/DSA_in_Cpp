#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;

        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('/');
    }

    void insertUtil(string word, TrieNode *root)
    {

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';

        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(word.substr(1), child);
    }

    void insert(string word)
    {
        insertUtil(word, root);
    }
    bool serchUtil(string word, TrieNode *root)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return serchUtil(word.substr(1), child);
    }
    bool serch(string word)
    {
        return serchUtil(word, root);
    }
};

int main()
{

    Trie t;
    t.insert("PUNEETH");

    t.insert("RAMESH");

    cout << t.serch("PUNEETH") << endl;
    cout << t.serch("RAMESH") << endl;

    return 0;
}