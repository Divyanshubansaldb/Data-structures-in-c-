struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

std::map<std::string, std::string, cmpByStringLength> myMap;

// if you want to keep b after a than do like stated above (example:- 2,4,5,1,7
// is passed than you will get the output as 1,2,4,5,7) for the opposite do like
// b.length()> a.length();
// ...

struct compare 
{
    bool operator()(const int& a, const int& b) const 
    {
        return a>b;
    };
};

map<int,int,compare> mp;