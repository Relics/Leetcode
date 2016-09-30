class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int size = (int)matrix.size();
        int l=matrix[0][0], r=matrix[size-1][size-1];
        while (l<r){
            int num = 0;
            int mid = l+(r-l)/2;
            for (int i=0; i<size; ++i){
                    int temp = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                    num += temp;
            }
            if (num<k) {
                l = mid+1;
            }else {
                r = mid;
            }
        }
        return l;
    }
};