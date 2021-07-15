#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool end_of_word;
    int rest_words;

    TrieNode(): end_of_word{false}, rest_words{0}{}
};

class Trie{
public:
    TrieNode root;
    Trie() {
        root.end_of_word = false;
        root.rest_words = 0;
    }
    ~Trie(){
        //free(&root);
    }

    void add_word(string word){
        TrieNode* head = &root;
        head->rest_words++;
        for (char c: word){
            if(head->children.find(c) != head->children.end()){
                head = head->children[c];
                head->rest_words++;
            }
            else{
                TrieNode* new_node = new TrieNode();
                head->children[c] = new_node;
                head = new_node;
                head->rest_words++;
            }
        }
        head->end_of_word = true;
    }

    void traverse(){
        traverse(&root);
    }

private:
    void traverse(TrieNode* t){
        if (t->end_of_word){
            cout << '\n';
            return;
        }
        for (auto& it : t->children){
            cout << it.first << '\n';
            traverse(it.second);
        }
    }
};


int main(){
    Trie t;
    t.add_word("golang"); t.add_word("gone");
    t.add_word("yolo"); t.add_word("you");
    t.traverse();
}


