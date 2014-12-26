/**
 *  Disjoint-set Forests Data Structure.
 */
#include <fstream>
#include <iostream>
#define FIN "disjoint.in"
#define FOUT "disjoint.out"

using namespace std;

typedef unsigned int  uint;
typedef unsigned long ulong;

class Forest {

      public: 
      //constructor of the class
      Forest(ulong nElements): parent( new ulong[ nElements + 1 ] ), 
                               height( new ulong[ nElements + 1 ] ), 
                               numElems( nElements )
      {
             for(uint i = 1; i <= numElems; i++) {

                 parent[ i ] = i;

                 height[ i ] = 1;
             } 
      };

      //deconstructor of the class
      ~Forest()
      {
        delete [] parent;    

        delete [] height;
      };  

      void join(ulong x, ulong y) 
      {

           x = find( x );

           y = find( y );

           if( height[ x ] > height[ y ] ) {

               parent[ y ] = x;

           } else {

               parent[ x ] = y;
           }

           if(height[ x ] == height[ y ]) height[ y ]++;
      };

      bool areConnected(ulong x, ulong y) {

           return find(x) == find(y);
      }; 

      private:

      ulong* parent;
      ulong* height;
      ulong numElems;   

      ulong find(ulong node) 
      {
 
            while( node != parent[ node ]) {

                   node = parent[ node ];  
            }

            return node;
      };
};

//Main Function
int main() {

    ifstream fin( FIN );

    ofstream fout( FOUT );

    if( !fin || !fout ) {

        cout<<"Error opening files"<<"\n";

        return -1;
    }        

    ulong numElements,

          numOps,

          type,

          x,

          y; 

    /**
     *  Read the data in...
     */

     fin>>numElements>>numOps;

    /**
     *  Solve the problem...
     */
 
     Forest forest( numElements );       
  
     for(; numOps; numOps--) {

           fin>>type>>x>>y;

           switch( type ) {

                   case 1:
                   forest.join(x, y);                    
                   break;
          
                   case 2:
                   if(forest.areConnected(x, y) ) fout<<"DA"<<"\n"; 

                                      else 
 
                                           fout<<"NU"<<"\n";
                   break;
           } 
     }

    return(0);
};