#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
	#endif	
}

void solve(){
	int n;
	cin >> n;
	int temp = n;
	int a = 0, b = 0;
	while(temp--) {
		char x; 
		cin >> x;
		a += (x == 'A');
		b += (x == 'B');
	}
	if((a == n/2 )|| (b == n/2)) cout << "Y\n";
	else cout << "N\n";
}

int main(){
	localIO();
	IOS;
	int t = 1; 
	cin >> t;
	for(int i=0; i<t; i++) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}