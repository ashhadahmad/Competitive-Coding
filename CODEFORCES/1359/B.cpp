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
	ll n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<string> a(n);

	for(ll i=0; i<n; i++) cin >> a[i];
	ll ans = 0;

	for(ll i=0; i<n; i++){
		ll cur_len = 0;
		for(ll j=0; j<m; j++){
			if(a[i][j] == '*'){
				if(cur_len & 1){
					ans += x;
					--cur_len;
					ans += min(cur_len * x, y * (cur_len >> 1));
				}
				else{
					ans += min(cur_len * x, y * (cur_len >> 1));
				}
				cur_len = 0;
			}
			else{
				cur_len++;
			}
		}
		if(cur_len & 1){
			ans += x;
			--cur_len;
			ans += min(cur_len * x, y * (cur_len >> 1));
		}
		else{
			ans += min(cur_len * x, y * (cur_len >> 1));
		}
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