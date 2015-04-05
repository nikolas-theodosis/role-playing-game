#include <iostream>
#include <cstdlib>
#include "Item.h"
#include "Living.h"
#define maxHealth 100
#define max_magicPower 100

using namespace std ;

Item :: Item (string n , int c , int ml) {
     name = n;
     cost = c;
     min_level = ml;
}

Item :: ~Item(){
	cout << "item destroyed" << endl;
}
		
Spell :: Spell (string n , int d , int m , int c , int lvl)
{
	name = n ;
	damage = d ;
	mana_cost = m ;
	cost = c ;
	level = lvl ;
}

icespell :: icespell(int dmg , string n , int d , int mana , int ml , int c) : Spell(n , d , mana ,  c , ml) {
	dmg_reduction = dmg ;
}

firespell :: firespell(int def , string n , int d , int mana , int ml , int c) : Spell(n , d , mana , c , ml) {
	def_reduction = def ;
}

lightingspell :: lightingspell(int luck , string n , int d , int mana , int ml , int c) : Spell(n , d , mana ,  c , ml) {	
	luck_reduction = luck ;
}

string Item :: get_name() {
       return name;
}

string Spell :: get_spell_name() {
	return name ;
}

int Item :: get_cost() {
    return cost;
}

int Item :: get_min_level() {
    return min_level;
}


weapon :: weapon (int d , int h , string n ,int c , int ml) : Item (n , c , ml) {
       damage = d;
       handed = h;
}

weapon :: ~weapon() {
	cout << "weapon destroyed " <<endl;
}

int weapon :: get_damage() {
    return damage;
}

int weapon :: get_handed() {
    return handed;
}

void weapon :: print () {	
	cout << "name: " << name << endl;
	cout << "min level: " << min_level << endl;
	cout << "cost: " << cost << endl;
	cout << "damage: " << damage << endl;
	cout << "hands: " << handed+1 << endl;
	cout << "Type: weapon\n" << endl;
}

armor :: armor (int dr , string n , int c , int ml) : Item (n , c , ml) {
      dmg_reduction = dr;
}

armor :: ~armor() {
	cout << "armor destroyed" << endl;
}

int armor :: get_dmg_reduction () {
    return dmg_reduction;
}

void armor :: print() {
	cout << "name: " << name << endl;
	cout << "min level: " << min_level << endl;
	cout << "cost: " << cost << endl;
	cout << "dmg_reduction: " << dmg_reduction << endl;
	cout << "Type: armor\n" << endl;
}

potion :: potion (bool u , int b , string n , int c , int ml) : Item  (n , c , ml) {
       bonus = u;
       bonus_type = b; //flag timi gia to bonus se kapoio xaraktiristiko tou hero
	switch(bonus_type){
	case 0:
		bonus = rand() % 301;	//health
		break;
	case 1:
		bonus = rand() % 301;	//mana
		break;
	case 2:
		bonus = rand() % 11;		//strength
		break;
	case 3:
		bonus = rand() % 4;		//dexterity
		break;
	case 4:
		bonus = rand() % 2;		//agility
		break;
	}
}

potion :: ~potion () {
	cout << "potion destroyed" << endl;
}

int potion :: get_bonus_type () {
     return bonus_type;
}

int potion :: get_bonus () {
    return bonus;
}

void potion :: print () {	//new
	cout << "name: " << name << endl;
	cout << "min level: " << min_level << endl;
	cout << "cost: " << cost << endl;
	switch(bonus_type) {
	case 0:
		cout << "bonus: restores " << bonus << " health"<< endl;
		break;
	case 1:
		cout << "bonus: restores " << bonus << " mana" << endl;
		break;
	case 2:
		cout << "bonus: gives " << bonus << " strength permantly" << endl;
		break;
	case 3:
		cout << "bonus: gives " << bonus << " dexterity permantly" << endl;
		break;
	case 4:
		cout << "bonus: gives " << bonus << " agility permantly" << endl;
		break;
	}
	cout << "Type: potion\n" << endl;
}

void Item :: setCost(int amount)
{
	this->cost = amount ;
}

int Spell :: get_damage() 
{
	return damage ;
}

int Spell :: get_mana_cost()
{
	return mana_cost ;
}

int Spell :: get_spell_cost()
{
	return cost ;
}

int firespell :: get_def_reduction() {
	return def_reduction;
}


void firespell :: print() 
{
	 cout << "name: " << name << endl;
        cout << "level: " << level << endl;
        cout << "manacost: " << mana_cost << endl;
        cout << "damage: " << damage << endl;
	 cout << "defence reduction: " << def_reduction << endl;
        cout << "type: firespell\n" << endl;
}

int icespell :: get_dmg_reduction () {
	return dmg_reduction;
}

void icespell :: print()
{
	 cout << "name: " << name << endl;
        cout << "level: " << level << endl;
        cout << "manacost: " << mana_cost << endl;
        cout << "damage: " << damage << endl;
	 cout << "damage reduction: " << dmg_reduction << endl;
        cout << "type: icespell\n" << endl;
}

int lightingspell :: get_luck_reduction() {
	return luck_reduction;
}

void lightingspell :: print()
{
	 cout << "name: " << name << endl;
        cout << "level: " << level << endl;
        cout << "manacost: " << mana_cost << endl;
        cout << "damage: " << damage << endl;
	 cout << "chance reduction: " << luck_reduction << endl;
        cout << "type: lighting\n" << endl;
}

void armor :: equip_item(Hero &h , Item ** I) {
	h.set_dmg_reduction(I[0]->get_dmg_reduction());
	cout << "You equiped " << I[0]->get_name() << " to " << h.get_name() << endl;
}

void potion :: equip_item(Hero &h , Item ** I) {			//xreisimopoiisi tou potion kai diagrafi tou ap' ton pinaka
	int temp;
	switch(I[0]->get_bonus_type()) {
	case 0:
		//cout << "health = " << h.get_health() << endl;
		h.set_health(I[0]->get_bonus() , 0);
		//cout << "health = " << h.get_health() << endl;
		cout << h.get_name() << " recovered " << I[0]->get_bonus() << " health" << endl;
		delete I[0];
		I[0] = NULL;
		break;
	case 1:
		//cout << "mana = " << h.get_magic_power() << endl;
		h.set_magic_power(I[0]->get_bonus() , 0);
		//cout << "mana = " << h.get_magic_power() << endl;
		cout << h.get_name() << " recovered " << I[0]->get_bonus() << " mana" << endl;
		delete I[0];
		I[0] = NULL;
		break;
	case 2:
		//cout << "strength = " << h.get_strength() << endl;
		temp = I[0]->get_bonus();
		//h.set_strength(temp + h.get_strength());
		cout << "strength = " << h.get_strength() << endl;
		cout << h.get_name() << " has now " << I[0]->get_bonus() << " more strength" << endl;
		delete I[0];
		I[0] = NULL;
		break;
	case 3:
		//cout << "dexterity = " << h.get_dexterity() << endl;
		temp = I[0]->get_bonus();
		//h.set_dexterity(temp + h.get_dexterity());
		cout << "dexterity = " << h.get_dexterity() << endl;
		cout << h.get_name() << " has now " << I[0]->get_bonus() << " more dexterity" << endl;
		delete I[0];
		I[0] = NULL;
		break;
	case 4:
		//cout << "agility = " << h.get_agility() << endl;
		temp = I[0]->get_bonus();
		//h.set_agility(temp + h.get_agility());
		cout << "agility= " << h.get_agility() << endl;
		cout << h.get_name() << " has now " << I[0]->get_bonus() << " more agility" << endl;
		delete I[0];
		I[0] = NULL;
		break;
	default :
		cout << "No potion used. Maybe you did not give the right number......" << endl;
	}
}

void weapon :: equip_item(Hero &h , Item ** I) {	
	//cout << "strength = " << h.get_strength() << endl;
	h.set_equiped_strength(I[0]->get_damage());
	//cout << "strength = " << h.get_strength() << endl;
	cout << "You equiped " << I[0]->get_name() << " to " << h.get_name() << endl;
}


int icespell :: use_spell(Monster &m , int mana , int d) {
	if( mana >= mana_cost) {
		m.set_health (damage + d - m.get_def() , 1);
		m.set_damage(m.get_monster_damage() - dmg_reduction);
		cout << "You used " << name << " for " << damage - m.get_def() << " damage" << endl;
		return mana_cost;
	}
	else {
		cout << "Not enough mana" << endl;
		return 0;
	}
}

int firespell :: use_spell(Monster &m , int mana , int d) {
	if (mana >= mana_cost) {
		m.set_health (damage + d - m.get_def() , 1);
		m.set_def(m.get_def() - def_reduction);
		cout << "You used " << name << " for " << damage - m.get_def() << " damage" << endl;
		return mana_cost;
	}
	else {
		cout << "Not enough mana" << endl;
		return 0;
	}
}

int lightingspell :: use_spell(Monster &m , int mana , int d) {
	if (mana >= mana_cost) {
		m.set_health (damage +d - m.get_def() , 1);
		m.set_chance(m.get_chance() - luck_reduction);
		cout << "You used " << name << " for " << damage - m.get_def() << " damage" << endl;
		return mana_cost;
	}
	else {
		cout << "Not enough mana" << endl;
		return 0;
	}
}


