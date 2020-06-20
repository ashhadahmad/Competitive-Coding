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

int a[51][51];
int n, m;

void solve(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> a[i][j];
	}
	bool chance = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] == 0 && isvalid(i,j)){
				a[i][j] = 1;
				chance ^= 1;
			}
		}
	}
	if(chance&1) cout << "Ashish\n";
	else cout << "Vivek\n";
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