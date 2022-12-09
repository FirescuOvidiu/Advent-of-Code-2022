#include "../../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

bool checkEqual(long long & x, long long & y, long long & x2, long long & y2)
{
  if ((x - x2 == 2) && (y - y2 == 1))
  {
    x2++;
    y2++;
    return true;
  }
  else if ((x2 - x == 2) && (y - y2 == 1))
  {
    x2--;
    y2++;
    return true;
  }
  else if ((x2 - x == 2) && (y2 - y == 1))
  {
    x2--;
    y2--;
    return true;
  }
  else if ((x - x2 == 2) && (y2 - y == 1))
  {
    x2++;
    y2--;
    return true;
  }
  else if ((x - x2 == 1) && (y - y2 == 2))
  {
    x2++;
    y2++;
    return true;
  }
  else if ((x2 - x == 1) && (y - y2 == 2))
  {
    x2--;
    y2++;
    return true;
  }
  else if ((x2 - x == 1) && (y2 - y == 2))
  {
    x2--;
    y2--;
    return true;
  }
  else if ((x - x2 == 1) && (y2 - y == 2))
  {
    x2++;
    y2--;
    return true;
  }
  else if (x - x2 == 2)
  {
    x2++;
    return true;
  }
  else if (x2 - x == 2)
  {
    x2--;
    return true;
  }
  else if (y - y2 == 2)
  {
    y2++;
    return true;
  }
  else if (y2 - y == 2)
  {
    y2--;
    return true;
  }
  return false;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<long long> dx{ 0, 1, 0, -1 };
  vector<long long> dy{ -1, 0, 1, 0 };

  vector<vector<char>> m(1000, vector<char>(1000, '.'));
  vector<int>          v;
  string               line, aux;
  char                 c{}, c1{}, c2{}, c3{};
  long long            sum = 0, s1 = 0, s2 = 0, x = 500, y = 500, x2 = 500, y2 = 500, n = 0;
  long long            s = 0;

  m[x][y] = '#';

  while (in >> c >> s)
  {
    if (c == 'R')
    {
      for (int i = 0; i < s; i++)
      {
        y++;
        if (checkEqual(x, y, x2, y2))
          m[x2][y2] = '#';
      }
    }

    if (c == 'L')
    {
      for (int i = 0; i < s; i++)
      {
        y--;
        if (checkEqual(x, y, x2, y2))
          m[x2][y2] = '#';
      }
    }
    if (c == 'U')
    {
      for (int i = 0; i < s; i++)
      {
        x--;
        if (checkEqual(x, y, x2, y2))
          m[x2][y2] = '#';
      }
    }
    if (c == 'D')
    {
      for (int i = 0; i < s; i++)
      {
        x++;
        if (checkEqual(x, y, x2, y2))
          m[x2][y2] = '#';
      }
    }
  }

  for (int i = 0; i < 1000; i++)
  {
    for (int j = 0; j < 1000; j++)
    {
      // cout << m[i][j];
      if (m[i][j] == '#')
        sum++;
    }
    // cout << "\n";
  }
  cout << sum;
  /*
  vector<char> a;
  for (int i = 0; i < line.size(); i++)
    a.push_back(line[i]);
  m.push_back(a);
  */

  /*
  for (int i = 0; i < n; i++)
  {
    for (int i = 0; i < n; i++)
    {
    }
  }
  */
  in.close();
  out.close();
}
