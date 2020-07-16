#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

struct hold{
	char c;
	int x, y;
	hold(){
	}
	hold(char a,int p,int q){
		c = a; x = p; y = q;
	}
};

void solve(){
	int n,m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	int worst = -1;
	for(int i=0; i<n; i++) {
		if(a[i][m-1] == '#') worst = i;
	}
	for(int i=worst; i>=0; i--) {
		a[i][m-1] = '#';
	}

	worst = -1;
	for(int i=0; i<m; i++) {
		if(a[n-1][i] == '#') worst = i;
	}
	for(int i=worst; i>=0; i--) {
		a[n-1][i] = '#';
	}

	queue<hold> q;
	hold base(a[0][0], 0, 0);
	q.push(base);

	while(!q.empty()) {
		int size = q.size();
		cout << q.front().c;
		set<pair<int, int> > s;
		while(size--) {
			hold cur = q.front();
			q.pop();
			if(cur.x+1 < n) {
				if(a[cur.x+1][cur.y] != '#') s.insert(make_pair(cur.x+1, cur.y));
			}
			if(cur.y+1 < m) {
				if(a[cur.x][cur.y+1] != '#') s.insert(make_pair(cur.x, cur.y+1));
			}
		}
		char smallest = '#';
		for(auto cur: s) {
			if(smallest == '#' || a[cur.first][cur.second] < smallest) smallest = a[cur.first][cur.second];
		}
		for(auto cur: s){
			if(a[cur.first][cur.second] == smallest) q.push(hold(a[cur.first][cur.second], cur.first, cur.second));
		}
	}

	cout << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}