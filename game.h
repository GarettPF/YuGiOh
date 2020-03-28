#ifndef GAME_H_
#define GAME_H_

#define CLS system("clear")

#include "Stack.h"
#include "Queue.h"

struct Card {
    string name;
    string type;
    int atk;
    int def;
};

class Game {

    private:
        int choice;
        Card allCards[];

    public:
        void print_menu() const;
        bool menu_choice();
        void load_cards(ofstream &card_data, Card database[]);
        void play_game();
};

#endif