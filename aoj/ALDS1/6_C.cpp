#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
#define ALL(obj) (obj).begin(),(obj).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define SIZE(x) ((int)(x).size())
#define debug(x) cerr << #x << " -> " << x << " (line:" << __LINE__ << ")" << '\n';
#define debugpair(x, y) cerr << "(" << #x << ", " << #y << ") -> (" << x << ", " << y << ") (line:" << __LINE__ << ")" << '\n';
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
typedef vector<lint> vec;
typedef vector<vector<lint>> matrix;
typedef priority_queue<lint> p_que;
typedef priority_queue<lint, vector<lint>, greater<lint>> p_que_rev;
const lint INF = INT_MAX;
const lint LINF = LLONG_MAX;
const lint MOD = 1000000000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int di[]{0, -1, 0, 1, -1, -1, 1, 1};
const int dj[]{1, 0, -1, 0, 1, -1, -1, 1};

lint gcd(lint a, lint b) {
  lint r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

lint lcm(lint a, lint b) {
  return (a / gcd(a, b)) * b;
}

lint power(lint x, lint n, lint mod = MOD) {
  lint ret = 1;
  while(n > 0) {
    if(n & 1){
      (ret *= x) %= mod;
    }
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

vector<lint> make_power(int n, lint base){
  lint num = 1;
  vector<lint> ret;
  for (int i=0; i<=n; ++i){
    ret.push_back(num);
    num *= base;
  }
  return ret;
}

// vars
int n, idx;
vector<tuple<string, int, int>> a;
string is_stable = "Stable";

void input(){
  cin >> n;
  a.resize(n);
  string s;
  int num;
  REP(i, n){
    cin >> s >> num;
    a[i] = make_tuple(s, num, i);
  }
}

void output(){
  cout << is_stable << endl;
  REP(i, n)
  {
    cout << get<0>(a[i]) << " " << get<1>(a[i]) << endl;
  }
}

int partition(int p, int r){
  int x = get<1>(a[r]);
  int i = p - 1;
  FOR(j, p, r){
    if (get<1>(a[j]) <= x){
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[r]);
  return i + 1;
}

void quicksort(int p, int r){
  if (p < r){
    int q = partition(p, r);
    quicksort(p, q - 1);
    quicksort(q + 1, r);
  }
}

void solve(){
  quicksort(0, n - 1);
  int idx = -1;
  int num = -1;
  REP(i, n)
  {
    if (num != get<1>(a[i])){
      num = get<1>(a[i]);
      idx = get<2>(a[i]);
    }
    else if(idx > get<2>(a[i])){
      is_stable = "Not stable";
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  output();
  return 0;
}
