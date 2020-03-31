#include "game.h"

void Game::create_players() {
	
	string monster;
	char *str = (char*)malloc(sizeof(char*) * 256);
	Stack::Card card;

	for (int i = 0; i < 60; i++) {
		monster = gotoline(rand() % DATA_SIZE);
		strcpy(str, monster.c_str());

		card.name = strtok(str, ",");
		card.type = strtok(NULL, ",");
		card.atk = atoi(strtok(NULL, ","));
		card.def = atoi(strtok(NULL, ","));

		if (i < 30)
			p1_deck.push(card);
		else
			p2_deck.push(card);
	}
	cout << "Finished distributing cards" << endl;

	PAUSE;

}

string Game::gotoline(unsigned int num) {
	ifstream file(DATA_PATH);
	string line;
	int count = 0;

	while (count != num) {
		count++;
		getline(file, line);
	}

	return line;
}

void Game::print_database() {
	
	ifstream file(DATA_PATH);
	string line;
	int count = 0;


	while (!file.eof()) {
		count++;
		getline(file, line);
		cout << count << ". " << line << endl;
	}

	PAUSE;
}

void Game::add_card() {
	int player, monster;
	char *str = (char *)malloc(sizeof(char *) * 256);
	string monsterstr;
	Stack::Card card;

	cout << "Player 1 or Player 2: ";
	cin >> player;

	print_database();
	cout << "which monster would you like to add (no.): ";
	cin >> monster;

	monsterstr = gotoline(monster);
	strcpy(str, monsterstr.c_str());

	card.name = strtok(str, ",");
	card.type = strtok(NULL, ",");
	card.atk = atoi(strtok(NULL, ","));
	card.def = atoi(strtok(NULL, ","));

	if (player == 1)
		p1_deck.push(card);
	else
		p2_deck.push(card);

	cout << card.name << " added to player " << player << " deck" << endl;
	PAUSE;
}

void Game::trade_cards() {
	CLS;
	int count = 0, p1, p2;
	Stack::Card card1, card2;
	
	p1_deck.printAll();
	cout << "Player 1; which card would you like to trade: ";
	cin >> p1;
	CLS;
	p2_deck.printAll();
	cout << "Player 2; which card would you like to trade: ";
	cin >> p2;

	card1 = p1_deck.searchAndDestroy(p1);
	card2 = p2_deck.searchAndDestroy(p2);

	p1_deck.push(card2);
	p2_deck.push(card1);

	cout << "Finished trading:" << endl;
	PAUSE;
}

int Game::start() {
	int player = rand() % 2 + 1; // flip coin
	int choice, p1_ = 0, p2_ = 0, winner;
	Stack::Card sCard;
	Queue::Card qCard;
	Card card;

	p1LP = p2LP = 8000;

	for (int i = 0; i < 5; i++) {
		p1_deck.pop(sCard);
		card.name = sCard.name;
		card.type = sCard.type;
		card.atk = sCard.atk;
		card.def = sCard.def;
		p1_hand[i] = card;

		p2_deck.pop(sCard);
		card.name = sCard.name;
		card.type = sCard.type;
		card.atk = sCard.atk;
		card.def = sCard.def;
		p2_hand[i] = card;
	}

	while (check_winner(&winner)) {
		CLS;

		if (player == 1) {
			displayHand(p1_hand);
			// add to atk
			cout << "which card to atk queue? ";
			cin >> choice;
			qCard.name = p1_hand[choice].name;
			qCard.type = p1_hand[choice].type;
			qCard.atk = p1_hand[choice].atk;
			qCard.def = p1_hand[choice].def;
			p1_atk.enqueue(qCard);

			p1_deck.pop(sCard);
			card.name = sCard.name;
			card.type = sCard.type;
			card.atk = sCard.atk;
			card.def = sCard.def;
			p1_hand[choice] = card;

			displayHand(p1_hand);
			// add to def
			cout << "which card to def queue? ";
			cin >> choice;
			qCard.name = p1_hand[choice].name;
			qCard.type = p1_hand[choice].type;
			qCard.atk = p1_hand[choice].atk;
			qCard.def = p1_hand[choice].def;
			p1_def.enqueue(qCard);

			p1_deck.pop(sCard);
			card.name = sCard.name;
			card.type = sCard.type;
			card.atk = sCard.atk;
			card.def = sCard.def;
			p1_hand[choice] = card;

			cout << "Activate (1. atk) or (2. def): ";
			cin >> p1_;
		} else {
			displayHand(p2_hand);
			// add to atk
			cout << "which card to atk queue? ";
			cin >> choice;
			qCard.name = p2_hand[choice].name;
			qCard.type = p2_hand[choice].type;
			qCard.atk = p2_hand[choice].atk;
			qCard.def = p2_hand[choice].def;
			p2_atk.enqueue(qCard);

			p2_deck.pop(sCard);
			card.name = sCard.name;
			card.type = sCard.type;
			card.atk = sCard.atk;
			card.def = sCard.def;
			p2_hand[choice] = card;

			displayHand(p2_hand);
			// add to def
			cout << "which card to def queue? ";
			cin >> choice;
			qCard.name = p2_hand[choice].name;
			qCard.type = p2_hand[choice].type;
			qCard.atk = p2_hand[choice].atk;
			qCard.def = p2_hand[choice].def;
			p2_def.enqueue(qCard);

			p2_deck.pop(sCard);
			card.name = sCard.name;
			card.type = sCard.type;
			card.atk = sCard.atk;
			card.def = sCard.def;
			p2_hand[choice] = card;

			cout << "Activate (1. atk) or (2. def): ";
			cin >> p2_;
		}

		if (p1_ && p2_) {
			battle(&p1_, &p2_);
			cout << "Player 1 LP: " << p1LP << endl
				<< "Player 2 LP: " << p2LP << endl;
			PAUSE;
		}
		player = (player == 1) ? 2 : 1;
	}

	return winner;
}

void Game::displayHand(Card hand[]) {
	for (int i = 0; i < 5; i++) {
		cout << i << ". "
			<< hand[i].name << ", "
			<< hand[i].type << ", "
			<< hand[i].atk << ", "
			<< hand[i].def << endl;
	}
}

void Game::battle(int *p1, int *p2) {
	Queue::Card p1_card,
		p2_card;

	if (*p1 == 1) {
		p1_atk.dequeue(p1_card);
		cout << "Player 1 chooses " << p1_card.name << " in ATK mode\n";
	}
	else {
		p1_def.dequeue(p1_card);
		cout << "Player 1 chooses " << p1_card.name << " in DEF mode\n";
	}
	if (*p2 == 1) {
		p2_atk.dequeue(p2_card);
		cout << "Player 2 chooses " << p2_card.name << " in ATK mode\n";
	}
	else {
		p2_def.dequeue(p2_card);
		cout << "Player 2 chooses " << p2_card.name << " in DEF mode\n";
	}

	if (*p1 == 1 && *p2 == 1) {
		if (p1_card.atk > p2_card.atk) {
			p2LP -= p1_card.atk - p2_card.atk;
			cout << "Player 2 losses " << p1_card.atk - p2_card.atk << " life points" << endl;
		} else {
			p1LP -= p2_card.atk - p1_card.atk;
			cout << "Player 1 losses " << p2_card.atk - p1_card.atk << " life points" << endl;
		}
	} else if (*p1 == 1 && *p2 == 2) {
		p2LP -= p1_card.atk - p2_card.def;
		cout << "Player 2 losses " << p1_card.atk - p2_card.def << " Life points" << endl;
	} else if (*p1 == 2 && *p2 == 1) {
		p1LP -= p2_card.atk - p1_card.def;
		cout << "Player 1 losses " << p2_card.atk - p1_card.def << " Life points" << endl;
	} else if (*p1 == 2 && *p2 == 2) {
		cout << "No player losses points" << endl;
	}

	*p1 = *p2 = 0;
	
}

bool Game::check_winner(int *winner) {
	if (p1LP < 0) {
		*winner = 2;
		return false;
	}
	if (p2LP < 0) {
		*winner = 1;
		return false;
	}
	return true;
}

void Game::print_menu() const {
    cout << "~ Welcome to the world of Yu-Gi-Oh ~" << endl << endl
         << "1. Create Players" << endl
		 << "2. View cards" << endl
         << "3. Add Cards to Specific Player" << endl
         << "4. Trade Cards with Other Player" << endl
         << "5. Battle Other Player" << endl
         << "6. Exit" << endl;
}

bool Game::menu_choice() {
	int winner;
    do {
		CLS;
        print_menu();
        cin >> choice;
    } while (choice < 1 || choice > 6);

    switch (choice) {
        case 1:
			create_players();
            break;
        case 2:
			CLS;
			cout << "Player 1 deck:" << endl;
			p1_deck.printAll();
			PAUSE;
			CLS;
			cout << "Player 2 deck:" << endl;
			p2_deck.printAll();
			PAUSE;
            break;
        case 3:
			add_card();
            break;
        case 4:
			trade_cards();
            break;
        case 5:
			winner = start();
			cout << "Player " << winner << " wins the game!" << endl;
			PAUSE;
			break;
		case 6:
			return false;
    }

    return true;
}