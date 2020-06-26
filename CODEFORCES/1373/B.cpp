#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	string s;
	cin >> s;
	int z = 0, o = 0;
	for(auto x: s) {
		z += (x == '0');
		o += (x == '1');
	}
	if(min(z,o) & 1) cout << "DA\n";
	else cout << "NET\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}