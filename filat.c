#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Wrong Parameter \n");
        return 0;
    }
    struct stat attributes;

    if(stat(argv[1],&attributes
            ) < 0) return 1;
    printf("\n");
    printf("--------------------%s--------------------\n",argv[1]);
    printf("\n");
    printf("File Type: \t\t");
    if(S_ISBLK(attributes.st_mode)) printf("Block device");
    else if (S_ISREG(attributes.st_mode)) printf("Regular file");
    else if (S_ISDIR(attributes.st_mode)) printf("Directory");
    else if (S_ISCHR(attributes.st_mode)) printf("Character device");
    else if (S_ISLNK(attributes.st_mode)) printf("Symbolic link");
    printf("\n");
    printf("Access privileges:\t");
    (attributes.st_mode & S_IRUSR) ? printf("r") : printf("-");
    (attributes.st_mode & S_IWUSR) ? printf("w") : printf("-");
    (attributes.st_mode & S_IXUSR) ? printf("x") : printf("-");

    (attributes.st_mode & S_IRGRP) ? printf("r") : printf("-");

    (attributes.st_mode & S_IWGRP) ? printf("w") : printf("-");

    (attributes.st_mode & S_IXGRP) ? printf("x") : printf("-");
    (attributes.st_mode & S_IROTH) ? printf("r") : printf("-");
    (attributes.st_mode & S_IXOTH) ? printf("x") : printf("-");

    printf("\n");

    printf("File inode: \t\t%ld\n",attributes.st_ino);
    printf("Device Numbers: \tdev = %ld; rdev = %ld\n",attributes.st_dev, attributes.st_rdev);
    printf("Number of Links: \t%ld\n",attributes.st_nlink);
    printf("UID: \t\t\t%d\n",attributes.st_uid);
    printf("GID: \t\t\t%d\n",attributes.st_gid);
    printf("File size: \t\t%ld\n",attributes.st_size);
    printf("Last access: \t\t%s",asctime(gmtime(&attributes.st_atime)));
    printf("Last modification: \t%s",asctime(gmtime(&attributes.st_mtime)));
    printf("Last inode change: \t%s",asctime(gmtime(&attributes.st_ctime)));
    return 0;
}
