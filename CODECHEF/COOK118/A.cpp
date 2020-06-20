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
	int i = 0, j = 0, count = 0;
	map<int, int> used;
	map<int, int> counts;
	while(j < n){
		// cout << i << " " << j << endl;
		while(j < n && a[i] == a[j]){
			j++;
			count++;
		}
		counts[count]++;
		used[a[i]]++;
		i = j;
		count = 0;
	}
	for(auto x: used){
		if(x.second != 1) {
			cout << "NO\n";return;
		}
	}
	for(auto x: counts){
		if(x.second != 1) {
			cout << "NO\n";return;
		}
	}
	cout << "YES\n";
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