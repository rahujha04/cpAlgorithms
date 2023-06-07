#include<bits/stdc++.h>
using namespace std;

int binaryExpo(int base, int x){
    int ans = 1;
    while(x){
        if(x&1){
            ans = (ans * base)%mod;
            x--;
        }else{
            ans = (base * base)%mod;
            x >>= 1;
        }
    }
    return ans;
}

void solve(){
    return;
}

int main(){
    solve();
}