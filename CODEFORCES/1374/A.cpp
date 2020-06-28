#include<bits/stdc++.h>
using namespace std;

// GOT HACKED :(

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll x, y, n;
	cin >> x >> y >> n;
	while(y + x <= n) y += x;
	cout << y << endl;
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}