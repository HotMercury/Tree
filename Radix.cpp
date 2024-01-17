/*
Radix Tree
store words in tree
name has some information
todo : polymorphism
*/
#include <iostream>

using namespace std;

class TrieNode {
    public:
        TrieNode();
        TrieNode *children[26];
        bool isEndOfWord;
        char letter;
};
TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        children[i] = NULL;
    }
    letter = '\0';
}

class Trie {
    public:
        Trie();
        void insert(string);
        bool search(string);
        bool startsWith(string);
        bool __startsWith(TrieNode*, string, string);
    private:
        TrieNode *root;
};
Trie::Trie(){
    root = new TrieNode();
}
void Trie::insert(string word){
    TrieNode *current = root;
    for(int i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        if(current->children[index] == NULL){
            current->children[index] = new TrieNode();
            current->children[index]->letter = word[i];
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool Trie::search(string word){
    TrieNode *current = root;
    for(int i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        if(current->children[index] == NULL){
            return false;
        }
        current = current->children[index];
    }
    return current->isEndOfWord;
}

bool Trie::startsWith(string prefix){
    TrieNode *current = root;
    for(int i = 0; i < prefix.length(); i++){
        int index = prefix[i] - 'a';
        if(current->children[index] == NULL){
            return false;
        }
        current = current->children[index];
    }
    cout << "prefix with word: " << prefix << endl;
    return Trie::__startsWith(current, prefix, "");
}

bool Trie::__startsWith(TrieNode* current, string prefix, string suffix){
    if(current->isEndOfWord){
        cout << prefix + suffix << endl;
    }
    for(int i = 0; i < 26; i++){
        if(current->children[i]){
            Trie::__startsWith(current->children[i], prefix, suffix + current->children[i]->letter);
        }
    }
    return true;
}

int main() {

    Trie T;

    // Insert word(s) in the trie
    T.insert("we");
    T.insert("walk");
    T.insert("want");
    T.insert("wish");
    T.insert("wit");
    T.insert("am");
    T.insert("yo");
    T.insert("will");
    T.insert("wee");
    T.insert("war");
    T.insert("warp");
    T.insert("win");

    // Search for the prefix in the trie
    string prefix("wa");

    T.startsWith("wa");
    
    return 0;
}