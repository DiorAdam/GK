#include <iostream>
#include "./adjacency_list.cpp"


using namespace std;


double min_spanning_tree(AdjacencyList& graph){
    double ans{0};

    return ans;
}


int main(){
    AdjacencyList graph(cin);
    graph.print();
    cout << "Minimal Spanning Tree Cost: " << min_spanning_tree(graph) << endl;
    return 0;
}

