#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;





int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        unordered_map<int, long> diag_val;
        long ans{0};
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                long t; cin >> t;
                diag_val[i-j] += t;
                ans = max(ans, diag_val[i-j]);
            }
        }
        cout << "case #" << t << ": " << ans << '\n';
    }
}

