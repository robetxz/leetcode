class Solution {

 public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    unordered_map<string, vector<int>> M;
    for(int i = 0; i < words.size(); ++i) {
      if(words[i] == word1 || words[i] == word2) {
        M[words[i]].push_back(i);
      }
    }
    int dis = INT_MAX;
    for(auto & indx1 : M[word1]) {
      for(auto & indx2 : M[word2]) {
        dis = min(dis, abs(indx1 - indx2));
      }
    }
    return dis;
  }
};
