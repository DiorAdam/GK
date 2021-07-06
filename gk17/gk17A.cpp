#include <string>
#include <iostream>

using namespace std;

int count_squares(int r, int c){
    return 0;
}

int main(){
    string input;
    cin >> input;
    int T = stoi(input);
    cout << input << '\n';
    for (int i=0; i < T; i++){
        cin >> input ;
        int r = stoi(input);
        cin >> input;
        int c = stoi(input);
        cout << "case #" << i << ": " << count_squares(r, c) << '\n';
    }
}



