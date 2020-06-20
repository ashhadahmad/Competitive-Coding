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
	vector<string> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			if(a[i][j] == '1'){
				if(a[i+1][j] == '1' || a[i][j+1] == '1') continue;
				else {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
	return;
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