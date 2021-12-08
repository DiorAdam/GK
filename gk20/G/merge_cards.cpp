#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;


void fetch_odds(int N, vector<vector<double>>& mem){
    for (int i=mem.size(); i<=N-2; i++){
        int n = i+2;
        vector<double> cur(n,0);
        for (int j=0; j<n; j++){
            if (j >= ceil((float) n/2)){
                cur[j] = cur[n-1-j];
                continue;
            }
            cur[j] = 1 + (n-1-j)*mem.back()[j];
            if (j > 0) cur[j] += 1 + j*mem.back()[j-1];
            cur[j] /= n-1;
        }
        mem.push_back(cur);
    }
}



int main(){
    cout.precision(numeric_limits<double>::max_digits10);
    int T; cin >> T;
    vector<vector<double>> mem = {{1.,1.}};
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        if (N > mem.size()+1){
            fetch_odds(N, mem);
        }
        double ans{0}; 
        for (int i=0; i<N; i++){
            double a; cin >> a;
            ans += mem[N-2][i]*a;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    cout << '\n';
    for (int i=0; i<mem.size(); i++){
        for (int j=0; j<i+2; j++){
            cout << mem[i][j] << " "; 
        }
        cout << '\n';
    }
}


