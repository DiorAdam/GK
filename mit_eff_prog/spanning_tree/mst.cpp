#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include "./adjacency_list.cpp"

    
using namespace std;

// Prim Algorithm
double min_spanning_tree(AdjacencyList& graph){
    double ans{0};
    auto comp = [](const State& a, const State& b){ return a.get_dist() > b.get_dist();};
    vector<State> neighb0 = graph.neighbors(0);
    priority_queue<State, vector<State>, decltype(comp)> Q(neighb0.begin(), neighb0.end(), comp);
    unordered_set<int> added = {0};
    while (added.size() < graph.get_size()){
        State f = Q.top();
        while (added.find(f.get_node()) != added.end()){
            Q.pop();
            f = Q.top();
        }
        ans += f.get_dist();
        added.insert(f.get_node());
        for (State s : graph.neighbors(f.get_node())){
            if (added.find(s.get_node()) == added.end()){
                Q.push(s);
            }
        }
    }
    return ans;
}



int main(){
    AdjacencyList graph(cin);
    cout << "Minimal Spanning Tree Cost: " << min_spanning_tree(graph) << endl;
    return 0;
}

