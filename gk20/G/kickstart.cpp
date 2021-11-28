#include <iostream>
#include <string>

using namespace std;


bool matching_sub(const string& s, const string& s2, int i){
    for (int j=0; j<s2.size(); j++){
        if (s[i+j] != s2[j]) return false;
    }
    return true;
}


int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        string s; cin >> s;
        int kicks{0}, i = 0, ans{0};
        while (i <= (int) s.size()-5){
            if (matching_sub(s, "KICK", i)){
                kicks++;
                i+=3; // +3 and not +4 because KICK starts and ends with a K! 
            }
            else if (matching_sub(s, "START", i)){
                ans += kicks;
                i+=5;
            }
            else{
                i++;
            }
        }
        cout << "case #" << t << ": " << ans << '\n';
    }
}
