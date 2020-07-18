#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> store;
	vector<vector<int>> adjU(n+1);
	vector<vector<int>> pre(n+1);
	vector<bool> vis(n+1, false);

	vector<int> out(n+1);
	while(m--) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type) {
			store.push_back(make_pair(x,y));
			out[x]++;
			pre[y].push_back(x);
		}
		else {
			adjU[x].push_back(y);
			adjU[y].push_back(x);
		}
	}

	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(out[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		vis[cur] = true;
		for(auto x: adjU[cur]){
			if(!vis[x]) {
				store.push_back(make_pair(x, cur));
			}
		}
		for(auto x: pre[cur]) {
			out[x]--;
			if(out[x] == 0) q.push(x);
		}
	}

	for(int i=1; i<=n; i++) {
		if(out[i] > 0) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	for(auto x: store) {
		cout << x.first << " " << x.second << '\n';
	}
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}