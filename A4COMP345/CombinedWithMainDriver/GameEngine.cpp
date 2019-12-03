
#include "GameEngine.h"


MapLoader* loadMap(const char *directory);
void getUserSelection(int *choice);
vector<Player*> determinePlayerOrder(Player *winner, vector<Player*> players);

int main() {
    const char *directory = "../Maps/";

    int choice = 0;
    while (choice != 2 && choice != 1) {
      cout << "Welcome to the game! Enter 1 for single mode or 2 for Tournament mode.\n";
      cin >> choice;
    }
    bool tournament = choice - 1;

    try {
        MapLoader *mapLoader = loadMap(directory);// To be deleted at the end of the game.
        Map *map = mapLoader->getGraph();


        Map *map2 = Map::instance(new std::string("graph"));

        if(map2 == map){
            cout << "\n\nSAME MAP With the singleton pattern!" << endl;
        } else{
            cout << "\n\nNot the same MAP With the singleton pattern!" << endl;
        }

        //delete map2;
        int number = 0;
        while (number < 2 || number > 5) {
            std::cout << "\nEnter the number of players (2 to 5): ";
            if (!tournament)
              cin >> number;
            else
              number = rand() % 4 + 2;
        }
        cout << "\nThank You! Setting up the game for " << number << " players..." << endl;

        // Vector that will hold the pointers to the different players.
        vector<Player *> players;
        BidingFacility *bidingFacility = new BidingFacility();

        cout << "\n\nDISPLAY OF THE PLAYERS CREATED, THE DIFFERENT NAME, EMPTY HAND AND COINS ALLOWED." << endl;

        for (int i = 0; i < number; i++) {
            // Create a new player object with default name and coin number that will be changed later.
            Player *newPlayer = new Player("Red", 10, rand() % 31 + 1, rand() % +12, rand() % 99 + 1930, new HumanStrategy());
            newPlayer->setTournament(tournament);
            // Change the name of the player created above depending on the value of i.  0 stays as "Red".
            if (i == 1) {
                newPlayer->setName("Blue");
            } else if (i == 2) {
                newPlayer->setName("Green");
            } else if (i == 3) {
                newPlayer->setName("Yellow");
            } else if (i == 4) {
                newPlayer->setName("Pink");
            }

            // Set the number of coins according to the number of players playing.
            if (number == 2) {
                newPlayer->setPlayerCoins(14);

            } else if (number == 3) {
                newPlayer->setPlayerCoins(11);
            } else if (number == 4) {
                newPlayer->setPlayerCoins(9);
            } else {
                newPlayer->setPlayerCoins(8);
            }

            cout << "\n\tCoins supplied to Player " << i + 1 << " (" << newPlayer->getName() << "): "
                 << *newPlayer->getPlayerCoins() << endl;

            // Set the playerBidingFacility to be shared between players.
            newPlayer->setPlayerBiddingFacility(bidingFacility);


            // Showing that each player have an empty hand of cards.
            vector<Card *> cards = newPlayer->getCards();
            cout << "\tCards in the hand of Player " << i + 1 << " (" << newPlayer->getName() << "): " << cards.size()
                 << endl;

            // Add the player to the vector of players.
            players.emplace_back(newPlayer);
        }

        cout << endl;

        // Instantiate the deck of cards depending on the number of players.
        Deck *deck;
        if (number != 5) {
            deck = new Deck(37);
            cout << deck->howManyCards() << " cards were created. Shuffled on creation." << endl;
        } else {
            deck = new Deck(42);
            cout << deck->howManyCards() << " cards were created. Shuffled on creation." << endl;
        }

        cout << "\n\nDISPLAY OF THE 6 CARDS IN THE MIDDLE OF THE BOARD." << endl;

        HandObject *handObj = new HandObject(deck);
        handObj->toString();

        cout << "\n\nPLAYER DETAILS FOR BIDDING VALIDATION." << endl;
        for (std::vector<Player *>::size_type i = 0; i != players.size(); i++) {
            // Player* player = players[i];
            players[i]->toString();
        }

		vector<int> bids;
        cout << "\n\nBIDDING PROCESS" << endl;
        for (std::vector<Player *>::size_type i = 0; i != players.size(); i++) {
            // Player* player = players[i];
			cout << players[i]->getName() << ", how much would you like to bid? ";
            int bid;
            if (!tournament)
              cin >> bid;
            else
              bid = rand() % *players[i]->getPlayerCoins();
			bids.emplace_back(bid);
            players[i]->playerBid(bid);
        }

        cout << "\n\nBIDDING RESULT" << endl;
		for (std::vector<Player*>::size_type i = 0; i != players.size(); i++) {
			cout << players[i]->getName() << " bid " << bids[i] << " coins." << endl;
		}
        Player *winner = bidingFacility->revailHighestBider();
        players = determinePlayerOrder(winner, players);
        
        cout << "\n\nARMY PROCESS" << endl;
        int nbOfCountries = map->getNumberCountries();
        //srand(time(0));
        int startingLocation = 15;
        Node *startingLoc = map->getNode(startingLocation);

        PlayerActions* playerActions = new PlayerActions();
        PlayerActions::setStartingLocation(startingLoc);
            for (std::vector<Player *>::size_type i = 0; i != players.size(); i++) {
                for (int j = 0; j < 3; j++) {
                    // Add armies to the starting location.
                     //players[i]->PlaceNewArmies(startingLoc);
                     players[i]->PlaceNewArmies(startingLoc);
                     //playerActions->(startingLoc, players[i]);
                }
               // cout << "3 "<< players[i]->getName()<<" Armies were added to the starting location. Location: " << *startingLoc->getName() << endl;
            }
        // If there are 2 players, add another player that will not play with other armies (non player color)
         if (number == 2 ) {
            int armiesplaced = 0 ;
            int indexOfPlayer = 0;
            Player* nonPlayerColor = new Player();
            nonPlayerColor->setName("Black");
            int location = 0 ;
            // Run this loop ten times to place all of the armies of the 3rd non-player player.
            while(armiesplaced < 10 ){
            location = 0 ;
            //cout << "Player " << players[indexOfPlayer]->getName() << " turns to add another non player army of which node:(Has to be an index between 1 and"<< nbOfCountries<< ")." << endl;
            while( location < 1 || location > nbOfCountries  ) {
                cout << "\nPlayer " << players[indexOfPlayer]->getName() << " turns to add the " << armiesplaced + 1  << " non player army to which node:( it has to be an index between 1 and "<< nbOfCountries<< ")." << endl;
                cin >> location;
            }
            // Set a new army at this location.
            nonPlayerColor->PlaceNewArmies(map->getNode(location));
            // Increment the armies placed.
            armiesplaced++ ;

            // Increment the indexOfPlayer to place the armies and take the remainder for 2 so that it changes  at each iterations.
            indexOfPlayer++ ;
            indexOfPlayer = indexOfPlayer % 2;
        }
        // Place the starting armies of the players depending on the starting location.
        for (std::vector<Player *>::size_type i = 0; i != players.size(); i++) {
            for (int j = 0; j < 3; j++) {}
            players[i]->PlaceNewArmies(startingLoc);
        }
    }
        
        GameScore *gameScore = new GameScore(players, map);
        
         // Create the instance of the MainGameLoop, which will run itself.
        MainGameLoop *mainGameLoop = new MainGameLoop(handObj, players, gameScore);
        mainGameLoop->~MainGameLoop();
        
        // Delete the players.
        for(std::vector<Player*>::size_type i = 0; i != players.size(); i++) {
            Player* temp = players[i];
            //delete temp;
        }

        // Delete the mapLoader which will delete the map.
        delete mapLoader;

        // cout << "The winner of the bid is :"<< winner->getName() ;
    } catch (const std::exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}


// List files in directory, prompt for user selection and load map
MapLoader* loadMap(const char *directory) {
    DIR *dir;
    struct dirent *ent;
    vector<string> files;
    string filePath;

    if ((dir = opendir (directory)) != NULL) {

        // Print files in given directory
        while ((ent = readdir (dir)) != NULL) {
            if ((strcmp(ent->d_name, ".") != 0) && (strcmp(ent->d_name, "..") != 0)) {
                files.push_back(ent->d_name);
            }
        }
        closedir (dir);
    } else {
        throw invalid_argument("Directory could not be opened. Please review input.");
    }

	cout << "Please select a map from the following list:" << endl;
	cout << endl;

    // Display results
    for (int i = 0; i < files.size(); i++) {
        cout << to_string(i) << ": " << files.at(i) << endl;
    }

    // Prompt user choice
    int userChoice = -1;
    int *choice = &userChoice;
    bool isErrorState = true;

    while (isErrorState) {
        getUserSelection(choice);
        cout << "You have chosen file #" << *choice << ": " << files.at(*choice) << endl;
		cout << endl;

        // Combine dir and filename
        filePath = directory + files.at(*choice);

        try {
            MapLoader *mapLoader = new MapLoader(filePath);
            mapLoader->processMap();
            Map* map = mapLoader->getGraph();
            return mapLoader;

            isErrorState = 0;
        } catch (const std::exception& ex) {
            isErrorState = 1;
            cout << endl << ex.what() << endl;
        }
    }
    return NULL;
};

// Prompts user for input
void getUserSelection(int *choice) {
    cout << "\nEnter the number of the file you want to load: ";
    cin >> *choice;
}


// Loadmap
MapLoader* loadMap2(const char*  filePath) {

    try {
        MapLoader *mapLoader = new MapLoader(filePath);
        mapLoader->processMap();
        Map* map = mapLoader->getGraph();
        return mapLoader;


    } catch (const std::exception& ex) {

        cout << endl << ex.what() << endl;
    }

    return NULL;
};

// Determine the order in which players will play as determined by the winner
vector<Player*> determinePlayerOrder(Player *winner, vector<Player*> players) {
    cout << endl << winner->getName() << " suggests the following order for the gameplay: ";
    sort(players.begin(), players.end());
    
    for (int i = 0; i < players.size(); i++) {
        if (i < players.size() - 1) {
            cout << players[i]->getName() << ", ";
        } else {
            cout << players[i]->getName() << endl;
        }
    }
    
    cout << players[0]->getName() << " will start playing the game." << endl;
    
    return players;
}

