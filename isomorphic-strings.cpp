class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool ret = true;
        unordered_map<char, char> m;
        unordered_set<char> mapped;
        
        for(int i = 0; i < s.size() ; i++)
        {
            if(m.find(s[i]) == m.end())
                {
                    if(mapped.find(t[i]) == mapped.end()){
                        mapped.insert(t[i]);
                        m[s[i]] = t[i];
                    }
                }
                
                if(m[s[i]] != t[i]) ret = false;

            if (ret == false) break;
        }
        return ret;
    }
};
