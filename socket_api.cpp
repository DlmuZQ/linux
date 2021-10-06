#include <arpa/inet.h>
int main()
{
    char *szValue = inet_ntoa("1.2.3.4");
    char *szValue2 = inet_ntoa("10.11.10.12");
    printf("sz1: %s", szValue);
    printf("sz2: %s", szValue2);
    return 0;
}