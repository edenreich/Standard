#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <string>

void listFiles(const std::string & path)
{
    DIR * dir;
    struct dirent * entry;

    // open directory
    dir = opendir(path.c_str());
    if (dir == NULL) {
        std::cout << "Directory was not found" << std::endl;
        exit(1);
    }

    // read
    while ((entry = readdir(dir)) != NULL) {
       std::cout << entry->d_name << std::endl;
    }

    // close directory pointer
    closedir(dir);
}

int main()
{
    std::string directoryName;
    directoryName = "./fixtures";

    listFiles(directoryName);

    return 0;
}
