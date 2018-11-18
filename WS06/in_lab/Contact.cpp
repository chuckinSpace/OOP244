//
//  Contact.cpp
//  Ws06
//
//  Created by Carlos  Moyano on 11/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {
    // implementing default contructor
    Contact::Contact(){
       
        name[0] = '\0';
        phoneNumber = nullptr;
        validnumbers = 0;
       
    }

    
    Contact::Contact(const char* nm, const long long* pnumber, int nopnumbers){
        int index = 0;
        validnumbers = 0;
        
        
        if ( nm != nullptr ){
            
         
            phoneNumber = new (nothrow) long long[nopnumbers];
           
            strncpy(name,nm,SIZE);
            name[SIZE-1]='\0';
            
            if(isEmpty()){
               
                for(int i = 0 ; i < nopnumbers ; i++){
                   
                   if(nvalid(pnumber[i])== true){
                       validnumbers++;
                       phoneNumber[index] = pnumber[i];
                       index ++;
                    }
                    
                }
        
            }
        }else{
                name[0] = '\0';
                phoneNumber = nullptr;
            }
       
    }
    

    
       

    
    // implementing destructor
    Contact::~Contact(){
       
        delete [] phoneNumber;
            
    }
  
    
    int Contact::getCountryCode(const long long * num)const{
        return (int) (*num / 10000000000);
    }
    int Contact::getAreaCode(const long long * num)const{
        return (int) (*num % 10000000000 / 10000000);
    }
    int Contact::getNumber(const long long * num)const{
        return (int) (*num % 10000000);
    }
    
        
    
    bool Contact::isEmpty() const{
        if(name[0] == '\0' || phoneNumber == nullptr || phoneNumber[0] == '\0' ){
            return true;
        }else{
            return false;
        }
    }
    void Contact::display() const{
        if(name[0] == '\0' || phoneNumber == nullptr){
            cout << "Empty contact!" << endl;
        }else if (name[0] != '\0' && *phoneNumber == 0 ){
            
            cout << name << endl;
            
            
        }
        else{
            cout << name << endl;
            for (int i = 0;i<validnumbers;i++){
                
                cout << "(+" << getCountryCode(&phoneNumber[i]) << ") " << getAreaCode(&phoneNumber[i]) << " " << getNumber(&phoneNumber[i]) / 10000 << "-" << setfill('0')<<setw(4)<<getNumber(&phoneNumber[i]) % 10000 << endl;
            }
        }
    }
  
    bool Contact::nvalid(const long long numval){
        int counter=1;
        long long temp1 = numval;
        long long temp2 = numval;
        long long countrycode;
        long long areacode;
        long long numbercode;
        long long countrycodefirst;
        long long areacodefirst;
        long long numbercodefirst;
       
        int testcounter = 0;
    
        while ( temp1 /= 10 ){
            counter ++ ;
        }
        
        if(counter == 11){
            countrycode = temp2;
            countrycodefirst = (long long) countrycode / 10000000000;
            areacode = temp2;
            areacodefirst = (long long) areacode / 1000000000;
            areacodefirst %= 10;
            numbercode = temp2;
            numbercodefirst = (long long)numbercode / 1000000;
            numbercodefirst %= 10;
            
            
            if( countrycodefirst !=0 ){
                testcounter ++;
            }
            
            if(areacodefirst != 0 ){
                testcounter ++;
            }
            if(numbercodefirst != 0 ){
                testcounter ++;
            }
            if(testcounter == 3){
                return true;
            }
            
        }else if (counter == 12){
                    countrycode = temp2;
                    countrycodefirst = countrycode / 100000000000;
                    areacode = temp2;
                    areacodefirst = areacode / 1000000000;
                    areacodefirst %= 10;
                    numbercode = temp2;
                    numbercodefirst = numbercode / 1000000;
                    numbercodefirst %= 10;
            
            if( countrycodefirst !=0 ){
                testcounter ++;
            }
            
            if(areacodefirst != 0 ){
                testcounter ++;
            }
            if(numbercodefirst != 0 ){
                testcounter ++;
            }
            if(testcounter == 3){
                return true;
            }
            
        }
    return false;
    }


}


