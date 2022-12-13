#include "../../AOCHeaders/stdafx.h"

bool checkInMap(long long x, long long y, long long lines, long long columns)
{
  return x >= 0 && y >= 0 && x < lines && y < columns;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<long long> dx{ 0, 1, 0, -1 };
  vector<long long> dy{ -1, 0, 1, 0 };

  // vector<vector<char>> m(1000, vector<char>(1000, '.'));
  vector<vector<char>> m;
  vector<int>          v;
  string               line, aux;
  char                 c{}, c1{}, c2{}, c3{};

  int count = 1;
  int sum   = 0;

  while (getline(in, line))
  {
    getline(in, aux);

    bool aa       = false;
    bool aa2      = false;
    bool compMade = false;
    bool inOrder  = false;
    int  i        = 0;
    int  j        = 0;
    bool ranOutI  = false;
    bool ranOutJ  = false;
    int  ccc      = 0;
    int  cc       = 0;
    while (i < line.size() && j < aux.size())
    {
      vector<int> v1;
      bool        check = true;
      while (i < line.size() && (line[i] < '0' || line[i] > '9'))
      {
        if (line[i] == '[')
          ccc++;
        if (line[i] == ']')
        {
          ccc--;
          // ranOutJ = true;
          check = false;
          i++;
          break;
        }
        i++;
      }

      bool enclose = false;
      bool www     = true;
      while (check && www && i < line.size())
      {
        string number;
        while (i < line.size() && (line[i] < '0' || line[i] > '9'))
        {
          if (line[i] == '[' || line[i] == ']')
          {
            if (line[i] == ']')
              ccc--;
            if (line[i] == '[')
              ccc++;
            // ranOutJ = true;
            www = false;
            break;
          }
          i++;
        }

        while (i < line.size() && (line[i] >= '0' && line[i] <= '9'))
          number += line[i++];
        if (line[i] == ']')
        {
          ccc--;
          enclose = true;
          // ranOutJ = true;
          www = false;
        }
        else
        {
          i++;
        }

        if (!number.empty())
          v1.push_back(stoi(number));
      }

      vector<int> v2;
      int         check2 = true;
      while (j < aux.size() && (aux[j] < '0' || aux[j] > '9'))
      {
        if (aux[j] == '[')
          cc++;
        if (aux[j] == ']')
        {
          cc--;
          // ranOutI = true;
          check2 = false;
          j++;
          break;
        }
        j++;
      }

      bool enclose2 = false;
      bool www2     = true;
      while (check2 && www2 && j < aux.size())
      {
        string number2;
        while (j < aux.size() && (aux[j] < '0' || aux[j] > '9'))
        {
          if (aux[j] == '[' || aux[j] == ']')
          {
            if (aux[j] == ']')
              cc--;
            if (aux[j] == '[')
              cc++;
            // ranOutI = true;
            www2 = false;
            break;
          }
          j++;
        }

        while (j < aux.size() && (aux[j] >= '0' && aux[j] <= '9'))
          number2 += aux[j++];
        if (aux[j] == ']')
        {
          cc--;
          enclose = true;
          www2    = false;
        }
        else
          j++;

        if (!number2.empty())
          v2.push_back(stoi(number2));
      }

      if ((check2 == false) && (check == true))
      {
        inOrder = false;
        aa      = true;
        i = line.size(), j = aux.size();
        break;
      }
      else if ((check == false) && (check2 == true))
      {
        inOrder = true;
        aa2     = true;
        i = line.size(), j = aux.size();
        break;
      }
      else if ((check == false) && (check2 == false))
      {
        if (cc > ccc)
        {
          inOrder = true;
          aa2     = true;
          i = line.size(), j = aux.size();
          break;
        }
      }

      int size = v1.size();

      if (v1.size() < v2.size())
      {
        ranOutI = true;
      }
      else if (v1.size() > v2.size())
      {
        size    = v2.size();
        ranOutJ = true;
      }

      for (int i = 0; i < size; i++)
      {
        if (v1[i] > v2[i])
        {
          inOrder = false;
          aa      = true;
          i = line.size(), j = aux.size();
          break;
        }
        else if (v1[i] < v2[i])
        {
          inOrder = true;
          aa2     = true;
          i = line.size(), j = aux.size();
          break;
        }
      }

      if (v1.size() == v2.size() && v1.size() != 0)
      {
        if (!enclose && enclose2)
        {
          inOrder = true;
          aa2     = true;
          i = line.size(), j = aux.size();
          break;
        }
        if (!enclose && enclose2)
        {
          inOrder = false;
          aa      = true;
          i = line.size(), j = aux.size();
          break;
        }
      }

      if (j == aux.size() || i == line.size() || ranOutI || ranOutJ)
      {
        break;
      }
    }

    if (aa2)
    {
      std::cout << count << "\n";
      sum += count;
    }
    else
    {
      if (!aa)
      {
        if (ranOutI && !ranOutJ)
        {
          std::cout << count << "\n";
          sum += count;
        }
      }
    }
    getline(in, aux);
    count++;
  }

  std::cout << sum;
  /*
  while(getline(in,line))
  {
    stringstream ss(line);
  }

  vector<char> a;
  for (int i = 0; i < line.size(); i++)
    a.push_back(line[i]);
  m.push_back(a);
  */

  /*
  for (int i = 0; i < n; i++)
  {
    for (int i = 0; i < n; i++)
    {
    }
  }
  */

  in.close();
  out.close();
}