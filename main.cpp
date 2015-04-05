#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
//#include "Living.h"
//#include "Item.h"
#include "Grid.h"

using namespace std;
	
int main() {
	cout << "\n\nWelcome to our game\n\n\n\n\n\n\n" << endl;
	Grid *grid ;	
	grid = new Grid() ;
	grid->play() ;	
	cout << "\n\n\nExiting from game, thank you for playing\n\n\n" << endl;
}
