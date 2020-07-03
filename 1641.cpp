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
#define sortall(x) sort(all(x))
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

typedef struct event {
  lli x, i;
  bool operator<(event &o) {
    return x<o.x;
  }
} event;

void solve() {
  lli n, sum, t;
  vector<event> arr;
  cin >> n >> sum;
  for(int i=0; i<n; i++) {
    cin >> t;
    arr.pb({t, i});
  }

  sortall(arr);
  char space=' ';
  for(int i=0; i<n; i++) {
    lli lo=0, hi=n-1;
    while(lo<hi) {
      if(lo==i) {
        ++lo;
        continue;
      }

      if(hi==i) {
        --hi;
        continue;
      }

      if(arr[i].x+arr[lo].x+arr[hi].x==sum) {
        cout << arr[i].i+1 << space << arr[lo].i+1 << space << arr[hi].i+1 << endl;
        return;
      }
      else if(arr[hi].x+arr[lo].x>sum-arr[i].x)
        --hi;
      else
        ++lo;
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

