/**
 *  Disjoint-set Forests Data Structure
 */
#include <fstream>
#include <iostream>

using namespace std;

typedef unsigned int  uint;
typedef unsigned long ulong;

class Forest {

      public: 
      //constructor of the class
      Forest(ulong nElements): parent( new ulong[ nElements + 1 ] ), height( new ulong[ nElements + 1 ] ), numElems( nElements )
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

      void unite(ulong x, ulong y) 
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

      bool connected(ulong x, ulong y) {

           return find(x) == find(y);
      }; 

      private:
      ulong* parent;
      ulong* height;
      ulong numElems;   

      ulong find(ulong node) 
      {

           if(parent[ node ] != node) {

              find( parent[ node ] );

           } else return node; 
      };


      ulong find2(ulong node) {
 
            while( node != parent[ node ]) {

                   node = parent[ node ];  
            }

            return node;
      };
};

//main function
int main() {

    const char *FIN = "disjoint.in";

    const char *FOUT = "disjoint.out";

    ifstream fin(FIN);

    ofstream fout(FOUT);


    if( !fin || !fout ) {

        cout<<"Error opening files";
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
                   forest.unite(x, y);                    
                   break;
          
                   case 2:
                   if(forest.connected(x, y) ) fout<<"DA"<<"\n"; 

                                        else fout<<"NU"<<"\n";
                   break;
           } 
     }

    return(0);
};