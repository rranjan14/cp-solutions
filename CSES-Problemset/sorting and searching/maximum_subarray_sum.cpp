#include <iostream>
#include <vector>
#define lli long long int
using namespace std;
int main()
{
    lli n, sum, global_sum;
    cin >> n;
    vector<lli> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    global_sum = nums[0];
    sum = nums[0];
    for (auto i = nums.begin(); i != nums.end(); i++)
    {
        sum = max(sum + *i, *i);
        global_sum = max(global_sum, sum);
    }
    cout << global_sum;
    return 0;
}