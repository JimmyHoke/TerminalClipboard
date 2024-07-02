#include <iostream>
#include <libterminalclipboard.hpp>

using namespace std;


int main(int argc, char** argv)
{
    string board = "default";
    if (argc == 2)
    {
        board = argv[1];
    }
    int dataSize = TerminalClipboard::GetClipboardSize(board=board);
    if (dataSize == 0)
    {
        return 0;
    }
    
    unsigned char data[dataSize];
    TerminalClipboard::GetClipboard(data, board=board);

    for (int i = 0; i < dataSize; i++)
    {
        cout << data[i];
    }
    //cout << endl;
    
    

    return 0;
}