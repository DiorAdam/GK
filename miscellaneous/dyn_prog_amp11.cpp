#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int mincost(int i, int done, vector<int>& demand, vector<int>& cost){
    if (i >= demand.size() || done >= demand[cost.size()-1]) return 0;
    int ans = INT32_MAX;
    int j= max(0, demand[i]-done);
    int jj;
    for (; j <= 3 && done + j <= demand[cost.size()-1]; j++){
        int x = j*cost[i] + mincost(i+1, done + j, demand, cost);
        if (j>0) x+=1500;
        if (ans > x){
            ans = x;
            jj = j;
        }
    }
    return ans;
}

int dynmincost(vector<int>& demand, vector<int>& cost){
    demand.insert(demand.begin(), 0);
    cost.insert(cost.begin(), 0);
    int n = demand.size();
    vector<int> mem(demand[n-1]+1, 0);
    vector<int> newmem(mem);
    for(int h=n-1; h>0; h--){
        for (int s=demand[h-1]; s <= demand[n-1] && s <= 3*(h-1); s++){
            int loc_min = (s >= demand[h])? mem[s] : INT32_MAX;
            for (int k=1; k<=3 && s+k<= demand[n-1]; k++){
                if (s+k < demand[h]) continue; 
                loc_min = min(loc_min, 1500 + k*cost[h] + mem[s+k]);
            }
            if (loc_min < INT32_MAX) newmem[s] = loc_min;
        }
        copy(newmem.begin(), newmem.end(), mem.begin());
    }
    return mem[0];
}

int main() {
    vector<int> demand = {1, 2, 4, 6, 7, 8, 9, 11, 12, 13, 15, 15, 17};
    vector<int> cost = {5400, 5600, 5800, 5700, 5500, 5200, 36, 2778, 26, 26, 2891, 6373, 2382};
    auto start = chrono::steady_clock::now();
    int res = mincost(0, 0, demand, cost);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> diff = end-start;
    cout << "result: " << res << "  ; elapsed time: " << diff.count() << '\n';
    
    start = chrono::steady_clock::now();
    res = dynmincost(demand, cost);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "result: " << res << "  ; elapsed time: " << diff.count() << '\n';
}
