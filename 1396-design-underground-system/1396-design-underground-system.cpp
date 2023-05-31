class UndergroundSystem {
private:
    map<pair<string,string>, int> sum;
    map<pair<string,string>, int> cnt;
    unordered_map<int, int> id_to_checkin;
    unordered_map<int, string> id_to_station;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        id_to_checkin[id] = t;
        id_to_station[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        string str = id_to_station[id];
        int st = id_to_checkin[id];
        
        sum[{str, stationName}] += t-st;
        cnt[{str, stationName}] += 1;

    }
    
    double getAverageTime(string startStation, string endStation) {
        
        return (double)sum[{startStation, endStation}] / cnt[{startStation, endStation}];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */