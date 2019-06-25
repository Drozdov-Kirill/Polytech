#include <iostream>

struct Game {
    Game *Player[2];
    unsigned int Result[2];
};

Game* search(Game *root, int &pos);

int main()
{
  Game *t;

  t = new Game;
  Game *Head;
  Head = t;
  t->Result[0] = 10;
  t->Player[0] = nullptr;

  t->Result[1] = 20;
  t->Player[1] = new Game;
    t->Player[1]->Result[0] = 15;
    t->Player[1]->Player[0] = new Game;
      t->Player[1]->Player[0]->Result[0] = 5;
      t->Player[1]->Player[0]->Player[0] = nullptr;
      t->Player[1]->Player[0]->Result[1] = 13;
      t->Player[1]->Player[0]->Player[1] = nullptr;

    t->Player[1]->Result[1] = 10;
    t->Player[1]->Player[1] = nullptr;

  int pos;
  Game *firstGame = search(t, pos);
  std::cout << "\nРезультат первой встречи победителя(" << pos << "): " << firstGame->Result[pos] << std::endl;

  return 0;
}

Game* search(Game *root, int &pos)
{
  if (root->Result[0] < root->Result[1])
  {
    pos = 1;
  }
  else if (root->Result[0] > root->Result[1])
  {
    pos = 0;
  }

  if (root->Player[pos] != nullptr)
  {
    root = search(root->Player[pos], pos);
  }
  return root;
}
