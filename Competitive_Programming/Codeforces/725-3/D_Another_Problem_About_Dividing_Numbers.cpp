#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long                                   // Comment it out if default `int` is req. 
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define decimal(x) cout << fixed << setprecision(x)
#define fr(i,a,b) for(int (i)=(a) ; (i) <= (b) ; ++(i))
#define frr(i,a,b) for(int (i)=(a) ; (i) >= (b) ; --(i))
#define trav(ele,container) for(auto (ele): (container)) // Just gives a copy of the elements.
#define tra(ele,container) for(auto& (ele): (container)) // Gives the reference to the elements.
#define lbd(a,x) lower_bound(all((a)),(x)) - (a).begin()
#define ubd(a,x) upper_bound(all((a)),(x)) - (a).begin()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << " = " << x << "  ,  " << #y << "=" << y << "  ,  " << #z << "=" << z << endl
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
using namespace std;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<pi>	vpi;
typedef vector<int> vi;
typedef vector<vi>	vvi;
typedef priority_queue<int> prq;                          
const int M = 1e9 + 7;
const int INF = 1e18;
template <typename T> using min_prq = priority_queue<T, vector<T>, greater<T>>;   
//-----------------------------------------------------------------------------------------------------//
bool is_prime(int n){ 
    if (n < 2) return false;
    for(int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}    

vi prime_factors(int n){
    vi res;
    for(int i = 2; i*i <= n; i++){
        while (n % i == 0){
            res.pb(i);
            n /= i;  
        }
    }
    if (n > 1) res.pb(n);
    return res;
}

vi sieve_erato(int n){
    /*sieve[k]  = 0  -> k is prime
      sieve[k] != 0  -> k is not a prime & one of its prime factors is sieve[k].*/
    vi sieve(n+1);
    fr(i,2,n){
        if (sieve[i]) continue;
        for(int j = 2*i; j <= n; j+=i ){
            sieve[j] = i;
        }
    }
    return sieve;
}

int gcd(int a, int b){
    int c;
    while (b){
        c = b; 
        b = a % b;
        a = c;
    }
    return a;
}

int modpow(int a, int p = M-2, int MOD = M ){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return result;
}
//-----------------------------------------------------------------------------------------------------//

vi allp;

int get_exp_cnt(int x){
   
  int temp_x = x;
  int ans = 0;

  // Now for a given x, To find the sum of exponents count in its prime factors,
  // We start iterating over the numbers till sqrt(x) and if it is a Prime & if it divides the current number,
  // We calculate the exponent.
  for (int i = 2; i*i <= x; i++){
    if (allp[i] == 0){
        while ( temp_x % i == 0 ){
          ans++;
          temp_x /= i;
        }
    }
  }

  // If the number is still > 1, We can add one more value to the count. To understand this take an example & workout.
  if (temp_x > 1){
    ans++;
  }

  return ans;
}


void solve() {
  int a,b,k; cin >> a >> b >> k;

  // n = sum of exponents of prime divisors of a + sum of exponents of prime divisors of b.
  int n = get_exp_cnt(a) + get_exp_cnt(b);

  int m;
  if (a == b){
    m = 0;
  }
  else if (gcd(a,b) == a or gcd(a,b) == b){
    m = 1;
  }
  else{
    m = 2;
  }

  if (k == 1 and m == 1  and k <= n and m <= k){
    cout << "YES";
  } 
  else if (k <= n and m <= k and k != 1){
    cout << "YES";
  }
  else{
    cout << "NO";
  }


}

signed main() {
    
    // Since the Maximum value of a Number in the Input is 1e9, 
    // We just need to account for sqrt(1e9) becoz, The Prime Factors of a number can be found within sqrt(n) range.
    allp = sieve_erato(1e5 + 5);

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