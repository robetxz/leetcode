class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int result = nums[0];
    int cnt = 1;
    for(size_t i = 1; i < nums.size(); ++i) {
      if(nums[i] != result) {
        cnt -= 1;
        if(cnt == 0) {
          result = nums[i];
          cnt = 1;
        }
      } else {
        cnt += 1;
      }
    }
    return result;
  }
};
