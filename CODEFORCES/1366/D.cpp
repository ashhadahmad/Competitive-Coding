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

vector<pair<int, int> > bfs(vector<vector<int> > &v, int x, int y, int n, int m){
	vector<pair<int, int> > ans;
	queue<pair<int, int> > q;
	q.push(make_pair(x,y));
	vector<vector<bool> > vis(n, vector<bool> (m, false));
	while(!q.empty()){
		int size = q.size();
		int count0 = 0, count1 = 0;
		while(size--){
			pair<int,int> top = q.front();
			q.pop();
			int xn = top.first, yn = top.second;
			if(v[xn][yn] == 1) count1++;
			else count0++;
			if(xn < n-1){
				if(!vis[xn+1][yn]) {
					q.push(make_pair(xn+1,yn));
					vis[xn+1][yn] = true;
				}
			}
			if(yn < m - 1){
				if(!vis[xn][yn+1]) {
					q.push(make_pair(xn,yn+1));
					vis[xn][yn+1] = true;
				}
			}
		}
		ans.push_back(make_pair(count0, count1));
	}

	return ans;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(m));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> v[i][j];

	int fans = 0;
	vector<pair<int, int> > ans = bfs(v,0,0,n,m);
	int size = ans.size();
	int i = 0, j = size - 1;
	while(i < j){
		fans += min(ans[i].first + ans[j].first, ans[i].second + ans[j].second);
		i++, j--;
	}

	cout << fans << endl;
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