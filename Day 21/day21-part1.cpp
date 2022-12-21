#include "../../AOCHeaders/stdafx.h"

long long findRootValue(vector<string>                   m,
                        unordered_map<string, long long> monkeys,
                        unordered_map<string, string>    A,
                        unordered_map<string, string>    B,
                        unordered_map<string, string>    sign,
                        unordered_map<string, bool>      visited)
{
  while (A.size() > 0)
  {
    for (long long i = 0; i < m.size(); i++)
    {
      if (visited[m[i]] == false)
      {
        if ((monkeys.find(A[m[i]]) != monkeys.end()) && (monkeys.find(B[m[i]]) != monkeys.end()))
        {
          if (sign[m[i]] == "+")
          {
            monkeys.insert({ m[i], monkeys[A[m[i]]] + monkeys[B[m[i]]] });
          }
          else if (sign[m[i]] == "-")
          {
            monkeys.insert({ m[i], monkeys[A[m[i]]] - monkeys[B[m[i]]] });
          }
          else if (sign[m[i]] == "*")
          {
            monkeys.insert({ m[i], monkeys[A[m[i]]] * monkeys[B[m[i]]] });
          }
          else if (sign[m[i]] == "/")
          {
            monkeys.insert({ m[i], monkeys[A[m[i]]] / monkeys[B[m[i]]] });
          }
          A.erase(m[i]);
          B.erase(m[i]);
          sign.erase(m[i]);

          visited[m[i]] = true;
        }
      }
    }
  }
  cout << monkeys["root"];
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string    line, aux, a1, b1, sign1;
  long long n = 0;

  vector<string>                   m;
  unordered_map<string, long long> monkeys;
  unordered_map<string, string>    A, B, sign;
  unordered_map<string, bool>      visited;

  while (getline(in, line))
  {
    stringstream ss(line);
    ss >> aux;
    aux.erase(aux.size() - 1);
    m.push_back(aux);

    if (line[6] >= '0' & line[6] <= '9')
    {
      ss >> n;
      monkeys.insert({ aux, n });
      visited.insert({ aux, true });
    }
    else
    {
      ss >> a1 >> sign1 >> b1;
      A.insert({ aux, a1 });
      B.insert({ aux, b1 });
      sign.insert({ aux, sign1 });
      visited.insert({ aux, false });
    }
  }

  findRootValue(m, monkeys, A, B, sign, visited);

  in.close();
  out.close();
}
