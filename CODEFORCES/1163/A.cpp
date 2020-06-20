#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve() {
	string a,b,c;
	cin >> a >> b >> c;
	bool ans = true; 
	for(int i=0; i<a.size(); i++){
		// if(a[i] == b[i]) continue;
		if(c[i] == b[i] || c[i] == a[i]) continue;
		else{
			ans = false;
			break;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}