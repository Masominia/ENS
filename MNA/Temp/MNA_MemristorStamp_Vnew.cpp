/*
	Class member MemristorStamp of the class mnamatrix
	written by Ehsan Nedaaee Oskoee
	
*/


#include "mnamatrix.h"

 void MNA_Matrix::MemristorStamp(int a, double* Vx){

	int p, n, ir, mi, kind;

	double Un, Uo;
	double alpha, Rof, gq, Phio, Phin;
	double Qo, Qn, idt;
	double Geq, Ieq, Sr, Req;
	double Gon, Gof;
	double Kh, Kp;

	p = Elm[a].get_Port1();
	n = Elm[a].get_Port2();


	mi = Elm[a].get_ModelIndex();
	ir = Elm[a].get_GroupIndex();

	kind= Mdl[mi].vals("kind");
	Rof = Mdl[mi].vals("Rof");
	alpha = Mdl[mi].vals("alpha");

	Un = Vx[p] - Vx[n];
	Uo = uxtold[p] - uxtold[n];

	Qo = uxtold[ir];
	Qn = Vx[ir];

	idt = 1./Delt;

	gq = Rof*(1.-alpha*Qn);
	Kh = idt*Rof*(1.- alpha*Qn)*(Qn-Qo);
	Kp = idt*(-2.*alpha*Rof*Qn+alpha*Rof*Qo+Rof);
	
	Geq = 1./Kp;
	Req = Kp;
	Ieq = -Kh/Kp + Qn;

	Sr = Un -gq*idt*(Qn - Qo);

	if(p>0){
		ndmna[p](p) = ndmna[p][p] + idt*Geq;//Req;
		ndmna[ir](p) = ndmna[ir][p] - Geq;//1./gq;
		ndrval[p] += -(Ieq-Qo)*idt;
	}

	if(n>0){
		ndmna[n](n) = ndmna[n][n] + idt*Geq;//Req;
		ndmna[ir](n) = ndmna[ir][n] + Geq;//1./gq;
		ndrval[n] += (Ieq-Qo)*idt;
	}
	if((p>0)&&(n>0)){
		ndmna[p](n) = ndmna[p][n] - idt*Geq;//Req;
		ndmna[n](p) = ndmna[n][p] - idt*Geq;//Req;
	}
	ndmna[ir](ir) = ndmna[ir][ir] +1.;//idt;
	ndrval[ir] += Ieq;//Qo*idt;
	Dg[ir] += Sr;

 }
