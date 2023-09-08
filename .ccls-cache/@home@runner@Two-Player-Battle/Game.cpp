#include "Player.cpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <time.h>

class Game {
private:
  Player *p1, *p2;

public:
  Game() { p1 = NULL, p2 = NULL; }

  void Start() {
    printGameInfo();
    printPlayerTypeInfo();
    std::cout << "Let's begin the game.\n";
    std::cout << "Select a player type by entering a number (1 for Normal "
                 "Player, 2 for Assassin, 3 for Giant, 4 for Wizard)\n:";
    srand(time(0));
    int num1, num2 = (rand() % 4) + 1;
    std::cin >> num1;
    while (num1 < 1 || num1 > 4) {
      std::cout << "Invalid number entered. Kindly enter a valid number:\n";
      std::cin >> num1;
    }

    selectPlayerType(num1, p1);
    selectPlayerType(num2, p2);

    p2->setName("C.P.U.");
    std::cout << "Enter the name for your player: ";
    std::string nme;
    std::cin >> nme;
    p1->setName(nme);

    while (true) {
      Player1_move();
      if (p2->getHP() <= 0) {
        std::cout << "Player " << p1->getName() << " has won the game!!!!!!!\n";
        break;
      }
      showPlayerStats();
      Player2_move();
      if (p1->getHP() <= 0) {
        std::cout << "Player " << p2->getName() << " has won the game!!!!!!!\n";
        break;
      }
      showPlayerStats();
    }
  }

  void printGameInfo() {
    std::cout << "All the hail Great Wars.\n";
    std::cout << "Welcome to the game of 2 player battle game(ofcourse if are "
                 "a fan of battles).\n\n";
    std::cout << "Some info about the game:\n";
    std::cout << "1. A 2 player battle game in which 1 player is CPU and other "
                 "is you.\n";
    std::cout << "2. You can choose 1 type out of 4 type of players i.e., "
                 "Normal Player, Assassin, Giant, Wizard.\n";
    std::cout
        << "3. Each player has certain characteristics like HP, MP, attack, "
           "special ability which deals high damage while consuming MP, heal "
           "which restores health by certain points while consuming MP.\n";
    std::cout << "4. At a time you'll be allowed to play only 1 move.\n";
    std::cout << "5. If you have MP less than certain points special ability "
                 "will not activate and you will lose your chance.\n";
    std::cout
        << "6. Similar to special ability, heal also requires certain amount "
           "of MP to take effect. If MP is less heal will not be "
           "performed.\n\n";
  }

  void printPlayerTypeInfo() {
    std::cout << "Basically you can choose 1 type of player out of 4 types "
                 "whose characteristics are explained below:\n";
    std::cout << "Normal Player: It has high HP, high MP, avg Normal attack, "
                 "avg Special Attack.\n";
    std::cout << "Requires 100 MP to perform special attack.\n";
    std::cout << "Requires 100 MP to perform heal.\n\n";

    std::cout << "Assassin: It has avg HP, high MP, high Normal Attack, high "
                 "Special Attack.\n";
    std::cout << "Requires 120 MP to perform special attack.\n";
    std::cout << "Requires 80 MP to perform heal.\n\n";

    std::cout << "Giant: It has high HP, low MP, high Normal Attack, avg "
                 "Special Attack.\n";
    std::cout << "Requires 70 MP to perform special attack.\n";
    std::cout << "Requires 50 MP to perform heal.\n\n";

    std::cout << "Wizard: It has avg HP, high MP, low Normal Attack, high "
                 "Special Attack.\n";
    std::cout << "Requires 120 MP to perform special attack.\n";
    std::cout << "Requires 40 MP to perform heal.\n\n";
  }

  void selectPlayerType(int num, Player *&p) {
    if (num == 1) {
      p = new Player();
    } else if (num == 2) {
      p = new Assassin();
    } else if (num == 3) {
      p = new Giant();
    } else {
      p = new Wizard();
    }
  }

  void Player1_move() {
    std::cout << "Enter a number to select the move you want to perform:\n";
    std::cout << "(1 for normal attack, 2 for special attack & 3 for heal)\n";
    int mov;
    std::cin >> mov;
    while (mov < 1 && mov > 3) {
      std::cout << "Enter a valid move number: ";
      std::cin >> mov;
    }
    if (mov == 1) {
      p1->performNormalAttack(p2);
    } else if (mov == 2) {
      p1->performSpecialAttack(p2);
    } else {
      p1->performHeal();
    }
  }

  void Player2_move() {
    if (p2->getMP() >= p2->getSpecialAttack()) {
      p2->performSpecialAttack(p1);
    } else {
      p2->performNormalAttack(p1);
    }
  }

  void showPlayerStats() {
    std::cout << " " << p1->getName() << " HP = " << p1->getHP();
    std::cout << "       " << p2->getName() << " HP = " << p2->getHP() << "\n";
    std::cout << " " << p1->getName() << " MP = " << p1->getMP();
    std::cout << "       " << p2->getName() << " MP = " << p2->getMP()
              << "\n\n";
  }

  ~Game() {
    delete p1;
    delete p2;
  }
};