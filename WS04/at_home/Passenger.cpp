// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include "Passenger.h"
#include <cstring>
#include <iomanip>

using namespace std;

// TODO: continue your namespace here
namespace sict {
    

    // TODO: implement the default constructor here
    Passenger::Passenger(){
        pass_name[0] = '\0';
        destination[0] = '\0';
        
    }
	// TODO: implement the constructor with 2 parameters here
    Passenger::Passenger(const char  * pname ,const char  * dest){

          if( pname == 0 || dest == 0 || strcmp(pname,"")==0 || strcmp(dest,"")==0)
        {
            pass_name[0] = '\0';
            destination[0] = '\0';
        
        }else{
            
            strncpy(pass_name,pname,sizeof(pass_name));
            strncpy(destination,dest,sizeof(destination));
            
        }
    }
    

    
 
    Passenger::Passenger(const char * pname, const char * dest, const int yr_Dep, const int mont_Dep,
                         const int Day_Dep){
        
        
        if( (pname == 0 || dest == 0 || strcmp(pname,"")==0 || strcmp(dest,"")==0) || (yr_Dep < 2017 ||  yr_Dep > 2020 ) || (mont_Dep < 1 || mont_Dep > 12) || (Day_Dep < 1 || Day_Dep > 31))
        {
            pass_name[0] = '\0';
            destination[0] = '\0';
            year_dep = 0;
            month_dep = 0;
            day_dep = 0;
            
            
        }else{
            
            strncpy(pass_name,pname,sizeof(pass_name));
            strncpy(destination,dest,sizeof(destination));
            year_dep = yr_Dep;
            month_dep = mont_Dep;
            day_dep = Day_Dep;
            
        }
    }
    // TODO: implement isEmpty query here
    bool Passenger::isEmpty() const {
        bool flag = false;
        if( pass_name[0] == '\0' && destination[0] == '\0'){
            flag = true;
        }else{
            flag = false;
        }
        return flag;
    }
    // TODO: implement display query here
    void Passenger::display() const {
        if( pass_name[0] == '\0' && destination[0] == '\0'){
            cout << "No passenger!"<< endl;
        }else{
            cout << pass_name << " - " << destination<< " on " << year_dep << "/" <<setw(2)<<setfill('0')<<  month_dep << "/" << day_dep<< endl;
        }
    }
    
 
    const char * Passenger::name() const{
        if( (strcmp(pass_name, "")==0) || (pass_name[0] == '\0')) {
           return this->pass_name;
        } else {
            return this->pass_name;
        }
    }
   bool Passenger::canTravelWith(const Passenger & pass) const{
       if((strcmp(this->destination,pass.destination)==0) && this->year_dep == pass.year_dep && this->month_dep == pass.month_dep && this->day_dep == pass.day_dep){
           return true;
       }else{
           return false;
       }
    
   }
}
