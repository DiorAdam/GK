#include <iostream>
#include <vector>
#include <cmath>

using namespace std;





int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int M; cin >> M;
        int N; cin >> N;
        int P; cin >> P;
        vector<int> maxes(N, 0);
        vector<int> johns(N,0);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                int u; cin >> u;
                if (i+1 == P){
                    johns[j] = u;
                }
                maxes[j] = max(maxes[j], u);
            }
        }
        int ans = 0;
        for (int i=0; i<N; i++){
            ans += maxes[i] - johns[i];
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}


