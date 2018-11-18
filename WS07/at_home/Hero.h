//
//  Hero.hpp
//  WS07
//
//  Created by Carlos  Moyano on 19/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef Hero_h
#define Hero_h
#define MAX_ROUNDS 100

#include <iostream>

using namespace std;

namespace sict {
    
    class Hero{
        
        char h_name[41];
        int h_health;
        int h_strenght;
        int max_health;
        
        public:
        Hero();
        Hero(const char *name,int strenght, int health);
       
        void setEmpty();
        bool isEmpty()const;
        void operator-=(int attack);
        bool isAlive() const;
        int attackStrenght() const;
        void setHero(const Hero& original);
        int healthLeft() const;
        friend ostream& operator<<(ostream& os, const Hero& hero);
        void backtolife();
        
    };
    const Hero& operator*(const Hero& first, const Hero& second);
    
 
}
#endif /* Hero_h */
