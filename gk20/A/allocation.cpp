#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int max_houses(int B, vector<int>& prices){
    int c = 0;
    while (B > 0 && !prices.empty()){
        int p = -prices.front();
        pop_heap(prices.begin(), prices.end());
        prices.pop_back();

        if (B < p) return c;
        B-=p;
        c++;
    }
    return c;
}


int main(){
    string input;

    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int N = stoi(input);
        cin >> input;
        int B = stoi(input);
        vector<int> prices;
        make_heap(prices.begin(), prices.end());
        for (int i=0; i<N; i++){
            cin >> input;
            prices.push_back(-stoi(input));
            push_heap(prices.begin(), prices.end());
        }
        cout << "case #" << t << ": " << max_houses(B, prices) << '\n';
    }
}

