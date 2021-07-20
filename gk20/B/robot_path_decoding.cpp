#include <iostream>
#include <string>

#define GRID_SIZE 1000000000

using namespace std;




void final_position(const string& path, int l, int r, int& w, int& h){
    int pos {l};
    while(pos < r){
        if (path[pos] == 'E'){
            w++;
            pos++;
        }
        else if (path[pos] == 'W'){
            w--;
            pos++;
        }
        else if (path[pos] == 'N'){
            h--;
            pos++;
        }
        else if (path[pos] == 'S'){
            h++;
            pos++;
        }
        else{
            int sub_path_count = stoi(path.substr(pos, 1));
            int parentheses = 1;
            pos+=2;
            int start = pos;
            while (parentheses != 0){
                if (path[pos] == '(') parentheses++;
                else if (path[pos] == ')') parentheses--;
                pos++;
            }
            int w_ {0}, h_ {0};
            final_position(path, start, pos-1, w_, h_);
            w += sub_path_count*w_;
            h += sub_path_count*h_;
        }
    }
}



int main(){
    string input;
    cin >> input;
    int T = stoi(input);
    for (int t=1; t <= T; t++){
        cin >> input;
        int w {0}, h {0};
        final_position(input, 0, input.length(), w, h);
        w%=GRID_SIZE; h%=GRID_SIZE;
        if (w<0) w += GRID_SIZE;
        if (h<0) h += GRID_SIZE;
        cout << "case #" << t << ": " << w+1 << " " << h+1 << '\n';
    }
}


