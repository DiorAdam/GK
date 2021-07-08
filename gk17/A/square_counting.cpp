#include <string>
#include <iostream>

using namespace std;

int count_squares(int R, int C){
    int ans = 0;
    for (int i=1; i < R; i++){
        for (int j=1; j < C; j++){
            //ans += (j <= C-i-1)? j*(i+1-j) + j*(j+1)/2 : (j-C+i)*(C-j) + (C-i)*(i+1-j) + (C-i)*(C-i-1)/2;
            ans += min(i,j);
            for (int k=0; k<j; k++){
                ans += (i+k-j >= C-j-1)? C-j-1 : max(i+k-j,0);
            }
            ans %= 1000000000 + 7;  
        }
    }
    return ans;
}

int main(){
    cout << count_squares(2,4) << '\n';
    cout << count_squares(3,4) << '\n';
    cout << count_squares(4,4) << '\n';
    cout << count_squares(54,578100) << '\n';
    /*
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
    */
}



