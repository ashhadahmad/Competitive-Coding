#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	for(int i=0; i<k; i++) ans += a[i];
	cout << ans << "\n";
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}