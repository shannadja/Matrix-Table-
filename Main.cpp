#include <iostream> 
 using namespace std;
 
 #include <iomanip>
 #include "Matrix.h" 
 
 int main()
 {
     int oper,rows1,columns1,rows2,columns2;
     do
     {
         cout<<"Press 1 for Addition\n"                      
         <<setw(6)<<"2 for Substraction\n"
         <<setw(6)<<"3 for Multiplication\n"
         <<setw(6)<<"4 for Inverse\n"
         <<setw(6)<<"5 to EXIT\n";
         cin>>oper;
         Matrix Matrix1;
         switch(oper)
         {
             case 1:
             case 2:
                 Matrix1.AddSubtract(oper); 
                 break;
             case 3:
                 Matrix1.Multiply();
                 break;
             case 4:                 
                 Matrix1.Inverse(); 
                 break;
             case 5: 
                 break; 
             
             default:
                 cout<<"Wrong operation, you must choose between 1-4."<<endl;
                 break;
             }
             }while(oper!=5); 
              
         return 0;
         }
