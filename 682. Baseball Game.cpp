class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        int sum = 0;

        for (string s : op) {

            // Add a new score
            if (s != "C" && s != "D" && s != "+") {
                int num = stoi(s);
                st.push(num);
                sum += num;
            }

            // Cancel the previous score
            else if (s == "C") {
                int x = st.top();
                st.pop();
                sum -= x;
            }

            // Double the previous score
            else if (s == "D") {
                int n = st.top() * 2;
                st.push(n);
                sum += n;
            }

            // Add the previous two scores
            else {
                int first = st.top();
                st.pop();

                int second = st.top();

                int summ = first + second;

                st.push(first);
                st.push(summ);

                sum += summ;
            }
        }

        return sum;
    }
};
