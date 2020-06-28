#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int l = 0, r = n-1;
	for(int i=0; i<n; i++) {
		if(i & 1) b[i] = a[l++];
		else b[i] = a[r--];
	}
	if(b[0] <= 0) {
		// cout << b[0] << " ";
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i=0; i<n; i++) {
		cout << b[i] << " ";
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