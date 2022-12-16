#include "../../AOCHeaders/stdafx.h"

int                                minutes = 30;
vector<int>                        maxim;
map<tuple<string, bool, int>, int> visited;

void findMax(unordered_map<string, vector<string>> valves,
             unordered_map<string, int>            rates,
             unordered_map<string, int>            visited,
             int                                   max,
             int                                   minute,
             string                                curr,
             string                                last,
             unordered_map<string, bool>           opened)
{
  if (minute > minutes)
  {
    maxim.push_back(max);
    return;
  }

  if (visited[{ curr, opened[curr], minute }] != -1)
  {
    if ((visited[{ curr, opened[curr], minute }] >= max))
      return;
    visited[{ curr, opened[curr], minute }] =
      std::max(max, visited[{ curr, opened[curr], minute }]);
  }
  else
  {
    visited[{ curr, opened[curr], minute }] =
      std::max(max, visited[{ curr, opened[curr], minute }]);
  }

  for (const auto valve : valves[curr])
  {
    if (valve == last)
      continue;

    if (rates[valve] == 0)
      findMax(valves, rates, visited, max, minute + 1, valve, valve, opened);
    else
    {
      findMax(valves, rates, visited, max, minute + 1, valve, valve, opened);
      if (!opened[valve])
      {
        opened[valve] = true;
        findMax(valves, rates, visited, max + ((minutes - minute - 2) * rates[valve]), minute + 2,
                valve, valve, opened);
        opened[valve] = false;
      }
    }
  }

  maxim.push_back(max);
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<long long> dx{ 0, 1, 0, -1 };
  vector<long long> dy{ -1, 0, 1, 0 };

  vector<vector<char>> m;
  // vector<int>          v;
  string line, aux;
  char   c{};

  unordered_map<string, vector<string>> valves;
  unordered_map<string, int>            rates;
  unordered_map<string, int>            visited;
  unordered_map<string, bool>           opened;
  while (getline(in, line))
  {
    int          n = 0;
    string       abc;
    stringstream ss(line);
    ss >> aux >> abc;
    vector<string> test;
    ss >> aux >> aux >> c >> c >> c >> c >> c >> n >> c;
    rates[abc] = n;
    ss >> aux >> aux >> aux >> aux;
    while (ss >> aux)
    {
      if (aux[aux.size() - 1] == ',')
        aux.erase(aux.size() - 1);
      test.push_back(aux);
    }
    valves[abc]  = test;
    visited[abc] = false;
    opened[abc]  = false;
    for (int i = 0; i < 31; i++)
    {
      visited[{ abc, false, i }] = -1;
      visited[{ abc, true, i }]  = -1;
    }
  }

  visited["AA"]++;
  findMax(valves, rates, visited, 0, 0, "AA", "AA", opened);
  sort(begin(maxim), end(maxim), std::greater<int>());
  for (int i = 0; i < maxim.size(); i++)
  {
    cout << maxim[i] << "\n";
    break;
  }
  in.close();
  out.close();
}
