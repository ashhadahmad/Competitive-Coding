#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll v,c,n,m;
	bool ans = true;
	cin >> v >> c >> n >> m;
	if(v <= c) {
		v -= m;
	}
	else {
		c -= m;
	}
	if(v < 0 || c < 0) ans = false;
	if((v + c) < n) ans = false;
	if(ans) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}