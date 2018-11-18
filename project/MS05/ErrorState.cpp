//
//  ErrorState.cpp
//  MS02
//
//  Created by Carlos  Moyano on 21/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include "ErrorState.h"
#include <string.h>
#include <iostream>


namespace AMA{
    
  /*  ErrorState::ErrorState(){
        errorMessage = nullptr;
    }
   */
    ErrorState::~ErrorState(){
        delete [] errorMessage;
        errorMessage = nullptr;
    }
    void ErrorState::clear(){
        delete[] errorMessage;
        errorMessage = nullptr;
    }
    bool ErrorState::isClear() const{
        
        return (errorMessage == nullptr);
    }
    void ErrorState::message(const char* str){
        delete [] errorMessage;
     
        if (str == nullptr) {
            return;
        }
      
            errorMessage = new char[strlen(str) + 1];
            strncpy(errorMessage, str, strlen(str)+ 1);
     
    }
    const char* ErrorState::message()const{
        return errorMessage;
    }
    
    std::ostream& operator<<(std::ostream& out, ErrorState& rhs){
        if(rhs.isClear()){
            return out;
        }else{
            out << rhs.message();
        return out ;
        }
    }
    ErrorState::ErrorState(const char* errorMess){
        errorMessage = nullptr;
        message(errorMess);
        
    }
   
}
