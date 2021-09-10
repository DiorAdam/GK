#include <iostream>
#include <string>
#include <vector>

using namespace std;


void skyline(int N, int A, int B, int C, vector<int>& v){
    if (A-C+B > N || C > A || C > B || (A==1 && B==1) ) return;
    if  (C == 0){
        if(A==1 || B==1) return;
        for (int i=0; i<A-1; i++){
            v[i] = N-A+i+2;
        }
        for (int i=0; i<B-1; i++){
            v[N-i-1] = N-B+i+2;
        }
        for (int i=A-1; i<N-B+1; i++){
            v[i] = 1;
        }
    }
    else if (C==1){
        for (int i=0; i<A-1; i++){
            v[i] = i+2;
        }
        if (B==1){
            for (int i=A-1; i<N-1; i++){
                v[i] = 1;
            }
            v[N-1] = N;
        }
        else{
            v[A-1] = N;
            for (int i=0; i<B-1; i++){
                v[N-i-1] = i+2;
            }
            for (int i=A; i<N-B+1; i++){
                v[i] = 1;
            }
        }
    }
    else {
        for (int i=0; i<A-C; i++){
            v[i] = i+1;
        }
        for (int i=0; i<C-1; i++){
            v[A-C+i] = N;
        }
        for (int i=0; i<N-(A+B-C); i++){
            v[A-1+i] = 1;
        }
        v[N-B+C-1] = N;
        for (int i=0; i<B-C; i++){
            v[N-1-i] = i+1;
        }
    }
    return;
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
            cout << "case #" << t << ": ";
            for (auto x : v){
                cout << " " << x;
            }
            cout << endl;
        }
    }
}



