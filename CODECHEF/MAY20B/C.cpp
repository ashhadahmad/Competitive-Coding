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
	ll x,y,l,r;
	cin >> x >> y >> l >> r;
	ll ans = 0;
	for(int i=62; i>=0; i--){
		if((x & (1 << i)) || (y & (1 << i))){
			ans |= (1 << i);
		}
	}
	cout << ans << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}