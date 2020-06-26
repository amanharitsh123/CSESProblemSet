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

vector<string> ans;
map<char, int> mp;

void foo(string &inp, int n) {
  if(n==inp.size()) {
    ans.pb(inp);
    return;
  }

  for(char x='a'; x<='z'; x++) {
    if(mp[x]==0)
      continue;

    inp.pb(x);
    mp[x]-=1;
    foo(inp, n);
    inp.pop_back();
    mp[x]+=1;
  }
}

void solve() {
  string inp;
  cin >> inp;
  for(auto x:inp)
    mp[x]+=1;
  string temp;
  foo(temp, inp.size());
  cout << ans.size() << endl;
  for(auto x:ans)
    cout << x << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 lli testcases=1;
 while(testcases--) {
    solve();
  }
}

