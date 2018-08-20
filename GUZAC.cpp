/* shivamgor498
	https://www.codechef.com/COOK97B/problems/GUZAC*/
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
int main(){
	ios
	ll t;
	cin >> t;
	//t = 1;
	while(t--){
		ll n,k,x;
		cin >> n >> k >> x;
		vector<ll>a(k);
		for(int i=0;i<k;i++)
			cin >> a[i];
		vector<ll>b(k);
		b = a;
		b.pb(0);
		sort(b.begin(),b.end());
		ll mi = b[1],mx = b[b.size()-1],sum=0;
		ll rmx = mi+x;
		if(rmx!=mx && b.size()!=(n+1))
			b.pb(rmx);
		ll req = n-b.size()+1;
		ll cnt=b.size();
		for(int i=b.size()-2;i>=0;i--)
		{
			if(cnt>=(n+1))
				break;
			ll dif = b[i+1]-b[i]-1;
			ll temp = min(dif,req);
			ll temp1 = b[i];
			if(temp!=dif)
			{
				temp1+=(dif-req);
			}
			if(temp)
			{
				ll t1 = (b[i+1]*(b[i+1]-1))/2;
				ll t2 = (temp1)*(temp1+1)/2;
				sum+=(t1-t2);
				cnt+=temp;
				req-=temp;
			}
		}
		for(int i=0;i<b.size();i++)
			sum+=b[i];
		cout << sum << "\n";
	}
}
