# include <iostream>
# include <iomanip>

using namespace std;

inline int L (int x) { return 6*x-1; }
inline int P (int x) { return 6*x+1; }

inline int e1 (int x, int y) { return L(x)*y+x; }
inline int e2 (int x, int y) { return P(x)*y+x; }
inline int e3 (int x, int y) { return L(x)*y-x; }

bool spr (int *p, int *q, int n)
{
    while (n-->0) if (*p++!=*q++) return false;
    return true;
}

int por (int *p, int *q, int n, int pocz=0) // wynikiem jest pozycja z bledem + 1
{
    p+=pocz, q+=pocz;
    for (int i=pocz; i<n; i++) if (*p++!=*q++) return i+1;
    return 0;
}

void roznice (int *p, int *q, int n)
{
    for (int pocz=por(p,q,n); pocz; pocz=por(p,q,n,pocz)) cerr<<(pocz-1)<<endl;
}

int main ()
{
    cout<<setiosflags(ios::showpoint|ios::fixed)<<setprecision(3);
    cerr<<setiosflags(ios::showpoint|ios::fixed)<<setprecision(3);
    ;
    int N = 1000000;
    cerr<<"(rozmiar tablicy) N = ";
    cin>>N;
    if (!cin||N<1||N>1000000000) { cerr<<"zle dane (N)"<<endl; return 0; }
    if (N%6) N = N+6-N%6;
    int *era = new int[N];
    int *tab = new int[N];
int *licz = new int[N];
    ;
    clock_t start, stop; double dt;
    int comp, set0;
    ;
    ;
    start = clock(); // - czas start -
    era[0] = era[1] = 0;
    for (int n=2; n<N; era[n++]=1);
    comp=0, set0=0;
    for (int n=2; n*n<=N; n++)
    {
        if (comp++, era[n]) for (int k=n+n; k<N; k+=n) set0++, era[k] = 0;
    }
    stop = clock(); // - czas stop -
    dt = (double)(stop-start)/CLOCKS_PER_SEC; // - pomiar czasu -
    ;
    cerr<<"czas : "<<dt<<" [s]"<<endl;
    cerr<<"liczba porownan   : "<<setw(8)<<comp<<"\t"<<((double)comp/N)<<endl;
    cerr<<"liczba podstawien : "<<setw(8)<<set0<<"\t"<<((double)set0/N)<<endl<<endl;
    ;
    /*;
    start = clock(); // - czas start -
    tab[0] = tab[1] = 0;
    for (int n=2; n<N; tab[n++]=1);
    comp=0, set0=0;
    for (int n=2; n<N; n++)
    {
        if (comp++, tab[n]) for (int k=n+n; k<N; k+=n) set0++, tab[k] = 0;
    }
    stop = clock(); // - czas stop -
    dt = (double)(stop-start)/CLOCKS_PER_SEC; // - pomiar czasu -
    ;
    cerr<<"czas : "<<dt<<" [s]"<<endl;
    cerr<<"liczba porownan   : "<<setw(8)<<comp<<"\t"<<((double)comp/N)<<endl;
    cerr<<"liczba podstawien : "<<setw(8)<<set0<<"\t"<<((double)set0/N)<<endl<<endl;
    ;*/
    ;
    start = clock(); // - czas start -
    for (int n=0; n<N; tab[n++]=0, tab[n++]=1, tab[n++]=0, tab[n++]=0, tab[n++]=0, tab[n++]=1)
licz[n]=0;
    tab[1] = 0, tab[2] = tab[3] = 1;
    comp=0, set0=0;
    for (int x=1, v=L(e1(x,1)); v<N; x++, v=L(e1(x,1)))
        for (int y=1, z=L(e1(x,y)); z<N; y++, z=L(e1(x,y)))
            set0++, tab[z] = 0,
licz[z]++;
    for (int x=1, v=P(e2(x,1)); v<N; x++, v=P(e2(x,1)))
        for (int y=1, z=P(e2(x,y)); z<N; y++, z=P(e2(x,y)))
            set0++, tab[z] = 0,
licz[z]++;
    for (int x=1, v=P(e3(x,1)); v<N; x++, v=P(e3(x,1)))
        for (int y=1, z=P(e3(x,y)); z<N; y++, z=P(e3(x,y)))
            set0++, tab[z] = 0,
licz[z]++;
    stop = clock(); // - czas stop -
    dt = (double)(stop-start)/CLOCKS_PER_SEC; // - pomiar czasu -
    ;
    cerr<<"czas : "<<dt<<" [s]"<<endl;
    cerr<<"liczba porownan   : "<<setw(8)<<comp<<"\t"<<((double)comp/N)<<endl;
    cerr<<"liczba podstawien : "<<setw(8)<<set0<<"\t"<<((double)set0/N)<<endl<<endl;
    ;
    ;
    cerr<<"porownanie sit : "<<(spr(era,tab,N)?"==":"!=")<<endl;
    roznice(era,tab,N);
for (int i=0; i<N; i++) if (licz[i]>1) cerr<<i<<"("<<licz[i]<<") "; cerr<<endl;
    ;
    ;
    delete[] era;
    delete[] tab;
    return 0;
}
