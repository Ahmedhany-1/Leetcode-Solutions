class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, last = n + m - 1;
        while(p2 >= 0){
            if(p1 >= 0 && nums1[p1] > nums2[p2])
                nums1[last] = nums1[p1--];
            else
                nums1[last] = nums2[p2--];
            last--;
        }
    }
};

//     int p1 = m - 1, p2 = n - 1, p3 = m + n - 1;
//     while (p1 >= 0 && p2 >= 0) {
//         if (nums1[p1] >= nums2[p2]) {
//             nums1[p3--] = nums1[p1--];
//         } else {
//             nums1[p3--] = nums2[p2--];
//         }
//     }

//     while (p2 >= 0) {
//         nums1[p3--] = nums2[p2--];
//     }

