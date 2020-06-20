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

pair<bool, vector<ll> > check(ll mid, ll n){
	ll valInCell = mid / 10;
	vector<ll> a(10,valInCell);
	ll valLeft = mid % 10;
	ll i = 0;
	while(valLeft--){
		a[i++]++;
	}
	ll mul = 1;
	for(ll i = 0; i < 10; i++){
		mul *= a[i];
	}
	if(mul >= n) return make_pair(true, a);
	return make_pair(false,a);
}

void solve(){
	ll n;
	cin >> n;

	vector<ll> ans;

	ll l = 10, r = (ll) 1002;

	while(l <= r){

		ll mid = (l + r) >> 1;
		auto temp = check(mid, n);
		
		if(temp.first == true) {
			ans = temp.second;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	string s = "codeforces";

	for(int i=0; i<10; i++){
		for(int j=0; j<ans[i]; j++){
			cout << s[i];
		}
	}
}

int main(){
	FASTIO(); 
	localIO();
	int t = 1; 
	// cin >> t;
	while(t--) 
		solve();
	return 0;
}