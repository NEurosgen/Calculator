#pragma once

#include "vector"
#include "DownloadLibrary.h"

class LoaderLibrary final {
public:
    bool openedLibrary(std::string const& nameLibrary);

    SharedLibrary& getLibrary(std::string const& nameLibrary);

    ~LoaderLibrary();

private:
    void loadLibrary(std::string const& nameLibrary);
    std::vector<SharedLibrary> openedLibraries;
};
