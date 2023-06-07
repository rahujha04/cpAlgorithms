#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9 + 7;
const int N = 1e5 + 7;


// DSU Implementation

int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int findPar(int v){
    if(v==parent[v])return v;
    return parent[v] = findPar(parent[v]);
}

void Union(int a, int b){
    a = findPar(a);
    b = findPar(b);
    if(a!=b){
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}


void solve(){
    
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