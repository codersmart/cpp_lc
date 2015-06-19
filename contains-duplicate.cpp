class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // 28 ms
        int * data = nums.data();
        qsort(data, nums.size(), sizeof *data, 
            [](const void * a, const void *b){ 
                int arg1 = *static_cast<const int*>(a);
                int arg2 = *static_cast<const int*>(b);
             
                if(arg1 < arg2) return -1;
                if(arg1 > arg2) return 1;
                return 0;
                
                }
        );
        auto begin = nums.begin();
        auto end = nums.end();
        return adjacent_find(begin, end)        != end;
    }
    bool One_40ms(vector<int>& nums){
        auto begin = nums.begin();
        auto end = nums.end();
        sort(begin, end);
        return adjacent_find(begin, end)
        != end;
        
    }
    bool One_48ms(vector<int>& nums) {
        auto begin = nums.begin();
        auto end = nums.end();
        unordered_set<int> s(begin, end);
        
        return s.size() != nums.size();
        
    }
};
