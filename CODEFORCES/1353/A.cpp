//https://codeforces.com/contest/1353/problem/A
#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

// void lol(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif	
// }

void solve(){
	ll n, m;
	cin >> n >> m;
	if(n == 1) cout << 0 << endl;
	else if(n == 2) cout << m << endl;
	else cout << 2 * m << endl;
}

int main(){
	FAST(); 
	// lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}