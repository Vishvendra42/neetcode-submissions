class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;

        for (auto& it : s) {
            if (it == '[' || it == '{' || it == '(') {
                st.push(it);
            } else {
                if (st.size() == 0) return false;
                char ch = st.top();
                if (it == ')' && '(' == ch)
                    st.pop();
                else if (it == ']' && '[' == ch)
                    st.pop();
                else if (it == '}' && '{' == ch)
                    st.pop();
                else
                    return false;
            }
        }

        if (st.size() != 0) return false;
        return true;
    }
};
