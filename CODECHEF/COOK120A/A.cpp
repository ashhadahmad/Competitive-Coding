#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> mp;
	for(char c: s) {
		mp[c]++;
	}
	for(char st = 'a'; st <= 'z'; st++) {
		if(mp[st] & 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}