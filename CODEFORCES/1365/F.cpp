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
	vector<int> b(n);
	for(auto &x: a) cin >> x;
	for(auto &x: b) cin >> x;
	map<int, int> mp;
	for(auto x: a) mp[x]++;
	for(auto x: b){
		if(mp[x] >= 1) mp[x--];
		else{
			cout << "No\n";
			return;
		}
	}

	if(n&1){
		int mid = ((n-1) >> 1);
		if(a[mid] != b[mid]){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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