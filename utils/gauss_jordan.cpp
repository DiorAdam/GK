#include <vector>
#include <iostream>

#define eps 0.000001


using namespace std;

bool set_pivot(vector<vector<float>>& mat, int p){
    if (abs(mat[p][p]) > 0) return true;
    for (int i=p+1; i<mat.size(); i++){
        if (abs(mat[i][p]) > eps){
            vector<float> pivot_line(mat[i]);
            mat[i] = mat[p];
            mat[p] = pivot_line;
            return true;
        }
    }
    return false;
}

void do_row_operation(vector<vector<float>>& mat, int p, int r, float c){
    for (int j=p; j<mat.size()+1; j++){
        mat[r][j] = mat[r][j] + c*mat[p][j];
    }
}

vector<float> linear_solver(vector<vector<float>>& mat){
    int n = mat.size();
    vector<float> ans(n+1, 0);
    for (int p=0; p<n-1; p++){
        if (set_pivot(mat, p)){
            for (int r=p+1; r<n; r++){
                if (abs(mat[r][p]) < eps) continue;
                do_row_operation(mat, p, r, -mat[r][p]/mat[p][p]);
            }
        }
        else{
            ans[n] = -1;
            return ans;
        }        
    }
    if (abs(mat[n-1][n-1]) < eps){
        ans[n] = -1;
        return ans;
    }
    for (int i=n-1; i>=0; i--){
        ans[i] = mat[i][mat.size()];
        for (int j=i+1; j<n; j++){
            ans[i] -= mat[i][j]*ans[j];
        }
        ans[i]/=mat[i][i];
    }
    return ans;
}


int main(){
    vector<vector<float>> mat;
    vector<float> a(4, 0); a[0]=1; a[1] = 0; a[2] = 9; a[3] = 3;
    vector<float> b(4, 0); b[0]=1; b[1] = 0; b[2] = 0; b[3] = 6;
    vector<float> c(4, 0); c[0]=-2; c[1] = 3; c[2] = 0; c[3] = 0;
    mat.push_back(a); mat.push_back(b); mat.push_back(c);
    vector<float> ans = linear_solver(mat);

    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << "  ";
    }
    cout << "\n\n";
    for (int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
}


