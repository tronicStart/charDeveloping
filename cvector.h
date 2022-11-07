#ifndef _CVECTOR_H
#define _CVECTOR_H
#include <stdio.h>
typedef int Matriz[50][50];
//vectores de tipo int
typedef int vector[1];
typedef int vector2[2];
typedef int vector3[3];
typedef int vector4[4];
typedef int vector5[5];
typedef int vectorSimple6[6];
typedef int vectorSimple7[7];
typedef int vectorSimple8[8];
typedef int vectorSimple9[9];
typedef int vectorSimple10[10];
typedef int vectorSimple11[11];
typedef int vectorSimple12[12];
typedef int vectorSimple13[13];
typedef int vectorSimple14[14];
typedef int vectorSimple15[15];
typedef int vectorSimple16[16];
typedef int vectorSimple17[17];
typedef int vectorSimple18[18];
typedef int vectorSimple19[19];
typedef int vectorSimple20[20];
typedef int vectorSimple21[21];
typedef int vectorSimple22[22];
typedef int vectorSimple23[23];
typedef int vectorSimple24[24];
typedef int vectorSimple25[25];
typedef int vectorSimple26[26];
typedef int vectorSimple27[27];
typedef int vectorSimple28[28];
typedef int vectorSimple29[29];
typedef int vectorSimple30[30];
typedef int vectorSimple31[31];
typedef int vectorSimple32[32];
typedef int vectorSimple33[33];
typedef int vectorSimple34[34];
typedef int vectorSimple35[35];
typedef int vectorSimple36[36];
typedef int vectorSimple37[37];
typedef int vectorSimple38[38];
typedef int vectorSimple39[39];
typedef int vectorSimple40[40];
typedef int vectorSimple41[41];
typedef int vectorSimple42[42];
typedef int vectorSimple43[43];
typedef int vectorSimple44[44];
typedef int vectorSimple45[45];
typedef int vectorSimple46[46];
typedef int vectorSimple47[47];
typedef int vectorSimple48[48];
typedef int vectorSimple49[49];
typedef int vectorSimple50[50];
typedef int vectorSimple51[51];
typedef int vectorSimple52[52];
typedef int vectorSimple53[53];
typedef int vectorSimple54[54];
typedef int vectorSimple55[55];
typedef int vectorSimple56[56];
typedef int vectorSimple57[57];
typedef int vectorSimple58[58];
typedef int vectorSimple59[59];
typedef int vectorSimple60[60];
typedef int vectorSimple61[61];
typedef int vectorSimple62[62];
typedef int vectorSimple63[63];
typedef int vectorSimple64[64];
typedef int vectorSimple65[65];
typedef int vectorSimple66[66];
typedef int vectorSimple67[67];
typedef int vectorSimple68[68];
typedef int vectorSimple69[69];
typedef int vectorSimple70[70];
typedef int vectorSimple71[71];
typedef int vectorSimple72[72];
typedef int vectorSimple73[73];
typedef int vectorSimple74[74];
typedef int vectorSimple75[75];
typedef int vectorSimple76[76];
typedef int vectorSimple77[77];
typedef int vectorSimple78[78];
typedef int vectorSimple79[79];
typedef int vectorSimple80[80];
typedef int vectorSimple81[81];
typedef int vectorSimple82[82];
typedef int vectorSimple83[83];
typedef int vectorSimple84[84];
typedef int vectorSimple85[85];
typedef int vectorSimple86[86];
typedef int vectorSimple87[87];
typedef int vectorSimple88[88];
typedef int vectorSimple89[89];
typedef int vectorSimple90[90];
typedef int vectorSimple91[91];
typedef int vectorSimple92[92];
typedef int vectorSimple93[93];
typedef int vectorSimple94[94];
typedef int vectorSimple95[95];
typedef int vectorSimple96[96];
typedef int vectorSimple97[97];
typedef int vectorSimple98[98];
typedef int vectorSimple99[99];
typedef int vectorSimple100[100];
typedef int vectorSimple101[101];
typedef int vectorSimple102[102];
typedef int vectorSimple103[103];
typedef int vectorSimple104[104];
typedef int vectorSimple105[105];
typedef int vectorSimple106[106];
typedef int vectorSimple107[107];
typedef int vectorSimple108[108];
typedef int vectorSimple109[109];
typedef int vectorSimple110[110];
//vectores de tipo char
typedef char vector1[1];
typedef char vectorSimple2[2];
typedef char vectorSimple3[3];
typedef char vectorSimple4[4];
typedef char vectorSimple5[5];
typedef char vector6[6];
typedef char vector7[7];
typedef char vector8[8];
typedef char vector9[9];
typedef char vector10[10];
typedef char vector11[11];
typedef char vector12[12];
typedef char vector13[13];
typedef char vector14[14];
typedef char vector15[15];
typedef char vector16[16];
typedef char vector17[17];
typedef char vector18[18];
typedef char vector19[19];
typedef char vector20[10];
typedef char vector21[21];
typedef char vector22[22];
typedef char vector23[23];
typedef char vector24[24];
typedef char vector25[25];
typedef char vector26[26];
typedef char vector27[27];
typedef char vector28[28];
typedef char vector29[29];
typedef char vector30[30];
typedef char vector31[31];
typedef char vector32[32];
typedef char vector33[33];
typedef char vector34[34];
typedef char vector35[35];
typedef char vector36[36];
typedef char vector37[37];
typedef char vector38[38];
typedef char vector39[39];
typedef char vector40[40];
typedef char vector41[41];
typedef char vector42[42];
typedef char vector43[43];
typedef char vector44[44];
typedef char vector45[45];
typedef char vector46[46];
typedef char vector47[47];
typedef char vector48[48];
typedef char vector49[49];
typedef char vector50[50];
typedef char vector51[51];
typedef char vector52[52];
typedef char vector53[53];
typedef char vector54[54];
typedef char vector55[55];
typedef char vector56[56];
typedef char vector57[57];
typedef char vector58[58];
typedef char vector59[59];
typedef char vector60[60];
typedef char vector61[61];
typedef char vector62[62];
typedef char vector63[63];
typedef char vector64[64];
typedef char vector65[65];
typedef char vector66[66];
typedef char vector67[67];
typedef char vector68[68];
typedef char vector69[69];
typedef char vector70[70];
typedef char vector71[71];
typedef char vector72[72];
typedef char vector73[73];
typedef char vector74[74];
typedef char vector75[75];
typedef char vector76[76];
typedef char vector77[77];
typedef char vector78[78];
typedef char vector79[79];
typedef char vector80[80];
typedef char vector81[81];
typedef char vector82[82];
typedef char vector83[83];
typedef char vector84[84];
typedef char vector85[85];
typedef char vector86[86];
typedef char vector87[87];
typedef char vector88[88];
typedef char vector89[89];
typedef char vector90[90];
typedef char vector91[91];
typedef char vector92[92];
typedef char vector93[93];
typedef char vector94[94];
typedef char vector95[95];
typedef char vector96[96];
typedef char vector97[97];
typedef char vector98[98];
typedef char vector99[99];
typedef char vector100[100];
typedef int matriz[50][50];

int read_for_vector (int vector[] , int tam){

	int i;

	for(i = 0; i < tam; i++){

		fflush(stdin);
		scanf("%i",&vector[i]);

	}

	return *(vector);

}

void read_new_vector(int vector[] , int pos){

	int i;
	for(i = 0; i < pos ; i++){
		printf("%i",vector[i]);
	}

}

void _create_new_vector(int pos , const char * CA){

	int i;
	for(i = 0; i < pos ; i++){
		printf("%s",CA);
	}

}

int Vector(int Tam){

	int vector[Tam];

	return vector[Tam];

}

let read_vector_char (Public Vxy[][5]){
	let i , j;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			printf("%c",Vxy[i][j]);
		}
	}
}

void read_diagonal_matriz1 (matriz M){
	int i;
	for( i = 0; i < 5; ++i){
		printf("%i ",M[i][i]);
	}
	
}

void read_diagonal_matriz2(matriz M){
	int i,j;
	for( i = 5 -1 , j = 0; i >= 0 && j < 5; --i , ++j){
		printf("%i ",M[i][j]);
	}
	
}

#endif
