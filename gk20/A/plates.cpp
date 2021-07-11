#include <iostream>
#include <string>
#include <vector>

using namespace std;


/* 
for each new stack of  plate <n> and p the number of plates we want to chose,
the solution sol(n, p) is equal to
            MAX( 
                sol(n-1, P),                                          # 0 plate chosen from the new stack
                sol(n-1, p-1) + plates[n][0],                         # 1 plate chosen from the new stack
                sol(n-1, p-2) + plates[n][0] + plates[n][1],          # 2 plates chosen from the new stack
                .
                .
                .
                sol(n-1, p-K) + plates[n][0] + ... + plates[n][K-1],
                )
therefore we need to store the values sol(n, p) for 0 <= n < N && 0 <= p <= P
*/
int max_beauty_value(vector<vector<int>>& plates, int N, int K, int P){
    vector<int> mem(P+1,0);
    for (int i=0; i<N; i++){
        vector<int> prev_mem(mem);
        for (int p=0; p<P+1; p++){
            int new_stack = 0;
            for (int j=0; j<=p; j++){
                mem[p] = max(mem[p], prev_mem[p-j]+new_stack);
                if (j<K) new_stack += plates[i][j];
                if  (j>K) break;
            }
        }
    }
    return mem[P];
}



int main(){
    string input;

    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        
        cin >> input;
        int N = stoi(input);
        cin >> input;
        int K = stoi(input);
        cin >> input;
        int P = stoi(input);

        vector<vector<int>> plates;
        for (int n=0; n<N; n++){
            vector<int> stack;
            for (int k=0; k<K; k++){
                cin >> input;
                stack.push_back(stoi(input));
            }
            plates.push_back(stack);
        }
        cout << "case #" << t << ": " << max_beauty_value(plates, N, K, P) << endl;
    }
}

