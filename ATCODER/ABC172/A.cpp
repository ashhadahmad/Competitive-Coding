#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll a;
	cin >> a;
	cout << a + (a * a) + (a * a * a); 
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}