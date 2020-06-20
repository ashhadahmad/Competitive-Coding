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
	int n;
	cin >> n;
	int ans = 0;
	ans += (n-1) / 2;
	cout << ans << "\n";

	for(ll i = 2; i <= n; i *= 2){
		if(i == n) {
			cout << "-1\n";
			return;
		}
		else{
			ans += i + 1;
			
		}
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