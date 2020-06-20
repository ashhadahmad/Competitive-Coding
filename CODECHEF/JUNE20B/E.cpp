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
	int n;
	cin >> n;
	int ctr = 1;
	vector<vector<int> > v(n, vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			v[i][j] = ctr++;
		}
	}

	for(int i=0; i<n; i++){
		if((i & 1)^1){
			for(int j=0; j<n; j++) {
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
		else{
			for(int j=n-1; j>=0; j--){
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
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