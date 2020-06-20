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
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<int> ans(n);
	int use = 0;
	priority_queue<int> pq;
	map<int, bool> mp;
	for(int i=0; i<n; i++) mp[a[i]] = i;
	
	for(int i=0; i<n; i++){

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