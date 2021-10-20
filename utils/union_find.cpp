#include <vector>

using namespace std;


void quick_sort(vector<int>& arr, vector<int>& inds, int l, int r){
    if (l>=r) return;
    int pos{l};
    for (int i=l; i<r; i++){
        if (arr[i]<arr[r]){
            int c = arr[pos];
            arr[pos] = arr[i];
            arr[i] = c;
            int d = inds[pos];
            inds[pos] = inds[i];
            inds[i] = d;
            pos++;
        }
    }
    int c = arr[pos];
    arr[pos] = arr[r];
    arr[r] = c;
    int d = inds[pos];
    inds[pos] = inds[r];
    inds[r] = d;
    quick_sort(arr, inds, l, pos-1);
    quick_sort(arr, inds, pos+1, r);
}


vector<int> indexes_after_sort(const vector<int>& arr){
    vector<int> dup_arr(arr);
    vector<int> inds(arr.size(), 0);
    for (int i=0; i<arr.size(); i++) inds[i] = i;
    quick_sort(dup_arr, inds, 0, arr.size()-1);
    return inds;
}

bool connected(vector<int>& id, int p, int q){
    return id[p-1] == id[q-1];
}

void node_union(vector<int>& id, int p, int q){
    if (id[p-1] == id[q-1]) return;
    int idq = id[q-1];
    for (int i=0; i<id.size(); i++){
        if (id[i] == idq) id[i] = id[p-1];
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int ans{0};
    int e=0;
    vector<int> inds = indexes_after_sort(g_weight);
    vector<int> id(g_nodes, 0);
    for (int i=0; i<g_nodes; i++) id[i] = i;
    for (int i=0; i<inds.size() && e < g_nodes-1; i++){
        if (!connected(id, g_from[inds[i]], g_to[inds[i]])){
            ans+=g_weight[inds[i]];
            e++;
            node_union(id, g_from[inds[i]], g_to[inds[i]]);
            //cout << g_from[inds[i]] << "  " << g_to[inds[i]] << endl;
        }
    }
    return ans;
}



int main() {
    vector<int> gfrom(5, 0), gto(5,0), gweight(5,0);
    gfrom[0] = 1; gto[0] = 2; gweight[0] = 1; 
    gfrom[1] = 3; gto[1] = 2; gweight[1] = 150; 
    gfrom[2] = 4; gto[2] = 3; gweight[2] = 99; 
    gfrom[3] = 1; gto[3] = 4; gweight[3] = 100; 
    gfrom[4] = 3; gto[4] = 1; gweight[4] = 200;
    
    cout << kruskals(4, gfrom, gto, gweight) << endl;
}
