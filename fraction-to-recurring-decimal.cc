class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    string result;
    bool negative = false;
    unordered_map<long long, int> table;
    if((numerator < 0 && denominator > 0) 
       || (numerator > 0 && denominator < 0)) negative = true;
    long long N = abs(static_cast<long long>(numerator));
    long long M = abs(static_cast<long long>(denominator));
    result += to_string(N / M);
    result.push_back('.');
    N = (N % M) * 10;
    while(N) {
      long long r = N / M;
      long long m = N % M;
      if(table.count(N)) {
        result += ")";
        result.insert(result.begin() + table[N], '(');
        if(negative) result.insert(result.begin(), '-');
        return result;
      }
      result += to_string(r);
      table[N] = result.size() - 1;
      N = m * 10;
    }
    if(negative) result.insert(result.begin(), '-');
    if(result.back() == '.') return result.substr(0, result.size() - 1);
    return result;
  }
};
