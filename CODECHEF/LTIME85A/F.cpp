#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll s, n;
	cin >> s >> n;
	ll ans = 0;
	if(s % 2 == 0) ans++, s--;
	ans += ceil(s / n);
	cout << (ll) ans << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}