// LeetCode 71

/* /

 // /Reverse ans
    void reverseAns(stack<string>& s, string& ans) {
        if (s.empty()) {
            return;
        }

        string element = s.top();
        s.pop();

        reverseAns(s, ans);

        ans += element;
    }

    string simplifyPath(string path) {
        stack<string> st;

        int i = 0;
        while (i < path.size()) {
            int start = i;
            int end = i + 1;

            // jab tak '/' nahi aata tabtak
            while (end < path.size() && path[end] != '/') {
                end++;
            }

            string minPath = path.substr(start, end - start);

            i = end; // next start index;

            if (minPath == "/" || minPath == "/.") {
                continue;
            }

            if (minPath != "/..") {
                st.push(minPath);
            } else if (!st.empty()) {
                st.pop();
            }
        }
        string ans = st.empty() ? "/" : "";

        reverseAns(st, ans);

        return ans;
    }


 */