#include <vector>;

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

