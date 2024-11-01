#include "DownloadLibrary.h"

void SharedLibrary::loadLibrary(std::string const& nameLibrary) {
    std::string filePath;
    std::stringstream ss;

    ss << "../plugins/"
       << "/lib" << nameLibrary << ".so";
    filePath = ss.str();
    std::cout << filePath << " " << nameLibrary << '\n';
    void* libraryHandler = dlopen(filePath.c_str(), RTLD_LAZY);

    if (!libraryHandler) {
        std::string errorMessage;
        ss << "SharedLibrary  " << nameLibrary << "wasn't  download\n";
        errorMessage = ss.str();
        throw std::runtime_error(errorMessage.c_str());
    }
    std::cout << "Download librari by name" << nameLibrary << "\n";
    name = nameLibrary;
    handler = libraryHandler;
}

double SharedLibrary::runFunc(double const& value) {
    double (*function)(double) = (double (*)(double))dlsym(this->handler, "func");
    if (!function) {
        throw std::runtime_error("Invalid func!");
    }
    return function(value);
}

double SharedLibrary::runFunc(double const& value1, double const& value2) {
    double (*function)(double, double) = (double (*)(double, double))dlsym(this->handler, "func");
    if (!function) {
        throw std::runtime_error("Invalid func!");
    }
    return function(value1, value2);
}

void SharedLibrary::closeLib() {
    dlclose(handler);
}