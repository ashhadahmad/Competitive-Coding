#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

bool isvalid(int n, int m, int i, int j){
	return i < n && i >= 0 && j < m && j >= 0;
}

void solve(){
	int n,m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	vector<vector<bool>> isReachable(n, vector<bool>(m, false));
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	queue<pair<int, int> > q1;
	isReachable[n-1][m-1] = true;
	q1.push(make_pair(n-1,m-1));
	while(!q1.empty()) {
		auto cur = q1.front();
		q1.pop();
		if(isvalid(n,m,cur.first-1,cur.second) && !visited[cur.first-1][cur.second] && a[cur.first-1][cur.second] != '#'){
			isReachable[cur.first-1][cur.second] = true;
			visited[cur.first-1][cur.second] = true;
			q1.push(make_pair(cur.first-1, cur.second));
		}
		if(isvalid(n,m,cur.first,cur.second - 1) && !visited[cur.first][cur.second-1] && a[cur.first][cur.second-1] != '#'){
			isReachable[cur.first][cur.second-1] = true;
			visited[cur.first][cur.second-1] = true;
			q1.push(make_pair(cur.first, cur.second - 1));
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) visited[i][j] = false;
	}

	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<m; j++) {
	// 		cout << isReachable[i][j] << " "; 
	// 	}
	// 	cout << '\n';
	// }

	queue<pair<int, int> > q;
	q.push(make_pair(0,0));

	string ans = "";
	while(!q.empty()) {
		int size = q.size();
		auto x = q.front();
		ans += a[x.first][x.second];
		vector<pair<int, int> > s;
		// cout << size << "\n";
		while(size--) {
			auto cur = q.front();
			q.pop();
			// printf("Processing %d %d %c\n",cur.first, cur.second, a[cur.first][cur.second]);
			if(isvalid(n,m,cur.first+1,cur.second) && isReachable[cur.first+1][cur.second] && !visited[cur.first+1][cur.second]){
				// cout << "Added Down\n";
				visited[cur.first+1][cur.second] = true;
				s.push_back(make_pair(cur.first+1,cur.second));
			}
			if(isvalid(n,m,cur.first,cur.second + 1) && isReachable[cur.first][cur.second + 1] && !visited[cur.first][cur.second + 1]){
				// cout << "Added Right\n";
				visited[cur.first][cur.second + 1] = true;
				s.push_back(make_pair(cur.first,cur.second + 1));
			}
		}
		// cout << "Processing Finished for Level\n\n";

		char smallest = '#';
		for(auto cur: s) {
			if(smallest == '#' || a[cur.first][cur.second] < smallest) smallest = a[cur.first][cur.second];
		}
		// cout << smallest << " "<< s.size() << "\n";
		for(auto cur: s){
			if(a[cur.first][cur.second] == smallest) q.push(make_pair(cur.first, cur.second));
		}
	}

	cout << ans << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}