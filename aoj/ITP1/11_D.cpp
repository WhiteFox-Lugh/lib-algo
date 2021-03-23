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
struct dice {
  int num[6];
};

void roll(dice &d, char dir){
  int tmp;
  if(dir == 'N'){
    tmp = d.num[0];
    d.num[0] = d.num[1];
    d.num[1] = d.num[5];
    d.num[5] = d.num[4];
    d.num[4] = tmp;
  }
  else if(dir == 'E'){
    tmp = d.num[5];
    d.num[5] = d.num[2];
    d.num[2] = d.num[0];
    d.num[0] = d.num[3];
    d.num[3] = tmp;
  }
  else if(dir == 'W'){
    tmp = d.num[3];
    d.num[3] = d.num[0];
    d.num[0] = d.num[2];
    d.num[2] = d.num[5];
    d.num[5] = tmp;
  }
  else if(dir == 'S'){
    tmp = d.num[4];
    d.num[4] = d.num[5];
    d.num[5] = d.num[1];
    d.num[1] = d.num[0];
    d.num[0] = tmp;
  }
  return;
}

vector<dice> dices;
int n;

void input(){
  cin >> n;
  dices.resize(n);
  REP(i, n){
    REP(j, 6){
      cin >> dices[i].num[j];
    }
  }
}

void output(){
}

bool is_dice_same(dice d1, dice d2){
  REP(i, 6){
    if(d1.num[i] != d2.num[i]){
      return false;
    }
  }
  return true;
}

void solve(){
  REP(i, n){
    FOR(j, i+1, n){
      dice dice1 = dices[i];
      dice dice2 = dices[j];
      REP(i, 40){
        if(is_dice_same(dice1, dice2)){
          cout << "No" << endl;
          return;
        }
        else if(i % 5 == 4 && i % 20 != 19){
          roll(dice2, 'E');
        }
        else {
          roll(dice2, 'N');
        }
      }
    }
  }
  cout << "Yes" << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  output();
  return 0;
}