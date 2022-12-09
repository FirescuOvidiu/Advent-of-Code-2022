#include "../../AOCHeaders/stdafx.h"

bool CheckAndMoveTail(int & xH, int & yH, int & xT, int & yT)
{
  if ((xH - xT == 2) && (yH - yT == 1))
  {
    xT++;
    yT++;
    return true;
  }
  else if ((xT - xH == 2) && (yH - yT == 1))
  {
    xT--;
    yT++;
    return true;
  }
  else if ((xT - xH == 2) && (yT - yH == 1))
  {
    xT--;
    yT--;
    return true;
  }
  else if ((xH - xT == 2) && (yT - yH == 1))
  {
    xT++;
    yT--;
    return true;
  }
  else if ((xH - xT == 1) && (yH - yT == 2))
  {
    xT++;
    yT++;
    return true;
  }
  else if ((xT - xH == 1) && (yH - yT == 2))
  {
    xT--;
    yT++;
    return true;
  }
  else if ((xT - xH == 1) && (yT - yH == 2))
  {
    xT--;
    yT--;
    return true;
  }
  else if ((xH - xT == 1) && (yT - yH == 2))
  {
    xT++;
    yT--;
    return true;
  }
  else if (xH - xT == 2)
  {
    xT++;
    return true;
  }
  else if (xT - xH == 2)
  {
    xT--;
    return true;
  }
  else if (yH - yT == 2)
  {
    yT++;
    return true;
  }
  else if (yT - yH == 2)
  {
    yT--;
    return true;
  }

  return false;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<vector<char>> m(1000, vector<char>(1000, '.'));

  char dir{};
  int  xH = 500, yH = 500, xT = 500, yT = 500, steps = 0;

  m[xT][yT] = '#';
  while (in >> dir >> steps)
  {
    for (int i = 0; i < steps; i++)
    {
      if (dir == 'R')
        yH++;
      if (dir == 'L')
        yH--;
      if (dir == 'U')
        xH--;
      if (dir == 'D')
        xH++;
      if (CheckAndMoveTail(xH, yH, xT, yT))
        m[xT][yT] = '#';
    }
  }

  int visits = 0;

  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
      if (m[i][j] == '#')
        visits++;

  out << visits;

  in.close();
  out.close();
}
