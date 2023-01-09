int ipfact(int n){
    int ipresp=1;
    for(int x=1; x<=n; x++){
        ipresp = ipresp * x;
    }
    return ipresp;
}

int ipfactR(int n){
    if(n==0){
        return 1;
    }else{
        return n*ipfactR(n-1);
    }
}

char** ipinitMatriz(int rows, int cols){
    char** ipmatriz;
    ipmatriz = new char*[rows];
    for(int x=0; x<rows; x++){
        ipmatriz[x] = new char[cols];
    }
    return ipmatriz;
}

void printMatriz(char** matriz,int rows, int cols){

    cout<<"\n";
    for(int x=0; x<rows; x++){
        cout<<"\n\t";
        for(int y=0; y<cols; y++){
            cout<<matriz[x][y]<<",";
        }
    }
}
void ipalmacenando(char* items,char** almacen,int r,int* indexs,int* indice){
    for(int k=0; k<r; k++){   
        almacen[*indice][k] = items[indexs[k]];
    }
    *indice = *indice + 1;
}

void ipinitParams(int r,int** indexs,int** cont){
    int tmp = 0;
    *cont = &tmp;
    *indexs = new int[r];
}

void ipcombinacionSR(char* items,char** almacen,int n,int r,int* indexs,int i,int *cont){
    if(i<r){
        if(i==0){
            ipinitParams(r,&indexs,&cont);
            indexs[i] = 0;
        }else{
            indexs[i] = indexs[i-1] + 1;
        }
        while(indexs[i]<n){
            ipcombinacionSR(items,almacen,n,r,indexs,i+1,cont);
            indexs[i] = indexs[i] + 1;
        }
    }else{
        ipalmacenando(items,almacen,r,indexs,cont);
    }
}

void ipCombinacionSR(char* items,int n,int r){
    char** ipmatriz;
    int ipsize;
    ipsize = ipfact(n)/ipfact(r)/ipfact(n-r);
    ipmatriz = ipinitMatriz(ipsize,r);
    ipcombinacionSR(items,ipmatriz,n,r,NULL,0,NULL);
    printf("\n\n ------------ Combinacion sin repeticion ------------ ");
    printf("\n Total de mezclas: %d",ipsize);
    printf("\n Lista de mezclas:");
    printMatriz(ipmatriz,ipsize,r);
}