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
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	int bestAns = 0;
	for(int i=1; i<n; i++){
		bestAns += abs(a[i] - a[i-1]);
	}
	// cout << bestAns << endl;
	vector<bool> use(n, true);
	int totalSize = n;

	int li = 0, mi = 1, ri = 2;

	while(ri < n){
		int removing = abs(a[mi] - a[li]) + abs(a[ri] - a[mi]);
		int addingback = abs(a[ri] - a[li]);
		if(addingback >= removing){
			use[mi] = false;
			++ri;
			++mi;
			totalSize--;
		}
		else{
			li = mi;
			++mi;
			++ri;
		}
	}

	cout << totalSize << "\n";
	for(int i=0; i<n; i++){
		if(use[i]) cout << a[i] << " ";
	}
	cout << "\n";
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