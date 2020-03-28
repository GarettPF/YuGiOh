#include "game.h"

void Game::print_menu() const {
    cout << "~ Welcome to the world of Yu-Gi-Oh ~" << endl << endl
         << "1. Create Players" << endl
         << "2. Add Cards to Specific Player" << endl
         << "3. Trade Cards with Other Player" << endl
         << "4. Battle Other Player" << endl
         << "5. Exit" << endl;
}

bool Game::menu_choice() {
    do {
        print_menu();
        cin >> choice;
    } while (choice < 1 || choice > 5);

    switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            return false;
    }

    return true;
}


void Game::load_cards(ofstream &card_data, Card database[]) {

    

}