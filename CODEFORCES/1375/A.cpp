#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		x = abs(x);
		if(i&1) cout << -x << " ";
		else cout << x << " ";
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