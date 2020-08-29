#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	int ans = 0;
	for(int i=0; i < m-1; i++) {
		if(v[n-1][i] != 'R') ++ans;
	}
	for(int i=0; i<n-1; i++) {
		if(v[i][m-1] != 'D') ++ans;
	}
	cout << ans << '\n';
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}