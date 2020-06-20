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
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int odd = 0, even = 0;
	for(int i=0; i<n; i++){
		if((i + a[i]) & 1){
			odd += (a[i] & 1);
			even += ((a[i] & 1) ^ 1);
		}
	}
	if(odd == even) cout << odd << "\n";
	else cout << "-1\n";
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