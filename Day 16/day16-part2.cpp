#include "../../AOCHeaders/stdafx.h"

int                                       minutes = 26;
map<tuple<string, string, int, int>, int> visited;
int                                       totalMax = 0;

void findMax(unordered_map<string, vector<string>> valves,
             unordered_map<string, int>            ratesMe,
             unordered_map<string, int>            ratesEle,
             int                                   max,
             int                                   minute,
             string                                currMe,
             string                                currEle,
             bool                                  movedEle,
             bool                                  movedMe,
             unordered_map<string, bool>           opened,
             int                                   count,
             int                                   flow)
{
  if (minute >= minutes)
  {
    return;
  }

  if (max > totalMax)
  {
    totalMax = max;
    cout << totalMax << "\n";
  }

  if (count == opened.size())
    return;

  if (!movedMe)
    if ((!opened[currMe]))
    {
      if (movedEle)
      {
        opened[currMe] = true;
        findMax(valves, ratesMe, ratesEle, max + ((minutes - minute) * ratesMe[currMe]), minute + 1,
                currMe, currEle, false, false, opened, count + 1, flow + ratesMe[currMe]);
        opened[currMe] = false;
      }
      else
      {
        opened[currMe] = true;
        findMax(valves, ratesMe, ratesEle, max + ((minutes - minute) * ratesMe[currMe]), minute,
                currMe, currEle, false, true, opened, count + 1, flow + ratesMe[currMe]);
        opened[currMe] = false;
      }
    }

  if (!movedEle)
    if ((!opened[currEle]))
    {
      if (movedMe)
      {
        opened[currEle] = true;
        findMax(valves, ratesMe, ratesEle, max + ((minutes - minute) * ratesEle[currEle]),
                minute + 1, currMe, currEle, false, false, opened, count + 1,
                flow + ratesMe[currMe]);
        opened[currEle] = false;
      }
      else
      {
        opened[currEle] = true;
        findMax(valves, ratesMe, ratesEle, max + ((minutes - minute) * ratesEle[currEle]), minute,
                currMe, currEle, true, false, opened, count + 1, flow + ratesMe[currMe]);
        opened[currEle] = false;
      }
      movedEle = true;
    }

  if (visited.find({ currMe, currEle, flow, minute }) != end(visited))
  {
    if ((visited[{ currMe, currEle, flow, minute }] >= max))
      return;
    visited[{ currMe, currEle, flow, minute }] =
      std::max(max, visited[{ currMe, currEle, flow, minute }]);
  }
  else
  {
    visited[{ currMe, currEle, flow, minute }] = max;
  }

  if (!movedMe)
    for (const auto & valve : valves[currMe])
    {
      if (movedEle)
        findMax(valves, ratesMe, ratesEle, max, minute + 1, valve, currEle, false, false, opened,
                count, flow);
      else
        findMax(valves, ratesMe, ratesEle, max, minute, valve, currEle, false, true, opened, count,
                flow);
    }

  if (!movedEle)
  {
    for (const auto & valve2 : valves[currEle])
    {
      if (movedMe)
        findMax(valves, ratesMe, ratesEle, max, minute + 1, currMe, valve2, false, false, opened,
                count, flow);
      else
        findMax(valves, ratesMe, ratesEle, max, minute, currMe, valve2, true, false, opened, count,
                flow);
    }
  }
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string line, aux;
  char   c{};

  unordered_map<string, vector<string>> valves;
  unordered_map<string, int>            rates;
  unordered_map<string, bool>           opened;
  int                                   count = 0;

  while (getline(in, line))
  {
    int          n = 0;
    string       curr;
    stringstream ss(line);
    ss >> aux >> curr;
    vector<string> test;
    ss >> aux >> aux >> c >> c >> c >> c >> c >> n >> c;
    rates[curr] = n;
    ss >> aux >> aux >> aux >> aux;
    while (ss >> aux)
    {
      if (aux[aux.size() - 1] == ',')
        aux.erase(aux.size() - 1);
      test.push_back(aux);
    }
    valves[curr] = test;
    opened[curr] = rates[curr] == 0 ? true : false;
    count += rates[curr] == 0;
  }

  findMax(valves, rates, rates, 0, 1, "AA", "AA", false, false, opened, count, 0);

  in.close();
  out.close();
}
