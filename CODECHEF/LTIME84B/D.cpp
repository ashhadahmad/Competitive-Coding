#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
// https://www.codechef.com/LTIME84B/problems/TREDIFF
void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

vector<int> getPath(int n, vector<vector<int>>&adj, int st, int en){
	vector<int> vis(n, -1);
	queue<int> q;
	vis[st] = st;
	q.push(st);

	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto next: adj[x]){
			if(vis[next] == -1){
				vis[next] = x;
				q.push(next);
			}
		}
	}

	vector<int> ans;
	ans.push_back(st); 
	int cur = en;
	while(vis[cur] != cur){
		ans.push_back(cur);
		cur = vis[cur];
	}
	return ans;
}

void solve(){
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<vector<int>> adj(n);
	for(int i=0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	while(q--){
		int x,y;
		cin >> x >> y;
		--x, --y;
		auto path = getPath(n,adj,x,y);
		vector<int> tmp;
		for(auto x: path) tmp.push_back(a[x]);
		sort(tmp.begin(), tmp.end());
		int ans = INT_MAX;
		// for(auto x: path) cout << x << " ";
		for(int i=1; i<tmp.size(); i++) ans = min(ans, tmp[i]-tmp[i-1]);
		cout << ans << "\n";
	}
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