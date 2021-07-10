#include <iostream>
#include <vector>
#include <string>

using namespace std;


int min_covering_interval(vector<int>& centers, vector<int> radii){
    int m = 0, M=0;
    for (int i=1; i<centers.size(); i++){
        if (centers[i] < centers[m]) m = i;
        if (centers[i] > centers[M]) M = i;
    }
    int w = centers[M]-centers[m] + radii[M] + radii[m]; 
    int ans = w/2, l = centers[m] + w/2, r = centers[M] - w/2;
    if (w%2 == 1){
        l++; 
        r--;
        ans++;
    }
    int surplus = 0;
    for (int i=0; i<centers.size(); i++){
        if (centers[i] + radii[i] > l && centers[i] - radii[i] < r){
            surplus = max(surplus, min(centers[i]+radii[i]-l, r-centers[i]-radii[i]));
        }
    }
    return ans + surplus;
}



int main(){
    string input;

    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int N = stoi(input);
        vector<int> X, Y, Z, R;
        for (int i=0; i<N; i++){
            cin >> input;
            X.push_back(stoi(input));
            cin >> input;
            Y.push_back(stoi(input));
            cin >> input;
            Z.push_back(stoi(input));
            cin >> input;
            R.push_back(stoi(input));
        }
        int ans = min_covering_interval(X, R);
        ans = max(ans, min_covering_interval(Y,R));
        ans = max(ans, min_covering_interval(Z,R));
        cout << "case #" << t<< ": " << ans << '\n';
    }
}


