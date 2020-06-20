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
	int tc = 2;
	cin >> tc;
	while(tc--){
		int t, n, p;
		cin >> t >> n >> p;
		vector<vector<int> > v(n, vector<int>(n));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("1 %d %d %d %d\n",i+1,j+1,i+1,j+1);
				cin >> v[i][j];
				if(v[i][j] == -1) return;
			}
		}
		cout << 2 << "\n";
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		int ans;
		cin >> ans;
		if(ans == 1) continue;
		else if(ans == -1) return;
	}
}

int main(){
	FASTIO(); 
	// localIO();
	int t = 1; 
	// cin >> t;
	while(t--) 
		solve();
	return 0;
}