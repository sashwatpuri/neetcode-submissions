class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C"){
                st.pop();
            }else if(operations[i] == "D"){
                int res = st.top();
                st.push(2 * res);
            }else if(operations[i] == "+"){
                int sum = 0;
                stack<int> st2;

                //stack 1 to stack 2 top 2 element transfer while calculating sum
                st2.push(st.top());
                sum += st2.top();
                st.pop();
                st2.push(st.top());
                sum += st2.top();
                st.pop();

                //vis-a-vis from stack 2 to stack 1 transfer and then add the sum of previous two elements

                st.push(st2.top());
                st2.pop();
                st.push(st2.top());
                st2.pop();

                st.push(sum);
            }else{
                st.push(stoi(operations[i]));
            }
        }
        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};