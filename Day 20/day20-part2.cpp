#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  list<pair<long long, long long>> v, numbers;

  long long n = 0, id = 0;
  while (in >> n)
  {
    v.push_back({ n * 811589153, id });
    numbers.push_back({ n * 811589153, id });
    id++;
  }

  for (int i = 0; i < 10; i++)
  {
    for (const auto & val : numbers)
    {
      long long finalPos = 0, itCount = 0;
      for (auto it = begin(v); it != end(v); it++, itCount++)
      {
        if (*it == val)
        {
          finalPos = itCount + val.first;
          v.erase(it);
          break;
        }
      }

      finalPos = (finalPos + (long long)(LLONG_MAX / v.size() - 1) * v.size()) % v.size();

      auto itFinalPos = begin(v);
      while (finalPos-- > 0)
        itFinalPos++;

      v.insert(itFinalPos, val);
    }
  }

  int pos1 = 0, pos2 = 0, pos3 = 0, count = 0;
  for (auto it = v.begin(); it != v.end(); it++, count++)
  {
    if ((*it).first == 0)
    {
      pos1 = pos2 = pos3 = count;
      break;
    }
  }

  pos1 = (pos1 + 1000) % v.size();
  pos2 = (pos2 + 2000) % v.size();
  pos3 = (pos3 + 3000) % v.size();

  long long sum = 0;
  count         = 0;
  for (auto it = v.begin(); it != v.end(); it++, count++)
    if (count == pos1 || count == pos2 || count == pos3)
      sum += (*it).first;

  out << sum;

  in.close();
  out.close();
}
