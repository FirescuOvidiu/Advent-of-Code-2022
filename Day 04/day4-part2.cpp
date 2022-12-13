#include "../../AOCHeaders/stdafx.h"

bool IsBetween(int p, int x, int y)
{
  return (p >= x && p <= y);
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  int  x = 0, y = 0, x2 = 0, y2 = 0, count = 0;
  char c{};

  while (in >> x >> c >> y >> c >> x2 >> c >> y2)
    if (IsBetween(x, x2, y2) || IsBetween(y, x2, y2) || IsBetween(x2, x, y) || IsBetween(y2, x, y))
      count++;

  out << count;

  in.close();
  out.close();
}
