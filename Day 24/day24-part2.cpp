#include "../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

bool checkInMap2(long long x, long long y, long long lines, long long columns)
{
  return x >= 1 && y >= 1 && x < lines - 1 && y < columns - 1;
}

bool checkInMap3(long long x, long long y, long long lines, long long columns)
{
  if ((x == 0) && (y == 1))
    return true;

  if ((x == lines - 1) && (y == columns - 2))
    return true;

  return x >= 1 && y >= 1 && x < lines - 1 && y < columns - 1;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<long long> dx{ 0, 1, 0, -1 };
  vector<long long> dy{ -1, 0, 1, 0 };

  vector<vector<char>> m;
  string               line, aux;
  char                 c{}, c1{}, c2{}, c3{};

  map<pair<int, int>, vector<char>> t;
  int                               jj = 0;
  while (getline(in, line))
  {
    vector<char> a;
    for (int i = 0; i < line.size(); i++)
    {
      if ((line[i] != '.') && (line[i] != '#'))
      {
        vector<char> c;
        c.push_back(line[i]);
        t[{ jj, i }] = c;
      }
      a.push_back(line[i]);
    }
    m.push_back(a);
    jj++;
  }

  int nnnnnX = m.size(), nnnnnY = m[0].size();

  int startX = 0, startY = 1;

  queue<tuple<int, int, int, map<pair<int, int>, vector<char>>, int>> q1;
  q1.push({ startX, startY, 0, t, 0 });

  set<tuple<int, int, int, int>> visited;
  int                            min = 0;

  while (true)
  {
    auto cur = q1.front();
    q1.pop();

    auto tcur   = get<3>(cur);
    auto count1 = get<4>(cur);

    // if (count1 == 1 && ((get<2>(cur) + get<0>(cur) + abs(get<2>(cur) - 1)) > 50))
    //   continue;
    //
    //  if (count1 == 0 && (get<2>(cur) + std::abs(get<0>(cur) - (int)m.size() - 1) +
    //                     std::abs(get<1>(cur) - (int)m[0].size() - 2)) > 25)
    //   continue;

    if (tcur.find({ get<0>(cur), get<1>(cur) }) != tcur.end())
      continue;

    if (visited.find({ get<0>(cur), get<1>(cur), get<2>(cur), count1 }) != visited.end())
      continue;

    visited.insert({ get<0>(cur), get<1>(cur), get<2>(cur), count1 });

    if (count1 == 0 && get<0>(cur) == m.size() - 1 && get<1>(cur) == m[0].size() - 2)
    {
      count1 = 1;
      cout << get<2>(cur);
      break;
    }

    if (count1 == 1 && get<0>(cur) == 0 && get<1>(cur) == 1)
    {
      count1 = 2;
    }

    if (count1 == 2 && get<0>(cur) == m.size() - 1 && get<1>(cur) == m[0].size() - 2)
    {
      cout << get<2>(cur);
      break;
    }

    map<pair<int, int>, vector<char>> newT;
    for (const auto & gg : tcur)
    {
      for (int ii = 0; ii < gg.second.size(); ii++)
      {
        int x = 0, y = 0, car{};
        if (gg.second[ii] == '>')
        {
          int nX = gg.first.first, nY = gg.first.second + 1;
          if (!checkInMap2(nX, nY, nnnnnX, nnnnnY))
            x = nX, y = 1, car = '>';
          else
            x = nX, y = nY, car = '>';
        }
        else if (gg.second[ii] == '<')
        {
          int nX = gg.first.first, nY = gg.first.second - 1;
          if (!checkInMap2(nX, nY, nnnnnX, nnnnnY))
            x = nX, y = m[nY].size() - 2, car = '<';
          else
            x = nX, y = nY, car = '<';
        }
        else if (gg.second[ii] == 'v')
        {
          int nX = gg.first.first + 1, nY = gg.first.second;
          if (!checkInMap2(nX, nY, nnnnnX, nnnnnY))
            x = 1, y = nY, car = 'v';
          else
            x = nX, y = nY, car = 'v';
        }
        else if (gg.second[ii] == '^')
        {
          int nX = gg.first.first - 1, nY = gg.first.second;
          if (!checkInMap2(nX, nY, nnnnnX, nnnnnY))
            x = m.size() - 2, y = nY, car = '^';
          else
            x = nX, y = nY, car = '^';
        }

        if (newT.find({ x, y }) == newT.end())
        {
          vector<char> ccc;
          ccc.push_back(car);
          newT[{ x, y }] = ccc;
        }
        else
        {
          newT[{ x, y }].push_back(car);
        }
      }
    }

    for (int i = 0; i < 4; i++)
    {
      int newX = get<0>(cur) + dx[i], newY = get<1>(cur) + dy[i];
      if ((checkInMap3(newX, newY, m.size(), m[0].size()) &&
           newT.find({ newX, newY }) == newT.end()) &&
          visited.find({ newX, newY, get<2>(cur) + 1, count1 }) == visited.end())
      {
        q1.push({ newX, newY, get<2>(cur) + 1, newT, count1 });
      }
    }
    if (visited.find({ get<0>(cur), get<1>(cur), get<2>(cur) + 1, count1 }) == visited.end())
      q1.push({ get<0>(cur), get<1>(cur), get<2>(cur) + 1, newT, count1 });
  }

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
    for (int j = 0; j < n; j++)
    {
    }
  }
  */

  in.close();
  out.close();
}
