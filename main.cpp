#define ARMA_DONT_USE_WRAPPER
#include <iostream>
#include <cmath>
#include <string>
#include <armadillo>
#include "cell.h"
#include "mesh.h"

using namespace arma ;
using namespace std ;


//fonction second membre

double f(double x){
    return x+2;
}

//methode de quadrature gauss 3 pts

double gauss(double a, double b, double h(double) ){
    vec wj={ 5./9, 8./9, 5./9};
    vec xj={-sqrt(3/5), 0,sqrt(3/5) };
    double I;
    I=0;
    for (int k=0; k<=2; ++k) {
        I=I+wj(k)*h( 0.5*(a+b)+(b-a)*xj(k)*0.5);
    }
    I=I*(b-a)*0.5;
    return I;
}


int main()
{
//initialisation
    double (*pf ) ( double); // pointeur
    pf=f ;
    int N=100;
    double a=0;
    double b=1;

Mesh M=Mesh(a,b,N)  ;// creation maillage




// Construction second membre
  vec B(N, fill::zeros);
  double xg(0.);
  double xd(0.);
  for (int i=1; i<N ; ++i) {
       Cell K(i,0,1);
       K= *M.get_cel(i);
       xg=K.get_ctg();
       xd=K.get_ctd();
       //std::cout << gauss(xg , xd, pf) << std::endl;
       B(i)=gauss(xg , xd, pf);

  }

// Matrice A
mat A(N, N, fill::zeros);

  A.diag()+=2./M.m_h;
  A.diag(-1)-=1./M.m_h ;
  A.diag(1)-=1./M.m_h ;

  //resolution
  vec U( N, fill::zeros);//vecteur solution approchee

  U=solve( A, B);
// sauvegarde dans un fichier pour tracer avec gnuplot
  FILE *f;
      f= fopen("vof1d.dat","w");
      for (int j=1;j<= N;++j){

              fprintf(f,"%lf %lf \n",(j-1)*M.m_h, U(j-1));

      }
      fclose(f);


	return 0;
}
