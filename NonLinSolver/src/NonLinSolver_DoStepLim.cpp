/*
	Member Do_Step_limit of the class NonLinSolver
	written by Ehsan Nedaaee Oskoeee. 	
*/


#include "nonlinsolver.h"

inline double sgn(double a){return (a!=0 ? fabs(a)/a : 0);}

void NonLinSolver::Do_Step_Limit(double x[], double xold[]){

	double gamma = 1.3;
	double kcof = 1.e13;
	double Sn;
	
	int k, p, n, mi;
	double Vd, Vdold, Vc;
	double Vt, Mob, Isat;

//cout<<" value of x before doing stamp correction is:\n";
//for(int i=1; i<=nlnp; i++) cout<<"========<< x["<<i<<"] = "<<x[i]<<"\t\t xold["<<i<<"] ="<<xold[i]<<'\n';

/*
	for(int i=1; i<= NumNonLinElement; i++){
		
		k = non_lin_list[i];
		
		if(Elm[k].get_Kind()=="Diode")
		{
			p = Elm[k].get_Port1();
			n = Elm[k].get_Port2();
			Vd = x[p] - x[n];
			Vdold = xold[p] - xold[n];

			mi = Elm[k].get_ModelIndex();

			Vt 	= Mdl[mi].vals("Vt");
			Isat	= Mdl[mi].vals("Is");
			Mob	= Mdl[mi].vals("mob");
			
			Vc = Mob*Vt*log(Mob*Vt/(Isat*sqrt(2.)));
		
			if(Vd>Vc){

				if(x[p]>x[n]){
					x[p] = xold[p] + Mob*Vt*log(1.+(Vd-Vdold)/(Mob*Vt));
//					x[p] = xold[p] + Mob*Vt*log(1.+(x[p]-xold[p])/(Mob*Vt));
				}else{
					x[n] = xold[n] + Mob*Vt*log(1.+(Vd-Vdold)/(Mob*Vt));			
//					x[n] = xold[n] + Mob*Vt*log(1.+(x[n]-xold[n])/(Mob*Vt));			
				}
			}
		}
	}
*/

/*

	for (int i=1; i<=nlnp; i++){
		Sn = x[i] - xold[i];
		x[i] = xold[i] + (gamma/kcof)*sgn(Sn)*log(1.+kcof*fabs(Sn));
	}
*/

//cout<<" value of x after doing stamp correction is:\n";
//for(int i=1; i<=nlnp; i++) cout<<"========<< x["<<i<<"] = "<<x[i]<<"\t\t xold["<<i<<"] ="<<xold[i]<<'\n';



 }


