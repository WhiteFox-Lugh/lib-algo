#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b - 1); i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define SIZE(x) ((int)(x).size())
#define debug(x) \
  cerr << #x << " -> " << x << " (line:" << __LINE__ << ")" << '\n';
#define debugpair(x, y)                                         \
  cerr << "(" << #x << ", " << #y << ") -> (" << x << ", " << y \
       << ") (line:" << __LINE__ << ")" << '\n';
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
  assert(a > 0 && b > 0);
  lint r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

lint gcd_vec(vector<lint> vec) {
  int len = vec.size();
  lint res = vec[0];
  for (int i = 1; i < len; ++i) {
    res = gcd(res, vec[i]);
  }
  return res;
}

lint lcm(lint a, lint b) {
  assert(a > 0 && b > 0);
  return (a / gcd(a, b)) * b;
}

lint lcm_vec(vector<lint> vec) {
  int len = vec.size();
  lint res = vec[0];
  for (int i = 1; i < len; ++i) {
    res = lcm(res, vec[i]);
  }
  return res;
}

lint extgcd(lint a, lint b, lint &x, lint &y) {
  lint g = a;
  x = 1;
  y = 0;
  if (b != 0) {
    g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return g;
}

lint power(lint x, lint n, lint mod = MOD) {
  lint ret = 1;
  while (n > 0) {
    if (n & 1) {
      (ret *= x) %= mod;
    }
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

vector<lint> make_power(int n, lint base) {
  lint num = 1;
  vector<lint> ret;
  for (int i = 0; i <= n; ++i) {
    ret.push_back(num);
    num *= base;
  }
  return ret;
}

// vars
int n, q;
vector<int> a;

void input() {
  cin >> n;
  a.resize(n);
  REP(i, n) { cin >> a[i]; }
}

void output() {}

void solve() {
  int com, b, e;
  cin >> q;
  REP(loop, q) {
    cin >> com >> b >> e;
    if (com == 0) {
      int min_num = *min_element(a.begin() + b, a.begin() + e);
      cout << min_num << endl;
    } else {
      int max_num = *max_element(a.begin() + b, a.begin() + e);
      cout << max_num << endl;
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