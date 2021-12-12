#include <iostream>
#include <unordered_map>
#include <unordered_set>   
#include <vector>
#include <cmath>


using namespace std;


struct TreeNode{
    vector<TreeNode*> children;
    int score;
    bool finished;
    TreeNode(): score{0}, finished{false}{}
};

void alma_play(TreeNode* head, int& S, int Ra, int Pa, int Rb, int Pb, unordered_set<int> closed_rooms);
void berthe_play(TreeNode* head, int& S, int Ra, int Pa, int Rb, int Pb, unordered_set<int> closed_rooms);
int maximizer(TreeNode* head);
int minimizer(TreeNode* head);




vector<int> neighbors(int S, int r, int p){
    if (p%2==0){
        return {r, p-1, r, p+1, r-1, p-1};
    }
    else{
        vector<int> ans;
        if (r<S){
            ans.push_back(r+1);
            ans.push_back(p+1);
        }
        if(p>1){
            ans.push_back(r);
            ans.push_back(p-1);
        }
        if(p<2*r-1){
            ans.push_back(r);
            ans.push_back(p+1);
        }
        return ans;
    }
}



void alma_play(TreeNode* head, int& S, int Ra, int Pa, int Rb, int Pb, unordered_set<int> closed_rooms){
    //cout <<  "\n Berthe: " << head->score << '\n';
    vector<int> neighbs = neighbors(S, Ra, Pa);
    for (int i=0; i<neighbs.size(); i+=2){
        if ( closed_rooms.find(pow(2, neighbs[i])*pow(3, neighbs[i+1])) == closed_rooms.end() ){
            TreeNode* child = new TreeNode();
            child->score = head->score + 1;
            unordered_set<int> new_closed_rooms(closed_rooms);
            new_closed_rooms.insert(pow(2,neighbs[i])*pow(3,neighbs[i+1]));
            head->children.push_back(child);
            berthe_play(child, S, neighbs[i], neighbs[i+1], Rb, Pb, new_closed_rooms);
        }
    }
    if (head->children.empty() && !head->finished){
        TreeNode* child = new TreeNode();
        child->score = head->score, child->finished = true;
        head->children.push_back(child);
        berthe_play(child, S, Ra, Rb, Rb, Pb, closed_rooms);
    }
}

void berthe_play(TreeNode* head, int& S, int Ra, int Pa, int Rb, int Pb, unordered_set<int> closed_rooms){
    //cout <<  "\n Alma: " << head->score << '\n';
    vector<int> neighbs = neighbors(S, Rb, Pb);
    for (int i=0; i<neighbs.size(); i+=2){
        if ( closed_rooms.find(pow(2, neighbs[i])*pow(3, neighbs[i+1])) == closed_rooms.end() ){
            TreeNode* child = new TreeNode();
            child->score = head->score - 1;
            unordered_set<int> new_closed_rooms(closed_rooms);
            new_closed_rooms.insert(pow(2,neighbs[i])*pow(3,neighbs[i+1]));
            head->children.push_back(child);
            alma_play(child, S, Ra, Pa, neighbs[i], neighbs[i+1], new_closed_rooms);
        }
    }
    if (head->children.empty() && !head->finished){
        TreeNode* child = new TreeNode();
        child->score = head->score, child->finished = true;
        head->children.push_back(child);
        alma_play(child, S, Ra, Rb, Rb, Pb, closed_rooms);
    }
}


int maximizer(TreeNode* head){
    if (head->children.empty()) return head->score;
    int ans{INT32_MIN};
    for (TreeNode* child: head->children){
        ans = max(ans, minimizer(child));
    }
    return ans;
}


int minimizer(TreeNode* head){
    if (head->children.empty()) return head->score;
    int ans{INT32_MAX};
    for (TreeNode* child: head->children){
        ans = min(ans, maximizer(child));
    }
    return ans;
}

int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int S; cin >> S;
        int Ra; cin >> Ra;
        int Pa; cin >> Pa;
        int Rb; cin >> Rb;
        int Pb; cin >> Pb;
        int C; cin >> C;
        unordered_set<int> closed_rooms;
        for (int c=0; c<C; c++){
            int a, b;
            cin >> a; cin >> b;
            closed_rooms.insert(pow(2, a)*pow(3, b));  // mapping the pair (a, b) to the integer (2^a)*(3^b)
        }
        closed_rooms.insert(pow(2, Ra)*pow(3, Pa));
        closed_rooms.insert(pow(2, Rb)*pow(3, Pb));

        TreeNode* game_tree = new TreeNode();
        alma_play(game_tree, S, Ra, Pa, Rb, Pb, closed_rooms);
        cout << "case #" << t << ": " << maximizer(game_tree) << '\n';
    }
}

