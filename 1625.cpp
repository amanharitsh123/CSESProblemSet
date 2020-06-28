#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
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
#define MOD 1000000007

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

lli power(lli num,lli base) {
  lli ans = 1;
  while(base>0) {
    if(base&1)
      ans = mul(ans, num);

    num = mul(num, num);
    base >>= 1;
  }

  return ans;
}
lli ans = 0;
bool visited[7][7];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y) {
  return x>=0 and x<7 and y>=0 and y<7;
}

string inp;
int ma = 0;



void print_mat() {
  for(int i=0; i<7; i++) {
    for(int j=0; j<7; j++)
      cout << visited[i][j]<<" ";
    cout << endl;
  }

  cout << "********************************" << endl;
}
void foo(int i, int j, int count, char last_move) {
  ma = max(ma, count);
  if(count==48) {
    if(i==6 and j==0)
      ++ans;
    return;
  }

  if(!valid(i,j) or visited[i][j] or (i==6 and j==0))
    return;


  visited[i][j]=true;
/*  for(auto x:moves)
    foo(i+x.first, j+x.second, count+1);
*/

  if(inp[count]=='?' || inp[count]=='D') {
    int x=i+1;
    int y=j;
    foo(x, y, count+1, 'D');
  }

  if(inp[count]=='?' || inp[count]=='U') {
    int x=i-1;
    int y=j;
    if(y!=6)
      foo(x, y, count+1, 'U');
 }

  if(inp[count]=='?' || inp[count]=='R') {
    int x=i;
    int y=j+1;

    bool possible = true;
    int ma=-1;
    while(y<7 and possible)
      possible = possible and !visited[i][y], y++;
    ma = y;
    y=j;

    possible = !possible;
    bool possible2 = true;
    while(i+1<7 and y<ma and possible2)
      possible2 = possible2 and visited[i+1][y], y++;

    y=j+1;
    //if(!possible)
      //print_mat();
    
    possible = !(possible and possible2);
    if(x!=6 and possible)
      foo(x, y, count+1, 'R');
 }

  if(inp[count]=='?' || inp[count]=='L') {
    int x=i;
    int y=j-1;
    if(i!=0 or last_move!='D')
      foo(x, y, count+1, 'L');
  }



  visited[i][j]=false;
}

void solve() {
  cin >> inp;
  memset(visited, false, sizeof(visited));
  foo(0, 0, 0, ' ');
  cout << ans << endl;
  cout << ma << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
  clock_t z = clock();
    solve();
debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
  }
}

