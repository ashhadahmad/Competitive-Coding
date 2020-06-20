#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Documents/Codes/input.txt", "r", stdin);
	freopen("/Users/mac/Documents/Codes/output.txt", "w", stdout);
	#endif	
}

void solve() {
	int n;
	cin >> n;
	if((n >> 1) & 1) {
		cout << "NO\n"; return;
	}
	else{
		cout << "YES\n";
		for(int i=1; i<=n/2; i++) cout << 2 * i << " ";
		for(int i=1; i<n/2; i++) cout << 2 * i - 1 << " ";
		cout << (3*n-2)/2 << endl;
		return;
	}
}

using namespace std;
int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}