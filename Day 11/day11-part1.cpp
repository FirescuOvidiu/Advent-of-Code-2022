#include "../../AOCHeaders/stdafx.h"

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string    line, aux;
  long long n = 0;
  char      c;

  vector<vector<long long>>  items;
  vector<pair<char, string>> op;
  vector<long long>          div;

  vector<long long> T;
  vector<long long> F;

  while (getline(in, line))
  {
    getline(in, line);
    stringstream ss(line);
    ss >> aux >> aux;
    vector<long long> nr;
    while (ss >> n)
    {
      nr.push_back(n);
      ss >> aux;
    }
    items.push_back(nr);

    getline(in, line);
    stringstream ss2(line);
    ss2 >> aux >> aux >> aux;
    ss2 >> aux;
    ss2 >> c >> aux;
    op.push_back({ c, aux });

    getline(in, line);
    stringstream ss3(line);
    ss3 >> aux >> aux >> aux >> n;
    div.push_back(n);

    getline(in, line);
    stringstream ss34(line);
    ss34 >> aux >> aux >> aux >> aux >> aux >> n;
    T.push_back(n);

    getline(in, line);
    stringstream ss354(line);
    ss354 >> aux >> aux >> aux >> aux >> aux >> n;
    F.push_back(n);
    getline(in, line);
  }

  vector<long long> times(10, 0);
  long long         rounds = 0;
  while (rounds < 20)
  {
    for (long long i = 0; i < items.size(); i++)
    {
      char      oper  = op[i].first;
      long long numar = 0;
      long long newNr = 0;
      for (long long j = 0; j < items[i].size(); j++)
      {
        if (op[i].second == "old")
          numar = items[i][j];
        else
          numar = stoi(op[i].second);

        if (oper == '+')
          newNr = items[i][j] + numar;
        else
          newNr = items[i][j] * numar;

        newNr = newNr / 3;

        if (newNr % div[i] == 0)
          items[T[i]].push_back(newNr);
        else
          items[F[i]].push_back(newNr);
      }
      times[i] += items[i].size();
      items[i].clear();
    }
    rounds++;
  }

  sort(begin(times), end(times));
  out << times[times.size() - 1] * times[times.size() - 2];

  in.close();
  out.close();
}
