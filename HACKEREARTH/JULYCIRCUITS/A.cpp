#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve() {
	ll a;
	cin >> a;
	cout << ((a * (a+1)) >> 1) + 1 << '\n';
}
 
int main(){
	int t; 
	cin >> t; 
	while(t--){
		solve();
	}
	return 0;
}