#pragma once

// https://leetcode.com/problems/insertion-sort-list/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertOptimal(ListNode* const begin, int value) {
    ListNode* prev = nullptr;
    for (auto* node = begin; node; node = node->next) {
        if (value < node->val) {
            auto* newNode = new ListNode(value, node);
            if (prev) {
                prev->next = newNode;
            }
            return prev ? begin : newNode;
        }
        prev = node;
    }
    auto* newNode = new ListNode(value);
    prev->next = newNode;
    return begin;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        auto* begin = new ListNode(head->val);
        for (head = head->next; head; head = head->next) {
            begin = insertOptimal(begin, head->val);
        }
        return begin;
    }
};
