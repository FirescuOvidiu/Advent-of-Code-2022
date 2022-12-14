#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<vector<char>> m(1000, vector<char>(1000, '.'));
  string               line, aux;
  char                 c{};

  int x = 0, y = 0, x2 = 0, y2 = 0, highY = 0;
  while (getline(in, line))
  {
    stringstream ss(line);

    ss >> x >> c >> y;
    ss >> aux;
    highY = max(y, highY);
    while (ss >> x2 >> c >> y2)
    {
      highY = max(y2, highY);

      for (int i = min(y, y2); i <= max(y, y2); i++)
        for (int j = min(x, x2); j <= max(x, x2); j++)
          m[i][j] = '#';

      ss >> aux;
      x = x2, y = y2;
    }
  }

  bool notFound = true;
  int  count    = 0;
  while (notFound)
  {
    int  posX = 0, posY = 500;
    bool canMove = true;
    while (canMove)
    {
      if (posX > highY)
      {
        out << count;
        notFound = false;
        break;
      }
      canMove = false;
      if (m[posX + 1][posY] == '.')
      {
        posX++;
        canMove = true;
      }
      else if (m[posX + 1][posY - 1] == '.')
      {
        posX++;
        posY--;
        canMove = true;
      }
      else if (m[posX + 1][posY + 1] == '.')
      {
        posX++;
        posY++;
        canMove = true;
      }
    }
    count++;
    m[posX][posY] = 'o';
  }

  in.close();
  out.close();
}
