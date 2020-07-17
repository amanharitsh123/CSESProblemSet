#include<bits/stdc++.h>
 
using namespace std;
typedef long long int lli;
 
#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
 
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
 
 
template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}
 
template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}
 
 
template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}
 
lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}
 
lli power(lli a,lli b) {
  lli ans = 1;
  while(b > 0) {
    if(b&1)
      ans = mul(ans, a);
    a = mul(a,a);;
    b >>= 1;
  }
  return ans;
}
 
struct event {
  lli u, v, w;
  bool operator<(const event &o) const {
    return w<o.w;
  }
};
 
const int N=2501;
vector<event> edges;
vector<lli> dist(N, 1e18);
vector<vector<vector<lli>>> adj(2, vector<vector<lli>> (N));
bool reachable[2][N];
bool marked[N];
int n, m;

void bfs(int i) {
  memset(reachable[i], false, sizeof(reachable[i]));
  memset(marked, false, sizeof(marked));
  queue<lli> q;
  if(i==0)
    q.push(1);
  else
    q.push(n);
  reachable[i][q.front()]=true;
  while(q.size()) {
    int ele=q.front();
    q.pop();
    for(auto x:adj[i][ele]) {
      if(marked[x])
        continue;
      marked[x]=true;
      reachable[i][x]=true;
      q.push(x);
    }
  }
}

bool bellman_ford() {
  dist[1]=0;
  for(int i=0; i<n-1; i++) {
    for(auto x:edges)  {
      lli u=x.u, v=x.v, w=x.w;
      dist[v]=min(dist[v], dist[u]+w);
    }
  }
 
  for(auto x:edges) {
    lli u=x.u, v=x.v, w=x.w;
    if(dist[u]+w<dist[v] and reachable[0][v] and reachable[1][v])
      return true;
  }
 
  return false;
}
 
void solve() {
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    lli u, v, w;
    cin >> u >> v >> w;
    adj[0][u].pb(v);
    adj[1][v].pb(u);
    edges.pb({u, v, -1LL*w});
  }

  bfs(0);
  bfs(1);
  bool cycle=bellman_ford();
  if(cycle)
    cout << -1 << endl;
  else 
    cout << -1LL*dist[n] <<endl;
}
 
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  lli testcases=1;
  while(testcases--) {
    solve();
  }
}
