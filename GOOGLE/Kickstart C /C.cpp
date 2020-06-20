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
	int n;
	cin >> n;
	int mxsq = 3164;
	vector<int> sqar(mxsq);
	for(int i=0; i<mxsq; i++) sqar[i] = i*i;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	int cur_sum = 0, ans = 0;
	map<int, int> mp;
	mp[0]++;
	for(int i=0; i<n; i++){
		cur_sum += a[i];
		for(int i=0; i<mxsq; i++){
			ans += mp[cur_sum - sqar[i]];
		}
		++mp[cur_sum];
	}
	cout << ans << endl;
}

int main(){
	// FAST(); 
	// lol();
	int t; cin >> t;
	for(int i=1; i<=t; i++) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}