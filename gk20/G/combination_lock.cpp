#include <iostream>
#include <vector>


using namespace std;



long cost_function(int x, int N, const vector<int>& wheels){
    long ans = 0;
    for (int w=0; w<wheels.size(); w++){
        ans += min(abs(x-wheels[w]), N - abs(x-wheels[w]));
    }
    return ans;
}


int min_moves(int N, const vector<int>& wheels){
    long min_cost = INT64_MAX;
    for (int x=1; x<=N; x++){
        min_cost = min(min_cost, cost_function(x, N, wheels));
    }
    return min_cost;
}


int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int W; cin >> W;
        int N; cin >> N;
        vector<int> wheels(W, 0);
        for (int w=0; w<W; w++){
            cin >> wheels[w];
        }
        cout << "case #" << t << ": " << min_moves(N, wheels) << '\n';
    }
}

