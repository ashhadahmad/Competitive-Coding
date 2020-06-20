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

int mxN = 25830;
ll* arr = new ll[mxN];

void fill(){
	for(ll i=0; i<mxN; i++){
		arr[i] = ((i * (3*i+1))/ 2);
	}
}

void solve(){
	ll n;
	cin >> n;
	int i = mxN-1;
	int count = 0;
	while(i > 0){
		if(n >= arr[i]){
			n-=arr[i];
			++count;
		}
		else{
			i--;
		}
	}
	printf("%d\n", count);
}

int main(){
	FAST(); 
	lol();
	fill();
	int t; cin >> t; while(t--) solve();
	return 0;
}