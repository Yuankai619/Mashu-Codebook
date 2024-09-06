double eps = 1e-15;
double learning_rate = 0.99;
const int MT_MAX = 1000;
double ans_energy = 1e18;
double ansx, ansy;
void sa(double x, double y) {
    double nowx=x, nowy=y;
    double T = 10000;
    while(T>eps) {
        double getx = nowx + (RAND()*2-MT_MAX)*T;
        double gety = nowy + (RAND()*2-MT_MAX)*T;
        double energy = get_energy(getx, gety);
        double delta = energy-ans_energy;
        if(energy<ans_energy) {
            ansx = nowx = getx;
            ansy = nowy = gety;
            ans_energy = energy;
        } 
        // else if(RAND()/MT_MAX < exp(-delta/T)) {
        //     nowx = getx;
        //     nowy = gety;
        // }
        T = T*learning_rate;
    }
}