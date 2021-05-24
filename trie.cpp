#include <bits/stdc++.h>
#define hashmap unordered_map<char, node *>
using namespace std;
class node
{
public:
    char data;
    hashmap h;
    bool isTerminal;
    node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node('\0');
    }
    void addWord(string word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 0)
            {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else
            {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }
    bool search(string word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch))
            {
                temp = temp->h[ch];
            }
            else
            {
                return false;
            }
            cout << temp->data << " ";
        }
        return temp->isTerminal;
    }
};
int main()
{
    char word[10][100] = {"apple", "ape", "coder", "coding", "no"};
    Trie t;
    for (int i = 0; i < 5; i++)
    {
        t.addWord(word[i]);
    }
    char searchWord[100];
    cin.getline(searchWord, 100);
    if (t.search(searchWord))
    {
        cout << searchWord << " found\n";
    }
    else
    {
        cout << "not found\n";
    }
    return 0;
}