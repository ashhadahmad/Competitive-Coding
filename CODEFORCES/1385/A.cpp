#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int x, y, z;
	cin >> x >> y >> z;
	int mx = max({x,y,z});
	int mn = min({x,y,z});
	if(x == y && x >= z || y == z && y >= x || x == z && x >= y) {
		cout << "YES\n";
		cout << mx << " " << mn << " " << 1 << '\n';
	}
	else {
		cout << "NO\n";
	}
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}