#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n,m;
	cin >> n >> m;
	bool ok = true;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			int cnt = 0;
			if(i > 0) ++cnt;
			if(i < n-1) ++cnt;
			if(j > 0) ++cnt;
			if(j < m-1) ++cnt;
			cin >> a[i][j];
			if(a[i][j] > cnt) ok = false;
			a[i][j] = cnt;
		}
	}
	if(!ok) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}