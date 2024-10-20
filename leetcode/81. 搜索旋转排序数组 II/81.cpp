class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int mid = -1;
        int right = nums.size() - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[left] == nums[mid])
            {
                left++;
                continue;
            }
            if (nums[left] < nums[mid])
            {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};