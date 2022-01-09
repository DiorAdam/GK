#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


long minimal_boxes(vector<vector<int>>& heights, int m, int M){
    int R = heights.size(), C = heights[0].size();
    unordered_map<int, vector<vector<int>>> index;
    for (int i=0; i < R; i++){
        for (int j=0; j<C; j++){ 
            index[heights[i][j]].push_back({i, j});
        }
    }
    long added_boxes{0};
    vector<vector<int>> neighbs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (int h = M; h > m; h--){
        for (const vector<int>& pos : index[h]){
            int i = pos[0], j = pos[1];
            if (h < heights[i][j]) continue;
            for (auto d : neighbs){
                int u = i + d[0], v = j + d[1];
                if (u<0 || u>=R || v<0 || v>=C) continue;
                if (heights[u][v] < heights[i][j] - 1){
                    added_boxes += heights[i][j]-1-heights[u][v];
                    heights[u][v] = heights[i][j]-1;
                    index[h-1].push_back({u, v});
                }
            }
        }
    }
    return added_boxes;
}


int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int R; cin >> R;
        int C; cin >> C;
        vector<vector<int>> heights(R, vector<int>(C, 0));
        int m = INT32_MAX, M = 0;

        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                cin >> heights[i][j];
                m = min(m, heights[i][j]);
                M = max(M, heights[i][j]);
            }
        }
        cout << "Case #" << t << ": " << minimal_boxes(heights, m, M) << '\n';
    }
}
