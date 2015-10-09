class Solution {

 public:
  // line 22: to handle case[[0, 1], [1, 3], [3, 1], [3, 2]]
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> vp; vp.resize(numCourses);
    for(auto & pr : prerequisites) vp[pr.first].push_back(pr.second);
    while(1) {
      // every round
      bool isEmpty = true;
      unordered_set<int> B;
      for(int i = 0; i < numCourses; ++i) {
        if(vp[i].size() != 0) {
          isEmpty = false;
          int left = i, right = vp[i].back();
          vp[i].pop_back();
          B.insert(left);
          while(vp[right].size() != 0) {
            left = right;
            int tmp = vp[right].back();
            vp[right].pop_back();
            for(auto & vv : vp[right]) if(B.count(vv)) return false;
            right = tmp;
            if(B.count(right)) return false;
            B.insert(left);
          }
          break;
        }
      }
      if(isEmpty) break;
    }
    return true;
  }
};
