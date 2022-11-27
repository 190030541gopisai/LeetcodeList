struct Node
{
    Node *links[26];
    bool flag;
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = nullptr;
        }
        flag = false;
    }
    int charToInt(char ch)
    {
        return (ch - 'a');
    }
    bool containsKey(char ch)
    {
        return links[charToInt(ch)] != nullptr;
    }

    Node* getNextNode(char ch)
    {
        return links[charToInt(ch)];
    }

    void insertNode(char ch)
    {
        links[charToInt(ch)] = new Node();
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
    Node * root;
    public:
        Trie()
        {
            root = new Node();
        }

    void insert(string word)
    {
        int n = word.size();
        Node *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (temp->containsKey(word[i]) == false)
            {
                temp->insertNode(word[i]);
            }
            temp = temp->getNextNode(word[i]);
        }
        temp->setEnd();
    }

    bool search(string word)
    {
        int n = word.size();
        Node *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (temp->containsKey(word[i]) == false)
            {
                return false;
            }
            temp = temp->getNextNode(word[i]);
        }
        return temp->isEnd();
    }

    bool startsWith(string prefix)
    {
        int n = prefix.size();
        Node *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (temp->containsKey(prefix[i]) == false)
            {
                return false;
            }
            temp = temp->getNextNode(prefix[i]);
        }
        return true;
    }
};

/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */