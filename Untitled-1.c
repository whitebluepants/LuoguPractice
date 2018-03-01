#include <stdio.h>


int main() {
int d,a,b,c;
scanf("%d",&d);
for(int j=d;; j++) {
    a=j;
    for(int i=1; i<=a-1; i++) {
        if(a%i==0) {
            b+=i;
        }
    }
    for(int i=1; i<=b-1; i++) {
        if(b%i==0) {
            c+=i;
        }
    }
    if(c==a) {
        printf("%d %d",a,b);
        return 0;
    }
}
return 0;
}