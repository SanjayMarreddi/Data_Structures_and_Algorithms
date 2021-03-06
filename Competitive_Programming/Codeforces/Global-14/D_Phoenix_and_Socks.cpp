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
const long long INF = 1e18;

int N,L,R;
int C[200001];
int lcnt[200001],rcnt[200001];

void solve(){

  cin>>N>>L>>R;

  for (int i=1;i<=N;i++){
    lcnt[i]=0;
    rcnt[i]=0;
  }

  for (int i=1;i<=N;i++){
    cin>>C[i];
    if (i<=L)
      lcnt[C[i]]++;
    else
      rcnt[C[i]]++;
  }

  //remove pairs that are already matching
  for (int i=1;i<=N;i++){
    int mn=min(lcnt[i],rcnt[i]);
    lcnt[i]-=mn;
    rcnt[i]-=mn;
    L-=mn;
    R-=mn;
  }
  if (L<R){
    swap(lcnt,rcnt);
    swap(L,R);
  }

  //now, there are at least as many left socks as right socks ( L >= R )
  int ans=0;
  for (int i=1;i<=N;i++){
    int extra=L-R; //always even
    int canDo=lcnt[i]/2;
    int Do=min(canDo*2,extra);
    //turn "Do"/2 left socks of color i into right socks
    ans+=Do/2;
    L-=Do;
  }
  //turn extra lefts into rights, then adjust all colors
  ans+=(L-R)/2+(L+R)/2;
  cout<<ans<<endl;
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