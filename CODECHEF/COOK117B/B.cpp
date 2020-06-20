#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

const ll mod = 1e9+7;

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Documents/Codes/input.txt", "r", stdin);
	freopen("/Users/mac/Documents/Codes/output.txt", "w", stdout);
	#endif	
}

ll powmod(ll x, ll y, ll p) 
{ 
    ll res = 1;
  
    x = x % p;  
  
    while (y > 0) { 
        if (y & 1)  res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
} 


void solve(ll n, ll a){
	ll p = 1;
	long long ans = 0;
	long long cur = a;
	for(ll i=0; i<n; i++, p+=2){
		// cout << p << " " << cur << endl;
		ans += powmod(cur, p, mod);
		cur = powmod(cur, p+1, mod);
		// cout << ans << endl;
		if(ans > mod) ans -= mod; 
	}
	cout << ans << endl;
}

using namespace std;
int main(){
	FAST(); 
	lol();
	ll t; cin >> t; while(t--){
		ll n,a; cin >> n >> a;
		solve(n, a);
	}
	return 0;
}