#pragma once

#include <cstddef>
#include <vector>

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void build_unordered_tree(TreeNode* node,
    std::unordered_map<TreeNode*, std::unordered_set<TreeNode*>>& neighbors,
    std::unordered_set<TreeNode*>& visited_nodes)
{
    if (visited_nodes.count(node))
        return;
    visited_nodes.insert(node);
    if (node->left) {
        neighbors[node].insert(node->left);
        neighbors[node->left].insert(node);
        build_unordered_tree(node->left, neighbors, visited_nodes);
    }
    if (node->right) {
        neighbors[node].insert(node->right);
        neighbors[node->right].insert(node);
        build_unordered_tree(node->right, neighbors, visited_nodes);
    }
}

void visit_unordered_tree(TreeNode* node,
    const std::unordered_map<TreeNode*, std::unordered_set<TreeNode*>>& neighbors,
    std::unordered_set<TreeNode*>& visited_nodes,
    const int k,
    std::vector<int>& values)
{
    if (visited_nodes.count(node) > 0)
        return;
    visited_nodes.insert(node);

    if (k > 0) {
        const auto it = neighbors.find(node);
        if (it != neighbors.cend()) {
            const auto& nodes = it->second;
            for (auto* n : nodes)
                visit_unordered_tree(n, neighbors, visited_nodes, k-1, values);
        }
    } else {
        values.push_back(node->val);
    }
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::unordered_map<TreeNode*, std::unordered_set<TreeNode*>> neighbors;
        std::unordered_set<TreeNode*> visited_nodes;
        std::vector<int> values;
        build_unordered_tree(root, neighbors, visited_nodes);
        visited_nodes.clear();
        visit_unordered_tree(target, neighbors, visited_nodes, k, values);
        return values;
    }
};