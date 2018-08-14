/* shivamgor498
	https://www.codechef.com/LTIME62B/problems/PRMDIV
	Explanation:- use sieve to calculate sum of prime factor of i
		  		and then store which satisfy condition then calculate final answer*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define pb push_back
#define unsigned long long int ull;
#define MAXL 1000006
#define x first
#define y second
using namespace std;
vector<ll>prime(MAXL,1),sum(MAXL,0),good_ind[MAXL];
ll fpow(ll x,ll y){x=x%hell;ll res=1;while(y){if(y&1)res=res*x;res%=hell;y=y>>1;x=x*x;x%=hell;}return res;}
ll inv(ll n){
	return fpow(n,hell-2);
}
ll modmul(ll x,ll y){
	return (x*1ll*y)%hell;
}
ll modadd(ll x,ll y){
	ll temp = x%hell + y%hell;
	temp%=hell;
	if(temp<0)
		temp = (temp+hell)%hell;
	return temp;
}
int main(){
	ios
	for(int i=2;i<MAXL;i++)
		if(prime[i])
			for(int j=i;j<MAXL;j+=i){
				sum[j]+=i;
				prime[j] = 0;
			}
	for(int i=2;i<MAXL;i++)
		for(int j=2*i;j<MAXL;j+=i)
			if(sum[j]%sum[i]==0)
				good_ind[j].pb(i);
	ll t;
	cin >> t;
	//t = 1;
	while(t--){
		ll n;
		cin >> n;
		vector<ll>a(n);
		map<ll,ll>m;
		for(int i=0;i<n;i++){
			cin >> a[i];
			m[a[i]]++;
		}
		ll ans = 0;
		for(auto e:m){
			ans+=e.y*(e.y - 1);
			for(int i=0;i<good_ind[e.x].size();i++)
				if(m[good_ind[e.x][i]])
					ans+=e.y*m[good_ind[e.x][i]];
		}
		cout << ans << "\n";
	}
}
