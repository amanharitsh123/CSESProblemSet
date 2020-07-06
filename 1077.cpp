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

int n, k;
multiset<lli, greater<lli>> bot;
multiset<lli> top;
lli smaller=0, larger=0;

void fix() {
  while(((int) top.size()- (int) bot.size())>=3) {
    lli x=*top.begin();
    //cout <<"Size "<<top.size() << endl;
    //cout <<"Size b "<<bot.size() << endl;
    top.erase(top.find(x));
    larger-=x;
    bot.insert(x);
    smaller+=x;
  }

  while((int) bot.size() - (int) top.size() >=0) {
    lli x=*bot.begin();
    bot.erase(bot.find(x));
    smaller-=x;
    top.insert(x);
    larger+=x;
  }
}

void add(lli x) {
  lli med;
  if(top.size())
    med=*top.begin();
  else
    med=0;
  
  if(x<med)
    bot.insert(x), smaller+=x;
  else
    top.insert(x), larger+=x;

  fix();
} 

void del(lli x) {
  lli med;
  if(top.size())
     med=*top.begin();
  else
     med=*bot.begin();
  if(x<med)
    bot.erase(bot.find(x)), smaller-=x;
  else
    top.erase(top.find(x)), larger-=x;
  fix();
}

lli cost() {
  lli small=bot.size(), lar=top.size(), med=*top.begin();
  return small*med-smaller+larger-lar*med ;
}

void solve() {
  vector<lli> arr;
  cin >> n >> k;
  input(arr, n);
  int lo=0, hi=1;
  add(arr[lo]);
  while(hi<k)
    add(arr[hi]), hi++;

  cout << cost() << " ";
  while(hi<n) {
    //cout <<"At : "<<hi << endl;
    add(arr[hi]);
    //cout << "Add done" << endl;
    ++hi;
    del(arr[lo]);
    ++lo;
    //cout << "Done" << endl;
    cout << cost() << " ";
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


