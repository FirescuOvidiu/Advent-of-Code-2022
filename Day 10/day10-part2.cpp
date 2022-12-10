#include "../../AOCHeaders/stdafx.h"

void SetPixel(vector<char> & pixels, int pos, char c)
{
  if (pos >= 0 && pos <= 39)
    pixels[pos] = c;
}

int main()
{
  fstream in("input.in", fstream::in);
  fstream out("output.out", fstream::out);

  vector<int> v;
  string      line;
  long long   n = 0;

  while (in >> line)
  {
    if (line == "noop")
      v.push_back(0);
    else if (line == "addx")
    {
      in >> n;
      v.push_back(0);
      v.push_back(n);
    }
  }

  vector<char> pixels(40, '.');

  pixels[0] = '#';
  pixels[1] = '#';
  pixels[2] = '#';

  string currPixels;
  int    pos = 0;
  for (int i = 0; i < v.size(); i++)
  {
    currPixels += pixels[i % 40];
    if (v[i] != 0)
    {
      SetPixel(pixels, pos, '.');
      SetPixel(pixels, pos + 1, '.');
      SetPixel(pixels, pos + 2, '.');

      SetPixel(pixels, pos + v[i], '#');
      SetPixel(pixels, pos + v[i] + 1, '#');
      SetPixel(pixels, pos + v[i] + 2, '#');

      pos += v[i];
    }

    if ((i == 39) || (i == 79) || (i == 119) || (i == 159) || (i == 199) || (i == 239))
    {
      out << currPixels << "\n";
      currPixels.clear();

      for (int i = 0; i < 40; i++)
        pixels[i] = '.';

      pixels[0] = '#';
      pixels[1] = '#';
      pixels[2] = '#';
    }
  }

  in.close();
  out.close();
}
