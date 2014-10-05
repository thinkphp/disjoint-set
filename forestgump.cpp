#include <fstream>

using namespace std;

namespace Forest {

           const int limit = 100005;

           int root[ limit ],

              depth[ limit ];

           void init( int n ) {

                for(int i = 1; i <= n; i++) root[ i ] = i, depth[ i ] = 1;
           };

           int findRoot(int node) {

               if( root[ node ] != node ) return findRoot( root[ node ] );

                   else return node;
           };

           bool connected(int node1, int node2) {

                return Forest::findRoot( node1 ) == Forest::findRoot( node2 ); 
           };           

           void unite(int x, int y) {

                x = findRoot( x ); 

                y = findRoot( y ); 

                if(x == y) return;

                if( depth[ x ] < depth[ y ]) {

                    root[ x ] = y;

                } else {

                    root[ y ] = x;
                }

                if(depth[ x ] == depth[ y ]) depth[ y ]++;
           };
}

int main() {
 
    const char *FIN = "disjoint.in",
               *FOUT = "disjoint.out";

    int N,M,x,y,type;

    ifstream fin( FIN );

    ofstream fout( FOUT );
 
    fin>>N>>M;

    Forest::init( N );  

    for(; M; M--) {

       fin>>type>>x>>y;

       if(type == 1) Forest::unite(x, y);

          else if( Forest::connected(x, y) ) fout<<"DA\n";

               else fout<<"NU\n";                         
    } 

    fin.close();

    fout.close();

    return(0);
};