/*
122. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.
Have you met this question in a real interview?
Example Given height = [2,1,5,6,2,3],
return 10.
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        vector<int> &a = height;
        int n = a.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dl(n), dr(n);
        int i;
        dl[0] = 0;
        for (i = 1; i <= n - 1; ++i) {
            dl[i] = i;
            while (dl[i] - 1 >= 0 && a[dl[i] - 1] >= a[i]) {
                dl[i] = dl[dl[i] - 1];
            }
        }
        dr[n - 1] = n - 1;
        for (i = n - 2; i >= 0; --i) {
            dr[i] = i;
            while (dr[i] + 1 <= n - 1 && a[dr[i] + 1] >= a[i]) {
                dr[i] = dr[dr[i] + 1];
            }
        }
        int ans = 0;
        for (i = 0; i < n; ++i) {
            ans = max(ans, a[i] * (dr[i] - dl[i] + 1));
        }
        return ans;
    }
};
