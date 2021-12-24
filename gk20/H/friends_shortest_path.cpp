#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;


bool friends(const string& a, const string& b){
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b.size(); j++){
            if (a[i] == b[j]) return true;
        }
    }
    return false;
}


int shortest_path(vector<vector<int>>& graph, vector<vector<int>>& mem, int s, int d){
    if (mem[s][d]>0) return mem[s][d];
    if (mem[d][s]>0) return mem[d][s];
    queue<int> Q; Q.push(d);
    unordered_map<int, int> dist = {{d, 1}};
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for (int neighb : graph[node]){
            if (dist.find(neighb) != dist.end()) continue;
            dist[neighb] = dist[node]+1;
            mem[d][neighb] = dist[neighb];
            Q.push(neighb);
        }
    }
    for (int i=0; i<mem.size(); i++){
        if (mem[d][i] == 0 && i!=d) mem[d][i] = -1;
    }
    return mem[d][s];
}


int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        int Q; cin >> Q;
        vector<string> names(N);
        vector<vector<int>> graph;
        for (int i=0; i<N; i++){
            cin >> names[i];
            vector<int> neighbs;
            for (int j=0; j<i; j++){
                if (friends(names[i], names[j])){
                    neighbs.push_back(j);
                    graph[j].push_back(i);
                }
            }
            graph.push_back(neighbs);
        }
        vector<vector<int>> queries(Q, vector<int>(3,0));
        unordered_map<int, int> occ;
        for (int i=0; i<Q; i++){
            cin >> queries[i][0]; queries[i][0]--;
            cin >> queries[i][1]; queries[i][1]--;
            occ[queries[i][0]]++;
            occ[queries[i][1]]++;
        }
        
        //preparing queries before sorting them according to their occurencies.
        for (int i=0; i<Q; i++){
            if (occ[queries[i][1]] >= occ[queries[i][0]]){
                queries[i][2] = occ[queries[i][1]];
            }
            else{
                int c = occ[queries[i][0]];
                occ[queries[i][0]] = occ[queries[i][1]];
                occ[queries[i][1]] = c;
                queries[i][2] = occ[queries[i][1]];
            }
        }
        
        // Sorting queries
        auto comp = [](const vector<int>& a, const vector<int>& b){ return a[2] > b[2];};
        sort(queries.begin(), queries.end(), comp);
        
        // Output answer
        vector<vector<int>> mem(N, vector<int>(N, 0));
        cout << "case #" << t << ":";
        for (int q=0; q<Q; q++){
            cout << " " << shortest_path(graph, mem, queries[q][0], queries[q][1]);
        }
        cout << '\n';
    }
}



