vector<int> vec;
sort(vec.begin(),vec.end()); 
vec.resize(unique(vec.begin(),vec.end())-vec.begin());
for(int i=0;i<n;++i){//+1是讓 index是1到N 可以不要
    arr[i]=lower_bound(vec.begin(),vec.end(),ll[i])-vec.begin()+1;
}
