#pragma once

#include <vector>

// https://leetcode.com/problems/binary-tree-level-order-traversal/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        std::deque<TreeNode*> nodes;
        if (root)
            nodes.push_back(root);
        while (!nodes.empty()) {
            std::vector<TreeNode*> levelNodes;
            while (!nodes.empty()) {
                levelNodes.push_back(nodes.front());
                nodes.pop_front();
            }
            result.push_back({});
            for (const auto* node : levelNodes) {
                if (node->left) {
                    nodes.push_back(node->left);
                }
                if (node->right) {
                    nodes.push_back(node->right);
                }
                result.back().push_back(node->val);
            }
        }
        return result;
    }
};