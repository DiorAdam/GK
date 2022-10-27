#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;



long rec(bool tr, long E, pair<long, long> pos, long np, vector<vector<long>>& nectar){
    long ans = 0;
    long l = 0, r = 0;
    for (int i=np; i<nectar.size() && nectar[i][1]==nectar[np][1]; i++){
        
        if (nectar[i][0] <= pos.first)
            l+=nectar[i][2];
        if (nectar[i][0] >= pos.first)
            r+=nectar[i][2];
    }
    long ans = 0;
    if (tr)
        l-=E;
    else
        r-=E;
    return 0;
}



int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        long N; cin >> N;
        long E; cin >> E;
        long my = 0;
        vector<vector<long>> nectar;
        for (int i=0; i<N; i++){
            long x; cin >> x;
            long y; cin >> y;
            long p; cin >> p;
            nectar.push_back({x, y, p});
            my = max(my, y);
        }
        auto comp = [](vector<long> a, vector<long> b){return a[1] > b[1];};
        sort(nectar.begin(), nectar.end(), comp);
        cout << "Case #" << t << ": " << rec(true, E, {0, pow(10, 18)}, 0, nectar) << '\n';
    }
}

