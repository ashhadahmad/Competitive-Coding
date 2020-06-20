#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
double PI = acos(-1);

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	double n;
	cin >> n;
	// cout << PI << endl;
	// cout << 1/(2*sin(PI/(2*n))) << endl;
	// printf("%.12lf\n", 1 / sin((PI) / (2 * n)));
	printf("%.12lf\n", 1 / (2 * sin(PI / (4 * n))));
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}