#include <stdio.h>
#define FIN "disjoint.in"
#define FOUT "disjoint.out"
#define MAXN 100005

int F[ MAXN ],
    R[ MAXN ],
    N,
    M;

int findRoot(int x) {

    if(F[ x ] != x) {

       return findRoot( F[ x ] ); 

    } else return F[ x ];
};

void unite(int x, int y) {

     if(R[ x ] > R[ y ]) {

        F[ y ] = x;
 
     } else {

        F[ x ] = y;
     }

     if( R[ x ] == R[ y ] ) R[ y ]++;
};

void ReadAndSolve() {

     int i,

         x,

         y,  

         type;

     freopen(FIN, "r", stdin);

     freopen(FOUT, "w", stdout);

     scanf("%d %d", &N, &M);

     for(i = 1; i <= N; i++) 
 
         F[ i ] = i,
         R[ i ] = 1;  

     for(i = 1; i <= M; i++) {

         scanf("%d%d%d", &type, &x, &y);

         if(type == 1) {

            unite(findRoot( x ), findRoot( y ));

         } else {

            if(findRoot( x ) == findRoot( y )) printf("%s\n", "DA");

                             else              printf("%s\n", "NU");      
         } 
     }

     fclose( stdin );  

     fclose( stdout );  
};

int main() {

    ReadAndSolve(); 

    return(0);
}

