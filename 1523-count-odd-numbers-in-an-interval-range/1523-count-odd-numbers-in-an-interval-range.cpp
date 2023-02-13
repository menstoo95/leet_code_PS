class Solution {
public:
    int countOdds(int low, int high) {
        return (high+1)/2 - low/2;
    }
};

/*
    1 : 1
    2 : 1
    3 : 2
    4 : 2
    5 : 3
    6 : 3
    7 : 4
*/