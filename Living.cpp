#include <iostream>
#include <cstdlib>
#include <string>
#include "Item.h"
#include "Living.h"

using namespace std ;

Living :: Living(int health , int living_level , int maxH , int maxM , string living_name) {
	this->healthPower = health ;
	this->level = living_level ;
	this->maxHealth = maxH;
	this->max_magicPower = maxM;
	this->name = living_name ;
	//cout << "\nLiving Created" << endl ;
}

Living :: ~Living() {
	cout << "Living Destoyed" << endl;
}

Hero :: Hero(int magic , int hero_strength , int hero_dexterity , int hero_agility , int cash , int exp, int health, int living_level , int level_cap , int maxH , int maxM , int dmg_red , string living_name) : Living(health , living_level , maxH , maxM , living_name) 
{	
	int i ;
	for (i=0 ; i<10 ; i++) {
		Inventory[i] = NULL;
		SInv[i] = NULL ;
	}
	this->magicPower = magic ;
	this->strength = hero_strength ;
	this->dexterity = hero_dexterity ;
	this->agility = hero_agility ;
	this->money = cash ;
	this->experience = exp ;
	this->level_cap = level_cap;
	this->equiped_strength = strength;
	this->equiped_dexterity = dexterity;
	this->dmg_reduction = dmg_red;
	cout << "New Hero Created with name " << name << endl ;
}

Hero :: ~Hero() {
	/*int i;
	for (i = 0 ; i < 3 ; i++) {*/
		
	cout << "Hero Destroyed" << endl;
}

void Hero :: show_stats() {
	cout << "Name: " << name << endl;
	cout << "Health: " << healthPower << endl;
	cout << "Mana: " << magicPower << endl;
	cout << "Level: " << level << endl;
	cout << "Base Strength: " << strength << "	Current Strength: " << equiped_strength << endl;
	cout << "Base Dexterity: " << dexterity << "	Current Dexterity: " << equiped_dexterity << endl;
	cout << "Agility: " << agility << endl;
	cout << "Money: " << money << endl;
	cout << "Experience: " << experience << endl;
	cout << "Level cap: " << level_cap << endl;
	cout << "Damage reduction: " << dmg_reduction << endl;
}

Monster :: Monster(int monster_damage , int monster_defence , int monster_chance , int health , int living_level , int monster_xp , int maxH , int maxM , string living_name) : Living(health , living_level , maxH , maxM , living_name) {
	this->damage = monster_damage ;
	this->defence = monster_defence ;
	this->chance = monster_chance ;
	this->xp = monster_xp;
	//cout << "Monster Created" << endl ;
}

Monster :: ~Monster() {
	cout << "Monster Destroyed" << endl;
}

int Monster :: get_monster_damage() {
    return damage;
}

void Hero :: set_dmg_reduction(int d) {
	dmg_reduction = d;
}

int Hero :: get_dmg_reduction() {
	return dmg_reduction;
}

int Monster :: get_def() {
	return defence;
}

int Monster :: get_chance () {
	return chance;
}

void Monster :: set_damage (int d) {
	if (damage < 0) {		//epeidi to damage mporei na pesei kato ap' to 0 tote ginetai 0
		damage = 0;
	}
	else {
		damage = d;
	}
}

void Monster :: set_def (int d) {
	if (defence < 0) {
		defence = 0;
	}
	else {
		defence = d;
	}
}

void Monster :: set_chance(int c) {
	if (chance > 30) {
		chance = 30;
	}
	else if (chance < 0) {
		chance = 0;
	}
	else {
		chance = c;
	}
}

void Monster :: set_xp(int x) {
	xp = x;
}

int Monster :: get_xp() {
	return xp;
}

Warrior :: Warrior(int magic , int hero_strength , int hero_dexterity , int hero_agility , int cash , int exp, int health, int living_level , int level_cap , int maxH , int maxM , int dmg_reduction , string living_name) : Hero(magic , hero_strength , hero_dexterity , hero_agility , cash , exp , health , living_level , level_cap , maxH , maxM , dmg_reduction , living_name) 
{
	//cout << "Warrior Created" << endl ;
}

Warrior :: ~Warrior() {
	cout << "Warrior Destroyed" << endl;
}

Sorcerer :: Sorcerer(int magic , int hero_strength , int hero_dexterity , int hero_agility , int cash , int exp, int health, int living_level , int level_cap , int maxH , int maxM , int dmg_reduction , string living_name) : Hero(magic , hero_strength , hero_dexterity , hero_agility , cash , exp , health , living_level , level_cap , maxH , maxM , dmg_reduction , living_name) 
{ 
	//cout << "Sorcerer Created" << endl ;
}

Sorcerer :: ~Sorcerer() {
	cout << "Sorcerer Destroyed" << endl;
}

Paladin :: Paladin(int magic , int hero_strength , int hero_dexterity , int hero_agility , int cash , int exp, int health, int living_level , int level_cap , int maxH , int maxM , int dmg_reduction , string living_name) : Hero(magic , hero_strength , hero_dexterity , hero_agility , cash , exp , health , living_level , level_cap , maxH , maxM , dmg_reduction , living_name){
	//cout << "Paladin Created" << endl ;
}

Paladin :: ~Paladin() {
	cout << "Paladin Destroyed" <<endl;
}

Dragon :: Dragon(int monster_damage , int monster_defence , int monster_chance , int health , int living_level , int xp , int maxH , int maxM , string living_name) : Monster(monster_damage , monster_defence , monster_chance , health , living_level , xp , maxH , maxM , living_name)
{
	/*cout << "damage = " << damage << endl;
	cout << "defence = " << defence << endl;
	cout << "chance = " << chance << endl;
	cout << "health = " << healthPower << endl;
	cout << "level = " << living_level << endl;
	cout << "xp = " << xp << endl;
	cout << "maxH = " << maxHealth << endl;
	cout << "maxM = " << max_magicPower <<endl;*/
	//cout << "Dragon Created\n" << endl ;8
}

Dragon :: ~Dragon() {
	cout << "Dragon Destroyed" << endl;
}

Exoskeleton :: Exoskeleton(int monster_damage , int monster_defence , int monster_chance , int health , int living_level , int xp , int maxH , int maxM , string living_name) : Monster(monster_damage , monster_defence , monster_chance , health , living_level , xp , maxH , maxM , living_name)
{
	/*cout << "damage = " << damage << endl;
	cout << "defence = " << defence << endl;
	cout << "chance = " << chance << endl;
	cout << "health = " << healthPower << endl;
	cout << "level = " << living_level << endl;
	cout << "xp = " << xp << endl;
	cout << "maxH = " << maxHealth << endl;
	cout << "maxM = " << max_magicPower <<endl;*/
	//cout << "Exoskeleton Created\n" << endl ;
}

Exoskeleton :: ~Exoskeleton() {
	cout << "Exoskeleton Destroyed" << endl;
}

Spirit :: Spirit(int monster_damage , int monster_defence , int monster_chance , int health , int living_level , int xp , int maxH , int maxM , string living_name) : Monster(monster_damage , monster_defence , monster_chance , health , living_level , xp , maxH , maxM , living_name)
{
	/*cout << "damage = " << damage << endl;
	cout << "defence = " << defence << endl;
	cout << "chance = " << chance << endl;
	cout << "health = " << healthPower << endl;
	cout << "level = " << living_level << endl;
	cout << "xp = " << xp << endl;
	cout << "maxH = " << maxHealth << endl;
	cout << "maxM = " << max_magicPower <<endl;*/
	//cout << "Spirit Created\n" << endl ;
}

Spirit :: ~Spirit() {
	cout << "Spirit Destroyed" << endl;
}

void Hero :: set_experience(int amount)
{
	this->experience = this->experience + amount ;
}

int Hero :: get_experience()
{
	return (this->experience) ;
}

void Hero :: set_strength(int amount)
{
	int temp;
	this->strength = this->strength + amount ;
}

int Hero :: get_strength()
{
	return (this->strength) ;
}

int Hero :: get_equiped_strength() {
	return equiped_strength;
}

void Hero :: set_equiped_strength(int e) {	
	equiped_strength = strength + e;
}

void Hero :: set_equiped_dexterity(int e) {
	equiped_dexterity = equiped_dexterity + e;
} 

int Hero :: get_equiped_dexterity() {
	return equiped_dexterity;
}

void Hero :: set_dexterity(int d) {
	dexterity = d;
}

int Hero :: get_dexterity() {
	return dexterity;
}

void Hero :: set_agility (int a) {
	if(agility <= 30) {
		agility = a;
	}
	else {
		cout << "Max agility reached" << endl;
	}
}

int Hero :: get_agility () {
	return agility;
}

void Hero :: set_money(int amount)
{
	this->money = this->money + amount ;
}

int Hero :: get_money()
{
	return (this->money) ;
}	

void Hero :: set_magic_power(int amount , bool temp)
{									//gia timi 1 o iroas xanei mana allios kerdizei
	if(temp == 1) {		
             this->magicPower = this->magicPower - amount ;
             return;
       } 
	this->magicPower = this->magicPower + amount ;
	this->magicPower = this->magicPower + amount ;
	if (this->magicPower > max_magicPower)
		this->magicPower = max_magicPower ;
	if (this->magicPower < 0)
		this->magicPower = 0 ;
}

int Hero :: get_magic_power() 
{
	return (this->magicPower) ;
}

void Living :: set_health(int amount , bool temp) 
{    
     if(temp == 1) {
             this->healthPower = this->healthPower - amount ;
             return;
     }
	this->healthPower = this->healthPower + amount ;
	if (this->healthPower > maxHealth)
		this->healthPower = maxHealth ;
	if (this->healthPower < 0)
		this->healthPower = 0 ;
}

int Living :: get_health() {
	return healthPower;
}

string Living :: get_name () {
	return name;
}

void Hero :: levelUp(int x) {
	cout << name << " took " << x << " exp "<< endl;
	experience = experience + x;
	if (experience >= level_cap){
		level++;
		cout << name << " is now " << level << " level" << endl;
		level_cap = level_cap + (level_cap * 0.2);
		maxHealth = maxHealth + 40;
		max_magicPower = max_magicPower+ 30;
		healthPower = maxHealth;
		magicPower = max_magicPower;
		dexterity = dexterity + 5;
		strength = strength + 10;
		cout << name << " needs " << level_cap << " experience to level up" << endl;
		experience = 0;
	}
}

int Living :: get_level()
{
	return level ;
}	

Item** Hero:: get_inventory(int i) {
	return &Inventory[i];
}

void Hero :: equip(int x , Hero &h)
{	
	//cout << Inventory[x]->get_name() << endl;
	if(Inventory[x] != NULL) {
		Inventory[x]->equip_item(h , get_inventory(x));
	}
	else {
	   cout << "No item in that position\n" << endl;
	}	
}
	
void Hero :: use_s (int x , Hero& h, Monster &m) {
	int temp;
	temp = SInv[x]->use_spell(m , h.magicPower , h.equiped_dexterity);	
	h.magicPower = h.magicPower - temp;
} 
