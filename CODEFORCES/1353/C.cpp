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
	ll n;
	cin >> n;
	vector<ll> ans(n+1);
	ans[0] = ans[1] = 0;
	for(ll i=2; i<=n; i++){
		if(n&1){
			ll num = 4 * (i-1);
			ans[i] = ans[i-2];
			ans[i] += (num * ((i - 1) >> 1));
		}
		else{
			ans[i] = ans[i-1];
			ll num = 2 * i - 1;
			ans[i] += (num * (i >> 1));
		}
	}

	cout << ans[n] << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}