#include "../../AOCHeaders/stdafx.h"

long long GCD(long long a, long long b)
{
  if (b == 0)
    return a;
  return GCD(b, a % b);
}

// Returns LCM of array elements
long long FindLCM(const vector<long long> & div)
{
  // Initialize result
  long long ans = div[0];

  // ans contains LCM of div[0], ..div[i]
  // after i'th iteration
  for (const auto & num : div)
    ans = (num * ans) / (GCD(num, ans));

  return ans;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string line, aux;
  char   c;

  vector<vector<long long>>  items;
  vector<pair<char, string>> op;
  vector<long long>          div, T, F;

  while (getline(in, line))
  {
    // Read starting items
    getline(in, line);
    stringstream ssItems(line);

    vector<long long> currItems;
    long long         item = 0;
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

  vector<long long> inspected(items.size(), 0);
  int               lcm = FindLCM(div);
  for (int round = 0; round < 10000; round++)
  {
    for (int i = 0; i < items.size(); i++)
    {
      int number = 0;
      for (const auto & item : items[i])
      {
        number = op[i].second == "old" ? item : stoi(op[i].second);

        long long newItem = 0;
        newItem           = (op[i].first == '+') ? (item + number) % lcm : (item * number) % lcm;

        if (newItem % div[i] == 0)
          items[T[i]].push_back(newItem);
        else
          items[F[i]].push_back(newItem);
      }
      inspected[i] += items[i].size();
      items[i].clear();
    }
  }
  nth_element(begin(inspected), begin(inspected) + 1, end(inspected), greater<long long>());
  out << inspected[0] * inspected[1];

  in.close();
  out.close();
}
