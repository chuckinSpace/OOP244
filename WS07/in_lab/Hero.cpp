//
//  Hero.cpp
//  WS07
//
//  Created by Carlos  Moyano on 19/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include "Hero.h"
#include <cstring>

/* Heroes Battle
   - Heroes not alive if h_health == 0
   - Attack inflict damage (h_health -= h_strenght)
        * operator-= (int attack)
                bool isValid(int attack) FUNCTION1
                attack >= 0
                isAlive() // true if is alive after attack
   - Draw after MAX_ROUNDS
   - Object receives 3 parameters (name,health,streght or no parameter)
        * Hero() set_Empty //default contructor
        * Hero(char name, int health, int strenght) // 3 par contructor
   - Not valid empty state
        * (set_Empty FUNCTION2)
   - isEmpty  bool, tru if safe empty state
   - attackStrengh FUNCTION
                return attack if !isEmpty
   - ostream insert the name into cout,
                if isEmpty cout "No Hero"
   - operator* non friend
        - make local copies (temp1, temp2)
        - for each round send obj (MAX_ROUNDS times)
        - send to operator-=
        - call cout show hero name
        - return Hero object winner after MAX_ROUNDS
        - for tie lhs wins
 */

namespace sict{
    //default contructor
    Hero::Hero(){
        setEmpty();
    }
    
    // 3param contructor
   
    Hero::Hero(const char *name, int health, int strenght){
        setEmpty();
        if(name[0] != '\0'|| (strcmp(name,""))){
            strncpy(h_name, name, 41);
            h_strenght = strenght;
            h_health = health;
            max_health = health;
        }
        
    }
    
       void Hero::setEmpty(){
        h_name[0]= '\0';
        h_health = 0;
        h_strenght = 0;
        max_health = 0 ;
        
    }
    
    bool Hero::isEmpty() const{
        if(h_name[0] == '\0'){
            return true;
        }else{
            return false;
        }
      
        
    }
    
    void Hero::operator-=(int attack){
        if(attack > 0){
            h_health -= attack;
            if(h_health < 0){
                h_health = 0;
                
            }
        }
     }
    
    
    bool Hero::isAlive() const{
        if(h_health > 0){
            return true;
        }else{
            return false;
        }
    }
    
    int Hero::attackStrenght() const{
        return h_strenght;
    }
    
    ostream& operator<<(ostream& os, const Hero& hero){
      
        
        if(!hero.isEmpty()){
            os << hero.h_name;
            
        }else{
            os << "No hero";
        }
        
        
            return os;
        
    }
    
    int Hero::healthLeft() const{
        return h_health;
    }
    const Hero& operator*(const Hero& first, const Hero& second){
       
        int rounds= 0;
        Hero t_first = first;
        Hero t_second = second;
        bool draw = false;
        Hero  *winner = new Hero;
        
        
        
        
        
        while(t_first.isAlive() && t_second.isAlive() && rounds <= MAX_ROUNDS){
            
            t_first -= t_second.attackStrenght();
            t_second -= t_first.attackStrenght();
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
            
            
        
        cout << "Ancient Battle! ";
        cout << first;
        cout << " vs ";
        cout << second;
        cout << " : Winner is ";
        cout << *winner;
        cout << " in " << rounds << " rounds.";
        cout << endl;
        
        winner->backtolife();
        
        return *winner;
        
        
    }
    void Hero::backtolife(){
        h_health = max_health;
        
    }
   
}


   
