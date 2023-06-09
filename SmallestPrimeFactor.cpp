#include<bits/stdc++.h>
using namespace std;


const int N = 1e6;
int spf[N+5];

void SmallestPrimeFactor(){
    for(int i=1;i<=N;i++){
        spf[i] = i;
    }

    for(int i=2;i*i <= N; i++){
        if(spf[i] == i){
            for(int j=i*i;j<=N;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    for(int i=1;i<=100;i++){
        cout<<i<<" -> "<<spf[i]<<endl;
    }
}

void solve(){
    SmallestPrimeFactor();
}

int main(){
    solve();
}