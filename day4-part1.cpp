#include "../AOCHeaders/stdafx.h"

int main()
{
    fstream in("input.in", fstream::in);
    fstream out("output.out", fstream::out);

    char c{};
    int s = 0, s1 = 0, x1 = 0, x2 = 0, sum=0;
    
    while (in >> s >> c >> s1 >> c >> x1 >> c >> x2)
    {
        if (s >= x1 && s<=x2 && s1 <= x2 && s1>=x1)
            sum++;
        else if (s <= x1 && x1 <= s1 && s1 >= x2 && x2>=s)
            sum++;
    }
    cout << sum;
    
    in.close();
    out.close();
}