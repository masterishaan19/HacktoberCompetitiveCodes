#include<bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define ll long long
#define ld long double
#define endl << "\n"
#define sp << " "
#define spp << " " <<
#define all(v) v.begin(),v.end()
#define a(n) a,a+n
#define lmax 9223372036854775807
#define lmin -9223372036854775808
#define li() for(i=0;i<n;++i)
#define lie(a,b) for(i=a;i<b;++i)
#define lj() for(j=0;j<n;++j)
#define lje(a,b) for(j=a;j<b;++j)
#define ft first
#define sd second
#define pb push_back
#define pf push_pront
#define mod 1000000007
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mset(a,b) memset(a,b,sizeof(a))
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1)
 
void solve(ll n,ll k){
	ll arr[n],i,j;
	unordered_set<ll> st;
	for(i=0;i<n;++i){
		cin>>arr[i];
		st.insert(arr[i]);
	}
	vector<ll> remm ;
	i = k;
	while(i>0){
		for(auto it:st){
			remm.pb(it);
			i--;
			if(i < 1)
				break;
		}
	}
	
	if(st.size() > k)
		cout << -1 endl;
	else{
		cout << (n*remm.size()) endl;
		for(i=0;i<n;++i)
			for(auto it:remm)
				cout << it sp;
		cout endl;
	}
}
 
int main(){
	ll timer;
	cin>>timer;
	while(timer--){
		ll n,k;
		cin>>n>>k;
		solve(n,k) ;
	}
	return 0;
}