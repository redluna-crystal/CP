#include <bits/stdc++.h>
#include<cstring>
using namespace std;

int cutRod(int p[], int n){
  
  if (n == 0) return 0;
  int q = INT_MIN;
  for (int i=0; i<n; i++){
    q = max(q, p[i]+cutRod(p, n-i-1));
  }
  return q;
} 

int cutRodAux(int p[], int n, int r[]){
  int q;
  if (r[n] >= 0) return r[n];
  if (n==0) return 0;
  else{
    q = INT_MIN;
    for(int i=0; i<n; i++){
      q = max(q, p[i]+cutRodAux(p, n-i-1, r));
    }
  }
  r[n] = q;
  return q;
}

int memoizedCutRod(int p[], int n){
  int r[n+1];
  for (int i=0; i<=n; i++) r[i] = INT_MIN;
  return cutRodAux(p, n, r);
}

int bottomUpSol(int p[], int n){
  int r[n+1];
  r[0] = 0;
  int q;
  for (int i=1; i<= n; i++){
    q = INT_MIN;
    for (int j=0; j<i; j++){
      q = max(q, p[j]+r[i-j-1]);
    }
    r[i] = q;
  }
  return r[n];
}

const int N = 1000;
int r[N], s[N];
int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

void init(){
  memset(r, -1, N);
  r[0] = 0;
}

int extendedButtomUpCutRod(int n) {

    if (r[n] != -1)
        return r[n];
    for (int j = 1; j <= n; ++j) {
        int q = 0;
        for (int i = 1; i <= j; ++i)
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        r[j] = q;
    }
    return r[n];
}
 
// prins the extended method's output
void printCutRodSoln(int n) {
    do
        cout << s[n] << " ";
    while ((n -= s[n]) > 0);
}
 
int main() {
    init();  
    int n = 4;
    cout << extendedButtomUpCutRod(n) << endl;
    printCutRodSoln(n);
    return 0;
}