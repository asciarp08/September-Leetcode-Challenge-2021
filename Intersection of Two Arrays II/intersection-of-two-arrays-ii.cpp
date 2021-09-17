/**
Time Complexity
1. Hash Table approach
Time - O(n+m)
Space - O(min(n,m))

2. Sorting approach
Time - O(nlogn+mlogm)
Space - O(logn + logm) to O(n+m) depending on the implementation of the sorting algorithm
**/
/**
Approach 1:
**/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n>m){
            swap(nums1, nums2);
        }
        
        unordered_map<int,int> cnt;
        
        for(auto num:nums1){
            cnt[num]++;
        }
        vector<int>ans;
        
        for(auto num:nums2){
            if(cnt.count(num) && cnt[num]>0){
                ans.push_back(num);
                cnt[num]--;
            }
        }
        return ans;
    }
};

/**
Approach 2:
**/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));
		int i = 0, j = 0, k = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j]) {
				++i;
			} else if (nums1[i] > nums2[j]) {
				++j;
			} else {
				nums1[k++] = nums1[i++];
				++j;
			}
		}
		return vector<int>(begin(nums1), begin(nums1) + k);
	}
};
