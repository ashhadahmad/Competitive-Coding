#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
// SORTING VASES
void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void dfs(vector<vector<int> > &adj, int current_node, int superior_node, vector<int> &superior, vector<bool> &vis){
	vis[current_node] = true;
	superior[current_node] = superior_node;
	for(int new_node: adj[current_node]){
		if(!vis[new_node]) dfs(adj,new_node,superior_node,superior,vis);
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1);
	vector<int> whereIs(n+1);
	vector<vector<int> > adj(n+1);
	vector<int> superior(n+1, -1);
	vector<bool> vis1(n+1, false);
	vector<bool> vis(n+1, false);

	for(int i=1; i<=n; i++) {
		cin >> a[i];
		whereIs[a[i]] = i;
	}
	while(m--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1; i<=n; i++){
		if(!vis1[i]) dfs(adj,i,i,superior,vis1);
	}

	for(int i=1; i<=n; i++){
		if(a[i] == i) continue;
		else{
			int j = 1;
			bool use = false;
			for(; j<=n; j++){
				if(a[j] == i) {
					use = true;
					break;
				}
			}
			if(use){
				if(superior[i] == superior[j]){
					swap(a[i], a[j]);
				}				
			}
		}
	}
	
	int ans = 0;
	for(int i=1; i<n; i++){
		if(vis[i] || a[i] == i) continue;
		int j = a[i];
		int count = 0;
		vis[i] = true;
		while(!vis[j]){
			vis[j] = true;
			j = a[j];
			++count;
		}
		ans += count; 
	}
	cout << ans << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}