/*
 *      SZYMON LATO
 *      https://github.com/szymonlato
 *
 */

#include <iostream>
typedef unsigned long long ull;

ull gcd(ull a, ull b){
    if (a == 0)
        return b;
    return gcd(b%a,a);
}

ull moja_funkcja(ull x){
    return (x*x)+1;
}

bool is_prime(ull x){
    if(x == 0 or x ==1)
        return false;
    else
    {
        for (int i = 2; i < x; ++i) {
            if (x % i == 0)
                 return false;
        }

    }
    return true;
}

ull Pollard_rho(ull n){
    if (is_prime(n))
        return 0;
    ull x=n,y=n,d=1;
    while(d == 1){
        x = moja_funkcja(x)%n;
        y = moja_funkcja(y%n)%n;
        d= gcd(abs(x-y),y);
    }
    if (1<d and d<n)
        return d;
    else
        return -1;
}
int main(int args,char **argv) {
    ull n = strtoull(argv[1], 0, 0);
    std::cout<<Pollard_rho(n);
    return 0;
}
