#include <iostream>
#include <libterminalclipboard.hpp>

using namespace std;


int main()
{
    int dataSize = TerminalClipboard::GetClipboardSize();
    if (dataSize == 0)
    {
        return 0;
    }
    
    unsigned char data[dataSize];
    TerminalClipboard::GetClipboard(data);

    for (int i = 0; i < dataSize; i++)
    {
        cout << data[i];
    }
    cout << endl;
    
    

    return 0;
}