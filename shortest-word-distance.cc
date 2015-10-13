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
    int i = 0, j = 0;
    while(i < M[word1].size() && j < M[word2].size()) {
      dis = min(dis, abs(M[word1][i] - M[word2][j]));
      M[word1][i] < M[word2][j] ? i ++ : j ++;
    }
    return dis;
  }
};
