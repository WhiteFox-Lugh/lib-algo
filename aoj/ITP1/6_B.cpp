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
vector<pint> card;
vector<pair<string, int>> ans;
int is_own[4][13];

void input(){
  cin >> n;
  card.resize(n);
  string s;
  int k;
  REP(i, n){
    cin >> s >> k;
    card[i].snd = k;
    if(s == "S"){
      card[i].fst = 0;
    }
    else if(s == "H"){
      card[i].fst = 1;
    }
    else if(s == "C"){
      card[i].fst = 2;
    }
    else {
      card[i].fst = 3;
    }
  }
}

void output(){
  REP(i, ans.size()){
    cout << ans[i].fst << " " << ans[i].snd << endl;
  }
}

void solve(){
  REP(i, 4){
    REP(j, 13){
      is_own[i][j] = 0;
    }
  }
  for(auto itr=card.begin(); itr!=card.end(); ++itr){
    int i = (*itr).fst;
    int j = (*itr).snd;
    is_own[i][j - 1] = 1;
  }
  REP(i, 4){
    REP(j, 13){
      string s;
      if(is_own[i][j] == 0){
        if(i == 0){s = "S";}
        else if(i == 1){s = "H";}
        else if(i == 2){s = "C";}
        else if(i == 3){s = "D";}
        ans.push_back(mp(s, j + 1));
      }
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
