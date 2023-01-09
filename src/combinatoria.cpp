#include <iostream>
#include <cmath>
using namespace std;
#include "utilitario.h"

int main()
{
char items[] = {'a','b','c','d','e','f','g','h','i'};
    int n,r;
    char** matriz;
    int size;

    cout<<"\n N:"; cin>>n;
    cout<<"\n R:"; cin>>r;
    cout<<"\n Elementos disponibles: "<<n<<" => [";
    for(int x=0; x<n; x++){
        cout<<items[x];
        if(x<n-1){
            cout<<", ";
        }else{
            cout<<"]";
        }
    }
    CombinacionSR(items,n,r);

    return 0;
}