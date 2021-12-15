#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> digits_of_long(long n){
    vector<int> ans;
    while(n>0){
        ans.push_back((int) n%10);
        n = n/10;
    }
    return ans;
}

int count_bn_size_1(int l, int r, bool even){
    int ans{0};
    if (even){
        for (int i=l+1; i<r; i++)
            if (i%2==0) ans++;
    }
    else{
        for (int i=l+1; i<r; i++)
            if (i%2==1) ans++;
    }
    return ans;
}

long count_bn_same_size(vector<int>& ld, vector<int>& rd){
    int n {ld.size()};
    int i{0};
    while(i < n){
        if (ld[i] < rd[i]){
            int sz{n-i-1};
            long ans{0};
            ans += count_bn_size_1(ld[i], rd[i], (i+1)%2==0)*count_bn_of_sizes(sz, sz);
            if (ld[i]%2 == (i+1)%2){
                long ansl{1};
                for (int j=i+1; j<n; j++) 
                    ansl*=count_bn_size_1(ld[i], 10, j+1%2==0);
                ans += ansl;
            }
            if (rd[i]%2 == (i+1)%2){
                long ansr{1};
                for (int j=i+1; j<n; j++)
                    ansr*=count_bn_size_1(0, rd[i], (j+1)%2==0);
                ans += ansr;
            }
            return ans;
        }
        else if(ld[i]%2 != (i+1)%2)
            return 0;
        i++;
    }
    return 1;
}

long count_bn_of_sizes(int sz_l, int sz_r){
    long ans{0};
    for (int sz=sz_l; sz<= sz_r; sz++){
        ans+= pow(5, sz);
    }
    return ans;
}

long count_bn(long L, long R){
    vector<int> ld = digits_of_long(L);
    vector<int> rd = digits_of_long(R);
    if (ld.size() == rd.size()) 
        return count_bn_same_size(ld, rd);
    else{
        int ls {ld.size()}, rs {rd.size()};
        long ans{0};
        vector<int> l9(ls, 9);
        vector<int> r1(rs, 1);
        return count_bn_same_size(ld, l9) + count_bn_of_sizes(ls+1, rs-1) + count_bn_same_size(r1, rd);
    }
}


int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        long L; cin >> L;
        long R; cin >> R;
        cout << "Case #" << t << ": " << count_bn(L, R) << '\n';
    }
}


