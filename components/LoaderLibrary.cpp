#include "LoaderLibrary.h"

bool LoaderLibrary::openedLibrary(std::string const &nameLibrary) {
    for (SharedLibrary const &it : openedLibraries) {
        if (it.name == nameLibrary) {
            return true;
        }
    }
    return false;
}

void LoaderLibrary::loadLibrary(std::string const &nameLibrary) {
    SharedLibrary newLibrary;
    newLibrary.loadLibrary(nameLibrary);
    openedLibraries.emplace_back(newLibrary);
}

SharedLibrary &LoaderLibrary::getLibrary(const std::string &nameLibrary) {
    if (!openedLibrary(nameLibrary)) {
        loadLibrary(nameLibrary);
    }
    for (SharedLibrary &it : openedLibraries) {
        if (it.name == nameLibrary) {
            return it;
        }
    }
}

LoaderLibrary::~LoaderLibrary() {
    for (SharedLibrary &it : openedLibraries) {
        it.closeLib();
    }
}
