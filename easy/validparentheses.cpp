#include <stack>
#include <string>
#include <map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        map<char, char> mymap;
        mymap['('] = ')';
        mymap['['] = ']';
        mymap['{'] = '}';
        
        
        for (int i = 0; i<s.size(); i++){
            if (s[i] == '(') mystack.push('(');
            else if (s[i] == '[') mystack.push('[');
            else if (s[i] == '{') mystack.push('{');
            else if (mystack.empty()) return false; //s must start with open
            else if (s[i] == mymap[mystack.top()]) mystack.pop();
            else{
                return false;
            }
        }
        if (mystack.empty()){
            return true;
        }
        return false;
    }
};
