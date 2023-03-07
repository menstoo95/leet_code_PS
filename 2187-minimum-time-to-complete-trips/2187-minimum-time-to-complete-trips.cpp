class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1;
        long long end = 1e14;
        while(start <= end){
            long long total = 0;
            long long mid = start + (end - start)/2;
            
            for(int i = 0; i < time.size(); i++)
                total += mid / time[i];
            
            if(total < totalTrips)
                start = mid + 1;
            else 
                end = mid - 1;
        }
        
        return start;
    }
};