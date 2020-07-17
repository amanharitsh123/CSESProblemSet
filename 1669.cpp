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

const int N=2e5+1;
vector<vector<int>> adj(N);
bool path[N];
bool visited[N];
int parent[N];
int target=-1;

int start, over;

void dfs(int i) {
  path[i]=true;
  visited[i]=true;
  for(auto x:adj[i]) {
    if(path[x] and parent[i]!=x and target==-1) {
      target=0, start=x, over=i;
      continue;
    }

    if(visited[x])
      continue;
    parent[x]=i;
    dfs(x);
  }

  path[i]=false;
}

void solve() {
  int n, m, u, v;
  cin >> n >> m;
  memset(visited, false, sizeof(visited));
  memset(path, false, sizeof(path));
  memset(parent, 1, sizeof(parent));
  for(int i=0; i<m; i++) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for(int i=1; i<=n; i++) if(!visited[i]) dfs(i);
  if(target==-1)
    cout << "IMPOSSIBLE" << endl;
  else {
    //cout << steps << endl;
    vector<int> ans={start};
    int cur=over;
    while(1) {
      ans.pb(cur);
      if(cur==start)
        break;
      cur=parent[cur];
    }

    reverse(all(ans));
    cout << ans.size() << endl;
    output(ans);
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}



