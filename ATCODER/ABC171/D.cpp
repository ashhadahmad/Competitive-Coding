#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	ll sum = 0;
	map<int, int> mp;
	for(int i=0; i<n; i++) {
		sum += a[i];
		mp[a[i]]++;
	}
	// cout << sum << endl;
	int q;
	cin >> q;
	while(q--){
		int x, y; 
		cin >> x >> y;
		sum += (mp[x] * (y-x));
		cout << sum << '\n';
		if(x != y) mp[y] += mp[x];
		mp[x] = 0;
	}
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}