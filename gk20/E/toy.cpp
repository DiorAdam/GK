#include <iostream>
#include <string>
#include <vector>

using namespace std;



void max_playing_time(vector<int>& E, vector<int>& R, int total_enj, vector<int>& ans){
    int n = E.size();
    int enj = total_enj;
    for (int i=0; i<n; i++){
        if (R[i] > total_enj - E[i]){
            if (enj > ans[1]){
                ans[1] = enj;
                ans[2] = ans[0];
            }
            total_enj-=E[i];
            E[i] = 0; R[i]=0;
            ans[0]++;
            if (ans[0] >= E.size()-1 ) return;
            max_playing_time(E, R, total_enj, ans);
            return;
        }
        enj += E[i];
        if (enj > ans[1]){
            ans[1] = enj;
            ans[2] = ans[0];
        }
    }
    ans[1] = -1;
    ans[2] = ans[0];
    return;
} 




int main(){
    string input;
    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int N = stoi(input);
        vector<int> enjoyment(N,0);
        vector<int> remembrance(N,0);
        int total_enj{0};
        int total_rem{0};
        for (int i=0; i<N; i++){
            cin >> input;
            enjoyment[i] = stoi(input);
            cin >> input;
            remembrance[i] = stoi(input);
            total_enj += enjoyment[i];
        }
        vector<int> ans(3,0);
        ans[1] = total_enj;
        max_playing_time(enjoyment, remembrance, total_enj, ans);
        if (ans[1] == -1) cout << "case #" << t << ": " << ans[2] << " INDEFINITELY\n";  
        else cout << "case #" << t << ": " << ans[2] << " " << ans[1] << endl;
    }
}


