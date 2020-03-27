#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <cstdlib>

#define CLS system("clear")

using namespace std;

struct Card {
    string name;
    string type;
    int atk;
    int def;
};

void print_menu();

bool menu_choice();

void load_cards(ofstream &card_data, Card database[]);

void play_game();






#endif