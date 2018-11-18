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
// Name  Carlos Moyano  Date  16-3-18               Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include <iomanip>

namespace AMA {
    
    // number of days in month mon_ and year year_
    //
    int Date::mdays(int mon, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    // setting receved code to errorstate
    void Date::errCode(int errorCode){
        errorstate = errorCode;
    }
    //returning errorstate
    int Date::errCode() const{
        return errorstate;
        
    }
    // default contructor, intialize to empty states.
    Date::Date(){
        setEmpty();
    }
    // contructor 3 argument call check fucntions and set comparator
    Date::Date(int yr, int mt, int dy){
        setEmpty();
        if (checkYear(yr)== false){
            return;
        }
        if (checkMonth(mt)== false){
            return;
        }
        if (checkDay(dy)==false){
            return;
        }
        
            setComparator();
    }
    
    // setting comparator
    void Date::setComparator(){
        comparator = (year * 372 + month * 13 + day);
    }
    
    // overloading ==
    bool Date::operator==(const Date& rhs) const{
       return comparator == rhs.comparator;
    }
    // overloading !=
    bool Date::operator!=(const Date& rhs) const{
        return comparator != rhs.comparator;
    }
    // overloading <
    bool Date::operator<(const Date& rhs) const{
        return comparator < rhs.comparator;
    }
    // overloading >
    bool Date::operator>(const Date& rhs) const{
         return comparator > rhs.comparator;
    }
    //overloading <=
    bool Date::operator<=(const Date& rhs) const{
        return comparator <= rhs.comparator;
    }
    //overloading >=
    bool Date::operator>=(const Date& rhs) const{
        return comparator >= rhs.comparator;
    }
   // return NO_ERROR state
   bool Date::bad() const{
       return errorstate == NO_ERROR;
    }
   // set empty initialize data member to safe empty states
    void Date::setEmpty(){
        year = 0;
        month = 0;
        day = 0;
        comparator = 0;
        errCode(NO_ERROR);
    }
    // checking limits for year, if pass assign values, if not set error codes
    bool Date::checkYear(int yr){
        if(yr >= min_year && yr <=max_year){
            year = yr;
            return true;
            
        }
        else{
            if(errorstate == 0){
               // setEmpty();
                errorstate = YEAR_ERROR;
            }
            return false;
        }
    }
    // checking limits for month, if pass assign values, if not set error codes
    bool Date::checkMonth(int mn){
        if(mn >= 1 && mn <= 12){
            month = mn;
            return true;
        }
        else{
            
            if(errorstate == 0){
               setEmpty();
                errorstate = MON_ERROR;
            }
            return false;
        }
    }
    // checking limits for day, if pass assign values, if not set error codes
    bool Date::checkDay(int dy){
      int daymonth = (mdays(month,year)); // using mdays to get day of that month
        if(dy >= 1 && dy <= daymonth){
            day = dy;
            return true;
        }
        else{
           
            if(errorstate ==0){
                setEmpty();
                errorstate = DAY_ERROR;
            }
             return false;
        }
    }
    
    std::istream& Date::read(std::istream& istr){
        
        // temo variables to check input
        int tyear=0;
        int tmonth=0;
        int tday=0;
        
        // getting input and call check functions
       
        
        istr >> tyear;
        
        istr.ignore();
        istr >> tmonth;
        istr.ignore();
        istr >> tday;
        
        if(istr.fail()){
            errorstate = CIN_FAILED;
        }
        else{
            if(checkYear(tyear)){
                year = tyear;
                
            }else {
                return istr;
            }
         
            if(checkMonth(tmonth)){
                month = tmonth;
           
            }else {
                return istr;
            }
            
            
            if(checkDay(tday)){
                day = tday;
            }else {
                return istr;
            }
       
        }
        
        return istr; // returning object
    }
    std::ostream& Date::write(std::ostream& ostr) const{
        
      
        ostr << std::setfill('0') << std::setw(1) << year  << "/"
             << std::setfill('0') << std::setw(2) << month << "/"
             << std::setfill('0') << std::setw(2) << day;
       
    
        return ostr;  // returning object
        
    
    }
    
    int Date::getYear()const{
        return year;
    }
    int Date::getMonth()const{
        return month;
    }
    int Date::getDay()const{
        return day;
    }
    
    std::ostream& operator<<(std::ostream& out, Date& rhs){
        return rhs.write(out);
    }
    std::istream& operator>>(std::istream& in, Date& rhs){
        return rhs.read(in);
    }
    void Date::CopyYear(int _year){
        year = _year;
    }
    void Date::CopyMonth(int _month){
         month = _month;
    }
    
    void Date::CopyDay(int _day){
        day = _day;
    }

}
