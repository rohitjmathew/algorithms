#include<cstdio>
#include<cstdlib>
#define ll long long

// Compute (a*b)%c for long long
ll mulmod(ll a, ll b, ll c){
    ll x=0, y=a%c;
    while(b>0){
        if(b&1==1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b >>= 1;
    }
    return x%c;
}

// Compute (a^b)%c
ll modulo(ll a, ll b, ll c){
    ll x=1, y=a;
    while(b>0){
        if(b&1==1){
            x = mulmod(x,y,c);
        }
        y = mulmod(y,y,c);
        b >>= 1;
    }
    return x%c;
}

bool miller(ll p, int iteration){
    int i;
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    ll s = p-1;
    while(s%2==0){
        s>>=1;
    }
    for(i=0;i<iteration;i++){
        ll a = rand()%(p-1)+1, temp=s;
        ll mod = modulo(a,temp,p);
        //printf("Check\n");
        while(temp!=(p-1) && mod!=1 && mod!=(p-1)){
            //printf("sda\n");
            mod = mulmod(mod, mod, p);
            temp <<=2;
            if(temp>(p-1)){
                return false;
            }
        }
        if(mod!=(p-1) && temp%2==0){
            return false;
        }
    }
    return true;
}

int main(){
    ll a=9, b=9, c=13;
    //printf("%lld", modulo(a,b,c));
    printf("%lld", miller(9,2));
    return 0;
}
