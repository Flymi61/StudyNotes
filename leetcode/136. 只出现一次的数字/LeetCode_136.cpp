class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //���
        int _num = 0;
        for (auto e : nums)
        {
            _num = _num ^ e;
        }
        return _num;
    }
};