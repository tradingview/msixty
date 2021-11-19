#include <atlbase.h>
#include <windows.h>

#include <iostream>

int wmain(int argc, TCHAR* argv[]) {
    std::wcout << "Arguments count: " << argc << std::endl;
    std::wcout << "Arguments are: " << std::endl;

    for (int i = 0; i < argc; ++i) {
        std::wcout << '[' << i << "]: " << argv[i] << std::endl;
    }

    return 0;
}
