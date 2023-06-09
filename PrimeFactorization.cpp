#include<bits/stdc++.h>
using namespace std;


void primeFactorization(int n){
    int sq = sqrt(n);
    for(int i=2;i<=sq;i++){
        while(n%i==0){
            n/=i;
            cout<<i<<" ";
        }
    }

    if(n>1)cout<<n;
    cout<<endl;
}

void solve(){
    primeFactorization(36);
}

int main(){
    solve();
}