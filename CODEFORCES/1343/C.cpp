#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Documents/Codes/input.txt", "r", stdin);
	freopen("/Users/mac/Documents/Codes/output.txt", "w", stdout);
	#endif	
}

void solve(){
	ll n; cin >> n;
	vector<ll> a(n);
	for(ll i=0; i<n; i++) cin >> a[i];
	vector<ll> v;
	ll cur_pos = 0, cur_neg = 0;

	for(ll i=0; i<n; i++){
		if(a[i] > 0){
			if(cur_neg < 0) {
				v.push_back(cur_neg);
				cur_neg = 0;
			}
			cur_pos = max(cur_pos, a[i]);
		}

		if(a[i] < 0){
			if(cur_pos > 0) {
				v.push_back(cur_pos);
				cur_pos = 0;
			}
			if(cur_neg == 0) cur_neg = a[i];
			else cur_neg = max(cur_neg, a[i]);
		}	
	}

	if(cur_pos > 0) v.push_back(cur_pos);
	if(cur_neg < 0) v.push_back(cur_neg);

	ll sum = 0;
	for(auto x: v) sum += x;
	cout << sum << endl;
	
}

using namespace std;
int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}