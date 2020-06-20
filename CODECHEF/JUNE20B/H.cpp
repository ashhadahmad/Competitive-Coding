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

bool isValid(int x, int y, int n, int m){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int getBestAns(vector<vector<int> > &v, int x, int y, int n, int m){
	int tempDepth = 0;
	if(isValid(x+1, y, n, m) && v[x+1][y] > v[x][y]) tempDepth = max(tempDepth, getBestAns(v,x+1,y,n,m));
	if(isValid(x-1, y, n, m) && v[x-1][y] > v[x][y]) tempDepth = max(tempDepth, getBestAns(v,x-1,y,n,m));
	if(isValid(x, y+1, n, m) && v[x][y+1] > v[x][y]) tempDepth = max(tempDepth, getBestAns(v,x,y+1,n,m));
	if(isValid(x, y-1, n, m) && v[x][y-1] > v[x][y]) tempDepth = max(tempDepth, getBestAns(v,x,y-1,n,m));
	return 1 + tempDepth;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> v[i][j];
		}
	}
	
	map<int, vector<pair<int,int> > > mp;
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			mp[v[i][j]].push_back(make_pair(i,j));
		}
	}

	vector<vector<int> > isUsedPath(n, vector<int>(m, -1));

	int ans = 0;
	for(auto x: mp){
		for(auto y: x.second){
			int i = y.first , j = y.second;
			if(isUsedPath[i][j] == -1){
				isUsedPath[i][j] = 1;
				int tempans = getBestAns(v,i,j,n,m);
				ans = max(ans, tempans);
			}
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