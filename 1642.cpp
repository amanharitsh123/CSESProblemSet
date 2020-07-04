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
#define MOD 1000000007

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(set<T> arr) {
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

struct event{
  lli x, i, j;
  bool operator<(event &o) {
    return x<o.x;
  }
};

void solve() {
  lli n, sum, t;
  cin >> n >> sum;
  vector<lli> arr;
  map<lli, vector<pair<lli,lli>> > mp;
  for(int i=0; i<n; i++) {
    cin >> t;
    arr.pb(t);
  }

  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
      if(i!=j)
        mp[arr[i]+arr[j]].pb({i, j});

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) {
      lli val=sum-arr[i]-arr[j];
      if(i==j)
        continue;
      for(auto x:mp[val]) {
        set<lli> s;
        s.insert(j+1);
        s.insert(i+1);
        s.insert(x.first+1);
        s.insert(x.second+1);
        if(s.size()==4) {
          output(s);
          return;
        }
      }
    }

  cout << "IMPOSSIBLE" << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

