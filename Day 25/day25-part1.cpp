#include "../../AOCHeaders/stdafx.h"

char reVal(long long num)
{
  if (num == 0)
    return '0';
  if (num == 1)
    return '1';
  if (num == 2)
    return '2';
  if (num == 3)
    return '=';
  if (num == 4)
    return '-';
}

// Utility function to reverse a string
void strev(char * str)
{
  long long len = strlen(str);
  long long i;
  for (i = 0; i < len / 2; i++)
  {
    char temp        = str[i];
    str[i]           = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}

// Function to convert a given decimal number
// to a base 'base' and
char * fromDeci(char res[], long long base, long long inputNum)
{
  long long index = 0;  // Initialize index of result

  // Convert input number is given base by repeatedly
  // dividing it by base and taking remainder
  while (inputNum > 0)
  {
    int val      = 0;
    res[index++] = reVal(inputNum % base);

    if (inputNum % base == 0)
      val = 0;
    if (inputNum % base == 1)
      val = 1;
    if (inputNum % base == 2)
      val = 2;
    if (inputNum % base == 3)
      val = -2;
    if (inputNum % base == 4)
      val = -1;

    inputNum = ((inputNum - val) / base);
  }
  res[index] = '\0';

  // Reverse the result
  strev(res);

  return res;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  string line;

  long long sum = 0;
  while (getline(in, line))
  {
    long long currSum = 0, mult = 1;
    for (int i = line.size() - 1; i >= 0; i--)
    {
      if (line[i] == '2')
        currSum += mult * 2;
      if (line[i] == '1')
        currSum += mult * 1;
      if (line[i] == '0')
        currSum += mult * 0;
      if (line[i] == '-')
        currSum += mult * -1;
      if (line[i] == '=')
        currSum += mult * -2;
      mult *= 5;
    }
    sum += currSum;
  }

  char res[100];
  cout << fromDeci(res, 5, sum);

  /*
  // initial solution doesn't work for long numbers
  queue<pair<long long, string>> q;

  q.push({ 2, "2" });
  q.push({ 1, "1" });
  q.push({ 0, "0" });
  q.push({ -1, "-" });
  q.push({ -2, "=" });

  while (true)
  {
    queue<pair<long long, string>> q1;

    while (!q.empty())
    {
      auto curr = q.front();
      q.pop();
      long long five = 1;
      for (int ccc = 0; ccc < (curr.second.size()); ccc++)
        five *= 5;

      if (curr.first == sum)
      {
        reverse(begin(curr.second), end(curr.second));
        cout << curr.second;
      }

      q1.push({ curr.first + 2 * five, curr.second + "2" });
      q1.push({ curr.first + 1 * five, curr.second + "1" });
      q1.push({ curr.first + 0 * five, curr.second + "0" });
      q1.push({ curr.first + -1 * five, curr.second + "-" });
      q1.push({ curr.first + -2 * five, curr.second + "=" });
    }
    q = q1;
  }
  */

  in.close();
  out.close();
}
