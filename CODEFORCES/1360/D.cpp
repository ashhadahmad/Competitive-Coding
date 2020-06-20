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
	ll a,b;
	cin >> a >> b;
	set<int> s;
	for(ll i=1; i*i <= a; i++){
		if(a % i == 0) {
			s.insert(i);
			s.insert(a/i);
		}
	}
	ll ans = INT_MAX;
	for(auto el: s){
		if(el <= b){
			ans = a/el;
		}
		else break;
	}
	cout << ans << "\n";
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