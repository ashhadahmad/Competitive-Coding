#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void solve(){
	int a, b, n; 
	cin >> a >> b >> n;
	int count = 0;
	while(a <= n && b <= n){
		if(a < b) a += b;
		else b += a;
		++count;
	}
	cout << count << endl;
}

int main(){
	FASTIO(); 
	int t = 1; 
	cin >> t;
	while(t--) 
		solve();
	return 0;
}