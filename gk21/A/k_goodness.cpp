#include <iostream>
#include <string>


using namespace std;



int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        int K; cin >> K;
        string s; cin >> s;
        int score{0};
        for (int i=0; i < (int) s.size()/2; i++){
            if (s[i] != s[N-1-i]) score++;
        }
        cout << "Case #" << t << ": " << abs(score - K) << '\n';
    }
}