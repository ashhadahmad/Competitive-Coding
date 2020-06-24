#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int X = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		X ^= a[i];
	}
	for(int i=0; i<n; i++) {
		cout << (X^a[i]) << " ";
	}
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}