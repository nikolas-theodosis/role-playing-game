#include<iostream>
#include<cstdlib>
#include<string>

using namespace std ;

class Living {
	protected : 
		int level ;
		int healthPower ;
		int maxHealth;
		int max_magicPower;
		string name ;
	public :
		Living(int , int , int , int , string) ;
		int get_level() ;
		string get_name();
		void set_health(int , bool);
	       int get_health();
		virtual ~Living();
};

class Item;
class Spell ;
class Monster;

class Hero : public Living {
	protected :
		int magicPower ;
		int strength ;
		int dexterity ;
		int agility ;
		int money ;
		int experience ;
		int level_cap;
		int dmg_reduction;
		int equiped_strength;	//o iroas xtipa me tin auksimenei dinami 
		int equiped_dexterity;	//o iroas xreisimopoiei tin auksimenei epideksiotita 
		Item *Inventory[10];
		Spell *SInv[10] ;
	public :
		Hero(int , int , int , int , int , int , int , int , int , int , int , int , string) ; 
		void levelUp(int) ;
		void set_strength(int) ;
		int get_strength() ;
		int get_dmg_reduction();
		void set_dmg_reduction(int);
		void set_money(int) ;
		int get_money() ;
		void set_experience(int) ;
		int get_experience() ;
		void set_magic_power(int , bool) ;
		int get_magic_power() ;
		void set_dexterity(int);
		int get_dexterity();
		void set_agility(int);
		int get_agility();
		int get_equiped_strength();
		int get_equiped_dexterity();
		void set_equiped_strength(int);
		void set_equiped_dexterity(int);
		int checkInventory() ;
		void checkSpellInventory();			
		void addInventory(int , string) ;
		void addSpellInventory(int , string) ;
		void removeInventory() ;
		void Market(Hero*) ;
		void removeSpell() ;
		void equip(int , Hero&);		
		int checkSpells();
		void show_stats();
		Item ** get_inventory(int);
		void use_s(int , Hero& , Monster&);
		~Hero();
};

class Warrior : public Hero {
	public : 
		Warrior(int , int , int , int , int , int , int , int , int , int , int ,  int , string);
		~Warrior();
};

class Sorcerer : public Hero { 
	public :
		Sorcerer(int , int , int , int , int , int , int , int , int , int , int , int , string);
		~Sorcerer();
};

class Paladin : public Hero {
	public :
		Paladin(int , int , int , int , int , int , int , int , int , int , int , int , string);
		~Paladin();
};

class Monster : public Living {
	protected :
		int damage ;
		int defence ;
		int chance ;
		int xp;
	public :
		Monster(int , int , int , int , int , int , int , int , string);
		int get_monster_damage();
		int get_def();
		int get_chance();
		int get_xp();
		void set_xp(int);
		void set_damage(int);
		void set_def(int);
		void set_chance(int);
		~Monster();
};

class Dragon : public Monster {
	public : 
		Dragon(int , int , int , int , int , int , int , int , string);		
		~Dragon();
};

class Exoskeleton : public Monster {
	public :
		Exoskeleton(int , int , int , int , int , int , int , int , string);
		~Exoskeleton();
};

class Spirit : public Monster {
	public :
		 Spirit(int , int , int , int , int , int , int , int , string);
		~Spirit();
};
