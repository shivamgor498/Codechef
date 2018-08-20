/* shivamgor498
	https://www.codechef.com/COOK97B/problems/BFTT*/
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell 1000000007
#define hell1 1000000006
#define pb push_back
#define x first
#define y second
using namespace std;
vector<ll>adj[400005],visited(400005,0);
ll mM(ll a,ll b,ll mod){ll res = 0;a %= mod;while(b){if (b & 1)res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
ll fpow(ll x,ll y,ll p){x=x%p;ll res=1;while(y){if(y&1)res=mM(res,x,p);res%=p;if(res<0)res=(res+p)%p;y=y>>1;x=mM(x,x,p);if(x<0)x=(x+p)%p;x%=p;}return res;}
ll inv(ll n){return fpow(n,hell-2,hell);}
ll modmul(ll x,ll y){return mM(x,y,hell);}
ll modadd(ll x,ll y){ll temp=x%hell+y%hell;temp%=hell;if(temp<0)temp = (temp+hell)%hell;return temp;}
void dfs(ll src)
{
	visited[src] = 1;
	for(auto e:adj[src])
		if(!visited[e])
			dfs(e);
}
ll count(ll n)
{
	ll cnt=0;
	while(n)
	{
		ll temp = n%10;
		n/=10;
		if(temp==3)
			cnt++;
	}
	return cnt;
}
int main(){
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--){
		ll n;
		cin >> n;
		n++;
		while(1)
		{
			ll cnt = count(n);
			if(cnt>=3)
				break;
			n++;
		}
		cout << n << "\n";
	}
}
