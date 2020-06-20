#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

// https://www.codechef.com/LTIME84B/problems/WWALK

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	ll prevA = 0, prevB = 0, ans = 0;
	for(int i=0; i<n; i++){
		if(prevA == prevB && a[i] == b[i]) ans += a[i];
		prevA += a[i];
		prevB += b[i];
	}
	cout << ans << "\n";
}

int main(){
	FASTIO(); 
	localIO();
	int t; 
	cin >> t;
	while(t--) 
		solve();
	return 0;
}