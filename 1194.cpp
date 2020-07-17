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
#define space ' '
 
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
 
const int N=1e4+1;
bool marked[N][N];
pi parent[N][N];
vector<string> arr;
vector<pi> moves={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<char> step={'D', 'U', 'L', 'R'};
int xb, yb;
int mlevel[N][N];
bool valid(int i, int j) {
  return i>=0 and i<arr.size() and j>=0 and j<arr[0].size() and (!marked[i][j]) and arr[i][j]!='#';
}

void multisource_bfs() {
  queue<pi> q;
  for(int i=0; i<arr.size(); i++) {
    for(int j=0; j<arr[0].size(); j++) {
      if(arr[i][j]=='M')
        marked[i][j]=true, q.push({i, j});
    }
  }
  q.push({-1, -1});
  int level=0;
  while(q.size()) {
    pi ele=q.front();
    q.pop();
    if(ele.first==-1) {
      ++level;
      if(q.size())
        q.push(ele);
      continue;
    }
    mlevel[ele.first][ele.second]=level;
    for(auto m:moves) {
      int x=m.first+ele.first;
      int y=m.second+ele.second;
      if(!valid(x,y))
        continue;
      q.push({x, y});
      marked[x][y]=true;
    }
  }
}

bool bfs(int i, int j) {
  bool possible=false;
  queue<pi> q;
  parent[i][j]={i, j};
  q.push({i, j});
  marked[i][j]=true;
  int level=0;
  q.push({-1, -1});
  while(q.size()) {
    pi ele=q.front();
    q.pop();
    if(ele.first==-1) {
      ++level;
      if(q.size())
        q.push(ele);
      continue;
    }
    possible = possible or arr[ele.first][ele.second]=='B';
    if(arr[ele.first][ele.second]=='B') {
      xb=ele.first, yb=ele.second;
      break;
    }
    for(auto m:moves) {
      int x=ele.first+m.first;
      int y=ele.second+m.second;
      if(valid(x, y) and (level+1)<mlevel[x][y])
        marked[x][y]=true, q.push({x, y}), parent[x][y]={ele.first, ele.second};
    }
  }
 
  return possible;
}
 
char cal_step(int i, int j, int px, int py) {
  for(int m=0; m<4; m++) {
    int x=i+moves[m].first;
    int y=j+moves[m].second;
    if(px==x and py==y)
      return step[m];
  }
 
  return ' ';
}
 
void solve() {
  int n, m;
  bool possible=false;
  cin >> n >> m;
  input(arr, n);
  memset(marked, false, sizeof(marked));
  memset(mlevel, inf, sizeof(mlevel));
  int x, y;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(arr[i][j]=='A')
        x=i, y=j;
      if(i==0 or i==n-1 or j==0 or j==m-1) arr[i][j]=arr[i][j]=='.'?'B':arr[i][j];
      
    }
  }
  multisource_bfs();
  memset(marked, false, sizeof(marked));
  possible=bfs(x, y);
  if(x==0 or x==n-1 or y==0 or y==m-1) {
    cout << "YES" << endl << 0 << endl;
    return;
  }
  if(!possible) {
    cout << "NO" << endl;
    return;
  }
  string ans="";
  while(parent[xb][yb]!=mp(xb, yb)) {
    ans.pb(cal_step(xb, yb, parent[xb][yb].first, parent[xb][yb].second));
    lli t=xb;
    xb=parent[xb][yb].first;
    yb=parent[t][yb].second;
  }
  cout << "YES" << endl;
  cout << ans.size() << endl;
  reverse(all(ans));
  cout << ans << endl;
}
 
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  lli testcases=1;
  while(testcases--) {
    solve();
  }
}
