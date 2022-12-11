#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string line, aux;
  char   c;

  vector<vector<int>>        items;
  vector<pair<char, string>> op;
  vector<int>                div, T, F;

  while (getline(in, line))
  {
    // Read starting items
    getline(in, line);
    stringstream ssItems(line);

    vector<int> currItems;
    int         item = 0;
    ssItems >> aux >> aux;
    while (ssItems >> item)
    {
      currItems.push_back(item);
      ssItems >> aux;
    }
    items.push_back(currItems);

    // Read operation
    getline(in, line);
    stringstream ssOp(line);
    ssOp >> aux >> aux >> aux >> aux >> c >> aux;
    op.push_back({ c, aux });

    // Read test
    getline(in, line);
    stringstream ssTest(line);
    ssTest >> aux >> aux >> aux >> item;
    div.push_back(item);

    // Read if true
    getline(in, line);
    stringstream ssTestTrue(line);
    ssTestTrue >> aux >> aux >> aux >> aux >> aux >> item;
    T.push_back(item);

    // Read if false
    getline(in, line);
    stringstream ssTestFalse(line);
    ssTestFalse >> aux >> aux >> aux >> aux >> aux >> item;
    F.push_back(item);

    // Ignore empty line
    getline(in, line);
  }

  vector<int> inspected(items.size(), 0);
  int         rounds = 0;
  for (int round = 0; round < 20; round++)
  {
    for (int i = 0; i < items.size(); i++)
    {
      int number = 0;
      for (const auto & item : items[i])
      {
        number = op[i].second == "old" ? item : stoi(op[i].second);

        int newItem = 0;
        newItem     = (op[i].first == '+') ? (item + number) / 3 : (item * number) / 3;

        if (newItem % div[i] == 0)
          items[T[i]].push_back(newItem);
        else
          items[F[i]].push_back(newItem);
      }
      inspected[i] += items[i].size();
      items[i].clear();
    }
  }
  nth_element(begin(inspected), begin(inspected) + 1, end(inspected), greater<int>());
  out << inspected[0] * inspected[1];

  in.close();
  out.close();
}
