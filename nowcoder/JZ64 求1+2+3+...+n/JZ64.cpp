class Sum
{
public:
    Sum()
    {
        _count += _i;
        _i++;
    }

    static int GetN()
    {
        return _count;
    }

private:
    static int _count;
    static int _i;
};

int Sum::_count = 0;
int Sum::_i = 1;

class Solution {
public:
    //˼·�����캯��    static����
    int Sum_Solution(int n)
    {
        Sum _n[n];
        //Sum* _n = new Sum[n];
        return Sum::GetN();
    }
};