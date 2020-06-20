#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ld long double


void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

ll h,c,t;

ld calc(ll x){
	ld hot = h * x;
	ld cold = c * (x-1);
	ld ans = (hot + cold) / ((ld) x + x - 1);
	return ans;
}

void solve(){
	cin >> h >> c >> t;
	if(t >= h) {
		cout << "1\n";
		return;
	}
	if(t <= ((h + c) / 2)) {
		cout << "2\n";
		return;
	}

	ll bestX = (t - c) / (2 * t - h - c);

	ld ans1 = calc(bestX);
	ld ans2 = calc(bestX + 1);

	if(abs(ans1 - t) <= abs(ans2 - t)) {
		cout << 2 * bestX - 1 << "\n";
	}
	else cout << 2 * bestX + 1 << "\n";
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