#include <stdio.h>
#define FIN "disjoint.in"
#define FOUT "disjoint.out"

int N,
    M;

class DisjointSets {

      public: 
             DisjointSets() {
            
                for(size_t i = 1; i <= size; i++) root[ i ] = i, 

                                                  height[ i ] = 1;
             };

             int join(int x, int y) {

                 if( height[ x ] > height[ y ]) {
                     
                     root[ y ] = x;  

                 }  else {

                     root[ x ] = y;
                 }

                 if(height[ x ] == height[ y ]) height[ y ]++;
             };

             int find(int x) {

                 if(root[ x ] != x) find( root[ x ] );
 
                    else return root[ x ];
             }

      private:
             static const size_t size = 100005;  
                          int root[ size ];
                          int height[ size ];   

};

int main() {
 
    DisjointSets s;

    int type, 

        x,

        y; 

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= M; i++) {

        scanf("%d %d %d", &type, &x, &y);

        if(type == 1) s.join(s.find( x ), s.find( y ) );

                else {

                     if(s.find( x ) == s.find( y )) printf("%s\n", "DA");

                                                 else 

                                                    printf("%s\n", "NU");
                }
    } 

    fclose( stdin );  

    fclose( stdout );  
    
    return(0);
};