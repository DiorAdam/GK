#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;



double dist(pair<int, int> a, pair<int, int> b){
    return sqrt(pow((double) a.first - b.first, 2) + pow((double) a.second-b.second, 2));
}

double dist0(pair<int, int> a){
    return dist(a, {0, 0});
}

int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int Rs; cin >> Rs;
        int Rh; cin >> Rh;
        pair<int, int> mr = {2*pow(10, 4), 2*pow(10, 4)}, my = {2*pow(10, 4), 2*pow(10, 4)};
        int N; cin >> N;
        vector<pair<int, int>> red;
        for (int i=0; i<N; i++){
            int x; cin >> x;
            int y; cin >> y;
            if (dist0({x, y}) <= Rs+Rh){
                if (dist0(mr) > dist0({x, y})){
                    mr = {x, y};
                }
                red.push_back({x, y});
            }
        }
        int M; cin >> M;
        vector<pair<int, int>> yel;
        for (int i=0; i<M; i++){
            int x; cin >> x;
            int y; cin >> y;
            if (dist0({x, y}) <= Rs+Rh){
                if (dist0(my) > dist0({x, y})){
                    my = {x, y};
                }
                yel.push_back({x, y});
            }
        }
        
        if (dist0(mr) < dist0(my)){
            int ans = 0;
            for (auto p : red){
                if (dist0(p) < dist0(my))
                    ans++;
            }
            cout << "Case #" << t << ": " << ans << " " << 0 << '\n';
        }
        else{
            int ans = 0;
            for (auto p : yel){
                if (dist0(p) < dist0(mr))
                    ans++;
            }
            cout << "Case #" << t << ": " << 0 << " " << ans << '\n';
        }
    }
}


