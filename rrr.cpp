/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///
    
    
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define lb lower_bound
#define up upper_bound
#define umap          unordered_map
#define uset          unordered_set
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                  1000000007
#define PI          3.141592653589793238
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)              ll n;cin>>n;
#define inpv(v)              for(auto &x: v) cin>>x;
#define make(arr,n)   ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)             for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)   for(ll i=a;i<=(n);++i)
#define fD(i,a,n)   for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all(str)           str.begin(), str.end()
    
    
    
using namespace std;
bool isFit(int arr[], int brr[], int n){
        // code here
        set<int> s;
        vector<int> v(n);
        for(int i=0;i<n;++i)
        v[i]=brr[i];
        sort(v.begin(),v.end());
        // for(auto &i:v)
        // cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n;++i)
        {
            int ind=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
           cout<<ind<<endl;
            if(ind!=n && s.find(ind)==s.end())
            {
                s.insert(ind);
            continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
void solve()
{
    int n;
    cin>>n;
   int arr[n],brr[n];
  
   for(int i=0;i<n;++i)
   cin>>arr[i];
    for(int i=0;i<n;++i)
   cin>>brr[i];
    cout<<isFit(arr,brr,n);
}
    
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
ll q;
//cin>>q;
q=1;
while(q--)
{
    solve();
}
    return 0;
}