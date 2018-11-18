//
//  Perishable.cpp
//  MS05
//
//  Created by Carlos  Moyano on 10/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include <stdio.h>
#include <iomanip>
#include "Perishable.h"

namespace AMA {
    //setting type P every time a perishble object is instiantiated
    Perishable::Perishable(){
        setType('P');
    }
    // store function in Perishable, uses Store function from Product to store all variables of the object in the file, and after that adds the data for expiry date.
    std::fstream& Perishable::store(std::fstream& file, bool newLine) const{
     
        Product::store(file, false);
        file << ","
             << expiry_date.getYear()
             << "/"
             << std::setfill('0') << std::setw(2)
             << expiry_date.getMonth()
             << "/"
             << expiry_date.getDay();
        
        if (newLine){
            file << std::endl;
        }
      return file;
    }
    void Perishable::expiry(const Date& date){
        expiry_date = date;
    }
    
    //load function from perishable uses load function from Product to load data from Product, and then this fucntion load all data for expiry date
    std::fstream& Perishable::load(std::fstream& file){
        Product::load(file);
        char temp[100];
    
        file.getline(temp,100,'/');
        expiry_date.CopyYear(atoi(temp));
     
        file.getline(temp,100,'/');
        expiry_date.CopyMonth(atoi(temp));
      
        file.getline(temp,100,'/');
        expiry_date.CopyDay(atoi(temp));
        file.ignore();
    
        return file;
       
    }
    
    void Perishable::setYear(int _year){
        expiry_date.CopyYear(_year);
    }
    // this function uses the write function from Product to write data into the ostream, and then this funciton adds the data for expory date.
    std::ostream& Perishable::write(std::ostream& os, bool linear) const{
       
        Product::write(os, linear);
            
        if(product_errorState.isClear()){
            if(!linear){
                os << std::endl << " Expiry date: " << expiry_date.getYear() << "/" << std::setfill('0') << std::setw(2) << std::fixed << expiry_date.getMonth() << "/" << expiry_date.getDay();
            }else{
                os << expiry_date.getYear() << "/" << std::setfill('0') << std::setw(2) << std::fixed << expiry_date.getMonth() << "/" << expiry_date.getDay();
            }
        }
        
        return os;
    }
    
    std::istream& Perishable::read(std::istream& is){
        int numDays;
        product_errorState.clear();
        Product::read(is);
     
        if (product_errorState.isClear()){
            std::cout << " Expiry date (YYYY/MM/DD): ";
            expiry_date.read(is);
            if (!is.fail()){
                if (expiry_date.getYear() < min_year || expiry_date.getYear() > max_year){
              
                    is.setstate(std::ios::failbit);
                    product_errorState.message("Invalid Year in Date Entry");
                }
                else if (expiry_date.getMonth() < 1 || expiry_date.getMonth() > 12){
                 
                    is.setstate(std::ios::failbit);
                    product_errorState.message("Invalid Month in Date Entry");
                }
                else{
                    numDays = expiry_date.getDay();
                    if (expiry_date.getDay() > numDays || expiry_date.getDay() < 1){
               
                        is.setstate(std::ios::failbit);
                        product_errorState.message("Invalid Day in Date Entry");
                    }
                }
            }
            else{
                is.setstate(std::ios::failbit);
                std::cout << "Invalid Date Entry";
            }
       
        }
      return is;
    }
    const Date& Perishable::expiry() const{
        return expiry_date;
    }
}
