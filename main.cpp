#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define SUCCESS "Access granted\n"
#define FAILURE "Access denied\n"
#define LOGIN_IN "Enter login\n"
#define KEY_IN "Enter key\n"

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
    s.resize(32, 'A');
    std::vector<int> l;
    for (char c : s)
        l.emplace_back(int(c));
    return l;
}

std::vector<char> str2list(std::string s)
{
    s.resize(32, 'A');
    std::vector<char> l;
    for (char c : s)
        l.emplace_back(c);
    return l;
}

std::vector<char> Transform(std::vector<int> s)
{
    std::string x = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789@.", a = "gx5CPeKGITBx5YDzhC3ihxFAoJOgqz5p";
    std::vector<char> b;
    int i, c = s.size(), d;

    for (i = 0; i < c / 4; i++)
    {
        d = int(a[i]) ^ s[i];
        b.push_back(x[((d << 1) | (d >> 2)) % 64]);
    }
    for (i = c / 4; i < c / 2; i++)
    {
        d = int(a[i]) ^ s[i];
        b.push_back(x[((d << 2) | (d >> 1)) % 64]);
    }
    for (i = c / 2; i < 3 * c / 4; i++)
    {
        d = int(a[i]) ^ s[i];
        b.push_back(x[((d << 3) | (d >> 1)) % 64]);
    }
    for (i = 3 * c / 4; i < c; i++)
    {
        d = int(a[i]) ^ s[i];
        b.push_back(x[((d << 1) | (d >> 3)) % 64]);
    }

    return b;
}

int main()
{
    std::vector<int> a;
    std::vector<char> b, c;
    std::string d;
    std::cout << LOGIN_IN;
    a = str2list();
    c = Transform(a);
    std::cout << KEY_IN;
    std::cin >> d;
    b = str2list(d);
    std::cout << b << "\n\n";
    if (b == c)
    {
        std::cout << SUCCESS;
    }
    else
    {
        std::cout << FAILURE;
//        std::cout << "Key was: " << c << "\n";
        std::cout << "Key was: " << std::hex << c << "\n";
    }
    return 0;
}
