#include<bits/stdc++.h>
using namespace std;
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

bool dfs(int i, int j, vector<string>& store, vector<vector<bool> >&vis, int r, int c, char cur){
	if(i == r || j == c || i < 0 || j < 0 || vis[i][j]) return true;
	if(store[i][j] != cur) return true;
	vis[i][j] = true;
	bool a1 = dfs(i+1, j, store, vis,r,c,cur);
	bool a2 = dfs(i, j+1, store, vis,r,c,cur);
	bool a3 = dfs(i-1, j, store, vis,r,c,cur);
	bool a4 = dfs(i, j-1, store, vis,r,c,cur);
	if(!a1 || !a2 || !a3 || !a4) return false;
	if(i != r-1) {
		if(store[i+1][j] != cur && !vis[i+1][j]) return false;
		return true;
	}
	return true;
}

bool try_solve(int st, int r, int c, vector<string>&store){
	vector<vector<bool> > vis(r, vector<bool>(c, false));
	string ans = "";
	for(int i=r-1; i>=0; i--){
		for(int j=st; j>=0; j--){
			if(!vis[i][j]) {
				ans += store[i][j];
				bool temp = dfs(i,j,store,vis,r,c, store[i][j]);
				if(!temp) {
					return false;
				}
			}			
		}
		for(int j=st+1; j<c; j++){
			if(!vis[i][j]) {
				ans += store[i][j];
				bool temp = dfs(i,j,store,vis,r,c, store[i][j]);
				if(!temp) {
					return false;
				}
			}				
		}
	}
	cout << ans << endl;
	return true;
}

void solve(){
	int r, c;
	cin >> r >> c;
	vector<string> store(r);
	for(int i=0; i<r; i++) cin >> store[i];
	for(int i=0; i<c; i++) {
		if(try_solve(i,r,c,store))return;
	}
	cout << "-1\n";
	return;
}

int main(){
	// FAST(); 
	lol();
	int t; cin >> t;
	for(int i=1; i<=t; i++) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}