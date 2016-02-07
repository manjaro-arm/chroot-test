#include <cstdlib>
#include <iostream>
#include <unistd.h> // for chroot
#include <cerrno> // errno variable
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    std::cout << "Note: this program must be run as root\n";
    int result = chroot("/home/owner/Downloads/chroot-env/");

    if (result == 0) {
        std::cout << "Chroot success." << std::endl;
    } else {
        std::cout << "Chroot failure: " << result << " " << errno << std::endl;
    }

    mode_t perms = S_IRWXU; // Pick appropriate permissions for the new file.
    int fd = open("/test.txt", O_CREAT | O_EXCL, perms);
    if (fd >= 0) {
        std::cout << "File created." << std::endl;
    } else {
        std::cout << "File creation failed." << std::endl;
    }
    return 0;
}
