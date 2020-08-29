#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll f(int n) {
	if(n == 1) return 1;
	int ans = 0;
	for(int i=2; i<=9; i++) {
		if(n % i == 0) ans += f(n/i);
	}
	return ans;
}
 
void solve() {
	int n;
	cin >> n;
	if(n == 1) cout << 0;
	else cout << f(n) << '\n';
}
 
int main(){
	int t = 1; 
	// cin >> t; 
	while(t--){
		solve();
	}
	return 0;
}
