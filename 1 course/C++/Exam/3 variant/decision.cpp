int getMax(const Game *root)
{
  int sumLeft = root->Result[0];
  int sumRight = root->Result[1];

  if (root != nullptr) {
    if (root->Player[0] != nullptr)
    {
      sumLeft += getMax(root->Player[0]);
    }
    if (root->Player[1] != nullptr)
    {
      sumRight += getMax(root->Player[1]);
    }
    return (sumLeft > sumRight) ? (sumLeft) : (sumRight);
  }
  else
    return -1;
}
