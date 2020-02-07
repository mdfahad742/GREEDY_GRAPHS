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

vector<pair<ll,pll> > adj[3001];
multiset<pair<ll,ll> > s;
vector<ll> distTo(3001,0);
vector<pair<ll,pll> > edgeTo(3001,{-1,{-1,-1}});

ll power(ll n,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=(ans*n)%mod;
        k/=2;
        n=(n*n)%mod;
    }
    return ans;
}

void relax(pair<ll,pll> edge,ll v){
    if(distTo[v]+edge.ss.ss<distTo[edge.ff]){
        auto f=s.find({distTo[edge.ff],edge.ff});
        if(f!=s.end())s.erase(f);
        distTo[edge.ff]=distTo[v]+edge.ss.ss;
        edgeTo[edge.ff]=edge;
        s.insert({distTo[edge.ff],edge.ff});
    }
}

void pathTo(ll v){
    cout<<0<<" to "<<v<<" ("<<distTo[v]<<"): ";
    list<pair<ll,pll> > path;
    for(auto e=edgeTo[v];e.ff!=-1&&e.ss.ff!=-1&&e.ss.ss!=-1;e=edgeTo[e.ss.ff]){
        path.push_front(e);
    }
    for(auto i:path){cout<<i.ss.ff<<"->"<<i.ff<<" "<<i.ss.ss<<" ";}cout<<endl;
}
 
// 8
// 16
// 0 1 5
// 0 4 9
// 0 7 8
// 1 2 12
// 1 3 15
// 1 7 4
// 2 3 3
// 2 6 11
// 3 6 9
// 4 5 4
// 4 6 20
// 4 7 5
// 5 2 1
// 5 6 13
// 7 5 6
// 7 2 7
// 0
 
int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    ll t;cin>>t;
    while(t--){
        ll n,e;cin>>n>>e;
        forn(i,e){
            ll v,w, wt;cin>>v>>w>>wt;
            adj[v].pb({w,{v,wt}});
            adj[w].pb({v,{w,wt}});
        }
        ll src;cin>>src;

        forn(i,n)distTo[i]=INT_MAX;
        distTo[src]=0;
        s.insert({distTo[src],src});
        while(!s.empty()){
            auto i=*(s.begin());
            auto j=(s.begin());
            ll v=i.ss;
            s.erase(j);
            for(auto edge:adj[v]){
                relax(edge,v);
            }
        }
        forn(i,n){
            if(i==src)continue;
            if(distTo[i]!=INT_MAX)
                cout<<distTo[i]<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;

        cout<<endl;
        forn(i,n){
            pathTo(i);
        }
        forn(i,n){
            adj[i].clear();
        }


    }

    return 0;
}