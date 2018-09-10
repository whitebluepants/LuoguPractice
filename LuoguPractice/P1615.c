#include <stdio.h>
int main()
{
    int s = 0;
    unsigned long long count = 0;
    int p1,p2,p3;
    int m1,m2,m3;
    int s1,s2,s3;
    scanf("%d:%d:%d",&p1,&p2,&p3);
    scanf("%d:%d:%d",&m1,&m2,&m3);
    scanf("%d",&s);

    // 1:02:35
    // 3:00:10
    s3 = m3 - p3;
    if(s3 < 0)
    {
        s3 += 60;
        m2 --;
    }
    s2 = m2 - p2;
    if(s2 < 0)
    {
        s2 += 60;
        m1 --;
    }
    s1 = m1 - p1;
    unsigned time = s3 + s2 * 60 + s1 * 60 * 60;
    count = (unsigned long long)time * s;
    printf("%lld",count);

    return 0;
}