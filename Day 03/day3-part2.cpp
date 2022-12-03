#include "../AOCHeaders/stdafx.h"

using namespace std;

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string    line;
  long long sum = 0;

  while (getline(in, line))
  {
    int size = line.size() / 2;

    vector<int>  v1(1000, 0);
    vector<int>  v2(1000, 0);
    vector<char> v11(1000);
    vector<char> v22(1000);
    for (int i = 0; i < size; i++)
    {
      v1[(int)line[i]]++;
      v11[line[i]] = line[i];
    }
    for (int i = size; i < line.size(); i++)
    {
      v2[(int)line[i]]++;
      v22[line[i]] = line[i];
    }

    for (int i = 0; i < 1000; i++)
    {
      if ((v1[i] > 0 && v2[i] > 0) && v1[i] != 0)
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
