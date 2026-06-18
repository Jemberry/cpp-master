#include "common.h"
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("a.txt", O_RDONLY);
    assert(fd != -1 && "open failed");

    char buf[4096] = { 0 };
    // 获取当前文件位置？
    printf("pos: %ld\n", lseek(fd, 0, SEEK_CUR)); // pos:0
    // read(fd, buf, 5);
    pread(fd, buf, 5, 6);
    printf("pos: %ld\n", lseek(fd, 0, SEEK_CUR)); // pos:0
    printf("buf: %s\n", buf); // world
}
