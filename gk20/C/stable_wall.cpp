#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string partial_sort(int R, int C){
    string input;
    string prev_line;
    cin >> prev_line;
    unordered_set<char> ordering[26];
    unordered_set<char> polyominos;
    bool b = true;
    for (int j=0; j<C; j++) polyominos.insert(prev_line[j]);
    for (int i=1; i<R; i++){
        cin >> input;
        if (!b) continue;
        for (int j=0; j<C; j++){
            if (prev_line[j] != input[j]){
                if (ordering[(int) input[j] - 65].find(prev_line[j]) != ordering[(int) input[j] -65].end()){
                    b = false;
                    break;
                }
                polyominos.insert(input[j]);
                ordering[(int) prev_line[j] - 65].insert(input[j]);
                prev_line[j] = input[j];
            }
        }
    }
    if (!b) return "-1";
    string ans;
    while (b && !polyominos.empty()){
        b = false;
        for (char c : polyominos){
            if (ordering[(int) c - 65].empty()){
                b = true;
                ans += c;
                for (char x : polyominos){
                    ordering[(int) x - 65].erase(c);
                }
                polyominos.erase(c);
                break;
            }
        }
    }
    return (polyominos.size()==0)? ans : "-1";
}



int main(){
    string input;
    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int R = stoi(input);
        cin >> input;
        int C = stoi(input);

        string ans = partial_sort(R, C);
        cout << "case #" << t << ": " << ans << '\n';
    }
}


