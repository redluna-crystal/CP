#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/// 2 1            3 2 1

string solve(vector<int>& v){
  int pivot;
  for (pivot = v.size()-1; pivot >0; pivot--){
    if (v[pivot-1] < v[pivot]) {
      break;
    }
  }
  pivot--;

  if (pivot == -1) return "-1";

  int j;
  for (j = pivot+1; j<v.size(); j++){
    if (v[j] < v[pivot]) {
      break;
    }
  }
  j--;

  //swapping the terms
  int temp = v[pivot];
  v[pivot] = v[j];
  v[j] = temp;

  string ans = "";
  for (int i= 0; i<=pivot; i++ ){
    ans += to_string(v[i]);
  }
  for (int i= v.size()-1; i>pivot; i--){
    ans += to_string(v[i]);
  }
  return ans;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--){
    int n; cin >> n;
    vector<int> arr;
    while(n--){
      int a; cin >> a;
      arr.push_back(a);
    }
    cout << solve(arr) << endl;
  }
  return 0;
}