#include "../../AOCHeaders/stdafx.h"

void findRootEquation(unordered_map<string, string>                        solvedEq,
                      unordered_map<string, tuple<string, string, string>> unsolvedEq,
                      unordered_map<string, bool>                          visited,
                      fstream &                                            out)
{
  bool anyEqUnsolved = true;

  while (anyEqUnsolved)
  {
    anyEqUnsolved = false;
    for (const auto & eq : unsolvedEq)
    {
      if (visited[eq.first] == true)
        continue;

      string A    = get<0>(eq.second);
      string B    = get<1>(eq.second);
      string sign = get<2>(eq.second);

      if ((solvedEq.find(A) != end(solvedEq)) && (solvedEq.find(B) != end(solvedEq)))
      {
        if (eq.first == "root")
          solvedEq.insert({ eq.first, "(" + solvedEq[A] + "=" + solvedEq[B] + ")" });
        else if (sign == "+")
          solvedEq.insert({ eq.first, "(" + solvedEq[A] + "+" + solvedEq[B] + ")" });
        else if (sign == "-")
          solvedEq.insert({ eq.first, "(" + solvedEq[A] + "-" + solvedEq[B] + ")" });
        else if (sign == "*")
          solvedEq.insert({ eq.first, "(" + solvedEq[A] + "*" + solvedEq[B] + ")" });
        else if (sign == "/")
          solvedEq.insert({ eq.first, "(" + solvedEq[A] + "/" + solvedEq[B] + ")" });

        visited[eq.first] = true;
        anyEqUnsolved     = true;
      }
    }
  }

  out << solvedEq["root"];
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string    line, aux, a, b, sign;
  long long n = 0;

  unordered_map<string, string> solvedEq;
  unordered_map<string, bool>   visited;

  unordered_map<string, tuple<string, string, string>> unsolvedEq;

  while (getline(in, line))
  {
    stringstream ss(line);
    ss >> aux;
    aux.erase(aux.size() - 1);

    bool isEqSolved = line[6] >= '0' & line[6] <= '9';

    if (isEqSolved)
    {
      ss >> n;
      solvedEq.insert({ aux, to_string(n) });
    }
    else
    {
      ss >> a >> sign >> b;
      unsolvedEq.insert({ aux, { a, b, sign } });
    }
    visited.insert({ aux, isEqSolved });
  }

  solvedEq["humn"] = "x";
  findRootEquation(solvedEq, unsolvedEq, visited, out);

  in.close();
  out.close();
}
