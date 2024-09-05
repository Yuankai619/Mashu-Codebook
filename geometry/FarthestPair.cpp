ld FarthestPair(vector<Pt>& poly){//旋轉卡尺 
    ld ret=0;
    for(int i = 0, j = i+1; i<poly.size()&& j<poly.size(); i++){
        while( Length(poly[i]-poly[j]) <= Length(poly[i]-poly[(j+1)%poly.size()]) && j!=i)
            j = (j+1) % poly.size();
        ret = max(ret, Length(poly[i]-poly[j]));
    }
    return ret;
}