#include <iostream>
#include <vector>

using namespace std;


void build_lr(int R, int C, vector<vector<int>>& X, int forward){
    int a{1}, b{C};
    if (forward < 0){ a = C-2; b = -1;}
    for (int i=0; i<R; i++){
        for (int j=a; j!=b; j+=forward){
            X[i][j] = X[i][j]*(X[i][j] + X[i][j-forward]);
        }
    }
}

void build_ud(int R, int C, vector<vector<int>>& X, int forward){
    int a{1}, b{R};
    if (forward < 0){ a = R-2; b = -1;}
    for (int j=0; j!=C; j++){
        for (int i=a; i!=b; i+=forward){
            X[i][j] = X[i][j]*(X[i][j] + X[i-forward][j]);
        }
    }
}


void print_mat(vector<vector<int>>& M){
    for (int i=0; i<M.size(); i++){
        cout << '\n';
        for (int j=0; j<M[0].size(); j++){
            cout << M[i][j] << " ";
        }
    }
    cout << '\n';
}

// min ((j-1)/2 , i) + min((j-1)/2 , R-1-i)
// min ((i-1)/2 , j) + min((i-1)/2, C-1-j)
// min ((C-j-2)/2, i) + min ((C-j-2)/2, R-1-i)
// min ((R-i-2)/2, j) + min((R-i-2)/2, C-1-j)

int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int R; cin >> R;
        int C; cin >> C;
        vector<vector<int>> M(R, vector<int>(C,0));
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                cin >> M[i][j];
            }
        }
        vector<vector<int>> LL(M); build_lr(R, C, LL, 1);
        vector<vector<int>> RR(M); build_lr(R, C, RR, -1);
        vector<vector<int>> UU(M); build_ud(R, C, UU, 1);
        vector<vector<int>> DD(M); build_ud(R, C, DD, -1);

        //print_mat(LL); print_mat(RR); print_mat(UU); print_mat(DD);

        int ans{0};
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                ans += max(min((LL[i][j]-2)/2 , UU[i][j]-1), 0) + max(min((LL[i][j]-2)/2 , DD[i][j]-1), 0);
                ans += max(min((UU[i][j]-2)/2 , LL[i][j]-1), 0) + max(min((UU[i][j]-2)/2 , RR[i][j]-1), 0);
                ans += max(min((RR[i][j]-2)/2 , UU[i][j]-1), 0) + max(min((RR[i][j]-2)/2 , DD[i][j]-1), 0);
                ans += max(min((DD[i][j]-2)/2 , LL[i][j]-1), 0) + max(min((DD[i][j]-2)/2 , RR[i][j]-1), 0);
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}




