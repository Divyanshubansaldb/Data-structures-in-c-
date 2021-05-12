//use q.top() in case of priority queue

struct Compare { 
    bool operator()(Person const& p1, Person const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        // so this means that p2 will be in the list at the starting (or before)
        // p1 in the queue arrangement
        return p1.height < p2.height;
    }
};


priority_queue <int> q;
