#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int check(vector<int> v) {
	int like1 = v[2] + v[3];  	
	int like2 = v[7] + v[4];
	if(like2 >  like1) swap(like1, like2);
	int add = min(like1 - like2, v[1]);
	like2 += add;
	v[1] -= add;
	like1 += v[1]/2; like2 += v[1]/2;
	if(v[1] % 2 !=0) {
		if(like1 > like2)
			like2 ++;
		else
			like1++;
	}

	int subtract = min(like1 - like2, v[9]);
	like1 -= subtract;
	v[9] -= subtract;
	like1 -= v[9]/2; like2 -= v[9]/2;
	if(v[9]%2 != 0) {
		if(like1 > like2) 
			like1 --;
		else
			like2 --;
	}

	return min(like1, like2);	
}


int main () {
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int> v(10, 0);
		vector<pair<int, int>> input(n, {0,0});
		for(int i=0;i<n;i++) {
			int a; cin>>a;
			input[i].first = a;
		}
		for(int i=0;i<n;i++) {
			int a; cin>>a;
			input[i].second = a;
		}

		for(int i=0;i<n;i++) {
			int f = input[i].first;
			int s = input[i].second;
			if(f==1 && s==1)
				v[1]++;
			else if(f==1 && s==0)
				v[2]++;
			else if(f==1 && s==-1)
				v[3]++;
			else if(f==0 && s==1)
				v[4]++;
			else if(f==-1 && s==1)
				v[7]++;
			else if(f==-1 && s==-1)
				v[9]++;
		}
		cout<<check(v)<<endl;
	}
}