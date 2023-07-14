#include vector


// counts the subsequences of s that are equal to t
// dynamic programming
int numDistinct(string s, string t) {
    vector<vector<long>> mem = {{-1, 1}};
    for (char c: t){
        vector<vector<long>> new_mem = {{-1, 0}};
        int i = 0;
        for (int j=mem[0][0]+1; j<s.size(); j++){
            if (s[j] == c){
                new_mem.push_back({j, (mem[i][1] + new_mem.back()[1]) % INT_MAX });
            }
            if (i+1 < mem.size() && j==mem[i+1][0])
                i++;
        }
        if (new_mem.empty())
            return 0;
        mem = new_mem;
    }
    return mem.back()[1];
}
