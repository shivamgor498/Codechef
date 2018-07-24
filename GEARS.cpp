//https://cp-algorithms.com/data_structures/disjoint_set_union.html
//for reference
 
 /*shivamgor498
 https://www.codechef.com/JULY18A/problems/GEARS
 */
#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define hell LLONG_MAX
#define pb push_back
#define x first
#define y second
using namespace std;
vector<ll>a(100005);
vector< pair<ll, pair<ll,ll> > >parent(100005);
vector<bool>bipartite(100005);
vector<ll>rnk(100005,0);
ll n,m,c1,c2;
void initialize()
{
	for(int i=0;i<parent.size();i++)
	{
		parent[i].x = i; // parent
		parent[i].y.x = 0; // parity
		parent[i].y.y = 0; // length from reprensitive
		bipartite[i] = true;
	}
}
pair < ll,pair<ll, ll>> find_set(ll v) {
    if (v != parent[v].x) {
        ll parity = parent[v].y.x;
        ll len = parent[v].y.y;
        parent[v] = find_set(parent[v].x);
        parent[v].y.x ^= parity;
        parent[v].y.y += len;
    }
    return parent[v];
}
void add_edge(ll ai, ll bi) {
    pair < ll,pair<ll, ll> > pa = find_set(ai);
    ai = pa.x;
    ll xi = pa.y.x;
 
    pair < ll,pair<ll, ll> > pb = find_set(bi);
    bi = pb.x;
    ll yi = pb.y.x;
 
    if (ai == bi) {
        if (xi == yi)
            bipartite[ai] = false;
    } else {
        if (rnk[ai] < rnk[bi])
            swap (ai, bi);
        ll temp = xi^yi;
        temp ^=1;
        ll temp1 = parent[ai].y.x;
        parent[bi] = {ai, {temp,temp1 + 1}};
        if(!bipartite[bi])
        	bipartite[ai] = false;
        if (rnk[ai] == rnk[bi])
            ++rnk[ai];
    }
}
bool is_bipartite(ll v) {
    return bipartite[find_set(v).first];
}
int main()
{
	ios
	ll t;
	//cin >> t;
	t = 1;
	while(t--)
	{
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		initialize();
		while(m--)
		{
			ll tc,xi,yi,c,v;
			cin >> tc;
			if(tc==1)
			{
				cin >> xi >> c;
				a[xi] = c;
			}
			else if(tc==2)
			{
				cin >> xi >> yi;
				add_edge(xi,yi);
			}
			else if(tc==3)
			{
				cin >> xi >> yi >> v;
				pair < ll,pair<ll, ll> > pa = find_set(xi);
				pair < ll,pair<ll, ll> > pb = find_set(yi);
				if(pa.x != pb.x)
					cout << 0;
				else if (!is_bipartite(xi))
					cout << 0;
				else
				{
					ll temp1 = a[xi]*v,temp2 = a[yi];
					ll gc = __gcd(temp1,temp2);
					temp1/=gc;
					temp2/=gc;
					//cout << pa.y.x << " " << pb.y.x << "\n";
					if(pa.y.x != pb.y.x)
						cout << "-";
					cout << temp1 << "/" << temp2	;
				}
				cout << "\n";
			}
		}
	}
}
