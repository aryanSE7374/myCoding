#include <bits/stdc++.h>
using namespace std;

/*
    Combined Trie Implementation
    --------------------------------
    Features:
    1. insert(word)
    2. search(word)
    3. startsWith(prefix)
    4. countWordsEqualTo(word)
    5. countWordsStartingWith(prefix)
    6. erase(word)

    Extra:
    - Node constructor takes alphabet size
    - Trie constructor takes:
        alphabet size
        starting character

    Examples:
    Trie trie(26, 'a');   // lowercase
    Trie trie(26, 'A');   // uppercase
    Trie trie(10, '0');   // digits
*/

class Node {
public:
    vector<Node*> links;

    int cntEndWith;
    int cntPrefix;

    Node(int alphabetSize) {
        links.resize(alphabetSize, nullptr);

        cntEndWith = 0;
        cntPrefix = 0;
    }

    bool containsKey(char ch, char baseChar) {
        return links[ch - baseChar] != nullptr;
    }

    Node* get(char ch, char baseChar) {
        return links[ch - baseChar];
    }

    void put(char ch, Node* node, char baseChar) {
        links[ch - baseChar] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void decreaseEnd() {
        cntEndWith--;
    }

    void decreasePrefix() {
        cntPrefix--;
    }

    ~Node() {
        for (auto child : links) {
            delete child;
        }
    }
};

class Trie {
private:
    Node* root;

    int alphabetSize;
    char baseChar;

public:
    /*
        alphabetSize:
            26 for lowercase/uppercase
            10 for digits

        baseChar:
            'a' for lowercase
            'A' for uppercase
            '0' for digits
    */
    Trie(int alphabetSize = 26, char baseChar = 'a') {
        this->alphabetSize = alphabetSize;
        this->baseChar = baseChar;

        root = new Node(alphabetSize);
    }

    ~Trie() {
        delete root;
    }

    // Insert a word
    // Time: O(n)
    // Space: O(n) (new nodes only)
    void insert(const string& word) {
        Node* node = root;

        for (char ch : word) {

            if (!node->containsKey(ch, baseChar)) {
                node->put(
                    ch,
                    new Node(alphabetSize),
                    baseChar
                );
            }

            node = node->get(ch, baseChar);

            node->increasePrefix();
        }

        node->increaseEnd();
    }

    // Search exact word
    // Time: O(n)
    // Space: O(1)
    bool search(const string& word) {
        Node* node = root;

        for (char ch : word) {

            if (!node->containsKey(ch, baseChar)) {
                return false;
            }

            node = node->get(ch, baseChar);
        }

        return node->cntEndWith > 0;
    }

    // Check prefix exists
    // Time: O(n)
    // Space: O(1)
    bool startsWith(const string& prefix) {
        Node* node = root;

        for (char ch : prefix) {

            if (!node->containsKey(ch, baseChar)) {
                return false;
            }

            node = node->get(ch, baseChar);
        }

        return true;
    }

    // Count exact words
    // Time: O(n)
    // Space: O(1)
    int countWordsEqualTo(const string& word) {
        Node* node = root;

        for (char ch : word) {

            if (!node->containsKey(ch, baseChar)) {
                return 0;
            }

            node = node->get(ch, baseChar);
        }

        return node->cntEndWith;
    }

    // Count words with given prefix
    // Time: O(n)
    // Space: O(1)
    int countWordsStartingWith(const string& prefix) {
        Node* node = root;

        for (char ch : prefix) {

            if (!node->containsKey(ch, baseChar)) {
                return 0;
            }

            node = node->get(ch, baseChar);
        }

        return node->cntPrefix;
    }

    // Erase one occurrence of word
    // Time: O(n)
    // Space: O(1)
    void erase(const string& word) {

        // word doesn't exist
        if (!search(word)) {
            return;
        }

        Node* node = root;

        for (char ch : word) {

            node = node->get(ch, baseChar);

            node->decreasePrefix();
        }

        node->decreaseEnd();
    }
};

int main() {

    // Lowercase Trie
    Trie trie(26, 'a');

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apps");

    cout << boolalpha;

    cout << "search(apple): "
         << trie.search("apple") << endl;

    cout << "search(appl): "
         << trie.search("appl") << endl;

    cout << "startsWith(app): "
         << trie.startsWith("app") << endl;

    cout << "countWordsEqualTo(apple): "
         << trie.countWordsEqualTo("apple") << endl;

    cout << "countWordsStartingWith(app): "
         << trie.countWordsStartingWith("app") << endl;

    trie.erase("apple");

    cout << "\nAfter erasing one 'apple'\n";

    cout << "countWordsEqualTo(apple): "
         << trie.countWordsEqualTo("apple") << endl;

    cout << "countWordsStartingWith(app): "
         << trie.countWordsStartingWith("app") << endl;

    return 0;
}