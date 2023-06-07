#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9 + 7;


// single hash -> collision -> 1/mod => 1/1e9+7 good
// rolling hash (double hash) -> 1/mod1*mod2 => 1/1e18 better
// random hash is the best


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


int find_hash(string &s){
    int h = 0;
    for(auto &c: s){
        h = (h * 1ll * 31 + (c - 'a' + 1))%mod;
    }
    return h;
}

vector<int> rabin_karp(string &s, string &t){
    vector<int> pos;

    int n = s.size(), m = t.size();

    vector<int> power(max(m, n), 0);
    
    int p = 31;

    power[0] = 1;

    for(int i=1;i<power.size();i++){
        power[i] = (power[i-1] * 1ll * p)%mod;
    }

    int hash_s = 0;

    for(int i=0;i<n;i++){
        hash_s = (hash_s + (s[i] - 'a' + 1)* 1ll *power[i])%mod;
    }

    vector<int> hash_t(m+1, 0);

    for(int i=0;i<m;i++){
        hash_t[i+1] = (hash_t[i] + (t[i] - 'a' + 1)* 1ll *power[i])%mod;
    }

    for(int i=0;i<=m-n;i++){
        int curHash = (hash_t[i+n] - hash_t[i] + mod)%mod;

        if(curHash == (hash_s * 1ll * power[i])%mod){
            pos.push_back(i);
        }
    }

    return pos;
}



void solve(){
    string t, s;
    cin>>t>>s;
    vector<int> pos = rabin_karp(s, t);
    for(int i=0;i<pos.size();i++){
        cout<<pos[i]<<" ";
    }
    cout<<endl;
    // cout<<pos.size()<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

// int main(){
//     solve();
// }