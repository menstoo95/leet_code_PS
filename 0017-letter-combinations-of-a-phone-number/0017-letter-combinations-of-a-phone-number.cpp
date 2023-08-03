class Solution {
public:
    vector<string> chars = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) {
            return {};
        }

        vector<string> ans;
        string builder;
        build(builder, 0, digits, ans);
        return ans;
    }

    void build(string builder, int i, string digits, vector<string>& ans) {
        if (i == digits.size()) {
            ans.push_back(builder);
            return;
        }

        int d = digits[i] - '0';
        for (char ch : chars[d]) {
            build(builder + ch, i + 1, digits, ans);
        }
    }
};