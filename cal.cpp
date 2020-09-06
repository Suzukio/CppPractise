#include <iostream>
#include <assert.h>
#include <unorder_map>

using namespace std;

class MyDate
{
public:
    MyDate() {};
    MyDate(int y, int m, int d)
        : _valid(true)
        , _year(y)
        , _month(m)
        , _day(d) {
        
        _valid = check_year(y);
        if (!_valid) return;
            
        _valid = check_month(m);
        if (!_valid) return;
        
        _valid = check_day(d);
    }
    
    bool valid() const {
        return _valid;
    }
    
    int year() const {
        return _year;
    }
    
    int month() const {
        return _month;
    }
    
    int day() const {
        return _day;
    }
    
    int days_from_11 {
        for (int )
    }
    
public:
    static unordered_map<int, int> month_day;
    
private:
    bool check_year(int y) {
        return (y >= 0 && y <=9999);
    }
    
    bool check_month(int m) {
        return (m >= 0 && m <= 12);
    }
    
    bool check_day(int d) {
        int month2_days = (_year % 4 == 0 )? 29: 28;
        switch(_month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (d < 0 || d >31)
                {
                    return false;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (d < 0 || d > 30)
                {
                    return false;
                }
                break;
            case 2:
                if (d < 0 || d > month2_days)
                {
                    return false;
                }
                break;
        }
        
        return true;
    }
    
private:
    bool _valid;
    int _year;
    int _month;
    int _day;
};

bool operator< (const MyDate& lhs, const MyDate& rhs) {
    assert(lhs.valid() && rhs.valid());
    
    if (lhs.year() != rhs.year())
    {
        return lhs.year() < rhs.year();
    }
    
    if (lhs.month() != rhs.month())
    {
        return lhs.month() < rhs.month();
    }     
    
    return lhs.day() < rhs.day();
}

int operator-(const MyDate& lhs, const MyDate& rhs) {
    int diff = 0;
    int flag = 1;
    
    MyDate min, max;
    if (lhs < rhs)
    {
        min = lhs;
        max = rhs;
    }
    else
    {
        min = rhs;
        max = lhs;
        flag = -1;
    }
    
    int year_of_366 = 0;
    for (int y = min.year(); y < max.year(); ++y)
    {
        if (y % 4 == 0) year_of_366++;
    }
    
    diff += (max.year() - min.year()) * 365 + year_of_366；
    
    
}

int main() {
    
    cout << "Hello World!" << endl;
}