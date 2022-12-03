#include "../AOCHeaders/stdafx.h"

using namespace std;

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string    line, line2, line3;
  long long sum = 0;

  while (getline(in, line))
  {
    getline(in, line2);
    getline(in, line3);

    vector<int>  v1(1000, 0);
    vector<int>  v2(1000, 0);
    vector<int>  v3(1000, 0);
    vector<char> v11(1000);
    vector<char> v22(1000);
    vector<char> v33(1000);
    for (int i = 0; i < line.size(); i++)
    {
      v1[(int)line[i]]++;
      v11[line[i]] = line[i];
    }
    for (int i = 0; i < line2.size(); i++)
    {
      v2[(int)line2[i]]++;
      v22[line2[i]] = line2[i];
    }
    for (int i = 0; i < line3.size(); i++)
    {
      v3[(int)line3[i]]++;
      v33[line3[i]] = line3[i];
    }

    for (int i = 0; i < 1000; i++)
    {
      if ((v1[i] > 0 && v2[i] > 0 && v3[i] > 0) && v1[i] != 0)
      {
        if ((v22[i] >= 'a') && (v22[i] <= 'z'))
          sum += v22[i] - 'a' + 1;
        if ((v22[i] >= 'A') && (v22[i] <= 'Z'))
          sum += v22[i] - 'A' + 27;
      }
    }
  }

  cout << sum;

  in.close();
  out.close();
}
