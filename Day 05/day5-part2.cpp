#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<string> lines;
  string         line, aux;
  int            findPosStart = 0;

  while (getline(in, line))
    lines.push_back(line);

  while (lines[findPosStart][1] < '0' || lines[findPosStart][1] > '9')
    findPosStart++;

  vector<stack<char>> v((lines[findPosStart - 1].size() + 1) / 4);

  // read input
  for (int i = findPosStart - 1; i >= 0; i--)
    for (int j = 1, it = 0; j < lines[i].size(); j += 4, it++)
      if (lines[i][j] != ' ')
        v[it].push(lines[i][j]);

  // solve problem
  int quant = 0, from = 0, to = 0;
  for (int i = findPosStart + 1; i < lines.size(); i++)
  {
    stringstream ss(lines[i]);
    ss >> aux >> quant >> aux >> from >> aux >> to;

    stack<char> temp;
    while (quant--)
    {
      temp.push(v[from - 1].top());
      v[from - 1].pop();
    }
    while (!temp.empty())
    {
      v[to - 1].push(temp.top());
      temp.pop();
    }
  }

  for (const auto & crate : v)
    out << crate.top();

  in.close();
  out.close();
}
