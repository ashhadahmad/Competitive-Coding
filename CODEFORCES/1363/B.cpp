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
	string s;
	cin >> s;
	int ans = s.size();
	int x = 0, y = (int) s.size() - 1;
	while(x < s.size() && s[x] == '1') ++x;
	while(y >= 0 && s[y] == '1') --y;

	int tempans1 = 0;
	int tempans2 = 0;
	int tempans3 = 0;
	int tempans4 = 0;


	for(int i = x; i < (int) s.size(); i++) tempans1 += s[i] == '1';
	for(int i = 0; i <= y; i++) tempans2 += s[i] == '1';
	for(int i = x; i < (int) s.size(); i++) tempans3 += s[i] == '0';
	for(int i = 0; i <= y; i++) tempans4 += s[i] == '0';


	cout << min({tempans1, tempans2, tempans3, tempans4}) << "\n";
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