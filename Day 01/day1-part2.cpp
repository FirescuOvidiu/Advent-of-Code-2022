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

  nth_element(begin(elvesCalories), begin(elvesCalories) + 2, end(elvesCalories), greater<int>());
  out << elvesCalories[0] + elvesCalories[1] + elvesCalories[2];

  in.close();
  out.close();
}
