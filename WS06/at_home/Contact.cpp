
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
        
        setEmptyState();
       
    }
    void Contact::setEmptyState()
    {
        name[0] = '\0';
        phoneNumber = nullptr;
        validnumbers = 0;
    }

    bool Contact::isEmpty() const{
        if(name[0] == '\0' || phoneNumber == nullptr || phoneNumber[0] == '\0' ){
            return true;
        }else{
            return false;
        }
    }
    
    Contact::Contact(const char* nm, const long long* pnumber, int nopnumbers){
        int index = 0;
        validnumbers = 0;
        
        
        if ( nm != nullptr || nm[0] != '\0'){
            
            strncpy(name, nm, SIZE);
            
            if(isEmpty() && nopnumbers > 0){
             
                for(int i = 0 ; i < nopnumbers ; i++){
                   
                   if(nvalid(pnumber[i])== true){
                       validnumbers++;
                      
                    }
                    phoneNumber = new (nothrow) long long[validnumbers];
                    for(int i = 0 ; i < nopnumbers ; i++){
                        phoneNumber[index] = pnumber[i];
                        index ++;
                    }
                    
                }
        
            }else{
                phoneNumber = nullptr;
                validnumbers = 0;
            }
      //  if(phoneNumber != nullptr){
        //    delete [] phoneNumber;
         //   phoneNumber = nullptr;
        //}
       
        }else{
            setEmptyState();
        }
}
    
    //Copy contructor
    Contact::Contact(const Contact& obj){
        
        //phoneNumber = new (nothrow) long long (obj.validnumbers);
       // if (isEmpty()==false) {
        //copyName(obj.name);
            strncpy(name, obj.name, SIZE);
            phoneNumber = new long long[validnumbers = obj.validnumbers];
            for (int i = 0; i < validnumbers; i++)
            {
                phoneNumber[i] = obj.phoneNumber[i];
            }
    }

       
    
  
       

    
    // implementing destructor
    Contact::~Contact(){
       
  // if(phoneNumber == nullptr){
            delete [] phoneNumber;
            phoneNumber = nullptr;
  // }
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
    
  
    Contact& Contact::operator=(const Contact& obj)
    {
        if (this != &obj)
        {
            strncpy(name, obj.name, SIZE);
            //copyName(obj.name);
            delete[] phoneNumber;
            phoneNumber = new long long[validnumbers = obj.validnumbers];
            for (int i = 0; i < validnumbers; i++)
            {
                phoneNumber[i] = obj.phoneNumber[i];
            }
        }
        return *this;
    }
     /*   if (this != &obj)
        {
            if(phoneNumber != nullptr){
               delete [] phoneNumber;
                phoneNumber = nullptr;
            }
           
            validnumbers = obj.validnumbers;
            strncpy(name, obj.name, 19);
            delete [] phoneNumber;
            
            phoneNumber = new long long[validnumbers = obj.validnumbers];
            for (int i = 0; i < validnumbers; i++)
            {
                phoneNumber[i] = obj.phoneNumber[i];
            }
          //  if(phoneNumber != nullptr){
           //     delete [] phoneNumber;
            //    phoneNumber = nullptr;
           // }
        }
       // delete[] phoneNumber;
        return *this;
    }
   */
    
    Contact& Contact::operator+=(long long nphone){
 
        {
            if (nvalid(nphone))
            {
                long long* temp = new long long[validnumbers + 1];
                int i;
                for (i = 0; i < validnumbers; i++)
                {
                    temp[i] = phoneNumber[i];
                }
                validnumbers += 1;
                temp[i] = nphone;
                delete[] phoneNumber;
                phoneNumber = temp;
                //delete [] temp;
                
            }
            return *this;
        }
    }
        
        /*
           long long* temp = new (nothrow) long long [validnumbers+1];// +1
        
           for ( int i = 0 ; i < validnumbers ; i++){
               temp[i]  = phoneNumber[i];
            }
            validnumbers ++;
        if(phoneNumber != nullptr){
            delete [] phoneNumber;
        }
        phoneNumber = new long long [validnumbers];
        for ( int j = 0 ; j < validnumbers ; j++){
            phoneNumber[j] = temp[j];
        }
        phoneNumber[validnumbers-1] = nphone;
        
        delete [] temp;
       // if(phoneNumber != nullptr){
        //    delete [] phoneNumber;
         //   phoneNumber = nullptr;
       // }
       return *this;
    }
   
   */
 
  
    void Contact::display() const{
        if(name[0] == '\0'){
            cout << "Empty contact!" << endl;
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
 
 /*   char* Contact::copyName(const char* right)
    {
        name[0] = '\0';
        strncpy(name, right, strlen(right));
        name[strlen(right)] = '\0';
        
        return name;
    }*/
 }







