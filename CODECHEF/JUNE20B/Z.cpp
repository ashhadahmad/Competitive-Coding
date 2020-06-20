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

int adj[26][26];
int cns[26];
bool vis[26];
int dp[26];

int getMaxAns(int st){
	if(dp[st] != -1) return dp[st];
	vis[st] = true;
	int tempans = 0;
	for(int i=0; i<26; i++){
		if(adj[st][i] && !vis[i]){
			tempans = max(tempans, getMaxAns(i));
		}
	}
	vis[st] = false;
	dp[st] = 1 + tempans;
	return dp[st];
}

void solve(){
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	memset(adj, 0, sizeof adj);
	memset(cns, 0, sizeof cns);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		adj[s[0] - 'a'][s[2]-'a'] = 1;
		adj[s[2] - 'a'][s[0]-'a'] = 1;
		cns[s[0] - 'a']++;
		cns[s[2] - 'a']++;
	}

	int ans = 0;

	for(int i = 0; i < 26; i++){
		if(cns[i] == 1){
			int tempans = getMaxAns(i);
			// cout << i << ":" << tempans << "\n";
			ans = max(ans, getMaxAns(i));
		}
	}

	cout << ans - 1 << "\n";
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