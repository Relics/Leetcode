class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* children[26];
    bool isWord = false;
    TrieNode() {
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* current = root;
        for (int i=0; i<(int)word.size(); ++i) {
            int index = word[i] - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return mySearch(word, false);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return mySearch(prefix, true);
    }

private:
    TrieNode* root;
    bool mySearch(string word, bool isPrefix) {
        TrieNode* current = root;
        for (int i=0; i<(int)word.size(); ++i) {
            int index = word[i] - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return isPrefix || current->isWord;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");