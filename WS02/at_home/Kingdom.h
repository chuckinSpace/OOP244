//
//  Kingdom.hpp
//  asig2
//
//  Created by Carlos  Moyano on 4/2/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef Kingdom_h
#define Kingdom_h

#include <stdio.h>



namespace sict {
    
    struct Kingdom {
        
        char  m_name[32];
        int   m_population;
        
        
    };
    
    void display(const Kingdom& kingdom);
    void display(const Kingdom kingdom[], int SIZE);
}




#endif /* Kingdom_hpp */
