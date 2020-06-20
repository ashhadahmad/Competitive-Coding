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
	int odd = 0, even = 0;
	for(auto x: a){
		odd += (x&1);
		even += ((x&1)^1);
	}
	if(even % 2 == 0 && odd % 2 == 0){
		cout << "YES\n";
		return;
	}
	map<int, int> mp;
	for(auto x: a){
		if(mp[x-1] || mp[x+1]) {
			cout << "YES\n";
			return;
		}
		mp[x]++;
	}
	cout << "NO\n";
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