#include <iostream>

using namespace std;

int main()
{
    int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    int year, month, day;
    cin >> year >> month >> day;
    int num = days[month - 1] + day;
    //�ж��Ƿ�Ϊ���꣬�Ҵ���2�£�������������1
    if (year % 4 == 0 && year % 100 != 0 && month > 2)
    {
        cout << num + 1;
    }
    else
    {
        cout << num;
    }
    return 0;
}
