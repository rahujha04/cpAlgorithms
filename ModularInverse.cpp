#include<bits/stdc++.h>
using namespace std;

int modularInverse(int base, int mod){
    return binaryExpo(base, mod - 2);
}

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