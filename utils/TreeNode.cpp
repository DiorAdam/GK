#include <unordered_map>

using namespace std:

struct TreeNode{
    unordered_map<int, TreeNode*> children;
    int val;
    TreeNode(): val{-1}{}
};


