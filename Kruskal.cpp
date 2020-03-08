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
 

vector<pair<ll,ll> > adj[3001];
vector<ll> parent(3001,0);
vector<ll> rk(3001,0);


struct lex_compare {
    bool operator() (pair<ll, pair<ll,ll> > lhs, pair<ll, pair<ll,ll> > rhs) const {
        //cout<<lhs.ff<<" "<<lhs.ss.ff<<" "<<lhs.ss.ss<<endl;

        if(lhs.ff==rhs.ff){
            ll x=lhs.ss.ff+lhs.ss.ss;
            ll y=rhs.ss.ff+rhs.ss.ss;
            return x>y;
        }
        return lhs.ff<rhs.ff;
    }
};



ll power(ll n,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=(ans*n)%mod;
        k/=2;
        n=(n*n)%mod;
    }
    return ans;
}

ll find(ll p){
    while(parent[p]!=p){
        parent[p]=parent[parent[p]];
        p=parent[p];
    }
    return p;
}

void union1(ll v,ll w){
    ll rootV=find(v);
    ll rootW=find(w);
    if(rootV==rootW)return;
    if(rk[rootV]>rk[rootW]){parent[rootW]=rootV;}
    else if(rk[rootV]<rk[rootW]){parent[rootV]=rootW;}
    else {
        parent[rootV]=rootW;
        rk[rootW]++;
    }
}


bool connected(ll v, ll w){
    return find(v)==find(w);
}
 
 
 
 
int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    ll v,e;cin>>v>>e;

    multiset<pair<ll, pair<ll,ll> > > s;

    forn(i,e){
        ll p,q,wt;cin>>p>>q>>wt;

        adj[p].push_back({q,wt});
        adj[q].push_back({p,wt});
        s.insert({wt,{p,q}});
    }

    forn(i,v){
        parent[i]=i;
        rk[i]=0;
    }
    

    vector<pair<ll, pair<ll,ll> > > mst;
    ll ans=0;
    
    while(!s.empty() && mst.size()<v-1){
        auto i=*(s.begin());
        
        auto j=s.begin();
        ll p,q,wt;
        p=i.ss.ff;q=i.ss.ss;wt=i.ff;
        
        s.erase(j);
        
       
        if(!connected(p,q)){
            mst.pb({p,{q,wt}});
            ans+=wt;
            union1(p,q);
            

        }
    }
    // cout<<endl;


    // forn(i,v-1){
    //     cout<<mst[i].ff<<" "<<mst[i].ss.ff<<" "<<mst[i].ss.ss<<endl;
    // }
    // cout<<mst.size()<<endl;
    cout<<ans<<endl;

 
    
 
    return 0;
}
