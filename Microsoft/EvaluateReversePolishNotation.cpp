class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long second = st.top();
                st.pop();
                long long first = st.top();
                st.pop();
                long long ans = 0;
                if(tokens[i] == "+") ans = first + second;
                if(tokens[i] == "-") ans = first - second;
                if(tokens[i] == "*") ans = first * second;
                if(tokens[i] == "/") ans = first / second;
                st.push(ans);
            } else {
                long long x = stoi(tokens[i]) * 1LL;
                st.push(x);
            }
        }
        return (int)st.top();
    }
};