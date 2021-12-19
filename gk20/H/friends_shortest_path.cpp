#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


bool friends(const string& a, const string& b){
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b.size(); j++){
            if (a[i] == b[j]) return true;
        }
    }
    return false;
}






int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        int Q; cin >> Q;
        vector<string> names(N);
        vector<vector<int>> graph;
        unordered_map<int, int> graph;
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
        vector<vector<int>> queries(Q, vector<int>(2,0));
        unordered_map<int, int> occ;
        for (int i=0; i<Q; i++){
            cin >> queries[i][0];
            cin >> queries[i][1];
            occ[queries[i][0]]++;
            occ[queries[i][1]]++;
        }
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) { 
            return a.second < b.second; 
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> queue(occ.begin(), occ.end(), comp);
    }
}



