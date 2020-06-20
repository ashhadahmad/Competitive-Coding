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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
    int max_so_far = a[0], max_ending_here = 0, start = 0, end = 0, s=0;
  
    for (int i=0; i < n; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    }
    int maxel = a[start];
    for(int i=start; i<=end; i++) maxel = max(maxel, a[i]);
    cout << max_so_far - maxel;
}

int main(){
	FASTIO(); 
	localIO();
	int t = 1; 
	// cin >> t;
	while(t--) 
		solve();
	return 0;
}