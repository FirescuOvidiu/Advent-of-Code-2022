#include "../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string currCalories;
  int    totalCalories = 0, elfCalories = 0;

  while (getline(in, currCalories))
  {
    if (currCalories == "")
    {
      totalCalories = std::max(elfCalories, totalCalories);
      elfCalories   = 0;
    }
    else
      elfCalories += stoi(currCalories);
  }

  out << totalCalories;

  in.close();
  out.close();
}
