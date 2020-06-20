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
	int n = s.size();
	vector<bool> left(n, false);
	vector<bool> right(n, false);
	string s1 = "";
	string s2 = "";
	for(int i=1; i<n; i+=2){
		if(s1.empty()){
			s1 += s[0];
			s2 += s[1];
		}
		else{
			s2 += s[i-1];
			s2 += s[i];
			s1 += s2[0];
			s2.erase(0,1);
		}
		left[i] = s1 == s2;
	}
	s1 = "", s2 = "";

	for(int i = s.size()-2; i>=0; i-=2){
		if(s1.empty()){
			s1 += s[i];
			s2 += s[i+1];
		}
		else{
			s2 = s1[0] + s2;
			s1.erase(0,1);
			s1 = s[i+1] + s1;
			s1 = s[i] + s1;
		}
		right[i] = s1 == s2;
	}
	int ans = 0;
	for(int i=0; i<n-1; i++){
		ans += (left[i] && right[i+1]);
	}
	for(int i=0; i<n; i++){
		cout << left[i] << " ";
	}
	cout << '\n';
	for(int i=0; i<n; i++){
		cout << right[i] << " ";
	}
	cout << '\n';
	cout << ans << "\n";
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