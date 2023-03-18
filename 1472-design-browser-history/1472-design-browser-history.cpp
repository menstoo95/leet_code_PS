class BrowserHistory {
private:
    stack<string> bac, forw;
public:
    BrowserHistory(string homepage) {
        bac.push(homepage);
    }
    
    void visit(string url) {
        forw = stack<string> ();
        bac.push(url);
    }
    
    string back(int steps) {
        while(steps && bac.size() > 1){
            forw.push(bac.top());
            bac.pop();
            steps--;
        }
        return bac.top();
    }
    
    string forward(int steps) {
        while(steps && forw.size() > 0){
            bac.push(forw.top());
            forw.pop();
            steps--;
        }
        return bac.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */