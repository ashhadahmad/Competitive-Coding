#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

//Another Birthday Present!

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}


void solve(){
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll> > a(n);
	for(ll i=0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());
	// cout << "------\n";
	// for(ll i=0; i<n; i++){
		// printf("%d -> %d, %d\n",i,a[i].first,a[i].second);
	// }

	map<ll, ll> mp;
	for(int i=0; i<n; i++){
		mp[a[i].first] += abs(a[i].second - i);
	}
	for(auto p: mp){
		if(p.second % k == 0) continue;
		else {cout << "no\n"; return;}
	}
	cout << "yes\n";
	return;
}


int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}