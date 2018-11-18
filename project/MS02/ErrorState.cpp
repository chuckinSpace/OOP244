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
    
    
    ErrorState::~ErrorState(){
        delete [] errorMessage;
    }
    void ErrorState::clear(){
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
        clear();
      
        if (strlen(str) != 0) {
            errorMessage = new char[strlen(str)];
            strncpy(errorMessage, str, strlen(str));
        }
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
