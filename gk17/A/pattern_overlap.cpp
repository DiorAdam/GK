#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:
        string p1;
        string p2;
        vector<vector<int>> mem;
        Solution(string p1_, string p2_){
            p1 = p1_;
            p2 = p2_;
            mem = vector<vector<int>>(p1.length(), vector<int>(p2.length(), 0));
        }

        bool just_stars(string p, int i){
            for (int k=i; k<p.length(); k++){
                if (p[k] != '*') return false;
            }
            return true;
        }

        bool patterns_overlap(int i, int j){
            if (i >= p1.length()){
                return just_stars(p2, j);
            }
            else if (j >= p2.length()){
                return just_stars(p1, i);
            }
            //cout << mem.size() << '\n';
            if (mem[i][j] == 1){
                return false;
            }
            mem[i][j] = 1;
            
            if (p1[i] == '*'){
                if (patterns_overlap(i+1, j+1) 
                || patterns_overlap(i+1, j+2)
                || patterns_overlap(i+1, j+3)
                || patterns_overlap(i+1, j+4)
                || patterns_overlap(i+1, j+5)) return true;    
            } 
            if (p2[j] == '*'){
                if (patterns_overlap(i+1, j+1) 
                || patterns_overlap(i+2, j+1)
                || patterns_overlap(i+3, j+1)
                || patterns_overlap(i+4, j+1)
                || patterns_overlap(i+5, j+1)) return true;    
            }
            else if (p1[i] == p2[j]){
                return patterns_overlap(i+1, j+1);
            }
            return false;
        }
};


int main(){
    /*
    Solution* s = new Solution("***", "jeudsbcekjd");
    cout << s->patterns_overlap(0,0) << '\n';
    */
    string input;

    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        string p1, p2;
        cin >> p1; cin >> p2;

        Solution* s = new Solution(p1, p2);
        if (s->patterns_overlap(0, 0)){
            cout << "case #" << t << ": TRUE\n"; 
        }
        else{
            cout << "case #" << t << ": FALSE\n";
        }

    }
}
