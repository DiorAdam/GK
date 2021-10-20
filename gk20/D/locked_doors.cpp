#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N, Q;
        cin >> N; cin >> Q;
        vector<int> diffs(N-1, 0);
        for (int n=0; n<N-1; n++){
            cin >> diffs[n];
        }
        string res{""};
        for (int q=0; q<Q; q++){
            int si, ki;
            cin >> si; cin >> ki;
            int tovisit{ki-1};
            int l=si-1, r=si-1, ans=si-1;
            while (tovisit > 0){
                if (ans == 0){
                    ans = r + tovisit;
                    break;
                }
                else if(ans == N-1){
                    ans = l-tovisit;
                    break;
                }
                else{
                    if (diffs[l-1] < diffs[r]){
                        l--;
                        ans = l;
                    }
                    else{
                        r++;
                        ans = r;
                    }
                }
                tovisit--;
            }
            res += " " + to_string(ans+1);
        }
        cout << "case #" << t << ":" << res <<'\n';
    }
}


