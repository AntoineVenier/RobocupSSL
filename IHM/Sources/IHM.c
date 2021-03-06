/*
 * IHM.c
 *
 *  Created on: May 29, 2018
 *      Author: MSI_COCA
 */
#include "IHM.h"
#include "bsp.h"

const unsigned char touche[]="Touche : ";
const unsigned char help1[]="Utilisez z,q,s,d pour deplacer le robot, o et p pour le faire tourner,";
const unsigned char help2[]="k pour tirer et m pour activer le dribleur.";
const unsigned char batterie[]= "Batterie :";
const unsigned char dx[]= "dx :";
const unsigned char dy[]= "dy :";
const unsigned char Rotation[]= "Vitesse angulaire :";
const unsigned char vitesse[]= "Vitesse :";
const unsigned char status_rf[]= "Status RF : ";

void draw_ihm(void){
	unsigned char i=0;




	for(i=0; i<100; i++){
		move(i,0);
		putc('#');
	}
	for(i=0; i<100; i++){
		move(i,25);
		putc('#');
	}
	for(i=1; i<25; i++){
		move(0,i);
		putc('#');
	}
	for(i=1; i<26; i++){
		move(100,i);
		putc('#');
	}

	//--------------------------------------------------------Batterie
	for(i=0; i<10; i++){  //15, 4 pour le nombre
		move((4+i),4);
		putc(batterie[i]);
	}
	move(18,4);
	putc('%');
	//--------------------------------------------------------dx
	for(i=0; i<4; i++){  //9, 6 pour le nombre
		move((4+i),6);
		putc(dx[i]);
	}
	//--------------------------------------------------------dy
	for(i=0; i<4; i++){  //9, 7 pour le nombre
		move((4+i),7);
		putc(dy[i]);
	}
	//--------------------------------------------------------Vitesse
	for(i=0; i<9; i++){  //15, 9 pour le nombre
		move((4+i),9);
		putc(vitesse[i]);
	}
	//--------------------------------------------------------Rotation
	for(i=0; i<19; i++){  //25, 10 pour le nombre
		move((4+i),10);
		putc(Rotation[i]);
	}
	//--------------------------------------------------------Status
	for(i=0; i<12; i++){
		move((4+i),12);
		putc(status_rf[i]);
	}
	//---------------------------------------------------------Help
	for (i = 0; i < 70; ++i) {
		move((4+i),22);
		putc(help1[i]);
	}
	//---------------------------------------------------------Help
	for (i = 0; i < 43; ++i) {
		move((4+i),23);
		putc(help2[i]);
	}
	//---------------------------------------------------------Touche
	for (i = 0; i < 9; ++i) {
		move((4+i),20);
		putc(touche[i]);
	}
}

void convert(unsigned char binary, unsigned char *dec){

	dec[2] = (binary % 10); 		//calcul des unit�s
	binary = binary - dec[2];		//suppression des unit�s
	dec[1] = ((binary % 100)/10);	//calcul des dizaines
	binary = binary - dec[1];		//suppression des dizaines
	dec[0] = ((binary % 1000)/100);	//calcul des centaines
	dec[0] += 0x30;					//Ajustement ASCII
	dec[1] += 0x30;
	dec[2] += 0x30;
}

void draw_number(unsigned char x, unsigned char y, unsigned char *dec){
	unsigned char i;
	for (i = 0; i < 3; ++i) {
		move((x+i), y);
		putc(dec[i]);
	}
}

void draw_message(unsigned char x, unsigned char y, const unsigned char *message, unsigned char lenth){
	unsigned char i=0;
	for(i=0; i<lenth; i++){
		move((x+i),y);
		putc(message[i]);
	}
}

void status_RF (unsigned char *check, unsigned char number){
	unsigned char i;
	const unsigned char statusOK[]="connected   " ;
	const unsigned char statusKO[]="disconnected" ;
	
	if (check[number] == 0xFF){
		for (i = 0; i < 12; ++i) {
			move((16+i), 12);
			putc(statusOK[i]);
		}
	}else{
		for (i = 0; i < 12; ++i) {
			move((16+i), 12);
			putc(statusKO[i]);
		}
	}
}




