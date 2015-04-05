#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Item.h"
#include "Grid.h"

using namespace std ;

void Grid :: Market(Hero *hero)
{
	int choice = 0 ;
	int sell ;
	int market_option = 0 ;
	int damage , hands , cost , min_lvl , damage_reduction , bonus , bought ;
	int item , x  , i , j = 1 , counter = 0 , used , mana ;
	char answer = 'y' ;
	string line , object ;
	cout << "\nWelcome to Agora....................................\n" << endl ;
	srand(time(NULL)) ;
	while (answer == 'y') {
	cout << "What would you like to do...?\n" << endl ;
	cout << "1.Buy\n" << endl ;
	cout << "2.Sell\n" << endl ;
	cin >> market_option ;
	cout << "\n" << endl ;
		if (market_option == 1)
		{
			cout << "What do you want to buy?\n" << endl ;
			cout << "1.Potions\n" << endl ;
			cout << "2.Weapons\n" << endl ;
			cout << "3.Armor\n" << endl ;
			cout << "4.Spell\n" << endl ;
			cin >> item ;
			cout << "\0" << endl ;
			switch (item)
			{
			case 1 :
			{
				object = "potion" ;
				ifstream myfile2 ;
				myfile2.open("potions.txt") ;
				while(!myfile2.eof()) {
					if (getline(myfile2 , line)) {
						cout << j << " : " <<  line << endl ;
						cout << "\n" << endl ;
						j++ ;
					}
				}
				j = 1 ;
				cout << "Choose Potion\n" << endl ;
                                cin >> bought ;
				if (bought > 66 )
						break ;
				else
					hero->addInventory(bought , object) ;
				myfile2.close() ;

			break ;
			}
			case 2 :
			{
				object = "weapon" ;
				ifstream myfile ;
		                myfile.open("weapons.txt");
				while(!myfile.eof()) {
					if (getline(myfile , line)){
						cout << j << " : " <<  line << endl ;
                                                cout << "\n" << endl ;
                                                j++ ;
							
					}
				}
				j = 1 ;
                                cout << "Choose Weapon\n" << endl ;
                                cin >> bought ;
				if (bought > 119 )
						break ;
				else
					hero->addInventory(bought , object) ;
				myfile.close() ;
			break ;
			}
			
			case 3 :
			{
				object = "armor" ;
				ifstream myfile3 ;
				myfile3.open("armors.txt") ;
				while(!myfile3.eof()) {
					if(getline(myfile3 , line)) {
						cout << j << " : " <<  line << endl ;
                                                cout << "\n" << endl ;
                                                j++ ;

					}
				}
				j = 1 ;
                                cout << "Choose Armor\n" << endl ;
                                cin >> bought ;
				if (bought > 80 )
						break ;
				else
                                	hero->addInventory(bought , object)  ;
				myfile3.close() ;
			break ;
			}
			
			case 4 :
			{	
				int spell ;
				cout << "What spell do you want to buy?" << "\n" << endl ;
				cout << "1.Firespell" << "\n" << endl ;
				cout << "2.Icespell" << "\n" << endl ;
				cout << "3.Lightingspell" << "\n" << endl ;
				cin >> spell ;
				switch (spell)
				{
				case 1 :
				{
					object = "firespell" ;
					ifstream myfile6 ;
					myfile6.open("firespells.txt") ;
					while (!myfile6.eof()) {
						if (getline(myfile6 , line)) {
							cout << j << " : " <<  line << endl ;
                                                	cout << "\n" << endl ;
                                                	j++ ;
						}
					}
					j = 1 ;
                                	cout << "Choose Firespell\n" << endl ;
                                	cin >> bought ;
					if (bought > 34 )
						break ;
					else
                                	hero->addSpellInventory(bought , object) ;
					break ;
				}
				case 2 :
				{
					object = "icespell" ;
                                        ifstream myfile7 ;
                                        myfile7.open("icespells.txt") ;
                                        while (!myfile7.eof()) {
                                                if (getline(myfile7 , line)) {
                                                        cout << j << " : " <<  line << endl ;
                                                        cout << "\n" << endl ;
                                                        j++ ;
                                                }
                                        }
                                        j = 1 ;
                                        cout << "Choose Icespell\n" << endl ;
                                        cin >> bought ;
					if (bought > 20 )
						break ;
					else
                                        hero->addSpellInventory(bought , object) ;
                                        break ;
				}
				case 3 :
				{
					object = "lightingspell" ;
                                        ifstream myfile8 ;
                                        myfile8.open("lightingspells.txt") ;
                                        while (!myfile8.eof()) {
                                                if (getline(myfile8 , line)) {
                                                        cout << j << " : " <<  line << endl ;
                                                        cout << "\n" << endl ;
                                                        j++ ;
                                                }
                                        }
                                        j = 1 ;
                                        cout << "Choose Lightingspell\n" << endl ;
                                        cin >> bought ;
					if (bought > 26 )
						break ;
					else
                                        hero->addSpellInventory(bought , object) ;
                                        break ;
				}
				}

			}			
		}
		}	
		else if (market_option == 2) {
			cout << "What do you want to sell ? " << "\n" << endl ;
			cout << "1. Items " << "\n" << endl ;
			cout << "2. Spells" << "\n" << endl ;
			cin >> sell ;
			if (sell == 2)
				hero->removeSpell() ;
			else			
                		hero->removeInventory() ;
		}
		else
			return ;

		cout << "Do you want to continue?\n" << endl ;
                        cin >> answer ;
	
	}
		
}
