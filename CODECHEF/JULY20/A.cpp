#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	int x = 0, y = 0;
	for(int i=0; i<4*n-1; i++){
		int a,b;
		cin >> a >> b;
		x ^= a; y ^= b;
	}
	cout << x << " " << y << "\n";
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}