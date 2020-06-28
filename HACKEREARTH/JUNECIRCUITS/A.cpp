#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
	int n, b1, b2;
	cin >> n >> b1 >> b2;
	ll ans = 0;
	for(int i=1; i<=n; i++) {
		int l = i-1;
		if(i == 1) l = n;
		int r = i+1;
		if(i == n) r = 1;
		if(i != b1 && l != b1 && i != b2 && l != b2){
			ans += (n - 4);
			if(r != b1 && r != b2) {
				ans--;
			}
		}
 
		// cout << i << l << r << endl;
		// cout << ans << endl;
	}
	cout << ans << "\n";
}
 
int main(){
	int t; 
	cin >> t; 
	while(t--){
		solve();
	}
	return 0;
}