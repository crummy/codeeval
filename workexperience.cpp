// https://www.codeeval.com/open_challenges/139/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Date {
public:
    Date(string str);
    friend int operator-(const Date& d1, const Date& d2);
    friend bool operator<(const Date& d1, const Date& d2);
    friend bool operator<=(const Date& d1, const Date& d2);
    friend bool operator>(const Date& d1, const Date& d2);
    friend bool operator>=(const Date& d1, const Date& d2);
    friend ostream& operator<<(ostream& os, const Date& date);
//private:
    int month;
    int year;
};

Date::Date(string str) {
    string m = str.substr(0, 3);
    if (m == "Jan") month = 1;
    else if (m == "Feb") month = 2;
    else if (m == "Mar") month = 3;
    else if (m == "Apr") month = 4;
    else if (m == "May") month = 5;
    else if (m == "Jun") month = 6;
    else if (m == "Jul") month = 7;
    else if (m == "Aug") month = 8;
    else if (m == "Sep") month = 9;
    else if (m == "Oct") month = 10;
    else if (m == "Nov") month = 11;
    else if (m == "Dec") month = 12;
    stringstream ss(str.substr(4));
    ss >> year;
    //cout << "month: " << month << ", year: " << year << endl;
}

int operator-(const Date& d1, const Date& d2) {
    return (d1.year - d2.year) * 12 + d1.month - d2.month + 1; // the +1 is because we start at the beginning of a month, end at the end
}

bool operator<(const Date& d1, const Date& d2) {
    return d1.year * 12 + d1.month < d2.year * 12 + d2.month;
}

bool operator<=(const Date& d1, const Date& d2) {
    return d1.year * 12 + d1.month <= d2.year * 12 + d2.month;
}

bool operator>(const Date& d1, const Date& d2) {
    return d1.year * 12 + d1.month > d2.year * 12 + d2.month;
}

bool operator>=(const Date& d1, const Date& d2) {
    return d1.year * 12 + d1.month >= d2.year * 12 + d2.month;
}

ostream& operator<<(ostream& os, const Date& date) {
    os << "Month " << date.month << ", " << date.year;
}

struct compareDateRange { // sorting dates: return the one with the earliest starting date
    inline bool operator() (const pair<Date, Date> &date1, const pair<Date, Date> &date2) {
        return date1.first < date2.first;
    }
};

vector<pair<Date, Date> > mergeDates(vector<pair<Date, Date> > &dates) {
    if (dates.size() <= 1) {
        return dates;
    }
    
    int index = 1;
    while (index < dates.size()) {
        pair<Date, Date> *prevRange = &dates[index-1];
        pair<Date, Date> *range = &dates[index];
        
        //cout << "(" << prevRange->first << " to " << prevRange->second << ") with (" << range->first << " to " << range->second << ")" << endl;
        if (range->second <= prevRange->second) {
            dates.erase(dates.begin() + index);
            //cout << "useless range" << endl;
            continue;
        }
        else if (range->first <= prevRange->second) {
            prevRange->second = range->second;
            dates.erase(dates.begin() + index);
            //cout << "expanded previous range. new: " << prevRange->first << " to " << prevRange->second << endl;
            continue;
        }
        index++;
    }
    return dates;
}

int main(int argc, char** argv) {
    ifstream file;
    file.open(argv[1]);
    
    string line;
    while (getline(file, line)) {
        
        stringstream ss(line);
        vector<pair<Date, Date> > dates;
        string dateString;
        while (getline(ss, dateString, ';')) {
            
            if (dateString.at(0) == ' ') {
                dateString = dateString.substr(1);
            }
            
            Date startDate = Date(dateString.substr(0, 8));
            Date endDate = Date(dateString.substr(9));
            dates.push_back(pair<Date, Date>(startDate, endDate));
        }
        
        sort(dates.begin(), dates.end(), compareDateRange());
        
        dates = mergeDates(dates);
        
        int totalMonths = 0;
        for (vector<pair<Date, Date> >::iterator it = dates.begin(); it != dates.end(); ++it) {
            int monthsInRange = (*it).second - (*it).first;
            //cout << (*it).first << " to " << (*it).second << ": " << monthsInRange << endl;
            totalMonths += monthsInRange;
        }
        
        cout << totalMonths /12 << endl;
    }
}