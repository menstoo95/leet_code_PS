class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = 0, f = 0, j = 0, ans = 0;

        for(int i = 0; i < answerKey.size(); i++){
            answerKey[i] == 'T' ? t++ : f++;
            int mini = min(t, f);

            if(mini > k){
                answerKey[j] == 'T' ? t-- : f--;
                j++;
            }
            else{
                ans = max(ans, t+f);
            }
        }

        return ans;
    }
};