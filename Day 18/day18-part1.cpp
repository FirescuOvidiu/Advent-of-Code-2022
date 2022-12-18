#include "../../AOCHeaders/stdafx.h"

bool IsAdj(int a, int b, int c, int x, int y, int z)
{
  return abs(a - x) + abs(b - y) + abs(c - z) == 1;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  set<tuple<int, int, int>> xyz;

  int  x = 0, y = 0, z = 0;
  char c{};

  while (in >> x >> c >> y >> c >> z)
    xyz.insert({ x, y, z });

  int surface = 0;
  for (const auto & first : xyz)
  {
    int countAdj = 0;
    for (const auto & second : xyz)
      countAdj += IsAdj(get<0>(first), get<1>(first), get<2>(first), get<0>(second), get<1>(second),
                        get<2>(second));
    surface += 6 - countAdj;
  }

  out << surface;

  in.close();
  out.close();
}
