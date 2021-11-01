#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <list>

using namespace std;


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


void explore(const int& S, list<int>& border, unordered_set<int>& closed_rooms){
    int n = border.size();
    for (int i=0; i<n; i+=2){
        int r = border.front();
        border.pop_front();
        int p = border.front();
        border.pop_front();
        vector<int> neighbs = neighbors(S, r, p);
        for (int j=0; j<neighbs.size(); j+=2){
            int hash = pow(2, neighbs[j])*pow(3, neighbs[j+1]);
            if (closed_rooms.find(hash) == closed_rooms.end()){
                border.push_back(neighbs[j]);
                border.push_back(neighbs[j+1]);
                closed_rooms.insert(hash);
            }
        }
    }
}


int alma_guaranteed_score(const int& S, list<int>& border_a, list<int>& border_b, unordered_set<int>& closed_rooms){
    int ans{0};
    while(!border_a.empty() || !border_b.empty()){
        explore(S, border_a, closed_rooms);
        if (!border_a.empty()) ans++;
        explore(S, border_b, closed_rooms);
        if (!border_b.empty()) ans--;
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
            closed_rooms.insert(pow(2, a)*pow(3, b));  // mapping the pair (a, b) to the integer 2^a*3^b
        }
        closed_rooms.insert(pow(2, Ra)*pow(3, Pa));
        closed_rooms.insert(pow(2, Rb)*pow(3, Pb));
        list<int> border_a = {Ra, Pa};
        list<int> border_b = {Rb, Pb};

        cout << "case #" << t << ": " << alma_guaranteed_score(S, border_a, border_b, closed_rooms) << '\n';
    }
}

