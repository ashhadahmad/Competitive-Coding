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

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll i=0; i<n; i++) cin >> a[i];
	vector<ll> peak(n,0);
	for(ll i=1; i<n; i++){
		peak[i] += peak[i-1];
		if(i != n-1 && i != 0) if(a[i] > a[i-1] && a[i] > a[i+1]) peak[i]++;
	}
	ll ans_idx = 0, ans_val = 0;
	for(ll i=0; i<n-k+1; i++){
		ll ri = i + k - 1;
		ll tempans = peak[ri-1] - peak[i];
		if(tempans > ans_val) ans_idx = i, ans_val = tempans;
	}
	cout << ans_val + 1 << " " << ans_idx + 1 << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}