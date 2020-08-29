#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const int MOD = 1e9+7;

unsigned long long power(unsigned long long x, ll y, ll p) { 
	unsigned long long res = 1;
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
}

void solve(){
	int n;
	cin >> n;
	ll fact = 1;
	for(int i=1; i<=n; i++) {
		fact *= i;
		fact = fact % MOD;
	}
	ll pow2n = power(2, n-1, MOD);
	cout << (fact - pow2n + MOD) % MOD;
	// cout << ((modFact(n,MOD) % MOD - (power(2, n-1, MOD)-1 + MOD)%MOD) + MOD) % MOD;
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}