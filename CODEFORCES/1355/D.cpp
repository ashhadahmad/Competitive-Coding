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
	int n, s;
	cin >> n >> s;
	if(n == s) {
		cout << "NO\n"; return;
	}
	if(n == 1){
		cout << "YES\n";
		cout << s << endl << 1 << endl;
		return;
	}
	if((s&1)^1){
		if(n <= s/2){
			cout << "YES\n";
			for(int i=0; i<n-1; i++) cout << 2 << " ";
			cout << s - 2 * (n-1) << endl;
			cout << 1 << endl;
			return;
		}
		else{
			cout << "NO\n";
			return;
		}
	}
	else{
		if(n <= s/2){
			cout << "YES\n";
			for(int i=0; i<n-1; i++) cout << 2 << " ";
			cout << s - 2 * (n-1) << endl;
			cout << 1 << endl;
			return;
		}
		else{
			cout << "NO\n";
			return;
		}
	}
}

int main(){
	FAST(); 
	lol();
	int t; t = 1; while(t--) solve();
	return 0;
}