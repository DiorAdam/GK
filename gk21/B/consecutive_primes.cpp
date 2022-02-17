#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void euclide(vector<long>& primes){
    int n = 1000001;
    bool* iscomposite = new bool[n];
    for (int i=2; i<n; i++){
        if (iscomposite[i]) continue;
        primes.push_back((long) i);
        for (int j=2; i*j<n; j++) iscomposite[i*j] = true;
    }
    delete iscomposite;
}

long prime_bin_search(long Z, vector<long> primes){
    int l = 0, r = min((long) sqrt(Z), (long) primes.size()-1);
    int m;
    while (l<r){
        m = (l+r)/2;
        if (primes[m]*primes[m+1] <= Z and primes[m+1]*primes[m+2]>Z)
            return primes[m]*primes[m+1];
        else if (primes[m]*primes[m+1] > Z) 
            r = m;
        else
            l = (l==m)? m+1 : m;
        //cout << '\n' << primes[m]*primes[m+1] << '\n';
    }
    return primes[l]*primes[l+1];
}


int main(){
    int T; cin >> T;
    vector<long> primes;
    euclide(primes);
    //cout << '\n' << primes[20] << '\n';
    for (int t=1; t <= T; t++){
        long Z; cin >> Z;
        cout << "Case #" << t << ": " << prime_bin_search(Z, primes) << '\n';
    }
}


