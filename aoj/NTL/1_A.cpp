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

pair<vector<lint>, vector<lint>> prime_factor(lint n) {
  assert(n > 0);
  vector<lint> prime_num, cnt;
  lint m = n;
  for (lint i = 2; i * i <= n; i++) {
    if (m % i != 0){
        continue;
    }
    lint c = 0;
    while (m % i == 0){
        c++;
        m /= i;
    }
    prime_num.push_back(i);
    cnt.push_back(c);
  }
  if (m > 1) {
    prime_num.push_back(m);
    cnt.push_back(1);
  }
  return make_pair(prime_num, cnt);
}

// vars
lint n;

void input(){
  cin >> n;
}

void output(){

}

void solve(){
  auto [p, cnt] = prime_factor(n);
  cout << n << ":";
  REP(i, p.size()){
    lint num = p[i];
    lint count = cnt[i];
    REP(j, count){
      cout << " " << p[i];
    }
  }
  cout << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  output();
  return 0;
}