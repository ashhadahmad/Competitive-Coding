#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Documents/Codes/input.txt", "r", stdin);
	freopen("/Users/mac/Documents/Codes/output.txt", "w", stdout);
	#endif	
}

using namespace std;
int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		int n, k;
		cin >> n >> k;
		ll ans = 0;
		int cur = 0;
		for(int i=0; i<k+k; i++){
			int p; cin >> p;
			ans += abs(p-cur);
			cur = p;
		}
		cout << ans << endl;
	}
	return 0;
}