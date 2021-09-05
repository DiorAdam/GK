#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int longest_arithmetic_subarray(const vector<int>& nums){
    int m{2}, p{2};
    for (int i=2; i<nums.size(); i++){
        if (nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
            p++;
            m = max(m, p);
        }
        else p=2;
    }
    return m;
}


int main(){
    string input;
    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int N {stoi(input)};
        vector<int> nums(N,0);
        for (int i=0; i<N; i++){  
            cin >> input;  
            nums[i] = stoi(input);
        }
        cout << "case #" << t << ": " << longest_arithmetic_subarray(nums) << '\n';
    }
}

