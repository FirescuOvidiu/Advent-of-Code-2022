#include "../../AOCHeaders/stdafx.h"

int manhattanDist(int X1, int Y1, int X2, int Y2)
{
  return abs(X2 - X1) + abs(Y2 - Y1);
}

bool IsBetween(int x, int a, int b)
{
  return x >= a && x <= b;
}

vector<pair<int, int>> GetPositions(int x, int y, int d)
{
  vector<pair<int, int>> pos;

  int tempX = x, tempY = y + d;
  while (tempX != x + d && tempY != y)
  {
    tempX++;
    tempY--;
    pos.push_back({ tempX + 1, tempY - 1 });
  }
  tempX = x, tempY = y - d;
  while (tempX != x - d && tempY != y)
  {
    tempX--;
    tempY++;
    pos.push_back({ tempX + 1, tempY - 1 });
  }
  tempX = x - d, tempY = y;
  while (tempX != x && tempY != y + d)
  {
    tempX++;
    tempY++;
    pos.push_back({ tempX + 1, tempY - 1 });
  }
  tempX = x + d, tempY = y;
  while (tempX != x && tempY != y - d)
  {
    tempX--;
    tempY--;
    pos.push_back({ tempX + 1, tempY - 1 });
  }

  return pos;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string                 aux;
  char                   c{};
  vector<pair<int, int>> S, B;
  vector<int>            dist;

  int x = 0, y = 0, x2 = 0, y2 = 0;
  while (in >> aux >> aux >> c >> c >> x >> c >> c >> c >> y >> c >> aux >> aux >> aux >> aux >>
         c >> c >> x2 >> c >> c >> c >> y2)
  {
    swap(x, y), swap(x2, y2);
    S.push_back({ x, y });
    B.push_back({ x2, y2 });
    dist.push_back(abs(x2 - x) + abs(y2 - y));
  }

  for (int i = 0; i < S.size(); i++)
  {
    vector<pair<int, int>> pos = GetPositions(S[i].first, S[i].second, dist[i] + 1);
    for (int j = 0; j < pos.size(); j++)
    {
      int it = 0;
      if (IsBetween(pos[j].first, 0, 4000000) && IsBetween(pos[j].second, 0, 4000000))
      {
        for (it = 0; it < S.size(); it++)
          if (manhattanDist(pos[j].first, pos[j].second, S[it].first, S[it].second) <= dist[it])
            break;
      }

      if (it == S.size())
      {
        cout << pos[j].first + (long long)pos[j].second * 4000000;
        i = S.size();
        break;
      }
    }
  }

  in.close();
  out.close();
}
