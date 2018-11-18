// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4


namespace AMA {
    
    const int min_year = 2000;
    const int max_year = 2030;

    class Date {
    
        
        int year;
        int month;
        int day;
        int comparator;
        int errorstate;
        
        
        int mdays(int, int)const;
        void errCode(int errorCOde);
        
    public:
        Date();
        Date(int yr, int mt, int dy);
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        int errCode() const;
        bool checkYear(int yr);
        bool checkMonth(int mn);
        bool checkDay(int dy);
        void CopyYear(int);
        void CopyMonth(int);
        void CopyDay(int);
        bool bad() const;
        void setEmpty();
        void setComparator();
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        int getYear()const;
        int getMonth()const;
        int getDay()const;
      //  void setYear();
        
        
    };
    
    std::ostream& operator<<(std::ostream& out, Date& rhs);
    std::istream& operator>>(std::istream& in, Date& rhs);
    
    
    
    
}
#endif
