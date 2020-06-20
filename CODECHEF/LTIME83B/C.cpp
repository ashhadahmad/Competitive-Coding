#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}
// Positive Mex

const int mod = 998244353;

ll powmod(int x, unsigned int y, int p) {  
    ll res = 1;
    x = x % p;   
    if (x == 0) return 0;
    while (y > 0)  
    {  
        if (y & 1) res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(auto &x: a) cin >> x;
	vector<int> temp;
	ll ans = 0;
	ans += powmod(2, n, mod);
	ll ones = 0;
	ll twos = 0;
	for(auto x: a) ones += x == 1, twos += x == 2;

	ll ways_ones = powmod(2, ones, mod) - 1;
	ll ways_twos = powmod(2, twos, mod) - 1;
	ll left = n - ones - twos;
	ans = (ans + ways_ones%mod * powmod(2, left, mod)%mod)%mod;
	if(ans > mod) ans %= mod;
	ans += 2 * ((((ways_ones%mod) * (ways_twos)%mod))%mod * powmod(2, left, mod))%mod; 
	ans = ans % mod;
	cout << ans << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}