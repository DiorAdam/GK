#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


vector<int> digits_of_long(long n);
int count_bn_size_1(int l, int r, bool even);
long count_bn_same_size(const vector<int>& ld, const vector<int>& rd);
long count_bn_of_sizes(int sz_l, int sz_r);
long count_bn(long L, long R);

vector<int> digits_of_long(long n){
    vector<int> ans;
    while(n>0){
        ans.push_back((int) n%10);
        n = n/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int count_bn_size_1(int l, int r, bool even){
    int ans{0};
    if (even){
        for (int i=l; i<=r; i++)
            if (i%2==0) ans++;
    }
    else{
        for (int i=l; i<=r; i++)
            if (i%2==1) ans++;
    }
    return ans;
}

long count_bn_same_size(const vector<int>& ld, const vector<int>& rd){
    int n {(int) ld.size()}; 
    int i{0}; 
    while(i < n){
        if (ld[i] < rd[i]){ 
            int sz{n-i-1}; 
            long ans{0}; 
            ans += count_bn_size_1(ld[i]+1, rd[i]-1, (i+1)%2==0)*count_bn_of_sizes(sz, sz);
            if (ld[i]%2 == (i+1)%2){ 
                long ansl{1};
                for (int j=i+1; j<n; j++) 
                    ansl*=count_bn_size_1(ld[j], 9, (j+1)%2==0);
                ans += ansl;
            }
            if (rd[i]%2 == (i+1)%2){
                long ansr{1}; 
                for (int j=i+1; j<n; j++) 
                    ansr*=count_bn_size_1(0, rd[j], (j+1)%2==0); 
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
    if (sz_r <=0) return 1;
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
        int ls {(int) ld.size()}, rs {(int) rd.size()};
        long ans{0};
        vector<int> l9(ls, 9);
        vector<int> r1(rs, 0); r1[0]=1;
        return count_bn_same_size(ld, l9) + count_bn_of_sizes(ls+1, rs-1) + count_bn_same_size(r1, rd);
    }
}

/*

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


vector<int> digits_of_long(long n);
int count_bn_size_1(int l, int r, bool even);
long count_bn_same_size(const vector<int>& ld, const vector<int>& rd, int s);
long count_bn_of_sizes(int sz_l, int sz_r);
long count_bn(long L, long R);

vector<int> digits_of_long(long n){
    vector<int> ans;
    while(n>0){
        ans.push_back((int) n%10);
        n = n/10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int count_bn_size_1(int l, int r, bool even){
    int ans{0};
    if (even){
        for (int i=l; i<=r; i++)
            if (i%2==0) ans++;
    }
    else{
        for (int i=l; i<=r; i++)
            if (i%2==1) ans++;
    }
    return ans;
}

long count_bn_same_size(const vector<int>& ld, const vector<int>& rd, int s){
    int n {(int) ld.size()}; 
    if (s==n-1) return count_bn_size_1(ld[n-1], rd[n-1], n%2==0);
    int i{s}; 
    while(i < n){
        if (ld[i] < rd[i]){ 
            int sz{n-i-1}; 
            long ans{0}; 
            ans += count_bn_size_1(ld[i]+1, rd[i]-1, (i+1)%2==0)*count_bn_of_sizes(sz, sz);
            if (ld[i]%2 == (i+1)%2){ 
                vector<int> l9(n, 9);
                ans += count_bn_same_size(ld, l9, i+1);
            }
            if (rd[i]%2 == (i+1)%2){
                vector<int> r1(n, 0);
                ans += count_bn_same_size(r1, rd, i+1); 
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
    if (sz_r <=0) return 1;
    for (int sz=sz_l; sz<= sz_r; sz++){
        ans+= pow(5, sz);
    }
    return ans;
}

long count_bn(long L, long R){
    vector<int> ld = digits_of_long(L);
    vector<int> rd = digits_of_long(R);
    if (ld.size() == rd.size()) 
        return count_bn_same_size(ld, rd, 0);
    else{
        int ls {(int) ld.size()}, rs {(int) rd.size()};
        long ans{0};
        vector<int> l9(ls, 9);
        vector<int> r1(rs, 0); r1[0]=1;
        return count_bn_same_size(ld, l9, 0) + count_bn_of_sizes(ls+1, rs-1) + count_bn_same_size(r1, rd, 0);
    }
}


*/


int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        long L; cin >> L;
        long R; cin >> R;
        cout << "Case #" << t << ": " << count_bn(L, R) << '\n';
    }
    return 0;
}


