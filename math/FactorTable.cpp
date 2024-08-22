int arr[MXN];
void init(){
    for(int i=1;i<MXN;++i) for(int j=i;j<MXN;j+=i) arr[j]++;
}