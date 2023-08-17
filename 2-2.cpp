//2-2
#include <iostream>
#include <string>
using namespace std;

char base[64];
char table[256];

void init()
{
    for (int i = 0; i < 26; i++) base[i] = 'A' + i;
    for (int i = 0; i < 26; i++) base[26 + i] = 'a' + i;
    for (int i = 0; i < 26; i++) base[52 + i] = '0' + i;
    base[62] = '+', base[63] = '/';

    for (int i = 0; i < 256; i++) table[i] = 0xff;
    for (int i = 0; i < 64; i++) table[base[i]] = i;
    table['='] = 0;
}

string decode(string str)
{
    string ret;
    int i;
    for (i=0; i < str.size(); i += 4) {
        ret += table[str[i]] << 2 | table[str[i+1]] >> 4;
        if (str[i + 2] != '=')
            ret += (table[str[i + 1]] & 0x0f) << 4 | table[str[i + 2]] >> 2;

        if(str[i + 3] != '=')
            ret += table[str[i + 2]] << 6 | table[str[i + 3]];
    }
    return ret;
}

int main()
{
    init();
    cout << int(table[0]) << endl;

    string str;
    cin >> str;
    cout << decode(str) << endl;
    return 0;
}