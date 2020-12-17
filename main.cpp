#include "LibrariesAndDefines.hpp"
#include "Utunes.hpp"

#define PATH_ARGUMENT 1

int main(int argc, char* argv[])
{
    string filePath = argv[PATH_ARGUMENT];
    Utunes utunes;
    utunes.startUtunes(filePath);
}