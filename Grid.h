#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Living.h"

using namespace std ;

class Grid {
	protected :
		int k ;
		int k_2 ;
		int k_3 ;
		int num ;
		int i_position;	//krata to teleutaio i gia tin emfanisi tou xarti
		int j_position;	//krata to teleutaio j gia tin emfanisi tou xarti
		int Area[10][10];
		int is_market;
		bool found_market;
		int heroes;
	public :
		Hero *hero_1 ;
		Hero *hero_2 ;
		Hero *hero_3 ;
		void Market(Hero*) ;

		void callMarket(Hero* hero) {
  			Market(hero) ;
		}

		void callCheck(Hero* hero) {
			hero->checkInventory() ;
		}

		void callCheckSpells(Hero* hero) {
			hero->checkSpells() ;
		}

		Grid() {
			int j=0 , option , i , number , flag  ;
			string line ;
			ifstream myfile5 ;
			create_map();
			myfile5.open("names.txt") ;
			number = chooseKind() ;
			num = number ;
			option = chooseName() ;
			while(!myfile5.eof()) {
               			 if(getline(myfile5 , line))
                       		 	 if (j == option) {
                               			 break ;
                        	 	 }
				j++ ;
		        }					
			j = 0 ;
			myfile5.close() ;
			if (number == 1) {
				if (k == 1)
		 			hero_1 = new Warrior(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
				else if (k_2 == 2)
					hero_1 = new Sorcerer(80 , 15 , 10 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 80 , 0 , line) ;
				else 
					hero_1 = new Paladin(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
			}
			else if (number == 2) {
				if (k == 1)
		 			hero_1 = new Warrior(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
				else if (k == 2)
					hero_1 = new Sorcerer(80 , 15 , 10 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 80 , 0 , line) ;
                            else if(k == 3)
					hero_1 = new Paladin(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
				option = chooseName() ;
				myfile5.open("names.txt") ;
				while(!myfile5.eof()) {
                                	if(getline(myfile5 , line))
                                        	 if (j == option) {
                                                	 break ;
                             			   }
                               		 j++ ;
                        	}
                       		j = 0 ;
				myfile5.close() ;	
				if (k_2 == 1)
		 			hero_2 = new Warrior(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
				else if (k_2 == 2)
					hero_2 = new Sorcerer(80 , 15 , 10 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 80 , 0 , line) ;
				else if (k_2 == 3)
					hero_2 = new Paladin(50 , 10 , 5 , 10 , 100000 , 1 , 100 , 100 , 100 , 100 , 50 , 0 , line) ;
			}
			else {
				if (k == 1)
		 			hero_1 = new Warrior(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
                                else if (k == 2)
					hero_1 = new Sorcerer(80 , 15 , 10 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 80 , 0 , line) ;
                                else if (k ==3)
					hero_1 = new Paladin(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
				option = chooseName() ;
                                myfile5.open("names.txt") ;
                                while(!myfile5.eof()) {
                                        if(getline(myfile5 , line))
                                                 if (j == option) {
                                                         break ;
                                                   }
                                         j++ ;
                               }
                               j = 0 ;
			       myfile5.close() ;
                               if (k_2 == 1)
		 			hero_2 = new Warrior(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
                                else if (k_2 == 2)
					hero_2 = new Sorcerer(80 , 15 , 10 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 80 , 0 , line) ;
                                else if (k_2 == 3)
					hero_2 = new Paladin(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
				option = chooseName() ;
                                myfile5.open("names.txt") ;
                                while(!myfile5.eof()) {
                                        if(getline(myfile5 , line))
                                                 if (j == option) {
                                                         break ;
                                                   }
                                         j++ ;
                                }
                                j = 0 ;
				myfile5.close() ;
				if (k_3 == 1)	
		 			hero_3 = new Warrior(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
				else if (k_3 == 2)
					hero_3 = new Sorcerer(80 , 15 , 10 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 80 , 0 , line) ;
				else if (k_3 == 3)
					hero_3 = new Paladin(50 , 30 , 5 , 5 , 1000 , 0 , 100 , 1 , 100 , 100 , 50 , 0 , line) ;
			}		
		heroes = num;
		}	
		
	 	Hero* users(int i , bool q) {
			int num = i;
			if(q == 1) {
				if (num == 1)
					return hero_1 ;
				else if (num == 2 && hero_2 != NULL)
					return hero_2 ;
				else if (num == 3 && hero_3 != NULL)
					return hero_3 ;
			}	
			if (num == 1)
				return hero_1 ;
			else if (num == 2 && hero_2 != NULL)
				return hero_2 ;
			else if (num == 3 && hero_3 != NULL)
				return hero_3 ;
			if(num < 1 && num > 3 || hero_2 == NULL || hero_3 ==NULL) {
				cout << "no hero matches your number , hero 1 will be selected by default" << endl;
				return hero_1;
			}
		}
		
		void print(int number) {
			if (number == 1)
				cout << hero_1->get_name() << "\n" << endl ;
			else if (number == 2) {
				cout << hero_1->get_name() << "\n" << endl ;
				cout << hero_2->get_name() << "\n" << endl ;
			}
			else {
				cout << hero_1->get_name() << "\n" << endl ;
                            cout << hero_2->get_name() << "\n" << endl ;
				cout << hero_3->get_name() << "\n" << endl ;
			}
			//cout << "Choose hero" << "\n" << endl ;
		}
		
		int chooseName() {
			 int j=0 , option ;
			 string line ;
			 ifstream myfile5 ;
			 myfile5.open("names.txt") ;
                                while(!myfile5.eof()) {
                                        if (getline(myfile5 , line)) {
                                                cout << j << " : " <<  line << endl ;
                                                cout << "\n" << endl ;
                                                j++ ;
                                        }
                                }
                                j = 1 ;
                                cout << "Choose Name\n" << endl ;
                                cin >> option ;
                                myfile5.close() ;
				return option ;
		}
		
		int chooseKind() {
			 int kind , kind2 , kind3 , number ;
			 cout << "Choose number of heroes , they have to be between 1-3. Otherwise one hero will be selected by default\n" << endl ;
  			 cin >> number ;
			 num = number ;
       		if (number == 1) {
                		cout << "Choose type of hero" << "\n" << endl ;
               		cout << "1.Warrior" << "\n" << endl ;
               		cout << "2.Sorcerer" << "\n" << endl ;
                		cout << "3.Paladin" << "\n" << endl ;
              		cin >> kind ;
				k = kind ;
				return number ;
        		}
        		else if (number == 2) {
                		cout << "Choose type of hero" << "\n" << endl ;
                		cout << "1.Warrior" << "\n" << endl ;
                		cout << "2.Sorcerer" << "\n" << endl ;
                		cout << "3.Paladin" << "\n" << endl ;
                		cin >> kind ;
				k = kind ;
                		cout << "Choose type of hero" << "\n" << endl ;
                		cout << "1.Warrior" << "\n" << endl ;
                		cout << "2.Sorcerer" << "\n" << endl ;
                		cout << "3.Paladin" << "\n" << endl ;
                		cin >> kind2 ;
				k_2 = kind2 ;
				return number ;
        		}
        		else if (number == 3){
                		cout << "Choose type of hero" << "\n" << endl ;
                		cout << "1.Warrior" << "\n" << endl ;
                		cout << "2.Sorcerer" << "\n" << endl ;
                		cout << "3.Paladin" << "\n" << endl ;
                		cin >> kind ;
				k = kind ;
                		cout << "Choose type of hero" << "\n" << endl ;
                		cout << "1.Warrior" << "\n" << endl ;
                		cout << "2.Sorcerer" << "\n" << endl ;
				cout << "3.Paladin" << "\n" << endl ;
                		cin >> kind2 ;
				k_2 = kind2 ;
				cout << "Choose type of hero" << "\n" << endl ;
                                cout << "1.Warrior" << "\n" << endl ;
                                cout << "2.Sorcerer" << "\n" << endl ;
                                cout << "3.Paladin" << "\n" << endl ;
                                cin >> kind3 ;
				k_3 = kind3 ;
				return number ;
			}
			else {
				cout << "heroes must be between 1-3 , one hero will be selected by default" << endl;
				return 1;
			}
		}

		void actions() {
			int choice ;
			Hero * h;
			char answer , answer2 , user ;
			//do {
        		       cout << "Choose hero" << "\n" << endl ;
 		      		print(get_number()) ;
				cin >> choice;
                		h = users(choice , 0) ;
                		/*cout << "\n" << "Do you wish to enter Market?" << endl ;
                		cin >> answer ;
                		if (answer == 'y')
                   		     	callMarket(users(choice)) ;
                		cout << "Do you wish to check your inventory?" << endl ;
                		cin >> answer2 ;
                		if (answer2 == 'y')
                        		callCheck(users(choice)) ;
				cout << "Do you wish to check your spells?" << "\n" << endl ;
				cin >> answer2 ;
				if (answer2 == 'y')
                   		     	callCheckSpells(users(choice)) ;
                		cout << "Do you wish to switch user?" << "\n" << endl ;
                		cin  >> user ;
        			}while (user == 'y');*/
			show_map(h);
			move(h);
			callCheck(h);
		}
		
		int get_number() {
			return num ;
		}

int battle (Hero *p) {
    Monster *m;
    int action; 
    int a; 
    int answer;
    //char* choise;    
    a = p->get_level();
    m = createMonster(a);
    while(p->get_health() >= 0 && m->get_health() > 0) {		//emfanizoume ta basika xaraktiristika
    do {
    cout << p->get_name() ;
    cout << "             " << m->get_name() << endl;
    cout << "Health : " << p->get_health() ;
    cout << "    	     " << "Health : " << m->get_health() <<endl ;
    cout << "Mana : " << p->get_magic_power();
    cout << endl;
    cout << endl;
    cout << " What action would you like to do? " << endl;
    cout << "1)attack\n2)use spell\n3)use inventory\n4)change hero" << endl;
    //cin >> choise;
    cin >> answer;
    //answer = atoi(choise);
    if (answer == 1) {			//gia timi 1 exoume apli epithesi
	int temp = 0;
	temp = rand() % 100;
	if(m->get_chance() > temp) {
		cout << "The " << m->get_name() << " dodged your attack" << endl;
	}
	else {
    		action = p->get_equiped_strength() - m->get_def();
		if (action < temp) {
			action = 0;
		}
       	m->set_health (action , 1);  
		cout << m->get_name() << " suffered " << action << " damage" << endl;    
		p->levelUp(m->get_xp());
	}     
	temp = rand() % 100;
	if(p->get_agility() > temp) {  
		cout << p->get_name() << " dodged " << m->get_name() << "'s" << " attack " << endl;
	}
	else {  
		action = m->get_monster_damage() - p->get_dmg_reduction();
		if (action < temp) {
			action = 0;
		}
        p->set_health (action , 1);   
	cout << p->get_name() << " suffered " << action << " damage" << endl;         
    }
	}
    
    else if(answer == 2) {			//gia timi 2 exoume ksorki
	int temp = 0 , temp2;  
	cout << endl;
	temp2 = rand() % 100;
	if (m->get_chance() > temp2) {
		cout << "The " << m->get_name() << " dodged your spell" << endl;
	}
	else {
		temp = p->checkSpells();
		cout << endl;
		cout << "To use a spell choose a number. It will be executed to your enemy" << endl;
		cin >> answer;
		if (answer > 0 && answer <= temp) {
			p->use_s(answer -1, *p , *m);
			action = m->get_monster_damage() - p->get_dmg_reduction();
			if (action < 0) {
				action = 0;
			}
       		p->set_health (action , 1);
			cout << p->get_name() << " suffered " << action << " damage" << endl;
			p->levelUp(m->get_xp());
		}
		else {
	    	cout << "No spell in that position\n" << endl;
		}
    }
	}
    
    else if(answer == 3) {			//gia timi 3 tsekaroume to inventory
	int temp = 0 , temp2 = 0;	
	cout << endl;
	temp = p->checkInventory();
	cout << endl;
	cout << "To use inventory choose a number. It will be equipped to your hero" << endl;
	cin >> answer;
	if (answer > 0 && answer <= 10) {		
		p->equip(answer -1 , *p);
		temp2 = rand() % 100 ;
		if(p->get_agility() > temp2) {  
		cout << p->get_name() << " dodged " << m->get_name() << "'s" << " attack " << endl;
		}
		else {  
			action = m->get_monster_damage() - p->get_dmg_reduction();
			if (action < 0) {
				action = 0;
			}
			p->set_health (action , 1);   
			cout << p->get_name() << " suffered " << action << " damage" << endl;         
		}
	}
    }

    else if(answer == 4) {		//gia timi 4 allazoume paikti
	cout << "choose hero" << endl;
	cin >> answer;
	p = users(answer , 0);
	cout << "you now control " << p->get_name() << endl;
	}
	
    else {
      cout << "Unknown command. Type 1 or 2 or 3 or 4" << endl;
    }
	if(answer >= 1 && answer <=4) {
		if(m->get_health() > 0 && p->get_health() > 0) {		//recover meta to telos tou girou
			double temp;
			temp = p->get_health() * 0.1;
			p->set_health(temp , 0);
			cout << p->get_name() << " recovered " << temp << " health" << endl;
			temp = p->get_magic_power() * 0.1;
			p->set_magic_power(temp , 0);
			cout << p->get_name() << " recovered " << temp << " mana" << endl;
			temp = m->get_health() * 0.1;
			m->set_health(temp , 0);
			cout << m->get_name() << " recovered " << temp << " health\n" << endl;
		}
	}
    }while(m->get_health() > 0 && p->get_health() > 0);
}    
    if(m->get_health() <= 0) {
    		cout << "Creature killed" << endl;
		p->set_money((m->get_level()*100)); 
		cout << p->get_name() << " gained " << p->get_money() << " money " << endl;		
		delete m;
		m = NULL;
    }
    else {
	cout << p->get_name() << " has been killed" << endl;
	p->set_health(100 , 0);
	p->set_magic_power(50 , 0);
    }
}	

Monster * createMonster(int lvl) {		//dimiourgoume tixaia 1 teras
	Monster* monster_1;
	int monster_kind;	
	monster_kind  = rand() % ((3 - 1 + 1) + 1) ;	
	if (monster_kind == 1) {
                monster_1 = new Dragon(lvl * 10 , lvl * 10 , lvl - 5 , lvl * 100 , lvl , lvl * 10 , lvl * 100 , 0 , "Dragon") ;
		cout << "A dragon blocks your path" << endl << endl;
	}        
	else if(monster_kind  == 2) {
                monster_1 = new Exoskeleton(lvl * 8 , lvl * 5 , lvl - 3 , lvl * 80 , lvl , lvl * 8 ,lvl * 80 , 0 , "Exoskeleton") ;
		cout << "An Exoskeleton blocks your path" << endl << endl;
	}        
	else {
        	monster_1 = new Spirit(lvl * 5 , lvl * 8 , lvl , lvl * 60 , lvl , lvl * 7 , lvl * 60 , 0 , "Spirit") ;
		cout << "A Spirit blocks your path" << endl << endl;
	}	
	return monster_1;	
}

void show_map(Hero *h) {			//emfanisi xarti
       int i , j , k;
       for (i = 0 ; i < 10 ; i++) {
                    cout << "+-----" ;
       }      
       for (j = 0 ; j < 10 ; j++) {  
                    cout << "+" ;                     
                    cout << endl ;
       for (i = 0 ; i < 10 ; i++) {
                    cout << "|  " ;                    
					if (Area[j][i] == 1) {
                      if(i == j_position && j == i_position) {
                         cout << "*";
                      }
                      else {
						cout << " ";
                      }
					}
					else if (Area[j][i] == 2) {
					  if(i == j_position && j == i_position) {
                         cout << "*";
                      }
                      else {
						cout << "M";
                      }
					}
					else if(Area[j][i] == 0){
						cout << "X";
					}
                    cout << "  ";
       }
       cout << "|" << endl;
			for (k = 0 ; k < 10 ; k++) {
                 cout << "+-----" ;
			}
       }
       cout << "+" ;
       cout << endl ;
}

void create_map() {
	int i , j;
	i_position = 0;
       j_position = 0;
       is_market = 0;
       found_market = 0;
       for (i = 0 ; i < 10 ; i++) {
           for (j = 0 ; j < 10 ; j++) {
                    if((j % 2) == 0 || i == j) {
                          Area[i][j] = 1;
                       if(found_market == 0) {                      
                          is_market = rand()%2;                            
                             if(is_market == 1) {
                                 Area[i][j] = is_market + 1;
                                 found_market = 1;
                             }
                       } 
                    }
                 else {
                      Area[i][j] = 0;
                 }   
           }          
       }
}

void move(Hero *hero) {		//exoume tin kinisi tou paikti
     char block , answer ;
//     int i = 0 , j = 0;
     int temp;
     cout << "Where do you want to go?" << "\n" << endl ;
     cin >> block ;
     if (block == 's') {
        i_position++;
        if (i_position>=0 && i_position<10) {
           if (Area[i_position][j_position] == 0) {
              i_position--;
              cout << "Non Accessible block" << "\n" << endl ;
           }
           else if (Area[i_position][j_position] == 2) {
                cout << "Market" << "\n" << endl ;
				callMarket(hero);
           }
             else {
                 //cout << "Common" << "\n" << endl ;
			 if((temp == rand() % 2) == 1) {
				battle(hero);
			 }
             }
        }
        else {
            cout << "Out of bounds" << "\n" << endl ;
            i_position--;
		}
//       i_position = i;
//       j_position = j;
       }
       else if (block == 'w') {
             i_position-- ;
             if (i_position>=0 && i_position<10) {
                if (Area[i_position][j_position] == 0) {
                   i_position++;
                   cout << "Non Accessible block" << "\n" << endl ;
                }
                else if (Area[i_position][j_position] == 2) {
                        cout << "Market" << "\n" << endl ;
						callMarket(hero);
                }
                else {
                          //cout << "Common" << "\n" << endl ;
			    if((temp = rand() % 2) == 1) {
			      	 battle(hero);
		   	    }
                }    
             }             
             else {
                 cout << "Out of bounds" << "\n" << endl ;
                 i_position++;
			 }
//         i_position = i;
//         j_position = j;
       }
     else if (block == 'd') {
        j_position++ ;
        if (j_position>= 0 && j_position<10) {
           if (Area[i_position][j_position] == 0) {
              j_position--;
              cout << "Non Accessible block" << "\n" << endl ;
           }
           else if (Area[i_position][j_position] == 2) {          
                cout << "Market" << "\n" << endl ;
				callMarket(hero);
           }
           else {
                 //cout << "Common" << "\n" << endl ;
		   if((temp = rand() % 2) == 1) {
		       battle(hero);
		   }
           }
        }      
        else {
            cout << "Out of bounds" << "\n" << endl ;
            j_position--;
        }
//     i_position = i;
//     j_position = j;
     }
     else if (block == 'a') {
        j_position-- ;
        if (j_position>= 0 && j_position<10) {
           if (Area[i_position][j_position] == 0) {
              j_position++;
              cout << "Non Accessible block" << "\n" << endl ;
           }
           else if (Area[i_position][j_position] == 2) {
                cout << "Market" << "\n" << endl ;
				callMarket(hero);
           }
             else {
                //cout << "Common" << "\n" << endl ;
				if((temp = rand() % 2) == 1) {
				battle(hero);
				}
             }
        }        
        else {
            cout << "Out of bounds" << "\n" << endl ;
            j_position++;
	  }
//      i_position = i;
//      j_position = j;
     }
     else {
		cout << "Unknown command. Type help to see available options" << endl;
     //cin >> answer ;
     }
//   cout << "i = " << i_position << "\nj = " << j_position << endl;
     show_map(hero);
}		

void	play() {	
		string action;
		int i;
		Hero *h;	
		cout << "Choose Hero" << endl;
		int temp;
		cin >> temp;
		h = users(temp , 0);
		show_map(h);
		do{
		cout << "choose action" << endl;	
		cin >> action;
		if(action == "move") {
			move(h);
		}
		else if(action == "inv") {
			callCheck(h);
			//show_map(h);
		}
		else if(action == "spells") {
			callCheckSpells(h);
			//show_map(h);
		}
		else if(action == "quit") {
			for (i = 0 ; i < num ; i++) {
				h = users(i+1 , 1);
				if (h != NULL) {
					delete h;
					h = NULL;
				}
			}
			return;
		}
		else if(action == "help") {
			help();
		}
		else if(action == "show_stats") {
			h->show_stats();
			//show_map(h);			
		}
		else if(action == "change_hero") {
			cout << "Choose your Hero" << endl;
			cin >> temp;
			h = users(temp , 0);
			cout << "You now control " << h->get_name() << endl;
			//show_map(h);
		}
		else {
			cout << "Unknown command , type help to see available options" << endl;
		}
		}while(action != "quit");
}

void help() {
	cout << "Type 'move' to move around the map.\n'w'->up\n's'->down\n'a'->left\n'd'->right" << endl;
	cout << "Type 'inv' to check your inventory" << endl;
	cout << "Type 'spells' to check your spells" << endl;
	cout << "Type 'quit' to exit the game" << endl;
	cout << "Type 'show_stats' to see current's hero stats" << endl;
	cout << "Type 'change_hero' to change your current hero" << endl;
}
};

			



	
