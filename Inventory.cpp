#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include "Living.h"
#include "Item.h"


using namespace std ;


void Hero :: addInventory(int number , string object)  
{
	
	int j = 0 , i , used , bonus , cost , min_lvl , damage , hands , damage_reduction , mana ;
	//srand(time(NULL)) ;
	string line ;
	ifstream myfile  ;
	ifstream myfile2 ;
	ifstream myfile3 ;
	myfile.open("weapons.txt") ;
	myfile2.open("potions.txt") ;
	myfile3.open("armors.txt") ;
	if (object == "potion") {
        while(!myfile2.eof()) {
        	if(getline(myfile2 , line)) 
			j++ ;
			if (j == number) {
				break ;
			}
	}
	
	used = rand() % 2 ;
       bonus = rand() % 5 ; // analoga tin timi dinei agility i dexterity klp
       cost = number * 100;
	min_lvl = number ;
	if (get_money() >= cost && get_level() >= min_lvl) {
		for (i=0 ; i<10 ; i++) {
			if (Inventory[i] == NULL) {
				Inventory[i] = new potion(used , bonus , line , cost , min_lvl) ;
				break ;
			
			}
		}
		set_money(-cost) ;
 

	}
	else
		cout << "Cannot afford" << "\n" << endl ;
	}
	if (object == "weapon") {
	while(!myfile.eof()) {
                if(getline(myfile , line))
                        j++ ;
                        if (j == number) {
                                break ;      
	         }
        }
       hands = rand() % 2 ;
	if (hands == 0) {
		damage = (number * (rand() % 30)) + 10;
       	cost = number * 150 ;
	}
	else {
		damage = (number * (rand() % 30)) + 30;
		cost = number * 200;
	}
      	min_lvl = number ;
	if (get_money() >= cost && get_level() >= min_lvl) {
		for (i=0 ; i<10 ; i++) {
        		if (Inventory[i] == NULL) {
                		Inventory[i] = new weapon(damage , hands , line , cost , min_lvl) ;
                       		 break ;
                	}
        	}
    
	}
	else
		cout << "Cannot afford" << "\n" << endl ;

	}
	
	if (object == "armor") {
	while(!myfile3.eof()) {
                if(getline(myfile3 , line))
                        j++ ;
                        if (j == number) {
                                break ;
                        }
        }
	damage_reduction = number * 5 ;
        cost = number * 100 ;
        min_lvl = number ;
	if (get_money() >= cost && get_level() >= min_lvl) {
		for (i=0 ; i<10 ; i++) {
        		if (Inventory[i] == NULL) {
                		Inventory[i] = new armor(damage_reduction , line , cost , min_lvl) ;
                        	break ;
                	}
        	}
	}
	else
		cout << "Cannot afford" << "\n" << endl ;
             
	}

	for (i=0 ; i<10 ; i++)
                if (Inventory[i] != NULL)
                        cout << i << " : " <<  Inventory[i]->get_name() << "\n"  << endl ;

	
} 		
	

void Hero :: addSpellInventory (int number , string object) {

	int j = 0 , i , cost , min_lvl , damage , mana , damage_reduction , defence_reduction , luck_reduction ;
        string line ;
	ifstream myfile6 ;
	ifstream myfile7 ;
	ifstream myfile8 ;
	myfile6.open("firespells.txt") ;
	myfile7.open("icespells.txt") ;
	myfile8.open("lightingspells.txt") ;
	if (object == "firespell") {
        while(!myfile6.eof()) {
                if(getline(myfile6 , line))
                        j++ ;
                        if (j == number) {
                                break ;
                        }
        }
	cost = number * 200 ;
       damage = (number * (rand() % 100)) + 50 ;
       mana = damage / 10 ;
	defence_reduction = number * 2 ;
	min_lvl = number ;
       if (get_money() >= cost && get_level() >= min_lvl) {
                for (i=0 ; i<10 ; i++) {
                        if (SInv[i] == NULL) {
                                  SInv[i] = new firespell(defence_reduction , line , damage , mana , min_lvl , cost) ;
                                break ;
                        }
                }
	set_money(-cost) ;
        }
        else
                cout << "Cannot afford" << "\n" << endl ;
	}

	if (object == "icespell") {
        while(!myfile7.eof()) {
                if(getline(myfile7 , line))
                        j++ ;
                        if (j == number) {
                                break ;
                        }
        }
        cost = number * 200 ;
        damage = (number * (rand() % 50)) + 40;
        mana = number * 10;
        damage_reduction = number * 5 ;
	min_lvl = number ;
        if (get_money() >= cost && get_level() >= min_lvl) {
                for (i=0 ; i<10 ; i++) {
                        if (SInv[i] == NULL) {
                                  SInv[i] = new icespell(damage_reduction , line , damage , mana , min_lvl , cost) ;
                                break ;
                        }
                }
        set_money(-cost) ;
        }
        else
                cout << "Cannot afford" << "\n" << endl ;
        }
	if (object == "lightingspell") {
        while(!myfile8.eof()) {
                if(getline(myfile8 , line))
                        j++ ;
                        if (j == number) {
                                break ;
                        }
        }
        cost = number * 200 ;
        damage = (number * (rand() % 80)) + 50 ;
        mana = number * 8;
        luck_reduction = number ;
	 min_lvl = number ;
        if (get_money() >= cost && get_level() >= min_lvl) {
                for (i=0 ; i<10 ; i++) {
                        if (SInv[i] == NULL) {
                                  SInv[i] = new lightingspell(luck_reduction , line , damage , mana , min_lvl , cost) ;
                                break ;
                        }
                }
        set_money(-cost) ;
        }
        else
                cout << "Cannot afford" << "\n" << endl ;
        }       
}

void Hero :: removeInventory()
{
	int i , number ;
	cout << "Check out your inventory.............." << "\n" << endl ;
	for (i=0 ; i<10 ; i++)
		if (Inventory[i] != NULL)
			cout << i <<  " : " <<  Inventory[i]->get_name() << "\n" << endl ;
	cout << "Choose what you want to sell........\n " << endl ;
	cin >> number ;
	set_money(Inventory[number]->get_cost()/2) ;
	delete Inventory[number] ;
	Inventory[number] = NULL ;
	for (i=0 ; i<10 ; i++)
                if (Inventory[i] != NULL)
                        cout << i << " : " <<  Inventory[i]->get_name() << "\n" << endl ;

}	


void Hero :: removeSpell() 
{	
	int i , number ;
	cout << "Check out your spells.............." << "\n" << endl ;
        for (i=0 ; i<10 ; i++)
               if (SInv[i] != NULL)
                        cout << i <<  " : " <<  SInv[i]->get_spell_name() << "\n" << endl ;
        cout << "Choose what you want to sell........\n " << endl ;
        cin >> number ;
 //       set_money(SInv[number]->get_spell_cost()/2) ;
        delete SInv[number] ;
        SInv[number] = NULL ;
        for (i=0 ; i<10 ; i++)
                if (SInv[i] != NULL)
                        cout << i << " : " << SInv[i]->get_spell_name() << "\n" << endl ;
}


int Hero :: checkInventory() {
	int i , temp = 0;
	for (i=0 ; i<10 ; i++) {
       	if (Inventory[i] != NULL) {
			cout << i+1 << ") ";
			Inventory[i]->print();
			temp++;
		}
        } 
	return temp;
}    
    
int Hero :: checkSpells() {
	int i , temp =0;
	for (i=0 ; i<10  ; i++) {
		if (SInv[i] != NULL) {
			cout << i+1 << ") ";
			SInv[i]->print() ;
			temp++;
		}
	}
	return temp;
}
 


