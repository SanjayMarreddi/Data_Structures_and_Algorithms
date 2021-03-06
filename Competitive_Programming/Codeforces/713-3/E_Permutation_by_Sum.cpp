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
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   // Min priority queue

inline ll pmod(ll i, ll n) { return (i % n + n) % n; }
const int mod = 1e9 + 7;


ll low(ll k){
  return (k* (k+1))/2;
}

ll high(ll n, ll k){
    return (k*(2*n + 1 - k)/2);
}

void solve() {
  ll n, l, r, s;
  cin >> n >> l >> r >> s;

  // k represents the number of elements to be placed carefully so that sum is `s`.
  ll k = (r-l) + 1;

  vl normal, lr;
  frr(i, n, 1){
     
     // For every number, Inorder to put it in lr, we just check the s & s-i is in correct limits.
     if (k >0 and high(i,k) >= s and s-i >= low(k-1)){
        lr.push_back(i);
        s -= (i);
        k --;
     }
     else{
       normal.push_back(i);
     }
  }

  if (s != 0){
    cout << -1;
  }
  else{
    int i = 0;
    int j = 0;
    fr(index,1,n){
        if (index < l or index > r){
          cout << normal[i] << " ";
          i++;
        }
        else{
          cout << lr[j] << " ";
          j++;
        }
    }

  }

}

int main() {
    fastIO;
    int t = 1;
    cin >>  t; // Comment if only 1 testcase.
    fr(T,1,t){
        //cout << "Case #" << T << ": ";
        solve();
        cout << endl;
    }
    return 0;
}