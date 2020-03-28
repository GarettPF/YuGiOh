#include "game.h"

void Game::create_players() {
	

}

void Game::print_database() {
	
	ifstream file(DATA_PATH);
	string line;

	while (!file.eof()) {
		file >> line;
		cout << line << endl;
	}

}

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
			create_players();
            break;
        case 2:
			print_database();
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