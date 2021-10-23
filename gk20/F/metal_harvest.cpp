#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



int min_bots(int K, vector<int*> slots){
    sort(slots.begin(), slots.end(), [](int* a, int* b){return a[0] < b[0];});

    int r {slots[0][0]}, ans{0};
    for (int i=0; i<slots.size(); i++){
        if (r < slots[i][0]){
            ans++;
            r=slots[i][0]+K;
        }
        if(r < slots[i][1]){
            int num_added_bots = ceil((slots[i][1]-r)/(float)K);
            ans += num_added_bots;
            r += num_added_bots*K;
        }
    }
    return ans;
}

void free_intervals(vector<int*> slots){
    for (int i=0; i<slots.size(); i++){
        free(slots[i]);
    }
}

int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        int K; cin >> K;
        vector<int*> intervals(N,0);
        for (int n=0; n<N; n++){
            int s; cin >> s;
            int e; cin >> e;
            int* se = (int*) calloc(2, sizeof(int));
            se[0] = s; se[1] = e;
            intervals[n] = se;
        }
        cout << "case #" << t << ": " << min_bots(K, intervals) << '\n';
        free_intervals(intervals);
    }
}


