#include <iostream>

using namespace std;





int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        long N; cin >> N;
        long K; cin >> K;
        long S; cin >> S;
        cout << "Case #" << t << ": " << N+min(K, 2*(K-S)) << '\n';
    }
}
