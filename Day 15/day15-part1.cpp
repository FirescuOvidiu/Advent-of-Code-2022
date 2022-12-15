#include "../../AOCHeaders/stdafx.h"

int manhattanDist(int X1, int Y1, int X2, int Y2)
{
  return abs(X2 - X1) + abs(Y2 - Y1);
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

  set<pair<int, int>> s;

  int currX = 10;
  for (int it = 0; it < S.size(); it++)
  {
    for (int i = -1; i <= 1; i++)
    {
      int currDist = abs(S[it].first - currX);
      int currY    = S[it].second;

      while (currDist <= dist[it])
      {
        if (find(begin(B), end(B), pair<int, int>(currX, currY)) == end(B))
          s.insert({ currX, currY });
        currY += i;
        currDist++;
      }
    }
  }

  out << s.size();

  in.close();
  out.close();
}
