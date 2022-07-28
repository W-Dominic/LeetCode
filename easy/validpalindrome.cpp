class Solution {
public:
    bool isPalindrome(string s) {
        //nonalphanumerics capital
        vector<char> newString; 
        for (int i = 0; i< s.length(); i++) {
            if ( s[i] > 64 && s[i] < 91) { //capital letter
                char newChar = s[i] + 32;
                newString.push_back(newChar);
            }
            else if(
                 (s[i] > 47 && s[i] < 58) ||
                 (s[i] > 96 && s[i] < 123)
                ) 
            {
                newString.push_back(s[i]);    
            }
        }
        
        /*
        for (int i = 0; i<newString.size(); i++){
            cout << newString[i];
        }
        cout<< endl;
        */
        
        //palindrome
        stack<char> mystack;
        //push to stack
        for (int i = 0; i<newString.size(); i++){
            mystack.push(newString[i]);
        }
        //pop from stack
        for (int i = 0; i < newString.size(); i++){
            if(newString[i] == mystack.top()){
                mystack.pop();        
            }
        }
        if (mystack.empty()){
            return true;
        }
        return false;
    }
};
