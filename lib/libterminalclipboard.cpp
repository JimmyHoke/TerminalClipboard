#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace std;
using namespace boost::interprocess;

namespace TerminalClipboard
{
    const int SIZE_LEN = sizeof(int);

    void SetClipboard(unsigned char data[], int size, std::string board = "default")
    {
        string boardName = "terminalclipboard-" + board;
        shared_memory_object::remove(boardName.c_str());
        shared_memory_object tclip(create_only,
                                   boardName.c_str(),
                                   read_write);
        tclip.truncate(SIZE_LEN + size);

        mapped_region sizeReg(tclip, read_write, 0, SIZE_LEN);
        int *clipboardDataSize = static_cast<int *>(sizeReg.get_address());
        *clipboardDataSize = size;

        mapped_region dataReg(tclip, read_write, SIZE_LEN, size);
        unsigned char *clipboardData = static_cast<unsigned char *>(dataReg.get_address());
        int i = 0;
        for (int i = 0; i < size; i++)
        {
            clipboardData[i] = data[i];
        }
    }

    void GetClipboard(unsigned char *data, std::string board = "default")
    {
        string boardName = "terminalclipboard-" + board;
        shared_memory_object tclip(open_only,
                                   boardName.c_str(),
                                   read_only);

        mapped_region sizeReg(tclip, read_only, 0, SIZE_LEN);
        int *dataSize = static_cast<int *>(sizeReg.get_address());
        mapped_region dataReg(tclip, read_only, SIZE_LEN, *dataSize);
        unsigned char *clipboardData = static_cast<unsigned char *>(dataReg.get_address());
        // unsigned char data[*dataSize];
        for (int i = 0; i < *dataSize; i++)
        {
            data[i] = clipboardData[i];
        }
    }

    int GetClipboardSize(std::string board = "default")
    {
        string boardName = "terminalclipboard-" + board;
        try
        {
            shared_memory_object tclip(open_only,
                                       boardName.c_str(),
                                       read_only);

            mapped_region sizeReg(tclip, read_only, 0, SIZE_LEN);
            int *dataSize = static_cast<int *>(sizeReg.get_address());
            return *dataSize;
        }
        catch (const std::exception &e)
        {
            return 0;
        }
    }

    void ClearClipboard(std::string board = "default")
    {
        string boardName = "terminalclipboard-" + board;
        shared_memory_object::remove(boardName.c_str());
    }
}