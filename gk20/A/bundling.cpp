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
    TrieNode* root;
    Trie(): root{new TrieNode} {}
    ~Trie(){
        traverse_del(root);
    }

    void add_word(string word){
        TrieNode* head = root;
        head->rest_words++;
        for (char c: word){
            if(head->children.find(c) != head->children.end()){
                head = head->children[c];
                head->rest_words++;
            }
            else{
                TrieNode* new_node = new TrieNode;
                head->children[c] = new_node;
                head = new_node;
                head->rest_words++;
            }
        }
        head->end_of_word = true;
    }

    void traverse(){
        traverse(root);
    }

private:
    void traverse_del(TrieNode* t){
        if (t->end_of_word){
            //cout << '\n';
            return;
        }
        for (auto& it : t->children){
            //cout << it.first << '\n';
            traverse_del(it.second);
        }
        delete t;
    }

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



void bundle(TrieNode* root, const string& prefix, int K){
    root->rest_words -= K;
    TrieNode* head = root;
    for (char c: prefix){
        head = head->children[c];
        head->rest_words -= K;
    }
}


int max_bundle_score(TrieNode* root, int K){
    int ans {0};
    
    TrieNode* head = root;

    while(root->rest_words >= K){
        bool pursue {true};
        string pref;
        while(pursue){
            pursue = false;
            if (head->children.size() == 0) break;
            for (auto& tp : head->children){
                if (tp.second->rest_words >= K){
                    pref += tp.first;
                    head = tp.second;
                    pursue = true;
                    break;
                }
            }
        }
        bundle(root, pref, K);
        head = root;
        ans += pref.length();
    }
    return ans;
}



int main(){
    int input;
    cin >> input;
    int T = input;
    for (int t=1; t <= T; t++){
        cin >> input;
        int N = input;
        cin >> input;
        int K = input;
        string inputs;
        Trie trie;
        for (int i=0; i<N; i++){
            cin >> inputs;
            trie.add_word(inputs);
        }

        cout << "case #" << t << ": " << max_bundle_score(trie.root, K) <<'\n';
    }
}


