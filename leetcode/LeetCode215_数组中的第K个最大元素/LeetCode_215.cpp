/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //����һ������
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};*/

/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //�������������
        priority_queue<int> pq;
        for(size_t i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
       while(--k)
       {
           pq.pop();
       }
        return pq.top();
    }
};*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //����������k������С��
        priority_queue<int, vector<int>, greater<int>> pq;
        for (size_t i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (size_t i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};