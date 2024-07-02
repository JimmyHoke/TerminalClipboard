#include <libterminalclipboard.hpp>

using namespace std;

int main(int argc, char** argv)
{
    string board = "default";
    if (argc == 2)
    {
        board = argv[1];
    }
    TerminalClipboard::ClearClipboard(board=board);
}