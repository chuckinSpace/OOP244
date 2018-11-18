//
//  Superhero.cpp
//  WS07
//
//  Created by Carlos  Moyano on 22/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include "SuperHero.h"
#include <cstring>
namespace sict {
  
    int SuperHero::attackStrenght() const{
        return (Hero::attackStrenght() + Shero_bonus);
    }
    int SuperHero::defend()const{
        if(isEmpty()){
            return 0;
        }else{
            return Shero_defend;
        }
    }
  
    //default contructor
    SuperHero::SuperHero() :Hero(){
       
        Shero_bonus = 0;
        Shero_defend = 0;
    }
    
    // 3param contructor
    
    SuperHero::SuperHero(const char *name,int health, int attacktohero, int superpower, int defense): Hero(name, health,attacktohero){
      
        if(name[0] != '\0'|| (strcmp(name,""))){
        
            Shero_bonus = superpower;
            Shero_defend = defense;
        }
        
    }
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        
        int rounds= 0;
        SuperHero t_first = first;
        SuperHero t_second = second;
        bool draw = false;
        SuperHero  *winner = new SuperHero;
        
        
        
        
        
        while(t_first.isAlive() && t_second.isAlive() && rounds <= MAX_ROUNDS){
            
            t_first -= (t_second.attackStrenght() - t_first.defend());
            t_second -= (t_first.attackStrenght() - t_second.defend());
            rounds ++;
        }
        if(t_first.isAlive() && t_second.isAlive() ){
            draw = true;
        }
        if(draw){
            *winner = t_first;
            
        }else if(t_first.isAlive()){
            *winner = t_first;
            
        }else{
            *winner = t_second;
            
        }
        
        
        
        cout << "Super Fight! ";
        cout << first;
        cout << " vs ";
        cout << second;
        cout << " : Winner is ";
        cout << *winner;
        cout << " in " << rounds << " rounds.";
        cout << endl;
        
        winner->Hero::backtolife();
        
        return *winner;
    }
  

}

