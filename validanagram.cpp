#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        // O(n) overall runtime
       
        //first check if lengths are equal
        int s_len = s.length();
        int t_len = t.length();
        if (t_len != s_len){
            return false;
        }
        //add elements of s to map, keeping track of occurances
        unordered_map<char, int> hash; 
        for (int i = 0; i<s_len; i++){
            char curr = s[i];
            if(hash.find(curr) != hash.end()){
                hash[curr] += 1;
            }
            else {
                hash[curr] = 1;
            }   
        }
        //check elements of t against map
        for (int i =0; i<t_len; i++){
            char curr = t[i];
            if(hash.find(curr) != hash.end()){
                hash[curr] -= 1;
                if (hash[curr] < 0){
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
        /*
        unordered_map<char, int>::iterator itr; 
        for (itr = hash.begin(); itr != hash.end(); itr ++){
            cout << itr->first << "," << itr->second << endl;
        }
        */
    }
};
