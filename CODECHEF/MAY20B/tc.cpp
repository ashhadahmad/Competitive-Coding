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
	cout << 100 << endl;
	for(int i=1; i<=100; i++){
		cout << i << " " << i*i << endl;
		for(int j=i; j>=1; j--){
			cout << j << " ";
		}
		cout << endl;
	}
}

int main(){
	FAST(); 
	lol();
	int t=1; while(t--) solve();
	return 0;
}