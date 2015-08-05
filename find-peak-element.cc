class Solution {
 public:
  int findPeakElement(const vector<int> &num) {
    int s = 0, e = num.size() - 1, m = 0;
    while(s <= e) {
      m = s + (e - s) / 2;
      if((m == 0 || num[m-1] < num[m])
         && ((m == num.size() - 1) || num[m] > num[m+1])) {
          return m;
      } else if(m > 0 && num[m-1] > num[m]) {
        e = m - 1;
      } else {
        s = m + 1;
      }
    }
    return m;
  }
};
