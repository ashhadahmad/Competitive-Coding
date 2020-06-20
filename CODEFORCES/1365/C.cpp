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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	map<int, int> mp;
	for(int i=0; i<n; i++) mp[a[i]] = i;
	map<int, int> diff; 
	for(int i=0; i<n; i++){
		int cur_diff = (mp[b[i]] - i + n) % n;
		diff[cur_diff]++;
	}
	int best_ans = 0;
	for(auto x: diff){
		best_ans = max(best_ans, x.second);
	}
	cout << best_ans << "\n";
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