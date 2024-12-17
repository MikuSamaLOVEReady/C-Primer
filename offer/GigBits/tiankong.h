//
// Created by ÂÞÈðµÑ on 2024/4/4.
//

#ifndef OFFER_TIANKONG_H
#define OFFER_TIANKONG_H
#include <string>
///  #include <bits/stdc++.h>

int cal(char *s)
{
    if (*s == 0)
        return 0;

    return cal(s + 1) + 1;
}

char h(char *s, int n, int i, int &p)
{
    if (i >= n)
        return 0;

    char c = h(s, n, 2 * i + 1, p);
    if (p == 0)
        return c;

    --p;
    if (p == 0)
        return s[i];

    return h(s, n, 2 * i + 2, p);
}


int f(int x)
{
    return x & (-x);
}

#endif //OFFER_TIANKONG_H
