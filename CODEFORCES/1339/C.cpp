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

using namespace std;
int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		ll n; cin >> n;
		vector<ll> a(n);
		for(auto &x: a) cin >> x;
		ll mx = -1e9-1;
		ll ans = 0;
		for(auto x: a){
			mx = max(mx, x);
			ll dif = mx - x;
			// cout << dif << " ";
			if(dif > 0){
				for(ll i=0; i<=31; i++){
					ll num = (1 << i);
					if(num & dif) ans = max(ans, i + 1);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}