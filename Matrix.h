#include <iostream>
using namespace std; 
const int MAX_ROW=30,MAX_COL=30;
 class Matrix
 {
     public:
         void ReadMatrix(int,int,float[][MAX_COL]);          
         void PrintMatrix(int,int,float[][MAX_COL]);
         void AddSubtract(int);
         void Multiply();
         float Find_Determinant(int,float[][MAX_COL]);
         void Find_Cofactor(float[][MAX_COL],float[][MAX_COL],int,int,int);
         void Adjoint(float[][MAX_COL],float[][MAX_COL],int);
         bool Inverse();
 };
