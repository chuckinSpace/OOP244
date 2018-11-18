//
//  Header.h
//  WS07
//
//  Created by Carlos  Moyano on 22/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef SuperHero_h
#define SuperHero_h

#include "Hero.h"
namespace sict {
    class SuperHero: public sict::Hero{
        

        int Shero_bonus;
        int Shero_defend;
        int Shero_max_health;
        
    public:
        SuperHero();
        SuperHero(const char *name,int health, int attacktohero, int superpower, int defense);
        int attackStrenght() const;
        int defend()const;
  
    };
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}

#endif /* SuperHero_h */
