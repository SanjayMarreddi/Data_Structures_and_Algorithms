#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll>	vl;
typedef vector<pi>	vpi;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef priority_queue<ll> prq;  // Max priority Queue.
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(ll (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(ll (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
const int M = 1e9 + 7;
const ll INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue
template <typename T> T pw(T a,T p=M-2,T MOD=M){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}   

vl result; ll maxy = -INF;

// Adapted from GFG.
void combinationUtil(vl &arr, ll n, ll r, ll index,
					vl &data, ll i)
{
	// Current combination is ready, print it
	if (index == r) {

        ll curr = data[0];
		for (int j = 1; j < r; j++)
            { curr ^= data[j]; }
	
        if (curr > maxy){
            maxy = curr;
            result = data;
        }
		return;
	}

	// When no more elements are there to put in data[]
	if (i >= n)
		return;

	// current is included, put next at next location
	data[index] = arr[i];
	combinationUtil(arr, n, r, index + 1, data, i + 1);

	// current is excluded, replace it with next
	// (Note that i+1 is passed, but index is not
	// changed)
	combinationUtil(arr, n, r, index, data, i + 1);
}

void printCombination(vl &arr, ll n, ll r)
{
	// A temporary array to store all combination
	// one by one
	vl data(r);

	// Print all combination using temporary array 'data[]'
	combinationUtil(arr, n, r, 0, data, 0);
}

void solve() {

 ll n, k; cin >> n >> k;
 vl arr;
 fr(i,1,n){arr.pb(i);}
 printCombination(arr, n, k);
 trav(e,result){
     cout << e << " ";
 }
 result.clear();
 maxy = -INF;
}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    fastIO;
    int t = 1;

    cin >>  t;  // Comment this line if only 1 testcase exists.

    fr(T,1,t){

        //cout << "Case #" << T << ": ";

        solve();
        cout << "\n";
    }
    return 0;
}