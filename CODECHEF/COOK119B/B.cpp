#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	vector<int> a(n);
	int count = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		if(a[i] > k) count++;
		else mp[a[i]]++;
	}
	for(int i=1; i<k; i++) {
		if(mp[i] == 0) {
			cout << "-1\n";
			return;
		}
		else {
			count += mp[i];
		}
	}
	cout << count << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}