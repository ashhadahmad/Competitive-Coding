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
	string s;
	cin >> s;
	int ans = 0;
	int n = (int) s.size();
	vector<bool> isValid(n, true);
	for(int i=1; i<n; i++){
		char cur = s[i];
		char prev = s[i-1];
		if(cur != prev) {
			if(isValid[i-1]) {
				++ans;
				isValid[i] = false;
			}
		}
	}
	cout << ans << "\n";
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