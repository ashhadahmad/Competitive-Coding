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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ans = 0;
	int new_sleep = max(0, c-d);
	if(a <= b) {cout << b << endl; return;}
	ans = b;
	a -= b;
	// cout << ans << endl;
	// cout << ceil((a/new_sleep)) * c << endl;
	if(new_sleep == 0) {cout << "-1\n"; return;}
	ans += ceil((double)a/new_sleep) * c;
	cout << ans << endl;
}


int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}