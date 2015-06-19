#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    using VVii = vector<vector<int>::iterator> ;
    using vii = vector<int>::iterator ;
  
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        bool ret = false;
        VVii v;
        for(size_t t=0; t < nums.size(); t++){
            v.push_back(nums.begin() + t);
        }
        sort(v.begin(), v.end(), [](vii a, vii b){
                return *a < *b;});
          

        auto first = v.begin();
        auto next = first;
        auto end = v.end();
        while(first != end){
            next = first + 1;
            while(next != end && ((**next - **first) <= t && (**next - **first) >=0))
            {
                if (abs(*next - *first) <= k)  return true;
                next ++;
            }
            first ++;
        }
        
        
        return ret;
        
    }
};
int main_20ms()
{
    vector<int> a = {1,3,6, 2};
    Solution c;
    std::cout <<std::boolalpha<< c.containsNearbyAlmostDuplicate(a,1, 2);
    return 0;
}
