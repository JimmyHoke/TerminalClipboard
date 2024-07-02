#include <iostream>
#include <libterminalclipboard.hpp>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    vector<unsigned char> data;
    string board = "default";
    if (argc == 2)
    {
        board = argv[1];
    }
    
    char curByte;
    while (cin.get(curByte)) {
        data.push_back(static_cast<unsigned char>(curByte));
    }
    //data.pop_back();
    TerminalClipboard::SetClipboard(data.data(), data.size(), board=board);

    return 0;
}