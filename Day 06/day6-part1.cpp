#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string line;

  getline(in, line);

  for (int i = 0; i <= line.size(); i++)
  {
    string curr(line.substr(i, 4));

    sort(begin(curr), end(curr));
    if (adjacent_find(begin(curr), end(curr)) == end(curr))
    {
      out << i + 4;
      break;
    }
  }

  in.close();
  out.close();
}
