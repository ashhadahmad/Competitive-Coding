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
	ll a,b,x,y;
	cin >> a >> b >> x >> y;
	ll diff1 = x-a;
	ll diff2 = y-b;
	// while(1) {
	// 	cout << "11";
	// }
	if(diff1 < 0 || diff2 < 0){
		cout << 0 << endl;
		return;
	}
	else{
		cout << 1 + (diff1 * diff2) << "\n";
		return;
	}
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