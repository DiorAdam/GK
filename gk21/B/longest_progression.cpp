#include <iostream>
#include <vector>

using namespace std;


void inline longest_ending(int N, int* arr, int* mem, vector<int>& ends){
    for (int i=2; i<N; i++){
        if (mem[i-1] == 1) mem[i] = 2;
        else if (arr[i] - arr[i-1] == arr[i-1] - arr[i-2]) mem[i] = mem[i-1]+1;
        else{
            ends.push_back(i-1);
            mem[i] = 1;
        } 
    } 
    ends.push_back(N-1);
}

void inline longest_starting(int N, int* arr, int* mem){
    for (int i=N-3; i>=0; i--){
        if (mem[i+1] == 1) mem[i]=2;
        else if (arr[i]-arr[i+1] == arr[i+1] - arr[i+2]) mem[i] = mem[i+1]+1;
        else mem[i] = 1;
    }
}

int main(){
    int T; cin >> T;
    for (int t=1; t <= T; t++){
        int N; cin >> N;
        int arr[N];
        for (int i=0; i<N; i++){
            cin >> arr[i];
        }
        int ll[N] = {1, 2};
        int lr[N]; lr[N-1] = 1; lr[N-2] = 2;
        vector<int> ends;
        longest_ending(N, arr, ll, ends); 
        longest_starting(N, arr, lr);
        int ans {2};
        if (ll[N-1] == N){
            cout << "Case #" << t << ": " << N << '\n';
            continue;
        }
        for (int i=0; i<ends.size(); i++){
            int j = ends[i];
            int period = arr[j]-arr[j-1];
            int new_sub_length = ll[j] +1;
            if (j<N-2 && arr[j+2] == arr[j]+2*period){
                new_sub_length++;
            }
            if (j < N-2 && period == arr[j+3] - arr[j+2]) new_sub_length += lr[j+2]-1;
            ans = max(ans, new_sub_length);
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
}

