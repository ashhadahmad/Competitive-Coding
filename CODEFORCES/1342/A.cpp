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

void solve() {
	ll x, y, a, b;
	cin >> x >> y >> a >>  b;

	ll ans1 = a * (x + y);
	ll ans2 = b * min(x,y) + a * (abs(x-y));

	cout << min(ans1, ans2) << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}