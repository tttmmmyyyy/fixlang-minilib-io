#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>

int minilib_iofs_stat(const char* pathname, uint64_t *ret)
{
    struct stat st;
    int err = stat(pathname, &st);
    if (err != 0) {
        return err;
    }
    ret[0] = (uint64_t)st.st_dev;
    ret[1] = (uint64_t)st.st_ino;
    ret[2] = (uint64_t)st.st_nlink;
    ret[3] = (uint64_t)st.st_mode;
    ret[4] = (uint64_t)st.st_uid;
    ret[5] = (uint64_t)st.st_gid;
    ret[6] = (uint64_t)st.st_rdev;
    ret[7] = (uint64_t)st.st_size;
    ret[8] = (uint64_t)st.st_blksize;
    ret[9] = (uint64_t)st.st_blocks;
    ret[10] = (uint64_t)st.st_atim.tv_sec;
    ret[11] = (uint64_t)st.st_atim.tv_nsec;
    ret[12] = (uint64_t)st.st_mtim.tv_sec;
    ret[13] = (uint64_t)st.st_mtim.tv_nsec;
    ret[14] = (uint64_t)st.st_ctim.tv_sec;
    ret[15] = (uint64_t)st.st_ctim.tv_nsec;
    return 0;
}
