#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) a.push_back(a[i]);
	n *= 2;
	ll cur_long_sum = 0;
	ll ans = 0;
	ll i = 0, j = 0;
	ll cur_sum = 0;
	while(j < n){
		cur_sum += a[j];
		cur_long_sum += ((a[j] * (a[j] + 1)) >> 1);
		j++;
		while(cur_sum >= k){
			if(cur_sum - a[i] < k) {
				ll diff = cur_sum - k;
				ll diff_sq = ((diff * (diff + 1)) >> 1);
				ans = max(ans, cur_long_sum - diff_sq);
			}
			cur_long_sum -= ((a[i] * (a[i] + 1)) >> 1);
			cur_sum -= a[i];
			i++;
		}
	}
	cout << ans << endl;
}

int main(){
	FASTIO(); 
	localIO();
	int t = 1; 
	// cin >> t;
	while(t--) 
		// t++;
		solve();
	return 0;
}