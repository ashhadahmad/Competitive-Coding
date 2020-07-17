#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

int f(string s, int l, int r, char ch) {
	if(l == r-1) {
		if(s[l] == ch) return 0;
		else return 1;
	}

	int n = s.size();
	string left = s.substr(0, n/2);
	int count1 = 0, count2 = 0;
	string right = s.substr(n/2);
	for(char c: left) {
		if(c != ch) count1++;
	}
	int ans1 = f(right, 0, n/2, ch+1);
	for(char c: right) {
		if(c != ch) count2++;
	}
	int ans2 = f(left, 0, n/2, ch+1);

	return min(count1 + ans1, count2 + ans2);
}

void solve(){
	int n;
	cin >> n;
	string s; 
	cin >> s;
	cout << f(s, 0, n, 'a') << '\n';
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}