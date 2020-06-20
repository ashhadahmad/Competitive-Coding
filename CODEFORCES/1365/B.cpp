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
	for(auto &x: a) cin >> x;
	for(auto &x: b) cin >> x;
	bool sorted = true;
	for(int i=1; i<n; i++){
		if(a[i] >= a[i-1]) continue;
		else {
			sorted = false;
			break;
		}
	}
	if(sorted) {
		cout << "Yes\n";
		return;
	}
	bool zero = false, one = false;
	for(int i=0; i<n; i++){
		zero |= b[i] == 0;
		one  |= b[i] == 1;
	}
	if(one && zero) cout << "Yes\n";
	else cout << "No\n";
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