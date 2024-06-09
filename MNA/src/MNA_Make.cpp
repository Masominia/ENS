/*

	 Class Make as a member of MNA 

	written by Ehsan Nedaaee Oskoee*/

#include "mnamatrix.h"

void MNA_Matrix::Make(double *Vx){

 	double idt;
 	if(Delt > 0.)  idt = 1./Delt;
	for(int i=1; i<=size; i++) {
		for(int j=1; j<=mna[i].size(); j++) mna[i](mna[i].row(j))=0.;
		rval[i] = 0.;
	}

 /* Elements of  V1 */ 
	auto Vt51 = [] (double t, double vs){
		double val;
		int ggqt;
		int ggqq;
		int ggqk;
		int ggqc;
		ggqt = t * 1.e10;
		val =0.;
			if(t>3000.e-5){
			if(t>4000.e-5){
				val = 0.;
			}else{
		ggqq = ggqt/300000;
		ggqc = ggqq * 3;
		ggqk = ggqc + 1;
		if(t > (ggqc*1.e-5)){
		if(t > (ggqk*1.e-5)){
			val = 0.;
		}
		else{
			val = 1.93;
			}
		}				

			}	
		}
			if(t>5000.e-5){
			if(t>15000.e-5){
				val = 0.;
			}else{
		ggqq = ggqt/300000;
		ggqc = ggqq * 3;
		ggqk = ggqc + 1;
		if(t > (ggqc*1.e-5)){
		if(t > (ggqk*1.e-5)){
			val = 0.;
		}
		else{
			val = 1.93;
			}
		}				

			}	
		}
			if(t>16000.e-5){
			if(t>17000.e-5){
				val = 0.;
			}else{
		ggqq = ggqt/300000;
		ggqc = ggqq * 3;
		ggqk = ggqc + 1;
		if(t > (ggqc*1.e-5)){
		if(t > (ggqk*1.e-5)){
			val = 0.;
		}
		else{
			val = 1.93;
			}
		}				

			}	
		}
		return val*vs;
	};
	rval[38] = rval[38] + Vt51(tm,Vs[1]);
	mna[1](38) = mna[1][38] + 1.;
	mna[38](1) = mna[38][1] + 1.;

 /* Elements of  V2 */ 
	auto Vt22 = [] (double t, double vs){
		double val;
		val = 1.75;
		return val*vs;
	};
	rval[39] = rval[39] + Vt22(tm,Vs[2]);
	mna[6](39) = mna[6][39] - 1.;
	mna[39](6) = mna[39][6] - 1.;

 /* Elements of  V3 */ 
	auto Vt23 = [] (double t, double vs){
		double val;
		val = 1.75;
		return val*vs;
	};
	rval[40] = rval[40] + Vt23(tm,Vs[3]);
	mna[10](40) = mna[10][40] + 1.;
	mna[40](10) = mna[40][10] + 1.;

 /* Elements of  V4 */ 
	auto Vt24 = [] (double t, double vs){
		double val;
		val = 1.75;
		return val*vs;
	};
	rval[41] = rval[41] + Vt24(tm,Vs[4]);
	mna[17](41) = mna[17][41] - 1.;
	mna[41](17) = mna[41][17] - 1.;

 /* Elements of  V5 */ 
	auto Vt25 = [] (double t, double vs){
		double val;
		val = 1.75;
		return val*vs;
	};
	rval[42] = rval[42] + Vt25(tm,Vs[5]);
	mna[21](42) = mna[21][42] + 1.;
	mna[42](21) = mna[42][21] + 1.;

 /* Elements of  V6 */ 
	auto Vt16 = [] (double t, double vs){
		double val;
		int ggqt;
		int ggqq;
		int ggqk;
		int ggqc;
		ggqt = t * 1.e10;
		val =0.;
			if(t>500.e-5){
			if(t>2500.e-5){
				val = 0.;
			}else{
		ggqq = ggqt/400000;
		ggqc = ggqq * 4;
		ggqk = ggqc + 1;
		if(t > (ggqc*1.e-5)){
		if(t > (ggqk*1.e-5)){
			val = 0.;
		}
		else{
			val = 1.93;
			}
		}				

			}	
		}
			if(t>5000.e-5){
			if(t>15000.e-5){
				val = 0.;
			}else{
		ggqq = ggqt/400000;
		ggqc = ggqq * 4;
		ggqk = ggqc + 1;
		if(t > (ggqc*1.e-5)){
		if(t > (ggqk*1.e-5)){
			val = 0.;
		}
		else{
			val = 1.93;
			}
		}				

			}	
		}
			if(t>17500.e-5){
			if(t>18500.e-5){
				val = 0.;
			}else{
		ggqq = ggqt/400000;
		ggqc = ggqq * 4;
		ggqk = ggqc + 1;
		if(t > (ggqc*1.e-5)){
		if(t > (ggqk*1.e-5)){
			val = 0.;
		}
		else{
			val = 1.93;
			}
		}				

			}	
		}
		return val*vs;
	};
	rval[43] = rval[43] + Vt16(tm,Vs[6]);
	mna[24](43) = mna[24][43] + 1.;
	mna[43](24) = mna[43][24] + 1.;

 /* Elements of  V7 */ 
	auto Vt27 = [] (double t, double vs){
		double val;
		val = 1.75;
		return val*vs;
	};
	rval[44] = rval[44] + Vt27(tm,Vs[7]);
	mna[29](44) = mna[29][44] - 1.;
	mna[44](29) = mna[44][29] - 1.;

 /* Elements of  V8 */ 
	auto Vt28 = [] (double t, double vs){
		double val;
		val = 1.75;
		return val*vs;
	};
	rval[45] = rval[45] + Vt28(tm,Vs[8]);
	mna[33](45) = mna[33][45] + 1.;
	mna[45](33) = mna[45][33] + 1.;

 /* Elements of  R1*/ 
	mna[1](46) = mna[1][46] + 1.;
	mna[46](1) = mna[46][1] + 1.;
	mna[2](46) = mna[2][46] - 1.;
	mna[46](2) = mna[46][2] - 1.;
	mna[46](46) = mna[46][46] - 1.e4;

 /* Elements of  R2*/ 
	mna[2](47) = mna[2][47] + 1.;
	mna[47](2) = mna[47][2] + 1.;
	mna[3](47) = mna[3][47] - 1.;
	mna[47](3) = mna[47][3] - 1.;
	mna[47](47) = mna[47][47] - 5.e3;

 /* Elements of  R3*/ 
	mna[3](48) = mna[3][48] + 1.;
	mna[48](3) = mna[48][3] + 1.;
	mna[4](48) = mna[4][48] - 1.;
	mna[48](4) = mna[48][4] - 1.;
	mna[48](48) = mna[48][48] - 24.e2;

 /* Elements of  R4*/ 
	mna[5](49) = mna[5][49] + 1.;
	mna[49](5) = mna[49][5] + 1.;
	mna[6](49) = mna[6][49] - 1.;
	mna[49](6) = mna[49][6] - 1.;
	mna[49](49) = mna[49][49] - 5.e1;

 /* Elements of  R5*/ 
	mna[3](50) = mna[3][50] + 1.;
	mna[50](3) = mna[50][3] + 1.;
	mna[7](50) = mna[7][50] - 1.;
	mna[50](7) = mna[50][7] - 1.;
	mna[50](50) = mna[50][50] - 15.e3;

 /* Elements of  R6*/ 
	mna[7](51) = mna[7][51] + 1.;
	mna[51](7) = mna[51][7] + 1.;
	mna[8](51) = mna[8][51] - 1.;
	mna[51](8) = mna[51][8] - 1.;
	mna[51](51) = mna[51][51] - 24.e2;

 /* Elements of  R7*/ 
	mna[9](52) = mna[9][52] + 1.;
	mna[52](9) = mna[52][9] + 1.;
	mna[10](52) = mna[10][52] - 1.;
	mna[52](10) = mna[52][10] - 1.;
	mna[52](52) = mna[52][52] - 5.e1;

 /* Elements of  R8*/ 
	mna[7](53) = mna[7][53] + 1.;
	mna[53](7) = mna[53][7] + 1.;
	mna[11](53) = mna[11][53] - 1.;
	mna[53](11) = mna[53][11] - 1.;
	mna[53](53) = mna[53][53] - 5.e4;

 /* Elements of  R28*/ 
	mna[11](54) = mna[11][54] + 1.;
	mna[54](11) = mna[54][11] + 1.;
	mna[37](54) = mna[37][54] - 1.;
	mna[54](37) = mna[54][37] - 1.;
	mna[54](54) = mna[54][54] - 1.e0;

 /* Elements of  R9*/ 
	mna[12](55) = mna[12][55] + 1.;
	mna[55](12) = mna[55][12] + 1.;
	mna[13](55) = mna[13][55] - 1.;
	mna[55](13) = mna[55][13] - 1.;
	mna[55](55) = mna[55][55] - 1.e0;

 /* Elements of  R10*/ 
	mna[13](56) = mna[13][56] + 1.;
	mna[56](13) = mna[56][13] + 1.;
	mna[14](56) = mna[14][56] - 1.;
	mna[56](14) = mna[56][14] - 1.;
	mna[56](56) = mna[56][56] - 5.e3;

 /* Elements of  R11*/ 
	mna[14](57) = mna[14][57] + 1.;
	mna[57](14) = mna[57][14] + 1.;
	mna[15](57) = mna[15][57] - 1.;
	mna[57](15) = mna[57][15] - 1.;
	mna[57](57) = mna[57][57] - 24.e2;

 /* Elements of  R12*/ 
	mna[16](58) = mna[16][58] + 1.;
	mna[58](16) = mna[58][16] + 1.;
	mna[17](58) = mna[17][58] - 1.;
	mna[58](17) = mna[58][17] - 1.;
	mna[58](58) = mna[58][58] - 5.e1;

 /* Elements of  R13*/ 
	mna[14](59) = mna[14][59] + 1.;
	mna[59](14) = mna[59][14] + 1.;
	mna[18](59) = mna[18][59] - 1.;
	mna[59](18) = mna[59][18] - 1.;
	mna[59](59) = mna[59][59] - 15.e3;

 /* Elements of  R14*/ 
	mna[18](60) = mna[18][60] + 1.;
	mna[60](18) = mna[60][18] + 1.;
	mna[19](60) = mna[19][60] - 1.;
	mna[60](19) = mna[60][19] - 1.;
	mna[60](60) = mna[60][60] - 24.e2;

 /* Elements of  R15*/ 
	mna[20](61) = mna[20][61] + 1.;
	mna[61](20) = mna[61][20] + 1.;
	mna[21](61) = mna[21][61] - 1.;
	mna[61](21) = mna[61][21] - 1.;
	mna[61](61) = mna[61][61] - 5.e1;

 /* Elements of  R16*/ 
	mna[18](62) = mna[18][62] + 1.;
	mna[62](18) = mna[62][18] + 1.;
	mna[22](62) = mna[22][62] - 1.;
	mna[62](22) = mna[62][22] - 1.;
	mna[62](62) = mna[62][62] - 5.e4;

 /* Elements of  R17*/ 
	mna[22](63) = mna[22][63] + 1.;
	mna[63](22) = mna[63][22] + 1.;
	mna[23](63) = mna[23][63] - 1.;
	mna[63](23) = mna[63][23] - 1.;
	mna[63](63) = mna[63][63] - 1.e4;

 /* Elements of  R18*/ 
	mna[24](64) = mna[24][64] + 1.;
	mna[64](24) = mna[64][24] + 1.;
	mna[25](64) = mna[25][64] - 1.;
	mna[64](25) = mna[64][25] - 1.;
	mna[64](64) = mna[64][64] - 1.e4;

 /* Elements of  R19*/ 
	mna[25](65) = mna[25][65] + 1.;
	mna[65](25) = mna[65][25] + 1.;
	mna[26](65) = mna[26][65] - 1.;
	mna[65](26) = mna[65][26] - 1.;
	mna[65](65) = mna[65][65] - 5.e3;

 /* Elements of  R20*/ 
	mna[26](66) = mna[26][66] + 1.;
	mna[66](26) = mna[66][26] + 1.;
	mna[27](66) = mna[27][66] - 1.;
	mna[66](27) = mna[66][27] - 1.;
	mna[66](66) = mna[66][66] - 24.e2;

 /* Elements of  R21*/ 
	mna[28](67) = mna[28][67] + 1.;
	mna[67](28) = mna[67][28] + 1.;
	mna[29](67) = mna[29][67] - 1.;
	mna[67](29) = mna[67][29] - 1.;
	mna[67](67) = mna[67][67] - 5.e1;

 /* Elements of  R22*/ 
	mna[26](68) = mna[26][68] + 1.;
	mna[68](26) = mna[68][26] + 1.;
	mna[30](68) = mna[30][68] - 1.;
	mna[68](30) = mna[68][30] - 1.;
	mna[68](68) = mna[68][68] - 15.e3;

 /* Elements of  R23*/ 
	mna[30](69) = mna[30][69] + 1.;
	mna[69](30) = mna[69][30] + 1.;
	mna[31](69) = mna[31][69] - 1.;
	mna[69](31) = mna[69][31] - 1.;
	mna[69](69) = mna[69][69] - 24.e2;

 /* Elements of  R24*/ 
	mna[32](70) = mna[32][70] + 1.;
	mna[70](32) = mna[70][32] + 1.;
	mna[33](70) = mna[33][70] - 1.;
	mna[70](33) = mna[70][33] - 1.;
	mna[70](70) = mna[70][70] - 5.e1;

 /* Elements of  R25*/ 
	mna[30](71) = mna[30][71] + 1.;
	mna[71](30) = mna[71][30] + 1.;
	mna[34](71) = mna[34][71] - 1.;
	mna[71](34) = mna[71][34] - 1.;
	mna[71](71) = mna[71][71] - 5.e4;

 /* Elements of  R26*/ 
	mna[34](72) = mna[34][72] + 1.;
	mna[72](34) = mna[72][34] + 1.;
	mna[35](72) = mna[35][72] - 1.;
	mna[72](35) = mna[72][35] - 1.;
	mna[72](72) = mna[72][72] - 1.e0;

 /* Elements of  R27*/ 
	mna[36](73) = mna[36][73] + 1.;
	mna[73](36) = mna[73][36] + 1.;
	mna[12](73) = mna[12][73] - 1.;
	mna[73](12) = mna[73][12] - 1.;
	mna[73](73) = mna[73][73] - 1.e0;

 /* Elements of  C1*/ 
	mna[1](1) = mna[1][1] + idt*15.e-10;
	rval[1] = rval[1] + idt*15.e-10*(uxtold[1] - uxtold[2]);
	mna[2](2) = mna[2][2] + idt*15.e-10;
	rval[2] = rval[2] + idt*15.e-10*(uxtold[2] - uxtold[1]);
	mna[1](2) = mna[1][2] - idt*15.e-10;
	mna[2](1) = mna[2][1] - idt*15.e-10;

 /* Elements of  C2*/ 
	mna[3](3) = mna[3][3] + idt*16.e-10;
	rval[3] = rval[3] + idt*16.e-10*(uxtold[3] - uxtold[0]);

 /* Elements of  C3*/ 
	mna[7](7) = mna[7][7] + idt*50.e-11;
	rval[7] = rval[7] + idt*50.e-11*(uxtold[7] - uxtold[0]);

 /* Elements of  C4*/ 
	mna[7](7) = mna[7][7] + idt*15.e-10;
	rval[7] = rval[7] + idt*15.e-10*(uxtold[7] - uxtold[11]);
	mna[11](11) = mna[11][11] + idt*15.e-10;
	rval[11] = rval[11] + idt*15.e-10*(uxtold[11] - uxtold[7]);
	mna[7](11) = mna[7][11] - idt*15.e-10;
	mna[11](7) = mna[11][7] - idt*15.e-10;

 /* Elements of  C4*/ 
	mna[14](14) = mna[14][14] + idt*16.e-10;
	rval[14] = rval[14] + idt*16.e-10*(uxtold[14] - uxtold[0]);

 /* Elements of  C5*/ 
	mna[18](18) = mna[18][18] + idt*50.e-11;
	rval[18] = rval[18] + idt*50.e-11*(uxtold[18] - uxtold[0]);

 /* Elements of  C6*/ 
	mna[18](18) = mna[18][18] + idt*15.e-10;
	rval[18] = rval[18] + idt*15.e-10*(uxtold[18] - uxtold[22]);
	mna[22](22) = mna[22][22] + idt*15.e-10;
	rval[22] = rval[22] + idt*15.e-10*(uxtold[22] - uxtold[18]);
	mna[18](22) = mna[18][22] - idt*15.e-10;
	mna[22](18) = mna[22][18] - idt*15.e-10;

 /* Elements of  C7*/ 
	mna[24](24) = mna[24][24] + idt*15.e-10;
	rval[24] = rval[24] + idt*15.e-10*(uxtold[24] - uxtold[25]);
	mna[25](25) = mna[25][25] + idt*15.e-10;
	rval[25] = rval[25] + idt*15.e-10*(uxtold[25] - uxtold[24]);
	mna[24](25) = mna[24][25] - idt*15.e-10;
	mna[25](24) = mna[25][24] - idt*15.e-10;

 /* Elements of  C8*/ 
	mna[26](26) = mna[26][26] + idt*16.e-10;
	rval[26] = rval[26] + idt*16.e-10*(uxtold[26] - uxtold[0]);

 /* Elements of  C9*/ 
	mna[30](30) = mna[30][30] + idt*50.e-11;
	rval[30] = rval[30] + idt*50.e-11*(uxtold[30] - uxtold[0]);

 /* Elements of  C10*/ 
	mna[30](30) = mna[30][30] + idt*15.e-10;
	rval[30] = rval[30] + idt*15.e-10*(uxtold[30] - uxtold[34]);
	mna[34](34) = mna[34][34] + idt*15.e-10;
	rval[34] = rval[34] + idt*15.e-10*(uxtold[34] - uxtold[30]);
	mna[30](34) = mna[30][34] - idt*15.e-10;
	mna[34](30) = mna[34][30] - idt*15.e-10;

 /* Elements of CMS1*/

	double Un_CM, Uo_CM, Omegaold_CM, Omegaxold_CM, Omega_CM;
	double Geq_CM, Ieq_CM, Sr_CM, Sr_CMO, GGeq_CM, IIeq_CM, Kpi_CM, Ki_CM, Kv_CM,Kpv_CM, RR, Jw, Jv, Fwv;
	static int tt_CM = 0;

	Un_CM = 0.;
	Uo_CM = 0.;
	Un_CM += -Vx[5];
	Un_CM += Vx[4];
	Uo_CM += -uxtold[5];
	Uo_CM += uxtold[4];
	Omegaxold_CM = 0.;
	Omegaold_CM = 0.;
	Omega_CM = 0;

	Omegaxold_CM = uxtold[74];
	Omegaold_CM = Vx[74];



	double Rch_I, Rch_II, Rch_W, dRch, Gth_W, dGth, dH_I, dH_II, dH_III, dH_W, ddH_I, ddH_II, ddH_III;

	if((-1*Omegaold_CM) > (-0.000001))
    {Omegaold_CM = 0.000001;
    }

    if(Omegaold_CM > 0.99999)
    {Omegaold_CM = 0.99999;
    }

    if((-1*Omegaxold_CM) > (-0.000001))
    {Omegaxold_CM = 0.000001;
    }

    if(Omegaxold_CM > 0.99999)
    {Omegaxold_CM = 0.99999;
    }
	
	Rch_I = ((1.6e-2 * 2)/(M_PI * (3* 3.e-8)));
    Rch_II = 1.+(((1.6e-2 / 3.e-4)-1.) * (Omegaold_CM * Omegaold_CM));
    Rch_W = Rch_I / Rch_II;
    dRch = 2. * (((1.6e-2/3.e-4)-1.)*M_PI*(3.e-8*3)*(Un_CM * Un_CM)*Omegaold_CM)/(1.6e-2 * 2);

    Gth_W =-2.*M_PI*2.e-8*0.9/log(Omegaold_CM);
    dGth = -2.*M_PI*2.e-8*0.9*784e0/(Omegaold_CM*(log(1./Omegaold_CM)*log(1./Omegaold_CM)));

    dH_I = M_PI*2.e-8*3.e-8*3.e-8;
    dH_II = 2.6e6*784e0*((1. - (Omegaold_CM*Omegaold_CM ) + (2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(4.*Omegaold_CM*Omegaold_CM*(log(Omegaold_CM)*log(Omegaold_CM))));
    dH_III = 2. * 1.6e8 * Omegaold_CM;
    dH_W = dH_I * (dH_II + dH_III);
    ddH_I = 2. *2.6e6 * 784e0 / (Omegaold_CM*log(Omegaold_CM));
    ddH_II = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM)*log(Omegaold_CM));
    ddH_III = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM));

    Fwv =(2*(Omegaold_CM-Omegaxold_CM)/1.e-10)-(1.e0*((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))/dH_W));
    Jw = (2/1.e-10)+1.e0*(((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))*((2.*1.6e8)+ddH_I+ddH_II+ddH_III))/(dH_I*((dH_II + dH_III)*(dH_II + dH_III))))-(1.e0*((dRch+dGth)/dH_W));
    Jv = (-2.*Un_CM)/(dH_W*Rch_W);	
	RR = Rch_W;
	Ki_CM = Fwv/(-1*Jw);
	Kpi_CM = Jv/Jw;
	Kv_CM = (dRch/(Rch_W*Rch_W))*(Ki_CM);
	Kpv_CM = (dRch/(Rch_W*Rch_W))*(Kpi_CM);

	IIeq_CM = (Omegaold_CM + Ki_CM) + (Kpi_CM*Un_CM);
	GGeq_CM = -1*Kpi_CM;
	Omega_CM = IIeq_CM+(GGeq_CM*Un_CM);
	Sr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;

	Geq_CM = (1./RR) + Kpv_CM;
	Ieq_CM = Kv_CM + (Kpv_CM * Un_CM);
	Sr_CM = ((Ieq_CM - Omega_CM)/Geq_CM) + Un_CM;

	mna[74](4) = mna[74][4] - GGeq_CM;
	mna[4](4) = mna[4][4] + Geq_CM;
	rval[4] += -Ieq_CM;
	fvec[4] += Vx[4];
	mna[4](5) = mna[4][5] - Geq_CM;
	mna[5](4) = mna[5][4] - Geq_CM;
	mna[74](5) = mna[74][5] + GGeq_CM;
	mna[5](5) = mna[5][5] + Geq_CM;
	rval[5] += Ieq_CM;
	fvec[5] += -Vx[5];
	mna[74](74) = mna[74][74] + 1.;
	rval[74] += IIeq_CM;
	fvec[74] += Sr_CMO;

 /* Elements of CMS2*/

	Un_CM = 0.;
	Uo_CM = 0.;
	Un_CM += -Vx[9];
	Un_CM += Vx[8];
	Uo_CM += -uxtold[9];
	Uo_CM += uxtold[8];
	Omegaxold_CM = 0.;
	Omegaold_CM = 0.;
	Omega_CM = 0;

	Omegaxold_CM = uxtold[75];
	Omegaold_CM = Vx[75];



	if((-1*Omegaold_CM) > (-0.000001))
    {Omegaold_CM = 0.000001;
    }

    if(Omegaold_CM > 0.99999)
    {Omegaold_CM = 0.99999;
    }

    if((-1*Omegaxold_CM) > (-0.000001))
    {Omegaxold_CM = 0.000001;
    }

    if(Omegaxold_CM > 0.99999)
    {Omegaxold_CM = 0.99999;
    }
	
	Rch_I = ((1.6e-2 * 2)/(M_PI * (3* 3.e-8)));
    Rch_II = 1.+(((1.6e-2 / 3.e-4)-1.) * (Omegaold_CM * Omegaold_CM));
    Rch_W = Rch_I / Rch_II;
    dRch = 2. * (((1.6e-2/3.e-4)-1.)*M_PI*(3.e-8*3)*(Un_CM * Un_CM)*Omegaold_CM)/(1.6e-2 * 2);

    Gth_W =-2.*M_PI*2.e-8*0.9/log(Omegaold_CM);
    dGth = -2.*M_PI*2.e-8*0.9*784e0/(Omegaold_CM*(log(1./Omegaold_CM)*log(1./Omegaold_CM)));

    dH_I = M_PI*2.e-8*3.e-8*3.e-8;
    dH_II = 2.6e6*784e0*((1. - (Omegaold_CM*Omegaold_CM ) + (2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(4.*Omegaold_CM*Omegaold_CM*(log(Omegaold_CM)*log(Omegaold_CM))));
    dH_III = 2. * 1.6e8 * Omegaold_CM;
    dH_W = dH_I * (dH_II + dH_III);
    ddH_I = 2. *2.6e6 * 784e0 / (Omegaold_CM*log(Omegaold_CM));
    ddH_II = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM)*log(Omegaold_CM));
    ddH_III = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM));

    Fwv =(2*(Omegaold_CM-Omegaxold_CM)/1.e-10)-(1.e0*((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))/dH_W));
    Jw = (2/1.e-10)+1.e0*(((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))*((2.*1.6e8)+ddH_I+ddH_II+ddH_III))/(dH_I*((dH_II + dH_III)*(dH_II + dH_III))))-(1.e0*((dRch+dGth)/dH_W));
    Jv = (-2.*Un_CM)/(dH_W*Rch_W);	
	RR = Rch_W;
	Ki_CM = Fwv/(-1*Jw);
	Kpi_CM = Jv/Jw;
	Kv_CM = (dRch/(Rch_W*Rch_W))*(Ki_CM);
	Kpv_CM = (dRch/(Rch_W*Rch_W))*(Kpi_CM);

	IIeq_CM = (Omegaold_CM + Ki_CM) + (Kpi_CM*Un_CM);
	GGeq_CM = -1*Kpi_CM;
	Omega_CM = IIeq_CM+(GGeq_CM*Un_CM);
	Sr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;

	Geq_CM = (1./RR) + Kpv_CM;
	Ieq_CM = Kv_CM + (Kpv_CM * Un_CM);
	Sr_CM = ((Ieq_CM - Omega_CM)/Geq_CM) + Un_CM;

	mna[75](8) = mna[75][8] - GGeq_CM;
	mna[8](8) = mna[8][8] + Geq_CM;
	rval[8] += -Ieq_CM;
	fvec[8] += Vx[8];
	mna[8](9) = mna[8][9] - Geq_CM;
	mna[9](8) = mna[9][8] - Geq_CM;
	mna[75](9) = mna[75][9] + GGeq_CM;
	mna[9](9) = mna[9][9] + Geq_CM;
	rval[9] += Ieq_CM;
	fvec[9] += -Vx[9];
	mna[75](75) = mna[75][75] + 1.;
	rval[75] += IIeq_CM;
	fvec[75] += Sr_CMO;

 /* Elements of CMS3*/

	Un_CM = 0.;
	Uo_CM = 0.;
	Un_CM += -Vx[16];
	Un_CM += Vx[15];
	Uo_CM += -uxtold[16];
	Uo_CM += uxtold[15];
	Omegaxold_CM = 0.;
	Omegaold_CM = 0.;
	Omega_CM = 0;

	Omegaxold_CM = uxtold[76];
	Omegaold_CM = Vx[76];



	if((-1*Omegaold_CM) > (-0.000001))
    {Omegaold_CM = 0.000001;
    }

    if(Omegaold_CM > 0.99999)
    {Omegaold_CM = 0.99999;
    }

    if((-1*Omegaxold_CM) > (-0.000001))
    {Omegaxold_CM = 0.000001;
    }

    if(Omegaxold_CM > 0.99999)
    {Omegaxold_CM = 0.99999;
    }
	
	Rch_I = ((1.6e-2 * 2)/(M_PI * (3* 3.e-8)));
    Rch_II = 1.+(((1.6e-2 / 3.e-4)-1.) * (Omegaold_CM * Omegaold_CM));
    Rch_W = Rch_I / Rch_II;
    dRch = 2. * (((1.6e-2/3.e-4)-1.)*M_PI*(3.e-8*3)*(Un_CM * Un_CM)*Omegaold_CM)/(1.6e-2 * 2);

    Gth_W =-2.*M_PI*2.e-8*0.9/log(Omegaold_CM);
    dGth = -2.*M_PI*2.e-8*0.9*784e0/(Omegaold_CM*(log(1./Omegaold_CM)*log(1./Omegaold_CM)));

    dH_I = M_PI*2.e-8*3.e-8*3.e-8;
    dH_II = 2.6e6*784e0*((1. - (Omegaold_CM*Omegaold_CM ) + (2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(4.*Omegaold_CM*Omegaold_CM*(log(Omegaold_CM)*log(Omegaold_CM))));
    dH_III = 2. * 1.6e8 * Omegaold_CM;
    dH_W = dH_I * (dH_II + dH_III);
    ddH_I = 2. *2.6e6 * 784e0 / (Omegaold_CM*log(Omegaold_CM));
    ddH_II = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM)*log(Omegaold_CM));
    ddH_III = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM));

    Fwv =(2*(Omegaold_CM-Omegaxold_CM)/1.e-10)-(1.e0*((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))/dH_W));
    Jw = (2/1.e-10)+1.e0*(((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))*((2.*1.6e8)+ddH_I+ddH_II+ddH_III))/(dH_I*((dH_II + dH_III)*(dH_II + dH_III))))-(1.e0*((dRch+dGth)/dH_W));
    Jv = (-2.*Un_CM)/(dH_W*Rch_W);	
	RR = Rch_W;
	Ki_CM = Fwv/(-1*Jw);
	Kpi_CM = Jv/Jw;
	Kv_CM = (dRch/(Rch_W*Rch_W))*(Ki_CM);
	Kpv_CM = (dRch/(Rch_W*Rch_W))*(Kpi_CM);

	IIeq_CM = (Omegaold_CM + Ki_CM) + (Kpi_CM*Un_CM);
	GGeq_CM = -1*Kpi_CM;
	Omega_CM = IIeq_CM+(GGeq_CM*Un_CM);
	Sr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;

	Geq_CM = (1./RR) + Kpv_CM;
	Ieq_CM = Kv_CM + (Kpv_CM * Un_CM);
	Sr_CM = ((Ieq_CM - Omega_CM)/Geq_CM) + Un_CM;

	mna[76](15) = mna[76][15] - GGeq_CM;
	mna[15](15) = mna[15][15] + Geq_CM;
	rval[15] += -Ieq_CM;
	fvec[15] += Vx[15];
	mna[15](16) = mna[15][16] - Geq_CM;
	mna[16](15) = mna[16][15] - Geq_CM;
	mna[76](16) = mna[76][16] + GGeq_CM;
	mna[16](16) = mna[16][16] + Geq_CM;
	rval[16] += Ieq_CM;
	fvec[16] += -Vx[16];
	mna[76](76) = mna[76][76] + 1.;
	rval[76] += IIeq_CM;
	fvec[76] += Sr_CMO;

 /* Elements of CMS4*/

	Un_CM = 0.;
	Uo_CM = 0.;
	Un_CM += -Vx[20];
	Un_CM += Vx[19];
	Uo_CM += -uxtold[20];
	Uo_CM += uxtold[19];
	Omegaxold_CM = 0.;
	Omegaold_CM = 0.;
	Omega_CM = 0;

	Omegaxold_CM = uxtold[77];
	Omegaold_CM = Vx[77];



	if((-1*Omegaold_CM) > (-0.000001))
    {Omegaold_CM = 0.000001;
    }

    if(Omegaold_CM > 0.99999)
    {Omegaold_CM = 0.99999;
    }

    if((-1*Omegaxold_CM) > (-0.000001))
    {Omegaxold_CM = 0.000001;
    }

    if(Omegaxold_CM > 0.99999)
    {Omegaxold_CM = 0.99999;
    }
	
	Rch_I = ((1.6e-2 * 2)/(M_PI * (3* 3.e-8)));
    Rch_II = 1.+(((1.6e-2 / 3.e-4)-1.) * (Omegaold_CM * Omegaold_CM));
    Rch_W = Rch_I / Rch_II;
    dRch = 2. * (((1.6e-2/3.e-4)-1.)*M_PI*(3.e-8*3)*(Un_CM * Un_CM)*Omegaold_CM)/(1.6e-2 * 2);

    Gth_W =-2.*M_PI*2.e-8*0.9/log(Omegaold_CM);
    dGth = -2.*M_PI*2.e-8*0.9*784e0/(Omegaold_CM*(log(1./Omegaold_CM)*log(1./Omegaold_CM)));

    dH_I = M_PI*2.e-8*3.e-8*3.e-8;
    dH_II = 2.6e6*784e0*((1. - (Omegaold_CM*Omegaold_CM ) + (2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(4.*Omegaold_CM*Omegaold_CM*(log(Omegaold_CM)*log(Omegaold_CM))));
    dH_III = 2. * 1.6e8 * Omegaold_CM;
    dH_W = dH_I * (dH_II + dH_III);
    ddH_I = 2. *2.6e6 * 784e0 / (Omegaold_CM*log(Omegaold_CM));
    ddH_II = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM)*log(Omegaold_CM));
    ddH_III = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM));

    Fwv =(2*(Omegaold_CM-Omegaxold_CM)/1.e-10)-(1.e0*((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))/dH_W));
    Jw = (2/1.e-10)+1.e0*(((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))*((2.*1.6e8)+ddH_I+ddH_II+ddH_III))/(dH_I*((dH_II + dH_III)*(dH_II + dH_III))))-(1.e0*((dRch+dGth)/dH_W));
    Jv = (-2.*Un_CM)/(dH_W*Rch_W);	
	RR = Rch_W;
	Ki_CM = Fwv/(-1*Jw);
	Kpi_CM = Jv/Jw;
	Kv_CM = (dRch/(Rch_W*Rch_W))*(Ki_CM);
	Kpv_CM = (dRch/(Rch_W*Rch_W))*(Kpi_CM);

	IIeq_CM = (Omegaold_CM + Ki_CM) + (Kpi_CM*Un_CM);
	GGeq_CM = -1*Kpi_CM;
	Omega_CM = IIeq_CM+(GGeq_CM*Un_CM);
	Sr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;

	Geq_CM = (1./RR) + Kpv_CM;
	Ieq_CM = Kv_CM + (Kpv_CM * Un_CM);
	Sr_CM = ((Ieq_CM - Omega_CM)/Geq_CM) + Un_CM;

	mna[77](19) = mna[77][19] - GGeq_CM;
	mna[19](19) = mna[19][19] + Geq_CM;
	rval[19] += -Ieq_CM;
	fvec[19] += Vx[19];
	mna[19](20) = mna[19][20] - Geq_CM;
	mna[20](19) = mna[20][19] - Geq_CM;
	mna[77](20) = mna[77][20] + GGeq_CM;
	mna[20](20) = mna[20][20] + Geq_CM;
	rval[20] += Ieq_CM;
	fvec[20] += -Vx[20];
	mna[77](77) = mna[77][77] + 1.;
	rval[77] += IIeq_CM;
	fvec[77] += Sr_CMO;

 /* Elements of CMS5*/

	Un_CM = 0.;
	Uo_CM = 0.;
	Un_CM += -Vx[28];
	Un_CM += Vx[27];
	Uo_CM += -uxtold[28];
	Uo_CM += uxtold[27];
	Omegaxold_CM = 0.;
	Omegaold_CM = 0.;
	Omega_CM = 0;

	Omegaxold_CM = uxtold[78];
	Omegaold_CM = Vx[78];



	if((-1*Omegaold_CM) > (-0.000001))
    {Omegaold_CM = 0.000001;
    }

    if(Omegaold_CM > 0.99999)
    {Omegaold_CM = 0.99999;
    }

    if((-1*Omegaxold_CM) > (-0.000001))
    {Omegaxold_CM = 0.000001;
    }

    if(Omegaxold_CM > 0.99999)
    {Omegaxold_CM = 0.99999;
    }
	
	Rch_I = ((1.6e-2 * 2)/(M_PI * (3* 3.e-8)));
    Rch_II = 1.+(((1.6e-2 / 3.e-4)-1.) * (Omegaold_CM * Omegaold_CM));
    Rch_W = Rch_I / Rch_II;
    dRch = 2. * (((1.6e-2/3.e-4)-1.)*M_PI*(3.e-8*3)*(Un_CM * Un_CM)*Omegaold_CM)/(1.6e-2 * 2);

    Gth_W =-2.*M_PI*2.e-8*0.9/log(Omegaold_CM);
    dGth = -2.*M_PI*2.e-8*0.9*784e0/(Omegaold_CM*(log(1./Omegaold_CM)*log(1./Omegaold_CM)));

    dH_I = M_PI*2.e-8*3.e-8*3.e-8;
    dH_II = 2.6e6*784e0*((1. - (Omegaold_CM*Omegaold_CM ) + (2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(4.*Omegaold_CM*Omegaold_CM*(log(Omegaold_CM)*log(Omegaold_CM))));
    dH_III = 2. * 1.6e8 * Omegaold_CM;
    dH_W = dH_I * (dH_II + dH_III);
    ddH_I = 2. *2.6e6 * 784e0 / (Omegaold_CM*log(Omegaold_CM));
    ddH_II = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM)*log(Omegaold_CM));
    ddH_III = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM));

    Fwv =(2*(Omegaold_CM-Omegaxold_CM)/1.e-10)-(1.e0*((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))/dH_W));
    Jw = (2/1.e-10)+1.e0*(((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))*((2.*1.6e8)+ddH_I+ddH_II+ddH_III))/(dH_I*((dH_II + dH_III)*(dH_II + dH_III))))-(1.e0*((dRch+dGth)/dH_W));
    Jv = (-2.*Un_CM)/(dH_W*Rch_W);	
	RR = Rch_W;
	Ki_CM = Fwv/(-1*Jw);
	Kpi_CM = Jv/Jw;
	Kv_CM = (dRch/(Rch_W*Rch_W))*(Ki_CM);
	Kpv_CM = (dRch/(Rch_W*Rch_W))*(Kpi_CM);

	IIeq_CM = (Omegaold_CM + Ki_CM) + (Kpi_CM*Un_CM);
	GGeq_CM = -1*Kpi_CM;
	Omega_CM = IIeq_CM+(GGeq_CM*Un_CM);
	Sr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;

	Geq_CM = (1./RR) + Kpv_CM;
	Ieq_CM = Kv_CM + (Kpv_CM * Un_CM);
	Sr_CM = ((Ieq_CM - Omega_CM)/Geq_CM) + Un_CM;

	mna[78](27) = mna[78][27] - GGeq_CM;
	mna[27](27) = mna[27][27] + Geq_CM;
	rval[27] += -Ieq_CM;
	fvec[27] += Vx[27];
	mna[27](28) = mna[27][28] - Geq_CM;
	mna[28](27) = mna[28][27] - Geq_CM;
	mna[78](28) = mna[78][28] + GGeq_CM;
	mna[28](28) = mna[28][28] + Geq_CM;
	rval[28] += Ieq_CM;
	fvec[28] += -Vx[28];
	mna[78](78) = mna[78][78] + 1.;
	rval[78] += IIeq_CM;
	fvec[78] += Sr_CMO;

 /* Elements of CMS6*/

	Un_CM = 0.;
	Uo_CM = 0.;
	Un_CM += -Vx[32];
	Un_CM += Vx[31];
	Uo_CM += -uxtold[32];
	Uo_CM += uxtold[31];
	Omegaxold_CM = 0.;
	Omegaold_CM = 0.;
	Omega_CM = 0;

	Omegaxold_CM = uxtold[79];
	Omegaold_CM = Vx[79];



	if((-1*Omegaold_CM) > (-0.000001))
    {Omegaold_CM = 0.000001;
    }

    if(Omegaold_CM > 0.99999)
    {Omegaold_CM = 0.99999;
    }

    if((-1*Omegaxold_CM) > (-0.000001))
    {Omegaxold_CM = 0.000001;
    }

    if(Omegaxold_CM > 0.99999)
    {Omegaxold_CM = 0.99999;
    }
	
	Rch_I = ((1.6e-2 * 2)/(M_PI * (3* 3.e-8)));
    Rch_II = 1.+(((1.6e-2 / 3.e-4)-1.) * (Omegaold_CM * Omegaold_CM));
    Rch_W = Rch_I / Rch_II;
    dRch = 2. * (((1.6e-2/3.e-4)-1.)*M_PI*(3.e-8*3)*(Un_CM * Un_CM)*Omegaold_CM)/(1.6e-2 * 2);

    Gth_W =-2.*M_PI*2.e-8*0.9/log(Omegaold_CM);
    dGth = -2.*M_PI*2.e-8*0.9*784e0/(Omegaold_CM*(log(1./Omegaold_CM)*log(1./Omegaold_CM)));

    dH_I = M_PI*2.e-8*3.e-8*3.e-8;
    dH_II = 2.6e6*784e0*((1. - (Omegaold_CM*Omegaold_CM ) + (2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(4.*Omegaold_CM*Omegaold_CM*(log(Omegaold_CM)*log(Omegaold_CM))));
    dH_III = 2. * 1.6e8 * Omegaold_CM;
    dH_W = dH_I * (dH_II + dH_III);
    ddH_I = 2. *2.6e6 * 784e0 / (Omegaold_CM*log(Omegaold_CM));
    ddH_II = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM)*log(Omegaold_CM));
    ddH_III = -1.*2.6e6*784e0*(1.-(Omegaold_CM*Omegaold_CM )+(2.*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)))/(2.*Omegaold_CM*Omegaold_CM*Omegaold_CM*log(Omegaold_CM)*log(Omegaold_CM));

    Fwv =(2*(Omegaold_CM-Omegaxold_CM)/1.e-10)-(1.e0*((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))/dH_W));
    Jw = (2/1.e-10)+1.e0*(((((Un_CM*Un_CM)/Rch_W)-(Gth_W*784e0))*((2.*1.6e8)+ddH_I+ddH_II+ddH_III))/(dH_I*((dH_II + dH_III)*(dH_II + dH_III))))-(1.e0*((dRch+dGth)/dH_W));
    Jv = (-2.*Un_CM)/(dH_W*Rch_W);	
	RR = Rch_W;
	Ki_CM = Fwv/(-1*Jw);
	Kpi_CM = Jv/Jw;
	Kv_CM = (dRch/(Rch_W*Rch_W))*(Ki_CM);
	Kpv_CM = (dRch/(Rch_W*Rch_W))*(Kpi_CM);

	IIeq_CM = (Omegaold_CM + Ki_CM) + (Kpi_CM*Un_CM);
	GGeq_CM = -1*Kpi_CM;
	Omega_CM = IIeq_CM+(GGeq_CM*Un_CM);
	Sr_CMO = ((IIeq_CM - Omega_CM)/GGeq_CM) + Un_CM;

	Geq_CM = (1./RR) + Kpv_CM;
	Ieq_CM = Kv_CM + (Kpv_CM * Un_CM);
	Sr_CM = ((Ieq_CM - Omega_CM)/Geq_CM) + Un_CM;

	mna[79](31) = mna[79][31] - GGeq_CM;
	mna[31](31) = mna[31][31] + Geq_CM;
	rval[31] += -Ieq_CM;
	fvec[31] += Vx[31];
	mna[31](32) = mna[31][32] - Geq_CM;
	mna[32](31) = mna[32][31] - Geq_CM;
	mna[79](32) = mna[79][32] + GGeq_CM;
	mna[32](32) = mna[32][32] + Geq_CM;
	rval[32] += Ieq_CM;
	fvec[32] += -Vx[32];
	mna[79](79) = mna[79][79] + 1.;
	rval[79] += IIeq_CM;
	fvec[79] += Sr_CMO;

 /* Elements of VMS1*/

	double Un_VM, Uo_VM, Omega_M, Omegaold_M, Omegaxold_M, Phi_M;
	double Geq_VM, Ieq_VM, Sr_VM, Sr_VMO, GGeq_M, IIeq_M;
	static int tt_VM = 0;

	Un_VM = 0.;
	Uo_VM = 0.;
	Un_VM += -Vx[37];
	Un_VM += Vx[12];
	Uo_VM += -uxtold[37];
	Uo_VM += uxtold[12];
	Omega_M = 0.;
	Omegaxold_M = 0.;
	Omegaold_M = 0.;
	Phi_M = 0;

	Omegaxold_M = uxtold[80];
	Omegaold_M = Vx[80];



	double Kv_VM, Kpv_VM;
		if((-1*Omegaold_M) > (-1*7000))
			{Omegaold_M = 7000;
		}
		if(Omegaold_M > 10000)
			{Omegaold_M = 10000;
		}
		if((-1*Omegaxold_M) > (-1*7000))
			{Omegaxold_M = 7000;
		}
		if(Omegaxold_M > 10000)
			{Omegaxold_M = 10000;
		}
		
		Jw = (1/1);
    Jv = 1*1.e-8*15.e7;
    Fwv = Omegaold_M + ((Omegaxold_M)/-1) - 1.e-8 *(15.e7 * Un_VM + (0.5*(0 - 15.e7)) * (abs(Un_VM + 0.5) - abs(Un_VM - 0.5)));
    Kv_VM = Un_VM /Omegaold_M;
    Kpv_VM = (1/Omegaold_M);

	GGeq_M = (1/Jw)*Jv;
	IIeq_M = Omegaold_M + (Fwv/(-1*Jw)) + (-1/Jw)*(Jv*Un_VM);
	Phi_M =  IIeq_M-(GGeq_M*Un_VM);

	Sr_VMO = ((-1* IIeq_M)/GGeq_M)+Un_VM;

	Ieq_VM = Kv_VM - (Kpv_VM * Un_VM);
	Geq_VM = Kpv_VM;
	Sr_VM = Kv_VM;

	mna[80](12) = mna[80][12] - GGeq_M;
	mna[12](12) = mna[12][12] + Geq_VM;
	rval[12] += -Ieq_VM;
	fvec[12] += Sr_VM;
	mna[12](37) = mna[12][37] - Geq_VM;
	mna[37](12) = mna[37][12] - Geq_VM;
	mna[80](37) = mna[80][37] + GGeq_M;
	mna[37](37) = mna[37][37] + Geq_VM;
	rval[37] += Ieq_VM;
	fvec[37] += -Sr_VM;
	mna[80](80) = mna[80][80] + 1.;
	rval[80] += IIeq_M;
	fvec[80] += Sr_VMO;

 /* Elements of VMS2*/

	Un_VM = 0.;
	Uo_VM = 0.;
	Un_VM += -Vx[35];
	Un_VM += Vx[36];
	Uo_VM += -uxtold[35];
	Uo_VM += uxtold[36];
	Omega_M = 0.;
	Omegaxold_M = 0.;
	Omegaold_M = 0.;
	Phi_M = 0;

	Omegaxold_M = uxtold[81];
	Omegaold_M = Vx[81];



	if((-1*Omegaold_M) > (-1*1000))
			{Omegaold_M = 1000;
		}
		if(Omegaold_M > 74000)
			{Omegaold_M = 74000;
		}
		if((-1*Omegaxold_M) > (-1*1000))
			{Omegaxold_M = 1000;
		}
		if(Omegaxold_M > 74000)
			{Omegaxold_M = 74000;
		}
		
		Jw = (1/1);
    Jv = 1*1.e-8*15.e8;
    Fwv = Omegaold_M + ((Omegaxold_M)/-1) - 1.e-8 *(15.e8 * Un_VM + (0.5*(0 - 15.e8)) * (abs(Un_VM + 0.55) - abs(Un_VM - 0.55)));
    Kv_VM = Un_VM /Omegaold_M;
    Kpv_VM = (1/Omegaold_M);

	GGeq_M = (1/Jw)*Jv;
	IIeq_M = Omegaold_M + (Fwv/(-1*Jw)) + (-1/Jw)*(Jv*Un_VM);
	Phi_M =  IIeq_M-(GGeq_M*Un_VM);

	Sr_VMO = ((-1* IIeq_M)/GGeq_M)+Un_VM;

	Ieq_VM = Kv_VM - (Kpv_VM * Un_VM);
	Geq_VM = Kpv_VM;
	Sr_VM = Kv_VM;

	mna[81](36) = mna[81][36] - GGeq_M;
	mna[36](36) = mna[36][36] + Geq_VM;
	rval[36] += -Ieq_VM;
	fvec[36] += Sr_VM;
	mna[36](35) = mna[36][35] - Geq_VM;
	mna[35](36) = mna[35][36] - Geq_VM;
	mna[81](35) = mna[81][35] + GGeq_M;
	mna[35](35) = mna[35][35] + Geq_VM;
	rval[35] += Ieq_VM;
	fvec[35] += -Sr_VM;
	mna[81](81) = mna[81][81] + 1.;
	rval[81] += IIeq_M;
	fvec[81] += Sr_VMO;
}