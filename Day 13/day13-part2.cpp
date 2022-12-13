#include "../../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int findSteps(const vector<string> & m, int startX, int startY)
{
  vector<long long> dx{ 0, 1, 0, -1 };
  vector<long long> dy{ -1, 0, 1, 0 };

  queue<pair<int, int>> q;
  vector<vector<bool>>  v(m.size(), vector<bool>(m[0].size(), false));

  v[startX][startY] = true;
  q.push({ startX, startY });

  int steps = 0, sizeQ = q.size();
  while (!q.empty())
  {
    sizeQ = q.size();
    for (int i = 0; i < sizeQ; i++)
    {
      int currX = q.front().first, currY = q.front().second;
      q.pop();

      if (m[currX][currY] == 'a')
        return steps;

      for (int k = 0; k < 4; k++)
      {
        int newX = currX + dx[k], newY = currY + dy[k];
        if (checkInMap(newX, newY, m.size(), m[0].size()) &&
            (m[currX][currY] - m[newX][newY] <= 1) && v[newX][newY] == false)
        {
          q.push({ newX, newY });
          v[newX][newY] = true;
        }
      }
    }
    steps++;
  }
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<string> m;
  string         line;

  while (getline(in, line))
    m.push_back(line);

  int startX = 0, startY = 0;

  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < m[i].size(); j++)
    {
      if (m[i][j] == 'S')
        m[i][j] = 'a';
      if (m[i][j] == 'E')
      {
        startX  = i;
        startY  = j;
        m[i][j] = 'z';
      }
    }
  }

  out << findSteps(m, startX, startY);

  in.close();
  out.close();
}
