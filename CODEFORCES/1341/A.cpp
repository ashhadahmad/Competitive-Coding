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

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		ll n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		ll left_limit = n * (a-b);
		ll right_limit = n * (a+b);
		bool ans = true;
		// cout << left_limit << " " << right_limit << " " << c << " " << d << endl;
		if(right_limit < c-d || left_limit > c+d) ans = false;
		cout << (ans ? "Yes\n" : "No\n");
	}
	return 0;
}