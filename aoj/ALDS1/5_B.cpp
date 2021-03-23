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
int n;
int cf = 0;
vector<int> s;

void input(){
  cin >> n;
  s.resize(n);
  REP(i, n){
    cin >> s[i];
  }
}

void output(){
  REP(i, n){
    if(i == n-1){
      cout << s[i] << endl;
    }
    else {
      cout << s[i] << " ";
    }
  }
  cout << cf << endl;
}

void merge(int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> l(n1 + 1), r(n2 + 1);
  REP(i, n1){
    l[i] = s[left + i];
  }
  REP(i, n2){
    r[i] = s[mid + i];
  }
  l[n1] = INF;
  r[n2] = INF;
  int i = 0, j = 0;
  FOR(k, left, right){
    cf++;
    if(l[i] <= r[j]){
      s[k] = l[i];
      i++;
    }
    else {
      s[k] = r[j];
      j++;
    }
  }
}

void mergeSort(int left, int right){
  if (left + 1 < right){
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

void solve(){
  mergeSort(0, n);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  output();
  return 0;
}
