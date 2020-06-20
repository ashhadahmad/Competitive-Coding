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
	int n, k;
	cin >> n >> k;
	int odd = 0, even = 0;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		if(x&1) odd++;
		else even++;
	}
	for(int i=1; i<=k; i+=2){
		if(i <= odd && k-i <= even) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
	return;
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