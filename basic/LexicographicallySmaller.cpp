template<class T> //字典序a嚴格小於b
bool lexicographicallySmaller(const vector<T> &a,const vector<T> &b){
    int n=a.size(), m=b.size();
    int i;
    for(int i=0;i<n && i<m;++i){
        if(a[i]<b[i])return true;
        else if(b[i]<a[i])return false;
    }
    return (i==n && i<m);
}