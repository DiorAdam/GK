#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> group;
    for (string path : paths){
        //size_t fi = path.rfind("/");
        size_t l = path.find(" ");
        string dir = path.substr(0, l);
        size_t cl = path.find("(", l);
        size_t cr = path.find(")", cl);
        string filename, content;
        while(cr < string::npos){
            filename = path.substr(l+1, cl-l-1);
            content = path.substr(cl+1, cr-cl);
            cout << dir << "   " << filename << '\n';
            group[content].push_back(dir + "/" + filename);
            l = cr+1;
            cl = path.find("(", l);
            cr = path.find(")", cl);
        }
    }
    vector<vector<string>> ans;
    for (auto& p : group){
        if (p.second.size() > 1)
            ans.push_back(p.second);
    }
    return ans;
}


