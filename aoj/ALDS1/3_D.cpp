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
string s;
lint a;
vector<lint> l;

void input(){
  cin >> s;
  l.resize(0);
}

void output(){
  cout << a << endl;
  cout << l.size();
  REP(i, l.size()){
    cout << " " << l[i];
  }
  cout << endl;
}

bool tuple_sort(tuple<int, int, int> t1, tuple<int, int, int> t2){
  if(get<0>(t1) == get<0>(t2)){
    return get<1>(t1) < get<1>(t2);
  }
  return get<0>(t1) < get<0>(t2);
}

void solve(){
  int n = s.length();
  stack<char> stk;
  int cnt = 0;
  vector<tuple<int, int, int>> pond(0);

  REP(i, n){
    char c = s[i];
    if(c == '/'){
      bool is_pond_exists = false;
      cnt = 0;
      while(!stk.empty()){
        char tp = stk.top();
        stk.pop();
        if(tp == '_'){
          cnt++;
        }
        else if(tp == '\\'){
          int area = cnt + 1;
          int right = i;
          int left = i - cnt - 1;
          pond.push_back(make_tuple(left, right, area));
          REP(j, cnt + 2){
            stk.push('_');
            // cout << "-";
          }
          // cout << cnt << endl;
          is_pond_exists = true;
          break;
        }
      }
      if(!is_pond_exists){
        cnt = 0;
      }
    }
    else if(c == '\\' || c == '_'){
      stk.push(c);
    }
  }
  sort(ALL(pond), tuple_sort);
  int r = -1;
  int area = 0;
  REP(i, pond.size()){
    int left = get<0>(pond[i]);
    if(r < left){
      if(i != 0){l.push_back(area);}
      area = get<2>(pond[i]);
      r = get<1>(pond[i]);
    }
    else {
      r = max(r, get<1>(pond[i]));
      area += get<2>(pond[i]);
    }
  }
  if(area > 0){
    l.push_back(area);
  }
  REP(i, l.size()){
    a += l[i];
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
