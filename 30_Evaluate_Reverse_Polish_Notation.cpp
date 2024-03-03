class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;    
        for(auto i:tokens){
            if(i == "+" || i == "-" || i == "*" ||i == "/"){
                int operand2 = st.top();
                st.pop();
                int operand1 =  st.top();
                st.pop();
                int res;
                if(i == "+")
                    res = (operand1 + operand2);
                else if(i == "-")
                    res = (operand1 - operand2);
                else if(i == "*")
                    res = (operand1 * operand2);
                else if(i == "/")
                    res = (operand1 / operand2);
                st.push(res);
            }
            else
                st.push(stoi(i));
        }
        return st.top();
    }
};
