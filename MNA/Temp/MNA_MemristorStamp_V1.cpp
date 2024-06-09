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

	Un = Vx[p] - Vx[n];
	Uo = uxtold[p] - uxtold[n];

	mi = Elm[a].get_ModelIndex();
	ir = Elm[a].get_GroupIndex();

	kind= Mdl[mi].vals("kind");
	Rof = Mdl[mi].vals("Rof");
	alpha = Mdl[mi].vals("alpha");


//	Rof = 160.e0;
//	alpha = 1.e0;
//	Gon = 1e0;
//	Gof = 1e-6;

	Qo = uxtold[ir];
	Qn = Vx[ir];
//	Qn = Qo + Delt/(Rof*(1.-alpha*Qn))*Un;
	idt = 1./Delt;

	gq = Rof*(1.-alpha*Qn);
	Kh = idt*Rof*(1.- alpha*Qn)*(Qn-Qo);
	Kp = idt*(-2.*alpha*Rof*Qn+alpha*Rof*Qo+Rof);
	
	Geq = 1./Kp;
	Req = Kp;
	Ieq = -Kh/Kp + Qn;
/*
	Qn = Geq*Un+Ieq;

	gq = Rof*(1.-alpha*Qn);
	Kh = idt*Rof*(1.- alpha*Qn)*(Qn-Qo);
	Kp = idt*(-2.*alpha*Rof*Qn+alpha*Rof*Qo+Rof);
	
	Geq = 1./Kp;
	Req = Kp;
	Ieq = -Kh/Kp + Qn;
*/
	Sr = Un -gq*idt*(Qn - Qo);
//	Sr = -gq*idt*(Qn-Qo);

//	Sr = gq;//*idt*(Qn -Qo);
//	Sr = Un/gq -idt*(Qn-Qo);
//	Sr = (Geq*(Vx[p]-Vx[n])+Ieq)/(Un-Uo);
//	Sr = Req*Qn+Ieq*Req;
//	Sr = Qo/(Un-Uo)+Delt/gq;
//	Sr = Qo + Delt*(Un-Uo)/gq;
//	Sr = -idt*gq*(Qn - Qo);
//	Sr = (alpha*Gon*Phin+Gof);

/*
	Phi = Rof*Qq*(1.-alpha*Qq/2.);
	Phin= Rof*Qn*(1.-alpha*Qn/2.);
	An = Rof*(1.-alpha*Qn);
	Bn = Rof*alpha*Qn*Qn/2.;
*/
/*
//	charge controlled memristor
	Sr = idt*(An*Qn+Bn-Phi);
	Sr = Phin;
	Sr = Un*Delt/An - Bn+Phi;
	Sr  = 1./An;
	Geq = An*idt;
	Ieq = (Bn-Phi)*idt;
*/

//	flux controlled memristor

//	Qo = 0.5*alpha*Gon*Phio*Phio + Gof*Phio;
//	Qn = 0.5*alpha*Gon*Phin*Phin + Gof*Phin;
	
//	An = alpha*Gon*Phin+Gof;
//	Bn = -0.5*alpha*Gon*Phin*Phin;

//	Sr = Qn*idt*(Phin-Phio);
	
/*
	if(p>0){
		ndmna[p](ir) = ndmna[p][ir] + idt*An;
		ndmna[ir](p) = ndmna[ir][p] + 1.;
		ndrval[p] += (Qo-Bn)*idt;
		Dg[p]	+= Sr;
	}

	if(n>0){
		ndmna[n](ir) = ndmna[n][ir] - idt*An;
		ndmna[ir](n) = ndmna[ir][n] - 1.;
		ndrval[n] += (Bn-Qo)*idt;
		Dg[n] 	+= -Sr;
	}
	ndmna[ir](ir) = ndmna[ir][ir] - idt;
	ndrval[ir] += -idt*Phio;
*/
/*
	if(p>0){
		ndmna[p](ir) = ndmna[p][ir] +  idt;
		ndmna[ir](p) = ndmna[ir][p] +  1.;//idt;
		ndrval[p] += -Ieq;
		Dg[p]	+= Sr;
	}

	if(n>0){
		ndmna[n](ir) = ndmna[n][ir] - idt;
		ndmna[ir](n) = ndmna[ir][n] - 1.;//idt;
		ndrval[n] += Ieq;
		Dg[n] 	+= -Sr;
	}
	ndmna[ir](ir) = ndmna[ir][ir] - Req;
//	ndrval[ir] += Ieq;

*/

	if(p>0){
		ndmna[p](p) = ndmna[p][p] + idt*Geq;//Req;
		ndmna[ir](p) = ndmna[ir][p] - Geq;//1./gq;
//		ndmna[p](ir) = ndmna[p][ir] + idt;
		ndrval[p] += -(Ieq-Qo)*idt;
//		Dg[p]	+= Sr;
	}

	if(n>0){
		ndmna[n](n) = ndmna[n][n] + idt*Geq;//Req;
		ndmna[ir](n) = ndmna[ir][n] + Geq;//1./gq;
//		ndmna[n](ir) = ndmna[n][ir] - idt;
		ndrval[n] += (Ieq-Qo)*idt;
//		Dg[n] 	-= Sr;
	}
	if((p>0)&&(n>0)){
		ndmna[p](n) = ndmna[p][n] - idt*Geq;//Req;
		ndmna[n](p) = ndmna[n][p] - idt*Geq;//Req;
	}
	ndmna[ir](ir) = ndmna[ir][ir] +1.;//idt;
	ndrval[ir] += Ieq;//Qo*idt;
	Dg[ir] += Sr;

 }
