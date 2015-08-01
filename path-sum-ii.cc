/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  void bt(TreeNode* root, int sum,
          vector<int> & path, vector<vector<int>> & result) {
    if(root == NULL) return;
    if(root->val == sum && root->left == NULL && root->right == NULL) {
      path.push_back(root->val);
      result.push_back(path);
      return;
    }
    vector<int> path_tmp = path;
    path.push_back(root->val);
    bt(root->left, sum - root->val, path, result);
    path = path_tmp;
    path.push_back(root->val);
    bt(root->right, sum - root->val, path, result);
  }

  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    vector<int> path;
    if(root == NULL) return result;
    bt(root, sum, path, result);
    return result;
  }
};
