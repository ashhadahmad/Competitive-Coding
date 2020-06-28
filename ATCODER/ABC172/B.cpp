#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int ans = 0;
	string a, b;
	cin >> a >> b;
	for(int i=0; i<(int) a.size(); i++) {
		ans += (a[i] != b[i]);
	}
	cout << ans;
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}