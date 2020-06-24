#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

const ll mod = (ll) 1000000007;

struct quad{
	ll c,o,l;
	quad() {
		c = o = l = 0;
	}
	quad(ll a,ll b, ll cl) {
		c = a;
		o = b;
		l = cl;
	}
};

quad f(ll n) {
	if(n == 1) {
		return quad(0,0,1);
	}

	quad smallAns = f(n-1);

	quad ans;
	ans.o = smallAns.l % mod;
	ans.c = (smallAns.o + smallAns.c) % mod;
	ans.l = (smallAns.l + (2 * smallAns.o)) % mod;
	return ans;
}

void solve(){
	ll n;
	cin >> n;

	quad ans = f(n);
	ll temp = ans.c;
	
	vector<int> store;

	int st = 1;
	bool chance = 0;
	ll f[2];
	while(true) {
		if(temp <= st) {
			f[chance] += temp;
		}
		else {
			f[chance] += st;
			chance ^= 1;
			
		}
	}

}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}