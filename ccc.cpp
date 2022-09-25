// by Siddhid Saha (2112010)


#include <bits/stdc++.h>
using namespace std;


#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI atan(1)*4
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<ll>
#define rsort(a) sort(a,a+n,greater<int>())
#define rvsort(a) sort(all(a),greater<int>())
#define read(a,n) for(int i = 0 ; i < n ; i ++){ cin >> a[i];}
#define printv(a) for(auto it: a){cout << it << " ";} cout << endl;
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef SID
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

/*--------------------------------------------------------------------------------------------------------------------------*/

/*

101110110
dp[0][0] = 3;
dp[0][1] = max(tmp0[i],)

16%15 = 1
16%9 = 7
16%8 = 0

1 2 3 4

*/


//const int mod = 1e9 + 7 , mod1 = 998244353; 


void solve(int tc =0)
{
    ll n; cin >> n; 
    vll a(n);
    read(a,n);
    set<ll> st;
    for(int i = 1 ; i <=  n ; i++){
        st.insert(i);
    }
    sort(all(a));
    ll cnt = 0;
    vector<bool> vis(n+1 , false);
    for(int i = 0 ; i < n ; i ++){
        if(a[i]<= n && a[i]>=1 && !vis[a[i]]){
            st.erase(a[i]);
            vis[a[i]]= true;
        }else{
            ll tmp = *st.begin();
            if(tmp >= ((a[i]+1)/2)){
                cout << -1 << endl;
                return;
            }else{
               /// cout << i << endl;
                a[i] = tmp;
                vis[a[i]]= true;
                st.erase(tmp);
                cnt++;
            }
        }
    }
    cout << cnt << endl;


}

int main() {
     
    #ifndef ONLINE_JUDGE
    freopen("D:/cp/input.txt", "r+", stdin);freopen("D:/cp/output.txt", "w+", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	ll t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++){
		//google(i);
		solve();
	}
	return 0;
}








/*struct Matrix{
	double a[2][2] = {{0,0} ,{0, 0}};
	Matrix operator *(const Matrix& other){
		Matrix product; 
		REP(i,2)REP(j,2)REP(k,2){
			product.a[i][k] += a[i][j] * other.a[j][k];
		} 
		return product;
	}
};*/


/*ll expo_power( ll a , ll k)
{
    ll product = 1;
	while(k > 0){
		if(k%2){
			product = product *a;
		} 
		a *= a;
		k /= 2;
	}
	return product;
}*/