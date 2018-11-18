//
//  ErrorState.hpp
//  MS02
//
//  Created by Carlos  Moyano on 21/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef ErrorState_h
#define ErrorState_h


#include <iostream>

namespace AMA {

    class ErrorState{
        char * errorMessage;
    public:
        explicit ErrorState(const char* errorMessage = nullptr);
        ErrorState(const ErrorState& em) = delete;
        ErrorState& operator=(const ErrorState& em) = delete;
        virtual ~ErrorState();
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message()const;
        
        
    };
    // check if this one is right
    std::ostream& operator<<(std::ostream& out, ErrorState& rhs);
    
}

#endif /* ErrorState_h */
