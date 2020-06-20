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
	int n, m, k;
	cin >> n >> m >> k;
	int maxJ = min(n/k, m);
	int leftJ = m - maxJ;
	// cout << maxJ << " " << leftJ << " ";
	int maxAnother = ceil((float)leftJ / (k-1));
	// cout << "->" << maxAnother << endl;
	if(maxAnother >= m){
		cout << "0\n";
		return;
	}
	cout << maxJ - maxAnother << endl;
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