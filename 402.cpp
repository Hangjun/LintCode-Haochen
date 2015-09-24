/*
402. Continuous Subarray Sum

Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)
Have you met this question in a real interview?
Example
Give [-3, 1, 3, -3, 4], return [1,4].
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        int n = A.size();
        int ll;
        int sum;
        int msum;
        
        ll = 0;
        msum = A[0];
        int i;
        for (i = 1; i < n; ++i) {
            if (A[i] > msum) {
                msum = A[i];
                ll = i;
            }
        }
        vector<int> ans;
        if (msum <= 0) {
            ans.push_back(ll);
            ans.push_back(ll);
            return ans;
        }
        
        int mll, mrr;
        ll = 0;
        msum = sum = 0;
        for (i = 0; i < n; ++i) {
            sum += A[i];
            if (sum < 0) {
                sum = 0;
                ll = i + 1;
            }
            if (sum > msum) {
                msum = sum;
                mll = ll;
                mrr = i;
            }
        }
        ans.push_back(mll);
        ans.push_back(mrr);
        return ans;
    }
};
