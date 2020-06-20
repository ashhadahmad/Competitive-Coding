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
	int n;
	cin >> n;
	ll ans1 = 0;
	ll ans2 = 0;
	for(int i=1; i<n/2; i++){
		ans1 += (1 << i);
	}

	for(int i=n/2; i<n; i++){
		ans2 += (1 << i);
	}
	ans1 += (1 << n);
	cout << ans1 - ans2 << endl;

}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}