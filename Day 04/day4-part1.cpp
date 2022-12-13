#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  int  x = 0, y = 0, x2 = 0, y2 = 0, count = 0;
  char c{};

  while (in >> x >> c >> y >> c >> x2 >> c >> y2)
    if ((x >= x2 && y <= y2) || (x <= x2 && y >= y2))
      count++;

  out << count;

  in.close();
  out.close();
}
