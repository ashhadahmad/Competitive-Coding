#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll n, x;
	cin >> n >> x;
	vector<ll> pre(1, 0);
	for(int i=0; i<n; i++) {
		int x; 
		cin >> x;
		pre.push_back(pre[i] + x);
	}
	ll ans = 0;
	for(int k=1; k <= n; k++) {
		map<ll, int> mp;
		for(int i=k; i<=n; i++) {
			ll sub_sum = pre[i] - pre[i-k];
			sub_sum *= k;
			ans += (2 * mp[x - sub_sum]);
			mp[sub_sum]++;
			if(x == sub_sum + sub_sum) ans++;
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