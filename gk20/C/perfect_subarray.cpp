#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;



int count_psa(vector<int>& A){
    int ans {0};
    for (int i=0; i<A.size(); i++){
        int s = 0;
        for (int j=i; j<A.size(); j++){
            s+= A[j];
            if (s <= 0) continue;
            if (sqrt(s) == (int) sqrt(s)) ans++;
        }
    }
    return ans;
}



int main(){
    string input;

    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int N = stoi(input);
        vector<int> A(N, 0);
        for (int i=0; i<N; i++){
            cin >> input;
            A[i] = stoi(input);
        }
        cout << "case #" << t << ": " << count_psa(A) << endl ;
    }
}


