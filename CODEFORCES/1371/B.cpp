#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll n, r; 
	cin >> n >> r;
	ll ans = 0;
	if(n > r) {
		ans = ((r * (r+1)) >> 1);
	}
	else {
		ans = (n * (n-1) >> 1);
		ans++;
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