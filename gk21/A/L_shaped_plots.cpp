#include <iostream>

using namespace std;


// min ((j-1)/2 , i) + min((j-1)/2 , R-1-i)
// min ((i-1)/2 , j) + min((i-1)/2, C-1-j)
// min ((C-j-2)/2, i) + min ((C-j-2)/2, R-1-i)
// min ((R-i-2)/2, j) + min((R-i-2)/2, C-1-j)

int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int R; cin >> R;
        int C; cin >> C;
        int ans{0};
        for (int i=1; i<R-1; i++){
            for (int j=1; j<C-1; j++){
                ans += min((j-1)/2 , i) + min((j-1)/2 , R-1-i);
                ans += min((i-1)/2 , j) + min((i-1)/2, C-1-j);
                ans += min((C-j-2)/2, i) + min ((C-j-2)/2, R-1-i);
                ans += min((R-i-2)/2, j) + min((R-i-2)/2, C-1-j)
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}




