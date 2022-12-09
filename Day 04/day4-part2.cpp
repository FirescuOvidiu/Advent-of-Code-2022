#include "../AOCHeaders/stdafx.h"

int main()
{
    fstream in("input.in", fstream::in);
    fstream out("output.out", fstream::out);

    char c{};
    int s = 0, s1 = 0, x1 = 0, x2 = 0, sum = 0;
    
    while (in >> s >> c >> s1 >> c >> x1 >> c >> x2)
    {
        vector<int> v(1000, 0);
        for (int i = s; i <= s1; i++)
            v[i]++;
        for (int i = x1; i <= x2; i++)
            v[i]++;
        for (int i = 0; i < 1000; i++)
            if (v[i] == 2)
            {
                sum++;
                break;
            }
    }
    cout << sum;

    in.close();
    out.close();
}