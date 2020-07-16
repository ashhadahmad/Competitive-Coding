#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) if(a[i] % 2 == 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}