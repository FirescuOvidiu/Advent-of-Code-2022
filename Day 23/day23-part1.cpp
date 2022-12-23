#include "../../AOCHeaders/stdafx.h"
#include <assert.h>

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<long long> dx{ 0, 1, 0, -1 };
  vector<long long> dy{ -1, 0, 1, 0 };

  vector<vector<char>> m(1000, vector<char>(1000, '.'));
  vector<vector<char>> m1;
  vector<int>          v;
  string               line, aux;
  char                 c{}, c1{}, c2{}, c3{};

  while (getline(in, line))
  {
    vector<char> a;
    for (int i = 0; i < line.size(); i++)
      a.push_back(line[i]);
    m1.push_back(a);
  }

  map<pair<int, int>, char> pos;

  for (int i = 0; i < m1.size(); i++)
  {
    for (int j = 0; j < m1[i].size(); j++)
    {
      m[i + 500][j + 500] = m1[i][j];
      if (m1[i][j] == '#')
      {
        pair<int, int> a{ i + 500, j + 500 };
        pos[a] = 'N';
      }
    }
  }
  vector<char> dir{ 'N', 'S', 'W', 'E' };
  int          rounds   = 0;
  int          dddd     = 0;
  char         currdddd = 'N';
  while (rounds < 10)
  {
    map<pair<int, int>, char>           newPos;
    map<pair<int, int>, pair<int, int>> consid;
    vector<pair<int, int>>              elves;
    vector<vector<int>>                 cc(1000, vector<int>(1000, 0));

    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < m[i].size(); j++)
      {
        if (m[i][j] == '#')
        {
          elves.push_back({ i, j });
          if (m[i - 1][j - 1] == '.' && m[i - 1][j] == '.' && m[i - 1][j + 1] == '.' &&
              (m[i + 1][j - 1] == '.' && m[i + 1][j] == '.' && m[i + 1][j + 1] == '.') &&
              m[i][j - 1] == '.' && m[i][j + 1] == '.')
            continue;

          auto currDir = pos[{ i, j }];
          int  found   = 0;
          for (int k = 0; k < dir.size(); k++)
            if (dir[k] == currDir)
            {
              found = k;
              break;
            }

          for (int k1 = found; k1 < found + 4; k1++)
          {
            char cDir = dir[k1 % 4];

            if (cDir == 'N')
            {
              if (m[i - 1][j - 1] == '.' && m[i - 1][j] == '.' && m[i - 1][j + 1] == '.')
              {
                cc[i - 1][j]++;
                consid[{ i, j }] = { i - 1, j };
                break;
              }
            }
            else if (cDir == 'S')
            {
              if (m[i + 1][j - 1] == '.' && m[i + 1][j] == '.' && m[i + 1][j + 1] == '.')
              {
                cc[i + 1][j]++;
                consid[{ i, j }] = { i + 1, j };
                break;
              }
            }
            else if (cDir == 'W')
            {
              if (m[i - 1][j - 1] == '.' && m[i][j - 1] == '.' && m[i + 1][j - 1] == '.')
              {
                cc[i][j - 1]++;
                consid[{ i, j }] = { i, j - 1 };
                break;
              }
            }
            else if (cDir == 'E')
            {
              if (m[i - 1][j + 1] == '.' && m[i][j + 1] == '.' && m[i + 1][j + 1] == '.')
              {
                cc[i][j + 1]++;
                consid[{ i, j }] = { i, j + 1 };
                break;
              }
            }
          }
        }
      }
    }
    dddd++;
    currdddd = dir[dddd % 4];
    map<pair<int, int>, char> newPositions;
    vector<pair<int, int>>    moved;
    for (const auto & elf : elves)
    {
      auto considerat = consid[{ elf.first, elf.second }];
      if (cc[considerat.first][considerat.second] == 1)
      {
        newPositions[considerat] = currdddd;
        moved.push_back(considerat);
      }
      else
      {
        newPositions[elf] = currdddd;
        moved.push_back(elf);
      }
    }

    pos = newPositions;

    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < m[i].size(); j++)
      {
        m[i][j]  = '.';
        cc[i][j] = 0;
      }
    }

    for (const auto & move : moved)
    {
      m[move.first][move.second] = '#';
    }
    // for (int i = 0; i < 20; i++)
    {
      //   for (int j = 0; j < 20; j++)
      {
        //  cout << m[i][j];
      }
      //  cout << endl;
    }
    //  cout << endl;
    rounds++;
  }

  int minX = 10000, minY = 100000, maxX = 0, maxY = 0;
  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < m[i].size(); j++)
    {
      if (m[i][j] == '#')
      {
        if (minX > i)
          minX = i;
        if (maxX < i)
          maxX = i;
        if (minY > j)
          minY = j;
        if (maxY < j)
          maxY = j;
      }
    }
  }

  int coun = 0;
  for (int i = minX; i <= maxX; i++)
  {
    for (int j = minY; j <= maxY; j++)
    {
      if (m[i][j] == '.')
        coun++;
    }
  }
  cout << coun;
  in.close();
  out.close();
}
