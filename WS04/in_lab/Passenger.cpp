// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include "Passenger.h"
#include <cstring>

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
            
            strcpy(pass_name,pname);
            strcpy(destination,dest);
            
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
        cout << pass_name << " - " << destination<< endl;
        }
    }
        
}
