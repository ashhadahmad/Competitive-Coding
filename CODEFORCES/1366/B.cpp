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
	ll n, x, m;
	cin >> n >> x >> m;
	ll bestl = n + 1, bestr = 0;
	bool use = false;
	for(int i=0; i<m; i++){
		ll li, ri;
		cin >> li >> ri;
		if(li <= x && ri >= x){
			bestl = min(bestl, li);
			bestr = max(bestr, ri);
		}
		else if(li > bestr || ri < bestl) continue;
		else{
			bestl = min(bestl, li);
			bestr = max(bestr, ri);
		}
	}
	if(bestr == 0) {
		cout << "1\n";
		return;
	}
	else {
		cout << bestr - bestl + 1 << "\n";
		return;
	}
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