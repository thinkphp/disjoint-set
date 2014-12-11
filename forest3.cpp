/**
 *  
 */
#include <fstream>
#define FIN "disjoint.in"
#define FOUT "disjoint.out"
#define MAXN 100005

using namespace std;

class Forest {

      private:
            int Father[ MAXN ], 

                Length[ MAXN ];

      public: 
             void init(int N) {
            
                  for(int i = 1; i <= N; i++) { 

                       Father[ i ] = i;

                       Length[ i ] = 1;
                  }
             };

             void unite(int x, int y) {

                  x = root( x );

                  y = root( y );  

                  if(x == y) return;

                  if( Length[ x ] < Length[ y ]) {

                      Father[ x ] = y;

                  } else {

                      Father[ y ] = x;
                  }

                  if( Length[ x ] == Length[ y ] ) Length[ x ]++;
             };

             int root(int node) {

                 if( Father[ node ] != node ) return root( Father[ node ] );

                     else return node;
             };

             bool same(int node1, int node2) {

                  return ( root( node1 ) == root( node2 ) );
             };
};

int main() {
 
    int N,

        M,

        type, 

        x,

        y; 

    Forest forest;

    ifstream fin( FIN );

    ofstream fout( FOUT );

    fin>>N>>M;

    forest.init( N );

    while( M-- ) {

            fin>>type>>x>>y;
            
            if(type == 1) forest.unite(x, y);
 
                      else if( forest.same(x, y) ) fout<<"DA\n";

                                       else        
                                                   fout<<"NU\n";  
    };

    fin.close();   

    fout.close();   

    return(0);
};