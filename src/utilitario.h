int fact(int n){
    int resp=1;
    for(int x=1; x<=n; x++){
        resp = resp * x;
    }
    return resp;
}

int factR(int n){
    if(n==0){
        return 1;
    }else{
        return n*factR(n-1);
    }
}

char** initMatriz(int rows, int cols){
    char** matriz;
    matriz = new char*[rows];
    for(int x=0; x<rows; x++){
        matriz[x] = new char[cols];
    }
    return matriz;
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
void almacenando(char* items,char** almacen,int r,int* indexs,int* indice){
    for(int k=0; k<r; k++){   
        almacen[*indice][k] = items[indexs[k]];
    }
    *indice = *indice + 1;
}

void initParams(int r,int** indexs,int** cont){
    int tmp = 0;
    *cont = &tmp;
    *indexs = new int[r];
}

void combinacionSR(char* items,char** almacen,int n,int r,int* indexs,int i,int *cont){
    if(i<r){
        if(i==0){
            initParams(r,&indexs,&cont);
            indexs[i] = 0;
        }else{
            indexs[i] = indexs[i-1] + 1;
        }
        while(indexs[i]<n){
            combinacionSR(items,almacen,n,r,indexs,i+1,cont);
            indexs[i] = indexs[i] + 1;
        }
    }else{
        almacenando(items,almacen,r,indexs,cont);
    }
}

void CombinacionSR(char* items,int n,int r){
    char** matriz;
    int size;
    size = fact(n)/fact(r)/fact(n-r);
    matriz = initMatriz(size,r);
    combinacionSR(items,matriz,n,r,NULL,0,NULL);
    printf("\n\n ------------ Combinacion sin repeticion ------------ ");
    printf("\n Total de mezclas: %d",size);
    printf("\n Lista de mezclas:");
    printMatriz(matriz,size,r);
}