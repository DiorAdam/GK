#include <iostream>
#include <string>

using namespace std;


bool is_subseq(string& I, string& P){
    int i=0, j=0;
    while (i<I.size() && j<P.size()){
        if (I[i] == P[j]){
            i++;
            j++;
        }
        else j++;
    }
    return i==I.size();
}



int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        string I, P;
        cin >> I; cin >> P;
        cout << "Case #" << t << ": ";
        if (is_subseq(I, P))
            cout << P.size()-I.size() << '\n';
        else
            cout << "IMPOSSIBLE\n";
    }
}

