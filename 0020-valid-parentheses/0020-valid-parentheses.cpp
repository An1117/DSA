class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> closetoOpen {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c: s){
            if(closetoOpen.count(c)){
                if(!st.empty() && st.top() == closetoOpen[c]){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                st.push(c);
            }
        }
        return st.empty();
    }
};