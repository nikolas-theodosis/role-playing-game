#include <cstdlib>
#include <iostream>
#include <string>

using namespace std ;

class Hero;
class Monster;

class Item {
      protected:
             	string name;
             	int cost;
             	int min_level ;
		int type;	
      public:
             	Item(string , int ,int);
              string get_name();
             	int get_cost();
             	int get_min_level();
		virtual int get_damage() {return 0;};
		virtual int get_dmg_reduction() {return 0;};	
		virtual int get_bonus() {return 0;};
		virtual int get_bonus_type() {return 0;}
	     	void setName(string);
		virtual void print() = 0; 	
		void setCost(int) ;
		virtual void equip_item(Hero& , Item **) = 0 ;	
		virtual ~Item();	
};

class weapon : public Item {
      protected:
                int damage;
                int handed;
      public:
             	weapon (int , int , std::string , int ,int);
             	int get_damage();
             	int get_handed();
		void print() ;	
		void equip_item(Hero& , Item **);
		~weapon();
};

class armor : public Item {
      protected:
                int dmg_reduction;
               
      public:
             	armor (int  , std:: string , int ,int);
             	int get_dmg_reduction();
		void print() ; 
		void equip_item(Hero& , Item **);
		~armor();
}; 

class potion : public Item {
      protected:
		int bonus_type;  
		int bonus ;
      public:
              potion (bool, int, std::string, int, int) ;
             	int get_bonus_type();
              int get_bonus() ;
		void print();	
		void equip_item(Hero& , Item **);
		~potion();
};        	

class icespell;

class Spell {
      protected:
                string name;
                int damage;
                int mana_cost;
		  int level ;
 		  int cost ; 	    
      public:
             	Spell(string , int ,int , int , int);
	  	int get_damage();
             	int get_mana_cost();
		string get_spell_name() ;
		int get_spell_cost() ;
		virtual void print() = 0 ;
		virtual int use_spell(Monster& , int , int) = 0 ;
		virtual int get_dmg_reduction() {}
		virtual int get_def_reduction() {}
		virtual int get_luck_reduction() {}
};

class icespell : public Spell {
      protected:
                int dmg_reduction;
      
      public:
             	icespell(int , string , int ,int , int ,int);
             	int get_dmg_reduction();
		void print() ;
		int use_spell(Monster& , int , int);
};

class firespell : public Spell {
      protected:
                int def_reduction;
      
      public:
             	firespell (int , string , int ,int , int ,int);
             	int get_def_reduction();
		void print() ;
		int use_spell(Monster& , int , int);
};

class lightingspell : public Spell {
      protected:
                int luck_reduction;
      
      public:
             	lightingspell (int , string , int ,int  , int ,int);
             	int get_luck_reduction();
		void print() ;
		int use_spell(Monster& , int , int);
};
