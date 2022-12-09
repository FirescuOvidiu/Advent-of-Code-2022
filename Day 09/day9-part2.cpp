#include "../../AOCHeaders/stdafx.h"

bool CheckAndMoveTail(int & xH, int & yH, int & xT, int & yT)
{
  if ((xH - xT == 2) && ((yH - yT == 1) || (yH - yT == 2)))
  {
    xT++;
    yT++;
    return true;
  }
  else if ((xT - xH == 2) && ((yH - yT == 1) || (yH - yT == 2)))
  {
    xT--;
    yT++;
    return true;
  }
  else if ((xT - xH == 2) && ((yT - yH == 1) || (yT - yH == 2)))
  {
    xT--;
    yT--;
    return true;
  }
  else if ((xH - xT == 2) && ((yT - yH == 1) || (yT - yH == 2)))
  {
    xT++;
    yT--;
    return true;
  }
  else if (((xH - xT == 1) || (xH - xT == 2)) && (yH - yT == 2))
  {
    xT++;
    yT++;
    return true;
  }
  else if (((xT - xH == 1) || (xT - xH == 2)) && (yH - yT == 2))
  {
    xT--;
    yT++;
    return true;
  }
  else if (((xT - xH == 1) || (xT - xH == 2)) && (yT - yH == 2))
  {
    xT--;
    yT--;
    return true;
  }
  else if (((xH - xT == 1) || (xH - xT == 2)) && (yT - yH == 2))
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

  vector<vector<char>>   m(10000, vector<char>(1000, '.'));
  vector<pair<int, int>> xyT(9, pair<int, int>(500, 500));

  char dir{};
  int  xH = 500, yH = 500, steps = 0;

  m[xH][yH] = '#';

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

      CheckAndMoveTail(xH, yH, xyT[0].first, xyT[0].second);
      for (int j = 1; j < xyT.size(); j++)
      {
        if (j == xyT.size() - 1)
        {
          if (CheckAndMoveTail(xyT[j - 1].first, xyT[j - 1].second, xyT[j].first, xyT[j].second))
            m[xyT[j].first][xyT[j].second] = '#';
        }
        else
          CheckAndMoveTail(xyT[j - 1].first, xyT[j - 1].second, xyT[j].first, xyT[j].second);
      }
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
