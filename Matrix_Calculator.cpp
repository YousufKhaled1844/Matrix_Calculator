#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void Multiplication ( long long arr1[10][10] , long long arr2[10][10] , int r1 ,int c1 , int r2 , int c2 );
void Get_in (long long arr[][10], int R , int C);
long long Determinant (long long arr1[10][10] , int R1 , int C1);
void Adding_Matrices ( long long arr1[10][10] , long long arr2[10][10] , int n );
void Subtracting_Matrices (long long arr1[10][10] , long long arr2[10][10] , int n);
int main()
{
    cout << fixed << setprecision(0);
    int RA , CA , RB , CB , x ;
    cout << "Please enter dimensions of Matrix A:" << "\n";
    cin >> RA >> CA ;
    cout << "Please enter dimensions of Matrix B:" << "\n";
    cin >> RB >> CB ;
    long long A [10][10];
    long long B [10][10];
    cout << "Please enter values of Matrix A:" << "\n";
    Get_in(A,RA,CA);
    cout << "Please enter values of Matrix B:" << "\n";
    Get_in(B,RB,CB);
   for ( int w = 0 ; w != 7 ; w=w)
    {
    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << "\n" ;
    cin >> x ;
    if ( x == 1 )
    {
        if(RA != RB || CA != CB)
            cout << "The operation you chose is invalid for the given matrices." << "\n";
        else
        Adding_Matrices(A,B,RA);
    }
    else if ( x == 2)
    {
        if(RA != RB || CA != CB)
            cout << "The operation you chose is invalid for the given matrices." << "\n";
        else
       Subtracting_Matrices(A,B,RA);
    }
    else if ( x == 3)
    {
        if ( RA <= 0 || CA <= 0 || RB <= 0 || CB <= 0 || CA!=RB)
            cout << "The operation you chose is invalid for the given matrices." << "\n";
        else
        Multiplication ( A , B , RA , CA , RB , CB );
    }
    else if ( x == 5 )
    {
        if ( RA != CA)
            cout << "The operation you chose is invalid for the given matrices." << "\n";
        else
        {
            cout << Determinant(A , RA , CA);
         cout << "\n";
        }
    }
    else if ( x == 6 )
    {
        if ( RB != CB)
            cout << "The operation you chose is invalid for the given matrices." << "\n";
        else
        {
            cout << Determinant(B , RB , CB);
         cout << "\n";
        }
    }
    else if ( x == 7)
      {
          w=x;
          cout << "Thank you!";
      }
    }
return 0;
}
void Multiplication ( long long arr1[][10] , long long arr2[][10] , int r1 ,int c1 , int r2 , int c2 )
{
    long long arr3[r1][c2];
    for(int i=0 ; i < r1 ; i++)
    {
        for ( int j=0 ; j < c2 ; j++)
        {
            arr3[i][j]=0;
            for ( int k=0 ; k < c1 ; k++)
                {
                     arr3[i][j] += arr1[i][k] * arr2[k][j] ;
                }
        }
    }
    for ( int row = 0 ; row < r1 ; row++)
    {
        for (int col=0 ; col < c2 ; col++)
        {
         cout << arr3[row][col] << "\t";
         if (col == (c2-1))
           {
               cout << "\n";
           }
        }
    }
}
void Get_in (long long arr[][10], int R , int C)
{
    for ( int row = 0 ; row < R ; row++)
    {
        for (int col=0 ; col < C ; col++)
         cin >>  arr[row][col];
    }
}
long long Determinant (long long arr1[10][10] , int R1 , int C1)
{
    long double sum = 0 ;
    long long arr2[10][10];
    if ( R1 ==2)
           return arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0] ;
    else if ( R1 == 1)
        return arr1[0][0];
    else
    {
    for (int i = 0; i < R1; i++)
      {
         int r2 = 0;
         for (int r1 = 1; r1 < R1; r1++)
            {
               int c2 = 0;
                  for (int c1 = 0; c1 < C1; c1++)
                   {
                     if (c1 == i)
                              continue;
                     arr2[r2][c2] = arr1[r1][c1];
                     c2++;
                   }
               r2++;
            }
         sum +=  arr1[0][i] * (pow(-1, i)) * (Determinant( arr2 , R1-1 , C1-1 ));
      }
    }
    return sum ;
}
void Adding_Matrices ( long long arr1[10][10] , long long arr2[10][10] , int n  )
{
    int C [10][10];
    for ( int row = 0 ; row < n ; row++)
    {
        for (int col=0 ; col < n ; col++)
         C[row][col]=arr1[row][col]+arr2[row][col];
    }
         for ( int row = 0 ; row < n ; row++)
    {
        for (int col=0 ; col < n ; col++)
        {
         cout << C[row][col] << "\t";
         if ( col == n-1  )
            cout << "\n";
        }
    }
}
void Subtracting_Matrices (long long arr1[10][10] , long long arr2[10][10] ,int n)
{
    int C [10][10];
     for ( int row = 0 ; row < n ; row++)
    {
        for (int col=0 ; col < n ; col++)
         C[row][col]=arr1[row][col]-arr2[row][col];
    }
         for ( int row = 0 ; row < n ; row++)
      {
        for (int col=0 ; col < n ; col++)
        {
         cout << C[row][col] << "\t";
         if ( col == n-1  )
            cout << "\n";
        }
      }
}