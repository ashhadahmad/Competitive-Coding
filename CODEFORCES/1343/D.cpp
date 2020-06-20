#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Documents/Codes/input.txt", "r", stdin);
	freopen("/Users/mac/Documents/Codes/output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n, k;
	cin >> n >> k; 
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<ll> range(k+k+2, 0);
	for(int i=0; i<n/2; i++){
		int min_val = min(a[i], a[n-1-i]);
		int max_val = max(a[i], a[n-1-i]);
		int min_range = min_val+1;
		int max_range = max_val+k;
		++range[min_range];
		--range[max_range+1];
	}
	for(int i=1; i<k+k+2; i++){
		range[i] += range[i-1];
	}

	vector<ll> store(k+k+1,0);
	for(int i=0; i<n/2; i++) store[a[i] + a[n-1-i]]++;

	ll ans = n;
	for(int i=2; i<=k+k; i++){
		ans = min(ans, n - range[i] - store[i]);
	}
	cout << ans << endl;
	return;
}
int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}