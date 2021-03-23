#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

// n が素数かどうかを判定する
// n: 整数
// return: bool
bool is_prime(lint n) {
  assert(n > 0);
  if (n == 1) {
    return false;
  }
  for (lint i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// n の約数を列挙する
vector<lint> divisor(lint n) {
  assert(n > 0);
  vector<lint> res;

  for (lint i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) {
        res.push_back(n / i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

// n を素因数分解する
// n : 整数
// return:
pair<vector<lint>, vector<lint>> prime_factor(lint n) {
  assert(n > 0);
  vector<lint> prime_num, cnt;
  lint m = n;
  for (lint i = 2; i * i <= n; i++) {
    if (m % i != 0) {
      continue;
    }
    lint c = 0;
    while (m % i == 0) {
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

// オイラーのファイ関数
lint euler_phi(lint n) {
  lint res = n;
  auto pf = prime_factor(n);
  for (auto prime_num : pf.first) {
    res *= prime_num - 1;
    res /= prime_num;
  }
  return res;
}

int main() {
  lint n;
  cin >> n;
  auto v = divisor(n);
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << endl;
  }
  return 0;
}