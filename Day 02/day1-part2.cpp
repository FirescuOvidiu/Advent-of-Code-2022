#include "../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  char      c{}, c1{};
  long long sum = 0;

  while (in >> c >> c1)
  {
    if (c == 'A')
    {
      if (c1 == 'X')
      {
        sum += 0 + 3;
      }
      if (c1 == 'Y')
      {
        sum += 3 + 1;
      }
      if (c1 == 'Z')
      {
        sum += 6 + 2;
      }
    }
    if (c == 'B')
    {
      if (c1 == 'X')
      {
        sum += 0 + 1;
      }
      if (c1 == 'Y')
      {
        sum += 3 + 2;
      }
      if (c1 == 'Z')
      {
        sum += 6 + 3;
      }
    }
    if (c == 'C')
    {
      if (c1 == 'X')
      {
        sum += 0 + 2;
      }
      if (c1 == 'Y')
      {
        sum += 3 + 3;
      }
      if (c1 == 'Z')
      {
        sum += 6 + 1;
      }
    }
  }

  out << sum;

  in.close();
  out.close();
}
