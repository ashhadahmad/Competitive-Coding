#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	ll n,x;
	cin >> n >> x;
	ll ans = 0;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		ans += max(0, num - x);
	}
	cout << ans << endl;
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