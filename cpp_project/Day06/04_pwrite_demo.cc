#include "common.h"
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("a.txt", O_RDWR);
    assert(fd != -1 && "open failed");

    // 获取当前文件位置？
    printf("pos: %ld\n", lseek(fd, 0, SEEK_CUR)); // pos:0
    // write(fd, "kitty", 5);
    pwrite(fd, "kitty", 5, 6);
    printf("pos: %ld\n", lseek(fd, 0, SEEK_CUR)); // pos:0
}
