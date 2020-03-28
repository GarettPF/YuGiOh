/**********************************************************
* Programmer: Garett Pascual-Folster					  *
* Class: CptS 122, Spring, 2020; Lab Section 4			  *
* Programming Assignment: PA5							  *
* Date: March 25, 2020									  *
* Description: Yu-Gi-Oh the card game simulator			  *
**********************************************************/
	
#include "game.h"

int main() {

	Game game;

	// program loop
	while (game.menu_choice()) {
		CLS;
	}
	

	return 0;
}