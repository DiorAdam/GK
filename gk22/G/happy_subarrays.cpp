
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;






int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        vector<long> A(N, 0);
        for (int i=0; i<N; i++){
            cin >> A[i];
        }
        long ans = 0;
        unordered_map<long, int> mem;
        for (int i=0; i<N; i++){
            unordered_map<long, int> newmem;
            for (auto p : mem){
                if (p.first + A[i] >= 0){
                    newmem[p.first+A[i]] = p.second;
                    if (A[i] == 0)
                        newmem[p.first]++;
                    ans += newmem[p.first]*(p.first+A[i]);
                }
            }
            mem = move(newmem);
            if (A[i] >= 0){
                mem[A[i]]++;
                ans += A[i];
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}

