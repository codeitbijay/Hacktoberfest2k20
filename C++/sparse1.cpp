#include <iostream>
using namespace std;
  
int main() 
{   int i, j;
    int sparsematrix[4][5]=
    {
    {1, 0, 0, 0, 0},
    {0, 0, 0, 4, 0},
    {0, 0, 3, 0, 7},
    {0, 9, 0, 0, 0}
    };
    
    int size=0;
    for(int i=0; i<4;i++){
       for(int j=0; j<5;j++){
           cout<<sparsematrix[i][j]<<" ";;
          
       }
       cout<<endl;
    }
    for(int i=0; i<4;i++){
       for(int j=0; j<5;j++){
           
          if(sparsematrix[i][j]!= 0){
              size++;
          }
       }
    }
    cout<<size<<endl;

    int newmatrix[3][size];
    int p =0;
    for(int i=0; i<4;i++){
       for(int j=0; j<5;j++){
          if(sparsematrix[i][j]!= 0){
              newmatrix[0][p] = i;  //row
              newmatrix[1][p] = j;  //col
              newmatrix[2][p] = sparsematrix[i][j];  //value  
              p++;  
          }
       }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<size;j++){
            cout<<newmatrix[i][j]<<" ";
            
           
        }
        cout<<endl;
        
    }
    for(int i=0;i<3;i++){
        cout<<"row ";
        for(int j=0;j<size;j++){
            
            cout<<newmatrix[0][j]<<" ";

                   }
        cout<<endl;           
        cout<<"col ";           
        for(int j=0;j<size;j++){
            cout<<newmatrix[1][j]<<" ";

                   }
        cout<<endl; 

        cout<<"val ";       
        for(int j=0;j<size;j++){
            cout<<newmatrix[2][j]<<" ";

                   }
        cout<<endl;           
    }
       
    
    return 0;
}