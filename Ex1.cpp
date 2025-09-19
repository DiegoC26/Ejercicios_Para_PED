/*1. Crea un programa que:
    - Genere un arreglo de 20 números aleatorios entre 1 y 100.
    - Implemente funciones para:
        - Contar cuántos son pares e impares.
        - Encontrar el segundo mayor y el segundo menor.
        - Invertir el arreglo (sin usar otro arreglo auxiliar).
        */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
const int n = 20;
int arr[n];
void gA(int arr[], int n);
void par(int arr[], int n);
void segundoM(int arr[],int n);
void segundoMe(int arr[],int n);
void InvertA(int arr[], int n);
int main()
{
  srand(time(0));
  gA(arr, n);
  par(arr, n);
  segundoM(arr, n);
  segundoMe( arr, n);
  InvertA( arr,n);
  return 0;
}
void gA(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 99 + 1;
    cout << arr[i] << "\t"<<endl;;
  }
};
void par(int arr[], int n)
{
  int pares = 0, impares = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 0)
    {
      pares++;
    }
    else{
    impares++;
    }
  }
  cout << "Hay " << pares++ << " pares " << " Hay " << impares++ << " impares" << endl;
};
void segundoM(int arr[],int n){
 int mayor=arr[0], seg_mayor=-1;
 for (int i = 0; i < n; i++)
 {
   if (arr[i]>mayor) {
   mayor=arr[i];
   }
 }
 for (int i = 0; i < n; i++)
 {
   if (arr[i] != mayor && arr[i]>seg_mayor)
   {
    seg_mayor=arr[i];
   }
   
 }
 
 cout<<"El segundo numero mayor del arreglo es: "<< seg_mayor<<endl;

};
void segundoMe(int arr[],int n){
  int menor=arr[0], seg_menor=9999;
 for (int i = 0; i < n; i++)
 {
   if (arr[i]<menor) {
   menor=arr[i];
   }
 }
 for (int i = 0; i < n; i++)
 {
   if (arr[i] != menor && arr[i]<seg_menor)
   {
    seg_menor=arr[i];
   }
   
 }
 
 cout<<"El segundo numero menor del arreglo es: "<< seg_menor<<endl;

};
void InvertA(int arr[], int n){
cout<<"Array invertido"<<endl;
  for (int i = n-1; i >= 0; i--)
  {
   cout<<arr[i]<<endl;
  }
};
