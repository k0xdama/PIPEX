# include <stdio.h>
# include <unistd.h>

int main(void)
{
    int ret = 0;

    ret = access("/usr/bin/.", X_OK);
    printf ("%d\n", ret);
}