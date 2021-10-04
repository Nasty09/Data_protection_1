#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define SUCCESS "Access granted\n"
#define FAILURE "Access denied\n"
#define LOGIN_IN "Enter login:\n"
#define KEY_IN "Enter key:\n"
#define MOD 64
#define SIZE 32

std::ostream& operator<<(std::ostream& out, std::vector<char> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        out << (s[i]);
    }
    return out;
}

std::vector<int> str2list()
{
    std::string s;
    std::cin >> s;
    s.resize(SIZE, 'Q');
    std::vector<int> l;
    for (char c : s)
        l.emplace_back(int(c));
    return l;
}

std::vector<char> str2list(std::string s)
{
    s.resize(SIZE, 'Q');
    std::vector<char> l;
    for (char c : s)
        l.emplace_back(c);
    return l;
}

std::vector<char> Transform(std::vector<int> s)
{
    std::string x = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789@.", a = "gx5CPeKGITBx5YDzhC3ihxFAoJOgqz5p";
    std::vector<char> b;
    int i, c = s.size(), d, sum = 0;

    for (i = 0; i < c; i++)
    {
        switch (i % 4){
            case 0:
                {
                    d = int(a[i]) ^ s[i];
                    b.push_back(x[((d << 1) | (d >> 2)) % MOD]);
                    sum += d;
                    break;
                }
            case 1:
                {
                    d = int(a[i]) ^ s[i];
                    b.push_back(x[((d << 2) | (d >> 1)) % MOD]);
                    sum *= d;
                    break;
                }
            case 2:
                {
                    d = int(a[i]) ^ s[i];
                    b.push_back(x[((d << 3) | (d >> 1)) % MOD]);
                    sum -= d;
                    break;
                }
            case 3:
                {
                    d = int(a[i]) ^ s[i];
                    b.push_back(x[((d << 1) | (d >> 3)) % MOD]);
                    sum /= d;
                    break;
                }
        }
    }
    d += sum;
    return b;
}

int main()
{
    std::vector<int> a;
    std::vector<char> b, c;
    std::string d;
    bool f;
    std::cout << LOGIN_IN;
    a = str2list();
    c = Transform(a);
    std::cout << KEY_IN;
    std::cin >> d;
    f = (d == KEY_IN);
    if (!f)
    {
        b = str2list(d);
    }
    std::cout << str2list("Use this key: 4KeY0") << "\n\n";
    if (b == c)
    {
        std::cout << SUCCESS;
    }
    else
    {
        std::cout << FAILURE;
    }
    return 0;
}
