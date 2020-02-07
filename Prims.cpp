#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define db double
#define pll pair<ll, ll>
#define pdb pair<db, db>
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define clr(x) memset(x, 0, sizeof(x))
#define count_bit(x) __builtin_popcount(x)
#define endl "\n"
#define debug(x) cout<<#x<<" = "<<x<<endl
const ll size = 505;
const ll mod = 1e9 + 7;

vector<pair<ll, pll > > adj[3001];
multiset<pair<ll, pll > > s;
vector<bool> visited(3001,0);

ll power(ll n,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=(ans*n)%mod;
        k/=2;
        n=(n*n)%mod;
    }
    return ans;
}

// ll find(ll p){
//     while(parent[p]!=p){
//         parent[p]=parent[parent[p]];
//         p=parent[p];
//     }
//     return p;
// }

// void union1(ll v,ll w){
//     ll rootV=find(v);
//     ll rootW=find(w);
//     if(rootV==rootW)return;
//     if(rk[rootV]>rk[rootW]){parent[rootW]=rootV;}
//     else if(rk[rootV]>rk[rootW]){parent[rootV]=rootW;}
//     else {
//         parent[rootV]=rootW;
//         rk[rootW]++;
//     }
// }


// bool connected(ll v, ll w){
//     return find(v)==find(w);
// }

void visit(int v){
    visited[v]=true;
    for(auto e:adj[v]){
        int w=e.ff;
        if(!visited[w])s.insert({e.ss.ss,{v,w}});
    }
}
 
 
 
 
int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    ll n,e;cin>>n>>e;
    forn(i,e){
        ll v,w,wt;cin>>v>>w>>wt;
        adj[v-1].pb({w-1,{v-1,wt}});
        adj[w-1].pb({v-1,{w-1,wt}});
    }
    

    ll src;cin>>src;
    visit(src-1);

    
    vector<pair<ll, pll > > mst;
    ll ans=0;
    while(!s.empty()&&mst.size()<n-1){
        auto i=*(s.begin());
        auto j=(s.begin());
        ll v=i.ss.ff,w=i.ss.ss,wt=i.ff;
        s.erase(j);
        if(visited[v]&&visited[w])continue;
        mst.pb({v,{w,wt}});
        ans+=wt;
        if(!visited[v])visit(v);
        if(!visited[w])visit(w);

    }
    //cout<<mst.size()<<endl;
    cout<<ans<<endl;
    

 
    
 
    return 0;
}