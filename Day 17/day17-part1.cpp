#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<vector<char>> m(5000, vector<char>(8, '.'));
  string               line;

  vector<int>         size = { 0, 2, 2, 3, 1 };
  vector<vector<int>> x{
    { 0, 0, 0, 0 }, { 0, 1, 1, 1, 2 }, { 0, 1, 2, 2, 2 }, { 0, 1, 2, 3 }, { 0, 0, 1, 1 }
  };
  vector<vector<int>> y{
    { 3, 4, 5, 6 }, { 4, 3, 4, 5, 4 }, { 5, 5, 3, 4, 5 }, { 3, 3, 3, 3 }, { 3, 4, 3, 4 }
  };

  vector<int> currX = x[0], currY = y[0];
  for (int i = 0; i < currX.size(); i++)
    currX[i] += 4996;

  getline(in, line);
  int i = 0, k = 0, count = 0;

  while (count < 2022)
  {
    if (i == line.size())
      i = 0;

    int move = line[i] == '>' ? 1 : -1;

    // try to move right/left
    bool canMove = true;
    for (int j = 0; j < currX.size(); j++)
    {
      if ((currY[j] + move > 0) && (currY[j] + move < 8) && m[currX[j]][currY[j] + move] != '#')
        continue;
      canMove = false;
    }

    if (canMove)
    {
      for (int j = 0; j < currX.size(); j++)
      {
        currY[j] = currY[j] + move;
      }
    }

    // try to move down
    bool canMoveDown = true;
    for (int j = 0; j < currX.size(); j++)
    {
      if ((currX[j] + 1 < 5000) && (m[currX[j] + 1][currY[j]] != '#'))
        continue;
      canMoveDown = false;
    }

    if (canMoveDown)
    {
      for (int j = 0; j < currX.size(); j++)
      {
        currX[j] = currX[j] + 1;
      }
    }
    else
    {
      for (int it = 0; it < currX.size(); it++)
        m[currX[it]][currY[it]] = '#';

      count++;
      k++;
      if (k == x.size())
        k = 0;

      int findLast = 0;
      for (int i2 = m.size() - 1; i2 > 0; i2--)
      {
        bool check = true;
        for (int j2 = 0; j2 < m[i2].size(); j2++)
        {
          if (m[i2][j2] == '#')
          {
            check = false;
            break;
          }
        }
        if (check)
        {
          findLast = i2;
          break;
        }
      }

      findLast -= 3;
      findLast -= size[k];

      currX = x[k];
      currY = y[k];
      for (int i = 0; i < currX.size(); i++)
        currX[i] += findLast;
    }
    i++;
  }

  for (int i = m.size() - 1; i > 0; i--)
  {
    bool check = true;
    for (int j = 0; j < m[i].size(); j++)
    {
      if (m[i][j] == '#')
      {
        check = false;
        break;
      }
    }
    if (check)
    {
      out << 5000 - i - 1;
      break;
    }
  }

  in.close();
  out.close();
}
