#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<vector<char>> m(15000, vector<char>(8, '.'));
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
    currX[i] += 14996;

  getline(in, line);
  int       i = 0, sum = 0, test = 0, k = 0;
  long long count = 0;

  while (count < 1000000000000)
  {
    if (i == line.size())
      i = 0;

    int move = line[i] == '>' ? 1 : -1;

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

    bool canMoveDown = true;
    for (int j = 0; j < currX.size(); j++)
    {
      if ((currX[j] + 1 < 15000) && (m[currX[j] + 1][currY[j]] != '#'))
        continue;
      canMoveDown = false;
    }

    if (canMoveDown)
    {
      for (int j = 0; j < currX.size(); j++)
      {
        currX[j] = currX[j] + 1;
      }
      i++;
      test++;
    }
    else
    {
      i++;
      for (int g = 0; g < currX.size(); g++)
        m[currX[g]][currY[g]] = '#';

      count++;
      k++;

      int pos2 = 0;
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
          pos2 = i2;
          break;
        }
      }
      if (k == x.size())
      {
        k = 0;
      }
      if ((test == 36) || (count == 8405))
      {
        int tall = 0;
        for (int it = m.size() - 1; it > 0; it--)
        {
          bool check = true;
          for (int j = 0; j < m[it].size(); j++)
          {
            if (m[it][j] == '#')
            {
              check = false;
              break;
            }
          }
          if (check)
          {
            it   = 0;
            tall = 15000 - i - 1;
          }
        }

        cout << count << " " << pos2 << " " << sum << "\n";
        sum = 0;
      }
      sum += test;
      test = 0;
      pos2 -= 3;
      pos2 -= size[k];
      currX = x[k];
      for (int i = 0; i < currX.size(); i++)
        currX[i] += pos2;
      currY = y[k];
    }
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
      cout << 15000 - i - 1;
  }

  // part 2 calculated on paper will write a program later for my input:
  // (rock number) (position last #)   (sum for every cicle of 36, on example it repeats for cycles of 12)
  // 504           14191               2377
  // 856           13648               1727
  // 2134          11658               6203
  // 3839          9009                8386
  // 5544          6360                8386
  // 7249          3711                8386
  // 8954          1062                8386

  // 9854 - 7249 = 1705 (1705 rocks are processed after one cycle) 
  // 3711 - 1062 = 2649 (the puzzle gets bigger by 2649 after one cycle)
  // 999999991595 / 1705 = 586510259 (number of cycles required)
  // 1000000000000 - 999999991595 = 8405 (inital number of rocks)
  // so now we have everything
  // for 8405 rocks ran the program and got a puzzle of 13065 tall
  // for 586510259 cycles got 586510259 * 2649= 1553665676091
  // result = 1553665676091 + 13065 = 1553665689156
  // we need to substract 1 don't really know why, it happened on example too
  // got +1 over the resulted number
  // so 1553665689156 - 1 = 1553665689155

  in.close();
  out.close();
}
