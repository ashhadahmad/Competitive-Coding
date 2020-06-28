#include<bits/stdc++.h>
using namespace std;

// https://www.codechef.com/LTIME85A/problems/MAXAND18

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
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
	map<ll, vector<int> > mp;
 
	for(ll i=0; i<32; i++) {
		if(bits[i] > 0) mp[bits[i] * (1LL << i)].push_back(i);
	}
 
	for(auto x: mp) {
		vi.push_back(x.first);
	}
 
	sort(vi.begin(), vi.end(), greater<ll>());

	ll ans = 0;

	for(auto el: vi) {
		auto vec = mp[el];
		if(x <= vec.size()) {
			sort(vec.begin(), vec.end());
			for(int i=0; i<x; i++) {
				int j = vec[i];
				ans = (ans | (1 << j));
			}
			x = 0;
			break;
		}
		else {
			x -= vec.size();
			for(auto j: vec) {
				ans = (ans | (1 << j));
			}
		}
	}

	for(int i=0; i<32; i++) {
		if(ans & (1LL << i)) continue;
		else {
			if(x){
				ans = ans | (1 << i);
				x--;
			}
		}
	}

	cout << ans << "\n";

}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}