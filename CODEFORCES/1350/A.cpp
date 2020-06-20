#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n, k;
	cin >> n >> k;
	if(n&1){
		int p = 3;
		for(; p <= n; p+=2){
			if(n%p == 0) break;
		}
		int ans = n + p;
		ans += (2 * (k-1));
		cout << ans << endl;
		return;
	}
	else{
		int ans = n;
		ans += (k * 2);
		cout << ans << endl;
		return;
	}
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}