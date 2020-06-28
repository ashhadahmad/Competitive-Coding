#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int>	a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	map<ll, ll> mp;
	ll maxEl = 0;
	for(int i=0; i<n; i++) {
		int rem = (a[i] % k);
		if(rem == 0) continue;
		rem = k - rem;
		if(mp[rem] == 0) mp[rem] = rem;
		else mp[rem] = (k + mp[rem]);
		maxEl = max(maxEl, mp[rem]);
	}
	if(maxEl == 0) cout << 0 << "\n";
	else cout << maxEl + 1 << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}