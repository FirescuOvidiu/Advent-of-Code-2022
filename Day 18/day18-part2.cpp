#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<int> dx{ 0, 0, 0, 0, 1, -1 };
  vector<int> dy{ 0, 0, 1, -1, 0, 0 };
  vector<int> dz{ -1, 1, 0, 0, 0, 0 };

  set<tuple<int, int, int>> xyz, goodCoord;

  int  x = 0, y = 0, z = 0;
  char c{};
  while (in >> x >> c >> y >> c >> z)
    xyz.insert({ x, y, z });

  int total = 0;
  for (const auto & coord : xyz)
  {
    for (int i = 0; i < dx.size(); i++)
    {
      if (goodCoord.find({ get<0>(coord) + dx[i], get<1>(coord) + dy[i], get<2>(coord) + dz[i] }) !=
          end(goodCoord))
      {
        total++;
        continue;
      }

      set<tuple<int, int, int>>   visited;
      queue<tuple<int, int, int>> q;

      q.push({ get<0>(coord) + dx[i], get<1>(coord) + dy[i], get<2>(coord) + dz[i] });

      int surface = 0;
      while (!q.empty())
      {
        auto curr = q.front();
        q.pop();

        if (xyz.find(curr) != end(xyz))
          continue;

        if (visited.find(curr) != end(visited))
          continue;

        visited.insert(curr);

        if (surface++ > 10000)
        {
          for (const auto & currCoord : visited)
            goodCoord.insert(currCoord);
          total++;
          break;
        }

        for (int i = 0; i < dx.size(); i++)
          q.push({ get<0>(curr) + dx[i], get<1>(curr) + dy[i], get<2>(curr) + dz[i] });
      }
    }
  }

  out << total;

  in.close();
  out.close();
}
