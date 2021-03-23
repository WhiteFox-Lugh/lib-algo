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
vector<string> c_b, c_s;
string bubble_is_stable = "Stable", selection_is_stable = "Stable";

void input(){
  cin >> n;
  c_b.resize(n);
  REP(i, n){
    cin >> c_b[i];
  }
  c_s = c_b;
}

void output(){
  REP(i, n){
    if(i == n-1){
      cout << c_b[i] << endl;
    }
    else {
      cout << c_b[i] << " ";
    }
  }
  cout << bubble_is_stable << endl;
  REP(i, n){
    if(i == n-1){
      cout << c_s[i] << endl;
    }
    else {
      cout << c_s[i] << " ";
    }
  }
  cout << selection_is_stable << endl;
}

void solve(){
  vector<vector<string>> check;
  check.resize(10);
  REP(i, 10){
    check[i].resize(0);
  }
  REP(i, n){
    int idx = c_b[i][1] - '0';
    check[idx].push_back(c_b[i]);
  }
  // bubble sort
  REP(i, n){
    REP(j, n - 1){
      int num1 = c_b[j][1] - '0';
      int num2 = c_b[j + 1][1] - '0';
      if(num1 > num2){
        swap(c_b[j], c_b[j + 1]);
      }
    }
  }
  FOR(i, 1, 10){
    int idx = 0;
    if(check[i].size() == 0){continue;}
    REP(j, n){
      if(idx != check[i].size() && c_b[j] == check[i][idx]){
        idx++;
      }
    }
    if(idx != check[i].size()){
      bubble_is_stable = "Not stable";
    }
  }
  // selection sort
  REP(i, n-1){
    int min_j = i;
    FOR(j, i+1, n){
      int num1 = c_s[min_j][1] - '0';
      int num2 = c_s[j][1] - '0';
      if(num1 > num2){
        min_j = j;
      }
    }
    if(min_j != i){
      swap(c_s[min_j], c_s[i]);
    }
  }
  FOR(i, 1, 10){
    int idx = 0;
    if(check[i].size() == 0){continue;}
    REP(j, n){
      if(idx != check[i].size() && c_s[j] == check[i][idx]){
        idx++;
      }
    }
    if(idx != check[i].size()){
      selection_is_stable = "Not stable";
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