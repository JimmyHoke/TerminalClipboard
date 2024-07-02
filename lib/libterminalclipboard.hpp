#ifndef H_LIBTERMINALCLIPBOARD
#define H_LIBTERMINALCLIPBOARD

#include <string>

namespace TerminalClipboard
{
    void SetClipboard(unsigned char data[], int size, std::string board = "default");

    void GetClipboard(unsigned char *data, std::string board = "default");

    void ClearClipboard(std::string board = "default");

    int GetClipboardSize(std::string board = "default");
}
#endif
