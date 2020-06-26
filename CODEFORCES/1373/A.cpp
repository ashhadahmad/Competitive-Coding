#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(a < c) {
		cout << "1 ";
	}
	else cout << "-1 ";
	if(a * b <= c) {
		cout << -1;
	}
	else cout << b;
	cout << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}