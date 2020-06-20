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
	int n, m, k;
	cin >> n;
	m = (n+1) >> 1;
	vector<int> a(m);
	for(int i=0; i<m; i++) cin >> a[i];
	cin >> k;
	ll sum = 0;
	for(int i=0; i<m; i++) sum += a[i];
	sum += (n-m) * k;
	if(sum > 0) {
		cout << n << endl;
		return;
	}
	bool g0 = false;
	for(int i=0; i<n; i++){
		if(a[i] > 0) g0 = true;
	}
	if(!g0 && k < 0){
		cout << -1 << endl;
		return;
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