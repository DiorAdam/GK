#include <iostream>

using namespace std;

// n is divisible by nine iff
// the sum of its digits is

string challenge_nine(string n){
    int acc = 0;
    int sz = n.size();
    for (char x : n)
        acc += x-48;  // char to integer
    int i = 9 - acc%9;
    if (i==9) i = 0;
    int ind = (i>0)? 0 : 1;
    string ans = n.substr(0, ind) + (char) (i+48) + n.substr(0+ind, sz-ind); 
    while (ind < sz){
        ind++;
        string x = n.substr(0, ind) + (char) (i+48) + n.substr(0+ind, sz-ind);
        if (x < ans)
            ans = x;
    }
    return ans;
}




int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        string n; cin >> n;
        cout << "Case #" << t << ": " << challenge_nine(n) << '\n';
    }
}

