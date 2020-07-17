#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	n += n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	map<int, bool> mp;
	for(int i=0; i<n; i++) {
		if(mp[a[i]]) continue;
		else {
			cout << a[i] << " ";
			mp[a[i]] = true;
		}
	}
	cout << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}