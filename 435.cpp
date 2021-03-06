/*
435. Post Office Problem

On one line there are n houses. Give you an array of integer means the the position of each house. Now you need to pick k position to build k post office, so that the sum distance of each house to the nearest post office is the smallest. Return the least possible sum of all distances between each village and its nearest post office.
Have you met this question in a real interview?
Example
Given array a = [1,2,3,4,5], k = 2. return 3.
Challenge
Could you solve this problem in O(n^2) time ?
*/

// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        const int n = A.size();
        if (A.empty() || k >= n) {
            return 0;
        }

        sort(A.begin(), A.end());  // Time:  O(nlogn)

        // Precompute cost.
        // Time:  O(n^3)
        // Space: O(n^2)
        vector<vector<int>> cost(A.size() + 1, vector<int>(A.size() + 1, 0));
        computeMinCost(A, &cost);

        // DP of sum.
        // Time:  O(k * n^2)
        // Space: O(n)
        // sum[i][j] denotes the smallest sum of
        // picking i post offices for the first j houses.
        vector<vector<int>> sum(2, vector<int>(A.size() + 1, INT_MAX));
        sum[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j <= n; ++j) {
                // sum[i % 2][j] = INT_MAX;
                for (int r = 1; r <= j; ++r) {
                    if (sum[(i - 1) % 2][j - r] != INT_MAX) {
                        sum[i % 2][j] = min(sum[i % 2][j],
                                            sum[(i - 1) % 2][j - r] +
                                            cost[j - r + 1][j]);
                    }
                }
            }
        }
        return sum[k % 2][n];
    }

    void computeMinCost(const vector<int>& A, vector<vector<int>> *cost) {
        // Min cost of building a post office between house (i, j).
        // This post office must be in median position.
        const int n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int mid = (i + j) / 2;
                for (int r = i; r <= mid; ++r) {
                    (*cost)[i + 1][j + 1] += A[mid] - A[r];
                }
                for (int r = mid + 1; r <= j; ++r) {
                    (*cost)[i + 1][j + 1] += A[r] - A[mid];
                }
            }
        }
    }
};
