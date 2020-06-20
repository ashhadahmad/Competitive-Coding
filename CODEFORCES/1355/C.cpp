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

const int mxn = 1e7;
ll prefix[mxn];

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for(int i=a; i<=b; i++){
		++prefix[i + b];
		--prefix[i+c+1];
	}
	for(int i=1; i<mxn; i++){
		prefix[i] += prefix[i-1];
	}
	for(int i=mxn-2; i>=0; i--) {
		prefix[i] += prefix[i+1];
	}

	// for(int i=0; i<10; i++) cout << prefix[i] << " ";
	ll ans = 0;
	for(int i=c; i<=d; i++) {
		ans += prefix[i+1];
	}
	cout << ans << endl;
}

int main(){
	FAST(); 
	lol();
	int t = 1; 
	// cin >> t; 
	while(t--) solve();
	return 0;
}