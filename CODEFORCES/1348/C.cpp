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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if(s[0] != s[k-1]){
		cout << s[k-1] << "\n";
		return;
	}
	else {
		if(s[k] == s[n-1]){
			cout << s[0];
			int diff = n - k;
			for(int i=0; i<diff/k; i++) cout << s[k];
			if(diff % k != 0) cout << s[k];
			cout << endl;
			return;
		}
		else{
			cout << s[0];
			for(int i=k; i<n; i++) cout << s[i];
			cout << endl;
			return;
		}
	}

}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}