#ifndef GAME_H_
#define GAME_H_

#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls")
#define PAUSE system("pause")
#define DATA_PATH "monster_data.csv"
#define DATA_SIZE 4119


#include "Stack.h"
#include "Queue.h"
#include <fstream>
#include <string>
#include <cstring>


struct Card {
    string name;
    string type;
    int atk;
    int def;
};

class Game {

    private:
        int choice;

		int p1LP;
		int p2LP;

		Stack p1_deck;
		Stack p2_deck;

		Queue p1_atk;
		Queue p1_def;
		Queue p2_atk;
		Queue p2_def;

		Card p1_hand[5];
		Card p2_hand[5];

		void create_players();
		string gotoline(unsigned int);
		void print_database();
		void add_card();
		void trade_cards();
		int start();
		void displayHand(Card hand[]);
		void battle(int*, int*);
		bool check_winner(int *);

    public:
		Game() {
			choice = 0;
		};
        void print_menu() const;
        bool menu_choice();
};

#endif