#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    struct sockaddr_in sa;    /* input */
    socklen_t len;         /* input */
    char hbuf[NI_MAXHOST];

    memset(&sa, 0, sizeof(struct sockaddr_in));

    /* For IPv4*/
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("199.223.232.0");
    len = sizeof(struct sockaddr_in);

    if (getnameinfo((struct sockaddr *) &sa, len, hbuf, sizeof(hbuf), 
        NULL, 0, NI_NAMEREQD)) {
        printf("could not resolve hostname\n");
    }
    else {
        printf("host=%s\n", hbuf);
    }

    return 0;                                                  
}