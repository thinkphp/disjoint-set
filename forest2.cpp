#include <iostream>
#include <cstdio>
#define FIN "disjoint.in"
#define FOUT "disjoint.out"

using namespace std;

class DisjointSets {

      private:
            static const int limit = 100005;

                         int root[ limit ];

                         int depth[ limit ];

                         int findRoot(int x) {

                             if(root[ x ] != x) return findRoot( root[ x ] );

                                           else 

                                                return root[ x ];
                         }

      public: 
             DisjointSets(int n) {
            
                  for(int i = 1; i <= n; i++) { 

                       root[ i ] = i;

                      depth[ i ] = 1;
                  }
             };

             int unite(int x, int y) {

                 x = findRoot( x );  

                 y = findRoot( y );

                 if( depth[ x ] > depth[ y ] ) {

                     root[ y ] = x;                       

                 } else {

                     root[ x ] = y;
                 }

                 if(depth[ x ] == depth[ y ] ) depth[ y ]++;
             };

             bool connected(int x, int y) {

                  return findRoot( x ) == findRoot( y );   
             };

};

int main() {
 
    int N,

        M,

        type, 

        x,

        y; 

    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    scanf("%d %d", &N, &M);

    DisjointSets disjoint( N );

    for(int i = 1; i <= M; i++) {

        scanf("%d %d %d", &type, &x, &y);

        if( type == 1 ) {

            disjoint.unite(x, y);

        } else {

           if( disjoint.connected(x, y) ) {

               printf("%s\n","DA"); 

           } else {

               printf("%s\n","NU");
           }
        } 
    } 

    fclose( stdin );  

    fclose( stdout );  
   
    return(0);
};