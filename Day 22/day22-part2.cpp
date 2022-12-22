#include "../../AOCHeaders/stdafx.h"
#include <assert.h>

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

class Region
{
public:
  Region(int a, int b, int c, int d, char t)
    : startX(a)
    , startY(b)
    , endX(c)
    , endY(d)
    , no(t)
  {
  }

  //   Region a(0, 50, 50, 100, 'A');
  // Region b(0, 100, 50, 150, 'B');
  // Region c(50, 50, 100, 100, 'C');
  // Region d(100, 0, 150, 50, 'D');
  // Region e(100, 50, 150, 100, 'E');
  // Region f(150, 0, 200, 50, 'F');
  tuple<int, int, char> findNextPos(int x, int y, char dir, char no)
  {
    if (no == 'A')
    {
      if (dir == 'D')
      {
        assert(x == 49);
        assert(y >= 50 && y < 100);
        return { x + 1, y, 'D' };
      }
      else if (dir == 'R')
      {
        assert(y == 99);
        assert(x >= 0 && x < 50);
        return { x, y + 1, 'R' };
      }
      else if (dir == 'U')
      {
        assert(x == 0);
        assert(y >= 50 && y < 100);
        return { 100 + y, 0, 'R' };
      }
      else if (dir == 'L')
      {
        assert(y == 50);
        assert(x >= 0 && x < 50);
        return { 149 - x, 0, 'R' };
      }
    }
    if (no == 'B')
    {
      if (dir == 'D')
      {
        assert(x == 49);
        assert(y >= 100 && y < 150);
        return { y - 50, 99, 'L' };
      }
      else if (dir == 'R')
      {
        assert(y == 149);
        assert(x >= 0 && x < 50);
        return { 149 - x, 99, 'L' };
      }
      else if (dir == 'U')
      {
        assert(x == 0);
        assert(y >= 100 && y < 150);
        return { 199, y - 100, 'U' };
      }
      else if (dir == 'L')
      {
        assert(y == 100);
        assert(x >= 0 && x < 50);
        return { x, y - 1, 'L' };
      }
    }
    if (no == 'C')
    {
      if (dir == 'D')
      {
        assert(x == 99);
        assert(y >= 50 && y < 100);
        return { x + 1, y, 'D' };
      }
      else if (dir == 'R')
      {
        assert(y == 99);
        assert(x >= 50 && x < 100);
        return { 49, x + 50, 'U' };
      }
      else if (dir == 'U')
      {
        assert(x == 50);
        assert(y >= 50 && y < 100);
        return { x - 1, y, 'U' };
      }
      else if (dir == 'L')
      {
        assert(y == 50);
        assert(x >= 50 && x < 100);
        return { 100, x - 50, 'D' };
      }
    }
    if (no == 'D')
    {
      if (dir == 'D')
      {
        assert(x == 149);
        assert(y >= 0 && y < 50);
        return { x + 1, y, 'D' };
      }
      else if (dir == 'R')
      {
        assert(y == 49);
        assert(x >= 100 && x < 150);
        return { x, y + 1, 'R' };
      }
      else if (dir == 'U')
      {
        assert(x == 100);
        assert(y >= 0 && y < 50);
        return { y + 50, 50, 'R' };
      }
      else if (dir == 'L')
      {
        assert(y == 0);
        assert(x >= 100 && x < 150);
        return { 149 - x, 50, 'R' };
      }
    }
    if (no == 'E')
    {
      if (dir == 'D')
      {
        assert(x == 149);
        assert(y >= 50 && y < 100);
        return { y + 100, 49, 'L' };
      }
      else if (dir == 'R')
      {
        assert(y == 99);
        assert(x >= 100 && x < 150);
        return { 149 - x, 149, 'L' };
      }
      else if (dir == 'U')
      {
        assert(x == 100);
        assert(y >= 50 && y < 100);
        return { x - 1, y, 'U' };
      }
      else if (dir == 'L')
      {
        assert(y == 50);
        assert(x >= 100 && x < 150);
        return { x, y - 1, 'L' };
      }
    }
    if (no == 'F')
    {
      if (dir == 'D')
      {
        assert(x == 199);
        assert(y >= 0 && y < 50);
        return { 0, y + 100, 'D' };
      }
      else if (dir == 'R')
      {
        assert(y == 49);
        assert(x >= 150 && x < 200);
        return { 149, x - 100, 'U' };
      }
      else if (dir == 'U')
      {
        assert(x == 150);
        assert(y >= 0 && y < 50);
        return { x - 1, y, 'U' };
      }
      else if (dir == 'L')
      {
        assert(y == 0);
        assert(x >= 150 && x < 200);
        return { 0, x - 100, 'D' };
      }
    }
    cout << "BIG";
  }
  int  startX, startY, endX, endY;
  char no;
};

bool check(int iA, int iB, int x, int y, int d, Region curr)
{
  char no{};

  if ((x >= 0 && x < 50) && (y >= 50 && y < 100))
    no = 'A';
  else if ((x >= 0 && x < 50) && (y >= 100 && y < 150))
    no = 'B';
  else if ((x >= 50 && x < 100) && (y >= 50 && y < 100))
    no = 'C';
  else if ((x >= 100 && x < 150) && (y >= 0 && y < 50))
    no = 'D';
  else if ((x >= 100 && x < 150) && (y >= 50 && y < 100))
    no = 'E';
  else if ((x >= 150 && x < 200) && (y >= 0 && y < 50))
    no = 'F';

  char dir{};

  if (d == 'D')
    dir = 'U';
  else if (d == 'U')
    dir = 'D';
  else if (d == 'L')
    dir = 'R';
  else if (d == 'R')
    dir = 'L';

  auto test = curr.findNextPos(x, y, dir, no);

  if (iA != get<0>(test) || iB != get<1>(test))
    return false;
  else
    return true;
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
  m2        = m;
  int start = 0;

  Region curr(posX, posY, 0, 0, 'A');
  while (start < code.size())
  {
    string num;
    while ((code[start] >= '0' && code[start] <= '9'))
      num += code[start++];
    int n = stoi(num);

    for (int i = 0; i < n; i++)
    {
      int  x = posX, y = posY;
      char no{};
      if ((x >= 0 && x < 50) && (y >= 50 && y < 100))
        no = 'A';
      else if ((x >= 0 && x < 50) && (y >= 100 && y < 150))
        no = 'B';
      else if ((x >= 50 && x < 100) && (y >= 50 && y < 100))
        no = 'C';
      else if ((x >= 100 && x < 150) && (y >= 0 && y < 50))
        no = 'D';
      else if ((x >= 100 && x < 150) && (y >= 50 && y < 100))
        no = 'E';
      else if ((x >= 150 && x < 200) && (y >= 0 && y < 50))
        no = 'F';
      else
        cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";

      if (dir == 'R')
      {
        int savePos = posY;
        posY++;
        if (posY >= m[posX].size() || (m[posX][posY] == ' '))
        {
          posY--;
          auto newPos = curr.findNextPos(posX, posY, 'R', no);
          if (!check(posX, posY, get<0>(newPos), get<1>(newPos), get<2>(newPos), curr))
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";

          if (m[get<0>(newPos)][get<1>(newPos)] == ' ')
          {
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '.')
          {
            posX = get<0>(newPos);
            posY = get<1>(newPos);
            dir  = get<2>(newPos);
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '#')
          {
            posY = savePos;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posY = savePos;
          break;
        }
      }
      else if (dir == 'D')
      {
        int savePos = posX;
        posX++;
        if ((posX >= m.size()) || (posY >= m[posX].size()) || (m[posX][posY] == ' '))
        {
          posX--;
          auto newPos = curr.findNextPos(posX, posY, 'D', no);

          if (!check(posX, posY, get<0>(newPos), get<1>(newPos), get<2>(newPos), curr))
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";

          if (m[get<0>(newPos)][get<1>(newPos)] == ' ')
          {
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '.')
          {
            posX = get<0>(newPos);
            posY = get<1>(newPos);
            dir  = get<2>(newPos);
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '#')
          {
            posX = savePos;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posX = savePos;
          break;
        }
      }
      else if (dir == 'U')
      {
        int savePos = posX;
        posX--;
        if (posX < 0 || (m[posX][posY] == ' '))
        {
          posX++;
          auto newPos = curr.findNextPos(posX, posY, 'U', no);

          if (!check(posX, posY, get<0>(newPos), get<1>(newPos), get<2>(newPos), curr))
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";

          if (m[get<0>(newPos)][get<1>(newPos)] == ' ')
          {
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '.')
          {
            posX = get<0>(newPos);
            posY = get<1>(newPos);
            dir  = get<2>(newPos);
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '#')
          {
            posX = savePos;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posX = savePos;
          break;
        }
      }
      else if (dir == 'L')
      {
        int savePos = posY;
        posY--;
        if (posY < 0 || (m[posX][posY] == ' '))
        {
          posY++;
          auto newPos = curr.findNextPos(posX, posY, 'L', no);

          if (!check(posX, posY, get<0>(newPos), get<1>(newPos), get<2>(newPos), curr))
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";

          if (m[get<0>(newPos)][get<1>(newPos)] == ' ')
          {
            cout << "BGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGUG";
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '.')
          {
            posX = get<0>(newPos);
            posY = get<1>(newPos);
            dir  = get<2>(newPos);
          }
          else if (m[get<0>(newPos)][get<1>(newPos)] == '#')
          {
            posY = savePos;
            break;
          }
        }
        else if (m[posX][posY] == '#')
        {
          posY = savePos;
          break;
        }
      }
      m2[posX][posY] = dir;
    }
    // cout << "\n";
    // for (int i1 = 0; i1 < m.size(); i1++)
    {
      //  for (int i2 = 0; i2 < m[i1].size(); i2++)
      {
        //    cout << m2[i1][i2];
      }
      //  cout << "\n";
    }
    //   vector<char> rr{ 'R', 'D', 'L', 'U' };
    if (dir == 'R')
      posRR = 0;
    else if (dir == 'D')
      posRR = 1;
    else if (dir == 'L')
      posRR = 2;
    else if (dir == 'U')
      posRR = 3;
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
  cout << "\n";
  for (int i1 = 0; i1 < m2.size(); i1++)
  {
    for (int i2 = 0; i2 < m2[i1].size(); i2++)
    {
      cout << m2[i1][i2];
    }
    cout << "\n";
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
