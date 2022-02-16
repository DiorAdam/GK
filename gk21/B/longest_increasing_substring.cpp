#include <iostream>

using namespace std;



int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        string s; cin >> s;
        int ans[N] = {1};
        for (int i=1; i<N; i++){
            ans[i] = (s[i] > s[i-1])? ans[i-1]+1 : 1;
        }
        cout << "Case #" << t << ":";
        for (int i=0; i< N; i++) cout << " " << ans[i];
        cout << '\n';
    }
}

