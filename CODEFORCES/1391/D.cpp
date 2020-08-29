#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n,m;
	cin >> n >> m;
	vector<string> vs(n);
	for(int i=0; i<n; i++) cin >> vs[i];
	if(min(n,m) >= 4) {
		cout << "-1\n";
		return;
	}
	if(n == 1 || m == 1) {
		cout << "0\n";
		return;
	}

	vector<vector<bool>> good;

	for(int i=1; i<n; i++) {
		vector<bool> isGood;
		for(int j = 1; j < m; j++) {
			if(((vs[i][j]-'0') + (vs[i][j-1]-'0') + (vs[i-1][j]-'0') + (vs[i-1][j-1]-'0')) & 1) {
				isGood.push_back(true);
			}
			else isGood.push_back(false);
		}
		good.push_back(isGood);
	}

	for(auto x: good) {
		for(auto y: x) cout << y << " ";
		cout << '\n';
	}
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}