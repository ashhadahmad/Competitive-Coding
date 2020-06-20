#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

// void localIO(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif	
// }

void solve(){
	int n;
	cin >> n;
	++n;
	cout << n * 3 + 1 << endl;
	cout << "0 0\n";
	cout << "1 0\n";
	cout << "0 1\n";
	cout << "1 1\n";
	for(int i=1; i < n; i++){
		cout << i + 1 << " " << i << endl;
		cout << i << " " << i + 1 << endl;
		cout << i + 1 << " " << i + 1 << endl;
	}
}

int main(){
	FASTIO(); 
	// localIO();
	int t= 1 ; 
	// cin >> t;
	while(t--) 
		solve();
	return 0;
}