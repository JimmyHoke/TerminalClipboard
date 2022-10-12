#ifndef H_LIBTERMINALCLIPBOARD
#define H_LIBTERMINALCLIPBOARD

namespace TerminalClipboard
{
    void SetClipboard(unsigned char data[], int size);

    void GetClipboard(unsigned char *data);

    void ClearClipboard();

    int GetClipboardSize();
}
#endif
