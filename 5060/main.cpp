#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double dINF=200000000;
int h,c;
double loc[201], minErr[201][201], err[201][201];

inline double linear_interpolate(int st,int ed,int k) {
    double t= loc[st];
    double another=(double)(k-st)/(ed-st);
    t+=(loc[ed]-loc[st])*another;
    return t;
}

    double Abs(double k) {
    if(k < 0) return -k;
    return k;
}

int main()
{
    int T;
    scanf("%d",&T);

    while(T--) {
        scanf("%d %d",&h,&c);
        for(int i=1; i<=h; i++) {
            scanf("%lf",&loc[i]);
        }

        //preprocess
        for(int i=1; i<h; i++) {
            for(int j=i+1; j<=h; j++) {
                double sum=0;
                for(int k=i+1; k<j; k++) {
                    sum+=Abs(loc[k]-linear_interpolate(i,j,k));
                }
                err[i][j]=sum;
            }
        }

        //dp

        for(int i=h-1; i>=1; i--) {
            for(int r=2; r <= c; r++) {
                if(r == 2) {
                    minErr[i][r]=err[i][h];
                }
                else {
                    minErr[i][r]=dINF;
                    for(int j=h-r+2; j>=i+1; j--) {
                        minErr[i][r]=min(minErr[i][r],minErr[j][r-1]+err[i][j]);
                    }
                }
            }
        }
        printf("%.4lf\n",minErr[1][c]/(double)h);

    }
    return 0;
}
