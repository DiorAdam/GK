#include <iostream>
#include <unordered_map>

using namespace std;


bool add_div_prod(long a){
    int p = 1, s = 0;
    while (a>0){
        int x = a%10;
        p*=x; s+=x;
        a = a/10;
    }
    return p%s == 0;
}


int main(){
    unordered_map<long, pair<long,int>> mem;
    int T; cin >> T;

    for (int t=1; t <= T; t++){
        long A; cin >> A;
        long B; cin >> B;
        long i = A;
        int ans = 0;
        while (i<=B){
            if (mem.find(i) != mem.end() && mem[i].first <= B){
                ans += mem[i].second;
                i = mem[i].first+1;
            }
            else{
                if (add_div_prod(i))
                    ans++;
                i++;
            }
        }
        mem[A] = {B, ans};
        cout << "Case #" << t << ": " << ans << '\n';
    }
}
