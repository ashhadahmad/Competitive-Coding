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
	ll n,m;
	cin >> n >> m;
	ll ans;
	if(n == 1 && m == 1) {
		cout << 1 << endl;
		return;
	}
	if(n == 1){
		cout << ((m+1) >> 1)  << endl;
		return;
	}
	if(m == 1){
		cout << ((n+1) >> 1) << endl;
		return;
	}
	if(m & 1){
		cout << n * ((m-1) >> 1) + ((n + 1) >> 1) << endl; 
		return;
	}
	else{
		cout << n * (m >> 1) << endl;
		return;
	}
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