#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll n) {
	ll ans = 1; 
	for(ll i = 1; i <= n; i++) ans *= i;
	return ans;
}

ll nCr(ll n, ll r){
	ll num = fact(n);
	ll den1 = fact(n-r);
	ll den2 = fact(r);
	
	return num / (den1 * den2);
}

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(ll i=0; i<n; i++) cin >> a[i];
	vector<ll> bits(32);
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<32; j++) {
			bits[j] += ((a[i] >> j) & 1);
		}
	}

	vector<ll> vi;
	map<ll, ll> mp;

	for(ll i=0; i<32; i++) {
		if(bits[i] > 0) mp[bits[i] * (1LL << i)]++;
	}

	for(auto x: mp) {
		vi.push_back(x.first);
	}

	sort(vi.begin(), vi.end(), greater<ll>());

	for(auto val: vi) {
		if(x == 0) {
			cout << "1\n";
			return;
		}
		if(mp[val] <= x){
			x -= mp[val];
			if(x == 0) {
				cout << "1\n";
				return;
			}
		}
		else{
			cout << nCr(mp[val], x) << "\n";
			return;
		}
	}

	cout << "-1\n";
	return;
}

int main(){
	int t; 
	cin >> t; 
	while(t--){
		solve();
	}
	return 0;
}