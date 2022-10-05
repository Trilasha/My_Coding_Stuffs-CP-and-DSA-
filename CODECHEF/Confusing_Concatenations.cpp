/*
Trilasha Mazumder
2112063
*/
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
using namespace std;
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define umap                  unordered_map
#define uset                  unordered_set
#define ff                    first
#define ss                    second
#define pi                    pair<ll,ll> 
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)             for(ll i=a;i<=(n);++i)
#define fD(i,a,n)             for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)         sort(str.begin(), str.end())
#define alldsort(str)         sort(str.begin(), str.end(),greater<char>())
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}


/// ---------------------------------------------------------------------------------------------- ///
//ceil(log2(x))
    
/// ---------------------------------------------------------------------------------------------- ///
    



void solve(){
   inp(n);
   vector<ll> v(n);
   inpv(v);
   //printv(v);
   map<ll,ll> mp;
   fr(i,n)
   mp[v[i]]++;
   // printv(v);
   for(auto &i:mp)
   {
    if(i.second>1)
    {
    cout<<-1<<endl;
    return;
    }
   }
   // printv(v);
   vector<ll> v1;
   vector<ll> v2;
   ll index=-1;
  
   v1.pb(v[0]);
   //cout<<v1[0]<<endl;
   for(ll i=0;i<v.size();++i)
   {
    if(v[i]<v[0])
    v1.pb(v[i]);
    else if(v[i]>v[0])
    {
        v2.pb(v[i]);
        index=i;
        break;
    }
   }
//    printv(a);
//    printv(b);
   if(index!=-1)
   {
    frs(i,index+1,n)
    v2.pb(v[i]);
   }
   if(v2.size()==0)
   {
    cout<<-1<<endl;
   }
   else
   {
   // cout<<"aaa"<<endl;
    cout<<v1.size()<<endl;
    printv(v1);
    cout<<v2.size()<<endl;
    printv(v2);
   }
}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q;
cin>>q;
while(q--)
{
    solve();
}
    return 0;
}








/*
//
string s=to_string(bitset<64> b(10));
//
stack,queue->no index access
use deque,vectors
-->assign(n,val)available for both
-->take size +1(extra) for vectors
//
using namespace std;
const ll N=1e9+10;
vector<ll> g[N];
bool vis[N];
void dfs(ll vertex)
{
vis[vertex]=true;
for(ll child:g[vertex])
{
    if(vis[child])continue;
    dfs(child);
}
}
*/