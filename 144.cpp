/*
144. Interleaving Positive and Negative Numbers

Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.
Have you met this question in a real interview?
Example
Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other reasonable answer.
Note
You are not necessary to keep the original order of positive integers or negative integers.
Challenge
Do it in-place and without extra memory.
*/

// O(n) time and O(1) space
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        int n = A.size();
        int n1, n2;
        int i, j;
        
        n1 = n2 = 0;
        for (i = 0; i < n; ++i) {
            if (A[i] < 0) {
                ++n1;
            } else {
                ++n2;
            }
        }
        if (n1 >= n2) {
            i = 0;
            j = 1;
            while (i < n && j < n) {
                if (A[i] < 0) {
                    i += 2;
                } else if (A[j] > 0) {
                    j += 2;
                } else {
                    swap(A[i], A[j]);
                    i += 2;
                    j += 2;
                }
            }
        } else {
            i = 0;
            j = 1;
            while (i < n && j < n) {
                if (A[i] > 0) {
                    i += 2;
                } else if (A[j] < 0) {
                    j += 2;
                } else {
                    swap(A[i], A[j]);
                    i += 2;
                    j += 2;
                }
            }
        }
    }
};
