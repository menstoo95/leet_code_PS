class Solution {
public:
    bool primes[1000001];
    vector<int> arr, ans = {0,0};
    int mini = 0x3f3f3f3f;
    
    vector<int> closestPrimes(int left, int right) {
        for(int i = 2; i < 1000001; i++)
             primes[i] = true;
        
        for(int i = 2; i*i < 1000001; i++)
            if(primes[i])
                for(int k = i*i; k < 1000001; k += i)
                    primes[k] = false;
        
        for(int i = left; i <= right; i++)
            if(primes[i])
                arr.push_back(i);
        
        if(arr.size() < 2)
            return {-1,-1};
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] < mini){
                ans[0] = arr[i-1];
                ans[1] = arr[i];
                mini = arr[i] - arr[i-1];
            }
        }
        
        return ans;
            
    }
};