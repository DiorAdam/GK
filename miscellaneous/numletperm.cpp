#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;



vector<int> numletperm(const string& s){
    vector<int> ans(10, 0);
    vector<string> numlet = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<char> key = {'z', 'o', 'w', 'h', 'u', 'f', 'x', 'v', 'g', 'i'};
    unordered_map<char, int> ss;
    for (char c : s){
        ss[c]++;
    }
    for (int i=0; i<=8; i+=2){
        if (ss[key[i]] > 0){
            ans[i] = ss[key[i]];
            for (char c : numlet[i]){
                if (ss[c] < ans[i]){
                    ans[0] = -1;
                    return ans;
                }
                ss[c] -= ans[i];
            }
        }
    }
    for (int i=1; i<=9; i+=2){
        if (ss[key[i]] > 0){
            ans[i] = ss[key[i]];
            for (char c : numlet[i]){
                if (ss[c] < ans[i]){
                    ans[0] = -1;
                    return ans;
                }
                ss[c] -= ans[i];
            }
        }
    }
    for (char c = 'a'; c<='z'; c++){
        if (ss[c] != 0){
            ans[0] = -1;
            return ans;
        }
    }
    return ans;
}


int minCoins(vector<int> coins, int target){
    vector<int> mem(target+1, INT32_MAX);
    mem[0] = 0;
    for (int i=1; i<=target; i++){
        for (int c : coins){
            if (i-c >= 0)
                mem[i] = min(mem[i], mem[i-c]+1);
        }
    }
    return mem[target];
}


int main(){
    string s = "fnienironxzeessvenenineoour";
    vector<int> ans = numletperm(s);
    if (ans[0] == -1)
        cout << "not a permutation\n";
    else{
        for (int i=0; i<10; i++){
            cout << ans[i] << "  ";
        }
        cout << '\n';
    }
    cout << minCoins({1, 3, 6}, 11) << "\n";
    return 0;
}

