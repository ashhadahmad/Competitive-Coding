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
	ll tom;
	cin >> tom;
	ll temp = tom;
	if(tom & 1){
		cout << (tom >> 1) << "\n";
		return;
	}
	ll count = 0;
	while((temp&1)^1) {
		temp >>= 1;
		++count;
	}
	ll jerry = (1LL << (count+1));
	if(jerry >= tom) {
		cout << "0\n";
		return;
	}
	cout << tom/jerry << "\n";
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