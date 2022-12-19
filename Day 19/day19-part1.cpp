#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<int>            oreCost, clayCost;
  vector<pair<int, int>> obsCost, getCost;

  string aux;
  int    n = 1, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;
  while (in >> aux >> aux >> aux >> aux >> aux >> aux >> n >> aux >> aux >> aux >> aux >> aux >>
         n2 >> aux >> aux >> aux >> aux >> aux >> n3 >> aux >> aux >> n4 >> aux >> aux >> aux >>
         aux >> aux >> n5 >> aux >> aux >> n6 >> aux)
  {
    oreCost.push_back(n);
    clayCost.push_back(n2);
    obsCost.push_back({ n3, n4 });
    getCost.push_back({ n5, n6 });
  }

  int sum = 0;
  for (int i = 0; i < oreCost.size(); i++)
  {
    int nOre = 1, nClay = 0, nObs = 0, nGeo = 0;
    int cOre = 0, cClay = 0, cObs = 0, cGeo = 0;
    int minute = 1, maxGeo = 0;

    int            ore = oreCost[i], clay = clayCost[i];
    pair<int, int> obs = obsCost[i], geo = getCost[i];

    queue<tuple<int, int, int, int, int, int, int, int, int>> q;
    set<tuple<int, int, int, int, int, int, int, int, int>>   visited;

    q.push({ 1, 0, 0, 0, 0, 0, 0, 0, 1 });

    while (!q.empty())
    {
      auto curr = q.front();
      q.pop();

      if (visited.find(curr) != visited.end())
        continue;

      visited.insert(curr);

      nOre   = get<0>(curr);
      nClay  = get<1>(curr);
      nObs   = get<2>(curr);
      nGeo   = get<3>(curr);
      cOre   = get<4>(curr);
      cClay  = get<5>(curr);
      cObs   = get<6>(curr);
      cGeo   = get<7>(curr);
      minute = get<8>(curr);

      if (minute > 24)
      {
        if (cGeo > maxGeo)
          maxGeo = cGeo;
        continue;
      }

      if (cOre >= geo.first && cObs >= geo.second)
      {
        q.push({ nOre, nClay, nObs, nGeo + 1, cOre + nOre - geo.first, cClay + nClay,
                 cObs + nObs - geo.second, cGeo + nGeo, minute + 1 });
      }

      if (cOre >= obs.first && cClay >= obs.second)
      {
        if (nObs >= geo.second)
          continue;

        q.push({ nOre, nClay, nObs + 1, nGeo, cOre + nOre - obs.first, cClay + nClay - obs.second,
                 cObs + nObs, cGeo + nGeo, minute + 1 });
      }
      if (cOre >= clay)
      {
        if (nClay >= max(obs.second, geo.second))
          continue;

        q.push({ nOre, nClay + 1, nObs, nGeo, cOre + nOre - clay, cClay + nClay, cObs + nObs,
                 cGeo + nGeo, minute + 1 });
      }

      if (cOre >= ore)
      {
        if (nOre >= max(max(max(ore, clay), obs.first), geo.first))
          continue;

        q.push({ nOre + 1, nClay, nObs, nGeo, cOre + nOre - ore, cClay + nClay, cObs + nObs,
                 cGeo + nGeo, minute + 1 });
      }

      q.push({ nOre, nClay, nObs, nGeo, cOre + nOre, cClay + nClay, cObs + nObs, cGeo + nGeo,
               minute + 1 });
    }
    sum += maxGeo * (i + 1);
  }
  out << sum;

  in.close();
  out.close();
}
