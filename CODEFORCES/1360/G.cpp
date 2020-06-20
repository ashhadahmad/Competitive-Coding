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

void solve(){
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	vector<vector<int> > v(x, vector<int>(y, 0));
	int st = 0;
	for(int i=0; i<x; i++){
		if(i > 0 && i%b == 0){
			st += a;
		}
		for(int j = st; j < st + a && j < y; j++){
			v[i][j] = 1;
		}
	}

	vector<int> row_sum(x, 0);
	vector<int> col_sum(y, 0);
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			// cout << v[i][j] << " ";
			if(v[i][j]){
				row_sum[i]++;
				col_sum[j]++;
			}		
		}
		// cout << "\n";
	}
	// cout << "\n";

	for(int i=0; i<x; i++){
		// cout << row_sum[i] << " ";
		if(row_sum[i] != a) {
			cout << "NO\n";
			return;
		}
	}

	// cout << "\n";

	for(int i=0; i<y; i++){
		// cout << col_sum[i] << " ";
		if(col_sum[i] != b) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			cout << v[i][j];		
		}
		cout << "\n";
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