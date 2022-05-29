#include <iostream>
#include <vector>

using namespace std;


bool is_pal5(vector<char>& ws, int p){
    return ((ws[p] == ws[p-4]) && (ws[p-1] == ws[p-3]));
}

bool is_pal6(vector<char>& ws, int p){
    return ((ws[p] == ws[p-5]) && (ws[p-1] == ws[p-4]) && (ws[p-2] == ws[p-3]));
}


bool pal_free(const string& s, vector<char>& ws, vector<int>& backtracks, int p, int b){
        // cout << "\np = " << p << "\n";
        // for (int i=0; i<ws.size(); i++){
        //     cout <<ws[i];
        // }
        // cout << "\n\n";
    //cout << "b = " << b << '\n';
    if (b >=0 && p==backtracks[b]){
        if (ws[p] == '0'){
            ws[p] = '1';
        }
        else{
            ws[p] = '?';
            if (b==0) return false;
            return pal_free(s, ws, backtracks, backtracks[b-1], b-1);
        }
    }
    while (p < ws.size()){
        cout <<"yolo5 p =" << p << '\n';
        for (int i=0; i<ws.size(); i++){
            cout <<ws[i];
        }
        cout << "\n";
        if (ws[p] == '?'){
            ws[p] = '0';
            b++;
            if (b==backtracks.size()) backtracks.push_back(p);
        }
        if (is_pal5(ws, p)){
            int i = backtracks[b];
            if (i < p-4)
                return false;
            return pal_free(s, ws, backtracks, i, b);
        }
        if (is_pal6(ws, p)){
            int i = backtracks[b];
            if (i < p-5)
                return false;
            return pal_free(s, ws, backtracks, i, b);
        }
        p++;
    }
    cout << '\n';
    for (int i=0; i<ws.size(); i++){
        cout <<ws[i];
    }
    cout << "\n\n";
    return true;
}



int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        string s; cin >> s;
        vector<char> ws(s.size()+5);
        for (int i=0; i<5; i++) ws[i] = '2';
        for (int i=0; i<s.size(); i++){
            ws[i+5] = s[i];
        }
        vector<int> backtracks;
        if (pal_free(s, ws, backtracks, 5, -1))
            cout << "Case #" << t << ": POSSIBLE\n";
        else
            cout << "Case #" << t << ": IMPOSSIBLE\n";
    }
}



