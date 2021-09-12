#include <iostream>
#include <string>
#include <vector>

using namespace std;


void skyline(int N, int A, int B, int C, vector<int>& v){
    if (A-C+B > N || C > A || C > B || C==0 || (A==1 && B==1 && N!=1) ) return;

    for (int i=0; i<A-C; i++){
        v[i] = i+2;
    }
    for (int i=0; i<C-1; i++){
        v[A-C+i] = N;
    }
    if (A==1){
        v[0] = N;
        for (int i=0; i<N-(A+B-C);i++){
            v[A+i] = 1;
        }
    }
    else{
        for (int i=0; i<N-(A+B-C); i++){
            v[A-1+i] = 1;
        }
        v[N-B+C-1] = N;
    }
    for (int i=0; i<B-C; i++){
        v[N-1-i] = i+2;
    }
}


int main(){
    string input;
    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        int N, A, B, C;
        cin >> N;
        cin >> A; 
        cin >> B;
        cin >> C;

        vector<int> v(N, 0);
        skyline(N, A, B, C, v);
        if (v[0] == 0) 
            cout << "case #" << t << ": " << "IMPOSSIBLE\n";
        else{
            cout << "case #" << t << ":";
            for (auto x : v){
                cout << " " << x;
            }
            cout << endl;
        }
    }
}



