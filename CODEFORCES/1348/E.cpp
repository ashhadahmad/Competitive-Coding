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
	ll n,k;
	cin >> n >> k;
	vector<pair<ll,ll> > v(n);
	for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
	vector<ll> ssum(n,0);
	ll red = 0, blue = 0, ans = 0;
	for(int i=0; i<n; i++){
		red += v[i].first;
		blue += v[i].second;
		ssum[i] = v[i].first + v[i].second;
	}
	
	ans += red / k;
	red = red % k;
	ans += blue / k;
	blue = blue % k;

	if(red + blue >= k){
		for(int i=0; i<n; i++){
			if(v[i].first <= red && v[i].second <= blue){

				++ans;
				break;
			}
		}
	}

	cout << ans;
}

int main(){
	FAST(); 
	lol();
	solve();
	return 0;
}