#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int r, c; 
	cin >> r >> c;
	vector<string> v(r);
	for(int i=0; i<r; i++) cin >> v[i];
	vector<int> vis(26, -1);
	vector<vector<bool> > after(26, vector<bool>(26, false));
	vector<int> req(26, 0);

	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			vis[v[i][j] - 'A'] = 0;
		}
	}

	for(int i=0; i<r-1; i++){
		for(int j=0; j<c; j++) {
			int cur = v[i][j] - 'A';
			int prev = v[i+1][j] - 'A';
			if(after[prev][cur] || cur == prev) continue;
			else {
				after[prev][cur] = true;
				req[cur]++;
			}
		}
	}

	queue<int> q;
	for(int i=0; i<26; i++) {
		if(req[i] == 0 && vis[i] == 0) q.push(i);
	}

	vector<char> ans;

	while(!q.empty()) {
		int best = q.front();
		q.pop();
		vis[best] = 1;
		ans.push_back((char)(best + 'A'));
		for(int i=0; i<26; i++) {
			if(after[best][i]) {
				req[i]--;
				if(req[i] == 0) q.push(i);
			}
		}
	}

	for(int i=0; i<26; i++) {
		if(vis[i] == 0) {
			cout << "-1\n";
			return;
		}
	}

	for(auto x: ans) cout << x;
	cout << "\n";

}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}