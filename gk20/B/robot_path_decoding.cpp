#include <iostream>
#include <string>

#define GRID_SIZE 1000000000

using namespace std;




void final_position(string& path, int l, int r, int& w, int& h){
    if (l >= r) return;
    int pos {l+1};
    if (path[l] == 'E'){
        w++;
        w%=GRID_SIZE;
    }
    else if (path[l] == 'W'){
        w = (w==0)? GRID_SIZE-1 : w-1;
    }
    else if (path[l] == 'N'){
        h = (h==0)? GRID_SIZE-1: h-1;
        //cout << w << "  " << h << '\n';
    }
    else if (path[l] == 'S'){
        h++;
        h%=GRID_SIZE;
    }
    else{
        while (path[pos] != '('){
            pos++;
        }
        //cout << '\n' << path << "  "<< path.substr(l, pos-l) << '\n';
        int sub_path_count = stoi(path.substr(l, pos-l));
        int parentheses = 1;
        pos++;
        l = pos;
        while (parentheses != 0){
            if (path[pos] == '(') parentheses++;
            else if (path[pos] == ')') parentheses--;
            pos++;
        }
        for (int i=0; i < sub_path_count; i++){
            final_position(path, l, pos-1, w, h);
        }
    }
    final_position(path, pos, r, w, h);
}



int main(){
    string input;

    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int w {0}, h {0};
        final_position(input, 0, input.length(), w, h);
        cout << "case #" << t << ": " << w+1 << " " << h+1 << '\n';
    }
}

