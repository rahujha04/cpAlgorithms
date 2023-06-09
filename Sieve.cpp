#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int sieve[N];

vector<int> cal_prime(int l, int r){
    memset(sieve, 1, sizeof(sieve));

    vector<int> prime;

    int sq = sqrt(N);

    for(int i=2;i<=sq;i++){
        if(sieve[i]){
            for(int j=i*i;j<=N;j+=i){
                sieve[j] = 0;
            }
        }
    }

    for(int i=l;i<=r;i++){
        if(sieve[i]){
            prime.push_back(i);
        }
    }

    return prime;

    // TC: O(N*Log(Log(N)))
}



void solve(){
    vector<int> prime = cal_prime(2, 22);
    for(auto &ele: prime){
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main(){
    solve();
}