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

ll countTwo(ll &a){
	ll count = 0;
	while(a % 2 == 0){
		a /= 2;
		count++;
	}
	return count;
}

void solve(){
	ll a, b;
	cin >> a >> b;
	ll c = countTwo(a);
	ll d = countTwo(b);
	if(a != b){
		cout << "-1\n";
		return;
	}
	int diff = max(c,d) - min(c,d);
	int ans = 0;
	while(diff >= 3) diff -= 3, ++ans;
	while(diff >= 2) diff -= 2, ++ans;
	while(diff >= 1) diff -= 1, ++ans;
	cout << ans << "\n";
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