#include <cstdio>
#include <math.h>

float root( int A, int n ){
    if(n==0){
        return 1;
    }
    if(n==1){
        return A;
    }
	float ret, s;
	ret = 1.0; /* Initial guess */
	s = 1.0;
	for ( ; ; ){
		ret = ( ( n - 1 ) * ret + ( A / ( float )pow( ret, n - 1 ) ) ) / n;
		if ( s == ret ){
			break;
		}
		else if ( s != ret - 1 ){
			s = ret;
		}
	}
	return ret;
}

int main(){
    /*
    float x = root(2,1);
    if((x-(int)x)==0){
        printf("Integer\n");
    }
    else{
        printf("Float\n");
    }*/
	printf( "%ith root of %i = %f\n", 20, 3, root( 20,3 ) );

	return 0;
}
