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
	int n, x;
	cin >> n >> x;
	vector<int> deg(n+1, 0);
	for(int i=0; i<n-1; i++){
		int u,v;
		cin >> u >> v;
		++deg[u], ++deg[v];
	}
	if(deg[x] <= 1) cout << "Ayush\n";
	else if((n&1)^1){
		cout << "Ayush\n";
	}
	else {
		cout << "Ashish\n";
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