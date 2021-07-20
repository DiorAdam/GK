#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;



void binom_table(vector<vector<int>>& table, int N){
    vector<int> l0(1,1);
    vector<int> l1(2,1);
    table.push_back(l0); table.push_back(l1);
    for (int n=2; n<=N; n++){
        vector<int> line(n+1, 1);
        for (int k=1; k<n; k++){
            line[k] = table.back()[k-1] + table.back()[k];
        }
        table.push_back(line);
    }
}


int main(){
    string input;
    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int W = stoi(input);
        cin >> input;
        int H = stoi(input);
        cin >> input;
        int L = stoi(input);
        cin >> input;
        int U = stoi(input);
        cin >> input;
        int R = stoi(input);
        cin >> input;
        int D = stoi(input);

        float ans {0.0};
        if (R==W && D==H) ans = 0.0;
        else if(W==1 && H==1) ans = 1.0;
        else{
            vector<vector<int>> binoms;
            binom_table(binoms, max(U+R-2, L+D-2));
            if (R<W){
                if (U>1) ans += (binoms[R][R])*pow(0.5,R);
                for (int i=2; i<U; i++){
                    ans += (binoms[i+R-1][R] - binoms[i+R-2][R])*pow(0.5,i+R-1);
                }
            }
            if (D<H){
                if (L>1) ans += (binoms[D][D])*pow(0.5,D);
                for (int j=2; j<L; j++){
                    ans += (binoms[j+D-1][D] - binoms[j+D-2][D])*pow(0.5,j+D-1);
                }
            }
        }
        cout << "case #" << t << ": " << ans << '\n';
    }
}


