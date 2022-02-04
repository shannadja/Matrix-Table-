 Implementation 
 #include <iostream> 
 using namespace  std; 
 
 #include <iomanip>
 #include "Matrix.h"  
    void Matrix::ReadMatrix(int rows,int cols,float matrix[][MAX_COL])  
      {
           for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++) 
                 cin>>matrix[i][j]; 
}



     void Matrix::PrintMatrix(int rows,int cols,float matrix[][MAX_COL])   
     {
             cout<<setw(12)<<"Result:"<<endl;
                   for(int i=0;i<rows;i++)
                {
                    for(int j=0;j<cols;j++)
                        cout<<setw(12)<<matrix[i][j];
                cout<<endl;
                } 
        }
        
        void Matrix::AddSubtract(int operation) //adds or subtracts 2 matrices 27:     {
             int rows,cols;
        cout<<"Enter the number of rows for the matrices: "<<endl; 
         cin>>rows;
         cout<<"Enter the number of columns for the matrices: "<<endl;
         cin>>cols;
         float Matrix_A[rows][MAX_COL],Matrix_B[rows][MAX_COL],Matrix_C[rows][
         for(int i=0;i<rows;i++)
             for(int j=0;j<cols;j++)
             {
                 Matrix_A[i][j]=0;
                 Matrix_B[i][j]=0;
                 Matrix_C[i][j]=0;
             }
         cout<<"Enter the elements of the first matrix: "<<endl;
         ReadMatrix(rows,cols,Matrix_A);
         cout<<"Enter the elements of the second matrix: "<<endl;
         ReadMatrix(rows,cols,Matrix_B);
         if (operation==1)
         {
             for(int i=0;i<=rows;i++)
                 for(int j=0;j<=cols;j++)
                   Matrix_C[i][j]=Matrix_A[i][j]+Matrix_B[i][j];
          }
         else if (operation==2)
         {
             for(int i=0;i<=rows;i++)
                 for(int j=0;j<=cols;j++)
                     Matrix_C[i][j]=Matrix_A[i][j]-Matrix_B[i][j];
         }
         PrintMatrix(rows,cols,Matrix_C);
         }
     
     void Matrix::Multiply() //multiplies 2 matrices
     {
         int rows1,cols1,rows2,cols2;
         cout<<"Enter the number of rows for the first matrix: "<<endl; 
         cin>>rows1;
         cout<<"Enter the number of columns for the first matrix: "<<endl; 
         cin>>cols1;
         cout<<"Enter the number of rows for the second matrix: "<<endl; 
         cin>>rows2;
         cout<<"Enter the number of columns for the second matrix: "<<endl;
         cin>>cols2;
         if(rows1==cols2)
         {
             float Matrix_A[rows1][MAX_COL],Matrix_B[rows2][MAX_COL],Matrix_C[
             for(int i=0;i<rows1;i++)
                 for(int j=0;j<cols2;j++)
                     Matrix_C[i][j]=0;
             cout<<"Enter the elements of the first matrix: "<<endl;
             ReadMatrix(rows1,cols1,Matrix_A);
             cout<<"Enter the elements of the second matrix: "<<endl;
             ReadMatrix(rows2,cols2,Matrix_B);
             for(int i=0;i<rows1;i++)
                 for(int j=0;j<cols1;j++)
                     for(int z=0;z<cols2;z++)
                         Matrix_C[i][z]=Matrix_C[i][z]+(Matrix_A[i][j]*Matrix_
             PrintMatrix(rows1,cols2,Matrix_C);
         }
         else
             cout<<"The number of the first matrix's rows must be the "
             <<"same as the second one's columns."<<endl; 90:     }
     
     float Matrix::Find_Determinant(int rows,float Matrix[][MAX_COL]) //finds 93:     {
         float det=0;
         if(rows==1)
             return Matrix[0][0];
         float temp[rows][MAX_COL]; //Storing cofactors
         int sign=1; //Storing signs
         
         for(int i=0;i<rows;i++)
         {
             Find_Cofactor(Matrix,temp,0,i,rows);
             det+=sign*Matrix[0][i]*Find_Determinant(rows-1,temp);
             sign=-sign;
         }
         return det; 
     }
     
     void Matrix::Find_Cofactor(float Matrix[][MAX_COL],float temp[][MAX_COL], 110:     {
         int row=0,col=0;
         for(int i=0;i<rows;i++)
         {
             for(int j=0;j<rows;j++)
             {
                 if((i!=z)&&(j!=loop))
                 {
                     temp[row][col++]=Matrix[i][j];
                     if(col==rows-1)
                     {
                         col=0;
                         row++;
                     }
                 }
             }
         } 
     }
     
   void Matrix::Adjoint(float Matrix_A[][MAX_COL],float Matrix_C[][MAX_COL], 130:     {
     float temp[rows_cols][MAX_COL];
     int sign=1;
         for(int i=0;i<rows_cols;i++)
         {
             for(int j=0;j<rows_cols;j++)
             {
                 Find_Cofactor(Matrix_A,temp,i,j,rows_cols);
                 sign=((i+j)%2==0)?1:-1;
                 Matrix_C[j][i]=(sign)*(Find_Determinant(rows_cols-1,temp));
             }
         }
     }
     bool Matrix::Inverse()
     {
         int rows;
         cout<<"Enter the number of rows and columns for the matrix: "<<endl;
         cin>>rows;
         float Matrix_C[rows][MAX_COL],Matrix_A[rows][MAX_COL];
         cout<<"Enter the elements of the matrix: "<<endl;
         ReadMatrix(rows,rows,Matrix_A);
         int sign=1;
         float det=Find_Determinant(rows,Matrix_A);
         if (det==0)
         {
         cout<<"Singular matrix, can't find it's inverse"<<endl;
           return false; 
         }
         
         float adj[rows][MAX_COL];
         Adjoint(Matrix_A,adj,rows);
         float A[rows][MAX_COL];
         for(int i=0;i<rows;i++)
             for(int j=0;j<rows;j++)
                 A[i][j]=adj[i][j]/det;
         PrintMatrix(rows,rows,A);
        return true; }   
