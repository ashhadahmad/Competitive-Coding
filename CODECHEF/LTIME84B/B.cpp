#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

//https://www.codechef.com/LTIME84B/problems/LOSTWKND

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	ll n, p;
	n = 5; 
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> p;
	ll curWork = 0;
	for(int i=0; i<n; i++){
		curWork += (p * a[i]);
	}
	if(curWork > 120) cout << "Yes\n";
	else cout << "No\n";
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