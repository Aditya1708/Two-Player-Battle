#include <iostream>
#include <string>

class Player {
private:
  std::string name;
  int HP, maxHP, MP, normalAttack, specialAttack;

public:
  Player() {
    setHP(170);
    setMP(170);
    setMaxHP(170);
    setNormalAttack(20);
    setSpecialAttack(100);
  }

  virtual std::string getName() { return name; }
  virtual void setName(std::string nm) { name = nm; }

  virtual int getHP() { return HP; }
  virtual void setHP(int hp) { HP = hp; }

  virtual int getMaxHP() { return maxHP; }
  virtual void setMaxHP(int mxHP) { maxHP = mxHP; }

  virtual int getMP() { return MP; }
  virtual void setMP(int mp) { MP = mp; }

  virtual int getNormalAttack() { return normalAttack; }
  virtual void setNormalAttack(int attack) { normalAttack = attack; }

  virtual int getSpecialAttack() { return specialAttack; }
  virtual void setSpecialAttack(int sp) { specialAttack = sp; }

  virtual void performNormalAttack(Player *p2) {
    std::cout << "Player " << getName()
              << " has performed normal attack dealing " << getNormalAttack()
              << " points of health damage to" << p2->getName() << ".\n";
    int p2hp = p2->getHP();
    p2hp -= normalAttack;
    p2->setHP(p2hp);
  }

  virtual void performSpecialAttack(Player *p2) {
    if (MP > specialAttack) {
      std::cout << "Player " << getName()
                << " has performed special attack dealing "
                << getSpecialAttack() << " points of health damage to "
                << p2->getName() << ".\n";
      int p2hp = p2->getHP(), p1mp = getMP();
      p2hp -= specialAttack;
      p1mp -= specialAttack;
      p2->setHP(p2hp);
      setMP(p1mp);
    } else {
      std::cout
          << "Magic Power of player " << getName()
          << " is less than required, so unable to perform special attack.\n";
    }
  }

  virtual void performHeal() {
    if (getMP() < 100) {
      std::cout << "Unable to perform heal as magic power is less. All the "
                   "best for the game ahead.\n";
    } else {
      std::cout << "Player " << getName() << " has performed heal.\n";
      int h = getHP();
      if (h + 100 > getMaxHP()) {
        std::cout << "Health restored to max health.\n";
        setHP(getMaxHP());
      } else {
        setHP(h + 100);
        std::cout << "Health restored by 100 points. Now health is " << h + 100
                  << ".\n";
      }
    }
  }
};

class Assassin : public Player {
public:
  Assassin() {
    setHP(150);
    setMP(200);
    setMaxHP(150);
    setNormalAttack(35);
    setSpecialAttack(120);
  }

  void performNormalAttack(Player *p2) {
    std::cout << "Assassin " << getName()
              << " has performed normal attack dealing " << getNormalAttack()
              << " points of health damage to" << p2->getName() << ".\n";
    int p1_norm_attck = getNormalAttack(), p2hp = p2->getHP();
    p2hp -= p1_norm_attck;
    p2->setHP(p2hp);
  }

  void performSpecialAttack(Player *p2) {
    int p1_mp = getMP(), p1_sp_attck = getSpecialAttack(), p2_hp = p2->getHP();
    if (p1_mp > p1_sp_attck) {
      std::cout << "Assassin " << getName()
                << " has performed special attack Shadow Blade dealing "
                << getSpecialAttack() << " points of health damage to "
                << p2->getName() << ".\n";
      p2_hp -= p1_sp_attck;
      p1_mp -= p1_sp_attck;
      p2->setHP(p2_hp);
      setMP(p1_mp);
    } else {
      std::cout << "Magic Power of Assassin " << getName()
                << " is less than required, so unable to perform special "
                   "attack Shadow Blade.\n";
    }
  }

  void performHeal() {
    if (getMP() < 80) {
      std::cout << "Unable to perform heal as magic power is less. All the "
                   "best for the game ahead.\n";
    } else {
      std::cout << "Assassin " << getName() << " has performed heal.\n";
      int h = getHP();
      if (h + 80 > getMaxHP()) {
        std::cout << "Health restored to max health.\n";
        setHP(getMaxHP());
      } else {
        setHP(h + 80);
        std::cout << "Health restored by 80 points. Now health is " << h + 80
                  << ".\n";
      }
    }
  }
};

class Giant : public Player {
public:
  Giant() {
    setHP(200);
    setMP(80);
    setMaxHP(210);
    setNormalAttack(50);
    setSpecialAttack(70);
  }

  void performNormalAttack(Player *p2) {
    int p2_hp = p2->getHP(), p1_norm_attck = getNormalAttack();
    std::cout << "Giant " << getName()
              << " has performed normal attack dealing " << getNormalAttack()
              << " points of health damage to" << p2->getName() << ".\n";
    p2_hp -= p1_norm_attck;
    p2->setHP(p2_hp);
  }

  void performSpecialAttack(Player *p2) {
    int p1_mp = getMP(), p1_sp_attck = getSpecialAttack(), p2_hp = p2->getHP();
    if (p1_mp > p1_sp_attck) {
      std::cout << "Giant " << getName()
                << " has performed special attack Mountain Fist dealing "
                << getSpecialAttack() << " points of health damage to "
                << p2->getName() << ".\n";
      p2_hp -= p1_sp_attck;
      p1_mp -= p1_sp_attck;
      setMP(p1_mp);
      p2->setHP(p2_hp);
    } else {
      std::cout << "Magic Power of Giant " << getName()
                << " is less than required, so unable to perform special "
                   "attack Mountain Fist.\n";
    }
  }

  void performHeal() {
    if (getMP() < 50) {
      std::cout << "Unable to perform heal as magic power is less. All the "
                   "best for the game ahead.\n";
    } else {
      std::cout << "Giant " << getName() << " has performed heal.\n";
      int h = getHP();
      if (h + 50 > getMaxHP()) {
        setHP(getMaxHP());
        std::cout << "Health restored to max health.\n";
      } else {
        setHP(h + 50);
        std::cout << "Health restored by 50 points. Now health is " << h + 50
                  << ".\n";
      }
    }
  }
};

class Wizard : public Player {
public:
  Wizard() {
    setHP(150);
    setMP(250);
    setMaxHP(150);
    setNormalAttack(10);
    setSpecialAttack(120);
  }

  void performNormalAttack(Player *p2) {
    int p1_norm_attck = getNormalAttack(), p2_hp = p2->getHP();
    std::cout << "Wizard " << getName()
              << " has performed normal attack dealing " << getNormalAttack()
              << " points of health damage to" << p2->getName() << ".\n";
    p2_hp -= p1_norm_attck;
    p2->setHP(p2_hp);
  }

  void performSpecialAttack(Player *p2) {
    int p1_mp = getMP(), p1_sp_attck = getSpecialAttack(), p2_hp = p2->getHP();
    if (p1_mp > p1_sp_attck) {
      std::cout << "Wizard " << getName()
                << " has performed special attack Magma Bullet dealing "
                << getSpecialAttack() << " points of health damage to "
                << p2->getName() << ".\n";
      p2_hp -= p1_sp_attck;
      p1_mp -= p1_sp_attck;
      setMP(p1_mp);
      p2->setHP(p2_hp);
    } else {
      std::cout << "Magic Power of Wizard " << getName()
                << " is less than required, so unable to perform special "
                   "attack Mountain Fist.\n";
    }
  }

  void performHeal() {
    if (getMP() < 40) {
      std::cout << "Unable to perform heal as magic power is less. All the "
                   "best for the game ahead.\n";
    } else {
      std::cout << "Wizard " << getName() << " has performed heal.\n";
      int h = getHP();
      if (h + 40 > getMaxHP()) {
        setHP(getMaxHP());
        std::cout << "Health restored to max health.\n";
      } else {
        setHP(h + 40);
        std::cout << "Health restored by 40 points. Now health is " << h + 40
                  << ".\n";
      }
    }
  }
};