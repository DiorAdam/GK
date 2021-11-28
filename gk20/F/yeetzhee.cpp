#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

using namespace std;

 

int rolls(int N, int M, int K, const vector<int>& groups){
    int ans{0};
    int min_unfilled_index{0};
    unordered_map<int, int> state;
    unordered_set<int> filled_groups;
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni_dist(0, M-1);
    for (int n=0; n<N; n++){
        while (true){
            int res = uni_dist(rng);
            ans++; 
            if (state.find(res) != state.end()){
                if (filled_groups.find(res) == filled_groups.end() ){
                    state[res]++;
                    if (state[res] == groups[min_unfilled_index]){
                        min_unfilled_index++;
                        filled_groups.insert(res);
                    }
                    break;
                }
            }
            else if (state.size() < K){
                state[res] = 1;
                if (state[res] == groups[min_unfilled_index]){
                    min_unfilled_index++;
                    filled_groups.insert(res);
                }
                break;
            }
        }
    }
    return ans;
}


float expected_value(int N, int M, int K, const vector<int>& groups){
    float ans{0.};
    for (int i=0; i<10; i++){
        ans += rolls(N, M, K, groups);
    }
    return ans/10.;
}



int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        int M; cin >> M;
        int K; cin >> K;
        vector<int> groups(K, 0);
        for (int k=0; k<K; k++){
            cin >> groups[k];
        }
        cout << "case #" << t << ": " << expected_value(N, M, K, groups) << '\n';
    }
}


