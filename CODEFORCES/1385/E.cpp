#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjD(n+1);
	vector<vector<int>> adjU(n+1);
	vector<int> pre();
	while(m--) {
		int type, x, y;
		if(type) adjD[x].push_back(y);
		else {
			adjU[x].push_back(y);
			adjU[y].push_back(x);
		}
	}
	
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}