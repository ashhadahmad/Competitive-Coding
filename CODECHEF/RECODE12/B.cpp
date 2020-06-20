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

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	bool ans = true;
	for(int i=0; i<s.size(); i++){
		int li = (n+i-1) % n;
		int ri = (i+1) % n;
		if(s[li] != s[ri]){
			ans = false;
			break;
		}
	}

	cout << (ans ? "YES\n" : "NO\n");
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}