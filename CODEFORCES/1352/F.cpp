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
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	string s = "";
	if(n3 > 0){
		s += '1';
		for(int i=0; i<n3; i++) s+='1';
	}
	if(n2 > 0){
		if(s.size() == 0) s+="10";
		else s+= "0";
		for(int i=0; i<n2-1; i++){
			if(i&1) s+='0';
			else s+='1';
		}
	}
	if(n1 > 0){
		if(s.size() == 0){
			s+="0";
		}
		for(int i=0; i<n1; i++) s+='0';
	}
	cout << s << endl;
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}