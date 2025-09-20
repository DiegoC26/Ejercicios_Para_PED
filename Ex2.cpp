/*2. Suma de vectores
    - Crea dos arreglos de tamaño n.
    - Implementa funciones para:
        - Llenar ambos arreglos con números enteros.
        - Calcular la suma elemento a elemento en un tercer arreglo.
        - Calcular el producto escalar de los dos vectores.
        */
#include <iostream>
using namespace std;
void TamanoA(int arr1[],int n);
void sumA(int arr1[],int arr2[],int resultado[],int n );
int escalarA(int arr1[],int arr2[],int n);
int main () {
    int n;
    
    cout<<"Ingrese el valor de los arrays"<<endl;
    cin>>n;
    int arr1[n],arr2[n],total[n];
    cout<<"Ingrese los valores del array 1"<<endl;
     TamanoA(arr1,n);
    cout<<"Ingrese los valores del array 2"<<endl;
    TamanoA(arr2,n);

    sumA(arr1,arr2,total,n);
 for ( int i = 0; i < n; i++)
 {
 cout<<"La suma de la posicion"<<"["<<i<<"]"<<"es "<<total[i]<<endl;
 }
 
 int esc= escalarA( arr1, arr2, n);

 cout<<"El producto del escalar es  :"<<esc<<endl;
return 0;
}
void TamanoA(int arr1[],int n) {
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el valor "<<"[ "<<i<<"]"<<endl;
        cin>>arr1[i];
    }
    
};
void sumA(int arr1[],int arr2[],int resultado[], int n ){
for (int i = 0; i < n; i++)
{
   resultado[i]=arr1[i]+ arr2[i];
}

};
int escalarA(int arr1[],int arr2[],int n){
    int resultado =0;
    for (int i = 0; i < n; i++)
    {
       resultado += arr1[i] * arr2[i];
    }
    
};
