#include <iostream>
#include <libterminalclipboard.hpp>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned char> data;

    char curByte;
    while (cin.get(curByte)) {
        data.push_back(static_cast<unsigned char>(curByte));
    }
    data.pop_back();
    TerminalClipboard::SetClipboard(data.data(), data.size());

    return 0;
}