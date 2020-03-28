#ifndef GAME_H_
#define GAME_H_

#define CLS system("cls")
#define DATA_PATH "monster_data.csv"
#define DATA_SIZE 4119


#include "Stack.h"
#include "Queue.h"
#include <fstream>

struct Card {
    string name;
    string type;
    int atk;
    int def;
};

class Game {

    private:
        int choice;

		Stack p1_deck;
		Stack p2_deck;

		void create_players();
		fstream &gotoline(fstream &, unsigned int);
		void print_database();

    public:
        void print_menu() const;
        bool menu_choice();
        void play_game();

};

#endif