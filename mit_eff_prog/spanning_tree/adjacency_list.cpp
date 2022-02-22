#include <iostream>
#include <vector>

//using namespace std;

class State {
    size_t node;
    double dist;
public:
    State(size_t aNode, double aDist ) : node{aNode}, dist{aDist} {}
    inline size_t get_node() const {return node;}
    inline double get_dist() const {return dist;}
};

class AdjacencyList {
    std::vector<std::vector<State>> vert;
    AdjacencyList() = delete;
public:
    AdjacencyList( std::istream &input ){
        int N; input >> N;
        int E; input >> E;
        vert = std::vector<std::vector<State>>(N, (std::vector<State>){});
        for (int i=0; i<E; i++){
            size_t n1; input >> n1;
            size_t n2; input >> n2;
            double d; input >> d;
            vert[(int) n1].push_back(State(n2, d));
            vert[(int) n2].push_back(State(n1, d));
        }
    }
    inline size_t get_size() const { return vert.size(); }
    inline const std::vector<State>& neighbors( size_t node ) const {
        return vert[node];
    }
    void print(){
        for (int i=0; i<vert.size(); i++){
            std::cout << i << ": ";
            for(int j=0; j<vert[i].size(); j++){
                std::cout << "(" << vert[i][j].get_node() << ", " << vert[i][j].get_dist() << ") ";
            }
            std::cout << '\n';
        }
    };
};

