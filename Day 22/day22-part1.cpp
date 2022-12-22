#include "../../AOCHeaders/stdafx.h"

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

  // vector<vector<char>> m(1000, vector<char>(1000, '.'));
  vector<vector<char>> m, m2;
  vector<int>          v;
  string               line, aux, code;
  char                 c{}, c1{}, c2{}, c3{};

  int posX = -1, posY = -1;

  char         dir = 'R';
  vector<char> rr{ 'R', 'D', 'L', 'U' };
  int          posRR   = 0;
  int          initial = 0;

  while (getline(in, line))
  {
    stringstream ss(line);
    if (line.empty())
      continue;
    if (line[0] >= '0' && line[0] <= '9')
    {
      code = line;
      continue;
    }
    vector<char> a;
    for (int i = 0; i < line.size(); i++)
    {
      if ((posX == -1 && posY == -1) && (line[i] == '.'))
      {
        posX    = 0;
        posY    = i;
        initial = i;
      }
      a.push_back(line[i]);
    }
    m.push_back(a);
  }
  m2           = m;
  int  start   = 0;
  char lastDir = 'R';
  while (start < code.size())
  {
    string num;
    while ((code[start] >= '0' && code[start] <= '9'))
      num += code[start++];

    int n = stoi(num);
    for (int i = 0; i < n; i++)
    {
      if (dir == 'R')
      {
        posY++;
        if (posY >= m[posX].size() || (m[posX][posY] == ' '))
        {
          int newPosY = 0;

          for (int j = 0; j < m[0].size(); j++)
          {
            if (m[posX][j] == ' ')
              continue;
            newPosY = j;
            break;
          }

          if (m[posX][newPosY] == '.')
            posY = newPosY;
          else if (m[posX][newPosY] == '#')
          {
            posY--;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posY--;
          break;
        }
      }
      else if (dir == 'D')
      {
        posX++;
        if ((posX >= m.size() || posY >= m[posX].size()) || (m[posX][posY] == ' '))
        {
          int newPosX = 0;

          for (int j = 0; j < m[0].size(); j++)
          {
            if (m[j][posY] == ' ')
              continue;
            newPosX = j;
            break;
          }

          if (m[newPosX][posY] == '.')
            posX = newPosX;
          else if (m[newPosX][posY] == '#')
          {
            posX--;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posX--;
          break;
        }
      }
      else if (dir == 'U')
      {
        posX--;
        if (posX < 0 || (m[posX][posY] == ' '))
        {
          int newPosX = 0;

          for (int j = m.size() - 1; j >= 0; j--)
          {
            if (m[j][posY] == ' ')
              continue;
            newPosX = j;
            break;
          }

          if (m[newPosX][posY] == '.')
            posX = newPosX;
          else if (m[newPosX][posY] == '#')
          {
            posX++;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posX++;
          break;
        }
      }
      else if (dir == 'L')
      {
        posY--;
        if (posY < 0 || (m[posX][posY] == ' '))
        {
          int newPosY = 0;

          for (int j = m[0].size() - 1; j >= 0; j--)
          {
            if (m[posX][j] == ' ')
              continue;
            newPosY = j;
            break;
          }

          if (m[posX][newPosY] == '.')
            posY = newPosY;
          else if (m[posX][newPosY] == '#')
          {
            posY++;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posY++;
          break;
        }
      }
      m2[posX][posY] = dir;
    }

    //  for (int i1 = 0; i1 < m.size(); i1++)
    {
      //   for (int i2 = 0; i2 < m[i1].size(); i2++)
      {
        //   cout << m[i1][i2];
      }
      //  cout << "\n";
    }
    lastDir     = dir;
    char rotate = code[start++];
    if (start < code.size())
    {
      if (rotate == 'R')
      {
        posRR++;
      }
      else
      {
        posRR = posRR - 1 + 4;
      }
      dir = rr[posRR % 4];
      std::cout << dir;
    }
  }

  for (int i1 = 0; i1 < m2.size(); i1++)
  {
    for (int i2 = 0; i2 < m2[i1].size(); i2++)
    {
      cout << m2[i1][i2];
    }
    cout << "\n";
  }

  int minus = 0;
  for (int i = 0; i < posY; i++)
  {
    if (m[posX][i] == ' ')
      minus++;
    else
      break;
  }
  cout << endl;
  cout << posX + 1 << " " << posY + 1 << " " << dir << "\n";
  int calc = 0;
  if (dir == 'R')
    calc = 0;
  else if (dir == 'D')
    calc = 1;
  else if (dir == 'L')
    calc = 2;
  else if (dir == 'U')
    calc = 3;
  cout << (posX + 1) * 1000 + 4 * (posY + 1) + calc;

  /*
          while(getline(in,line))
          {
            stringstream ss(line);
          }
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
