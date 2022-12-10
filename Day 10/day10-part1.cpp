#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<int> v;
  string      line;
  long long   n = 0;

  while (in >> line)
  {
    if (line == "noop")
      v.push_back(0);
    else if (line == "addx")
    {
      in >> n;
      v.push_back(0);
      v.push_back(n);
    }
  }

  int currSum = 1, totalSum = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if ((i == 19) || (i == 59) || (i == 99) || (i == 139) || (i == 179) || (i == 219))
      totalSum += (i + 1) * currSum;

    currSum += v[i];
  }

  out << totalSum;

  in.close();
  out.close();
}
