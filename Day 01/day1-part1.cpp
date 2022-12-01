#include "../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string      currCalories;
  vector<int> elvesCalories;
  int         elfCalories = 0;

  while (getline(in, currCalories))
  {
    if (currCalories == "")
    {
      elvesCalories.push_back(elfCalories);
      elfCalories = 0;
    }
    else
      elfCalories += stoi(currCalories);
  }

  if (elfCalories != 0)
    elvesCalories.push_back(elfCalories);

  out << *max_element(begin(elvesCalories), end(elvesCalories));

  in.close();
  out.close();
}
