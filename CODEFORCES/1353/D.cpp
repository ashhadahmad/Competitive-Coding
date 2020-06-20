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


struct triplet{
	int len, l, r;
	triplet(){
		return;
	}
	triplet(int a,int b,int c){
		len = a; l = b; r = c;
	}
	void print(){
		printf("%d %d %d\n", len, l, r);
	}
};

struct CompareTriplet { 
    bool operator()(triplet const& t1, triplet const& t2) 
    {
    	if(t1.len == t2.len) return t1.l > t2.l;
    	return t1.len < t2.len;
    } 
}; 

void solve(){
	int n;
	cin >> n;
	priority_queue<triplet, vector<triplet>, CompareTriplet> pq;
	vector<int> ans(n+1);
	pq.push(triplet(n,1,n));
	for(int i=1; i<=n; i++){
		triplet best = pq.top();
		pq.pop();
		if(best.len&1){
			int temp_idx = ((best.len-1) >> 1);
			temp_idx += best.l;
			ans[temp_idx] = i;
			if(best.len > 1){
				int lnew_size = ((best.len-1) >> 1);
				int lnew_start = best.l;
				int lnew_end = temp_idx-1;
				int rnew_start = temp_idx+1;
				int rnew_end = best.r;
				pq.push(triplet(lnew_size,lnew_start,lnew_end));
				pq.push(triplet(lnew_size,rnew_start,rnew_end));
			}
		}
		else{
			int temp_idx = ((best.len) >> 1) - 1;
			temp_idx += best.l;
			ans[temp_idx] = i;
			if(best.len > 1){
				int lnew_size = ((best.len >> 1) - 1);
				int rnew_size = ((best.len) >> 1);
				int lnew_start = best.l;
				int lnew_end = temp_idx-1;
				int rnew_start = temp_idx+1;
				int rnew_end = best.r;
				if(lnew_size > 0) pq.push(triplet(lnew_size,lnew_start,lnew_end));
				if(rnew_size > 0) pq.push(triplet(rnew_size,rnew_start,rnew_end));
			}
		}
	}


	for(int i=1; i<=n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}