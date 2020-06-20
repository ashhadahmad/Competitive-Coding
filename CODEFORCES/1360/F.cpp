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

bool isok(vector<string> ip, string ans){
	for(int i=1; i<ip.size(); i++){
		int diff = 0;
		for(int j=0; j<ip[i].size(); j++){
			if(ans[j] != ip[i][j]) ++diff;
		}
		if(diff > 1) return false;
	}
	return true;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> ip(n);
	for(int i=0; i<n; i++) cin >> ip[i];

	string ans = ip[0];
	if(isok(ip, ans)){
		cout << ans << "\n";
		return;
	}
	for(int i=0; i<m; i++){
		for(char c = 'a'; c <= 'z'; c++){
			ans[i] = c;
			if(isok(ip, ans)){
				cout << ans << "\n";
				return;
			}
		}
		ans[i] = ip[0][i];
	}

	cout << "-1\n";
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