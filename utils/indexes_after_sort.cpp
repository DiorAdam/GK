#include <vector>

using namespace std;

void quick_sort(vector<int>& arr, vector<int>& inds, int l, int r){
    if (l>=r) return;
    int pos{l};
    for (int i=l; i<r; i++){
        if (arr[i]<arr[r]){
            int c = arr[pos];
            arr[pos] = arr[i];
            arr[i] = c;
            int d = inds[pos];
            inds[pos] = inds[i];
            inds[i] = d;
            pos++;
        }
    }
    int c = arr[pos];
    arr[pos] = arr[r];
    arr[r] = c;
    int d = inds[pos];
    inds[pos] = inds[r];
    inds[r] = d;
    quick_sort(arr, inds, l, pos-1);
    quick_sort(arr, inds, pos+1, r);
}

vector<int> indexes_after_sort(const vector<int>& arr){
    vector<int> dup_arr(arr);
    vector<int> inds(arr.size(), 0);
    for (int i=0; i<arr.size(); i++) inds[i] = i;
    quick_sort(dup_arr, inds, 0, arr.size()-1);
    return inds;
}


int main() {
    vector<int> arr(6, 0);
    for (int i=0; i< 6; i++) arr[i] = 6-i;
    vector<int> inds = indexes_after_sort(arr);
    for (int i=0; i<6; i++) cout << inds[i] << " ";
    cout << endl;
}
