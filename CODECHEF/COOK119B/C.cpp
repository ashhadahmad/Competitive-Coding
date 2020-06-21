#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

// vector<int> dfs(int n, int st, vector<vector<int> > &adj, vector<bool> &bestIdx, vector<bool> &vis) {

// 	if(vis[st]){
// 		vector<int> temp;
// 		return temp;
// 	}

// 	vector<int> ans;
// 	ans.push_back(st);

// 	vis[st] = true;
	
// 	for(int x: adj[st]) {
// 		if(!vis[x] && bestIdx[x]) {
// 			vector<int> smallAns = dfs(n, x, adj, bestIdx, vis);
// 			for(auto el: smallAns) {
// 				ans.push_back(el);
// 			}
// 		}
// 	}

// 	return ans;
// }


void solve(){
	ll n, m; 
	cin >> n >> m;
	vector<ll> mon(n), pl(n);
	for(int i=0; i<n; i++) cin >> mon[i];
	for(int i=0; i<n; i++) cin >> pl[i];

	vector<vector<int>> adj(n);
	while(m--){
		int x, y;
		cin >> x >> y;
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int best = 0;
	for(int i=0; i<n; i++) {
		if(mon[best] * pl[i] < mon[i] * pl[best]) {
			best = i;
		}
	}

	vector<bool> bestIdx(n,false);

	for(int i=0; i<n; i++) {
		if(mon[best] * pl[i] == mon[i] * pl[best]) bestIdx[i] = true;
	}

	vector<bool> vis(n, false);

	vector<int> ans;

	for(int i=0; i<n; i++) {
		if(!vis[i] && bestIdx[i]) {
			vector<int> tempAns;
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int st = q.front();
				q.pop();
				tempAns.push_back(st);
				vis[st] = true;
				for(auto x: adj[st]) {
					if(!vis[x] && bestIdx[x]) {
						q.push(x);
						vis[x] = true;						
					}
				}
			}
			if(tempAns.size() > ans.size()) ans = tempAns;
		}
	}

	cout << ans.size() << endl;
	for(auto x: ans) cout << x + 1 << " ";
	cout << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}