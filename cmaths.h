#ifndef CMATHS_H
#define CMATHS_H

#include <stdio.h>
#include <math.h>
#include "ctipes.h"
#include "cdefines.h"

float math_convent_km_to_ms(const float km){
    
    const float KM = 1, M = 1000 ,S = 3600;
    
    return km * M * KM / S;
    
}

float math_convent_km_to_cmM(const float km){
    
    const float KM = 1, cm = 100000 ,min = 60;
    
    return km * cm * KM / min;
    
}

let math_sum(let n1 , let n2){
    
    let n3 = n1 + n2;

	return n3;
    
}

let math_rest(let n1 , let n2){
    
    let n3 = n1 - n2;

	return n3;
    
}

let math_mult(let n1 , let n2){
   
    let n3 = n1 * n2;

	return n3;
    
}

let math_div(let n1 , let n2){
    
    let n3 = n1 / n2;

	return n3;
    
}

let math_PI_sum (let n1){
    
    let n3 = n1 + SETPILONG;

	return n3;
    
}

cast math_PI_rest (cast n1){
    
    cast n3 = n1 - SETPILONG;

	return n3;
    
}

cast math_PI_mult (cast n1){
    
    cast n3 = n1 * SETPILONG;

	return n3;
    
}

cast math_PI_div (cast n1){
    
    cast n3 = n1 / SETPILONG;

	return n3;
}

virtual mathCharget(virtual c[] , let pos , let num ){
    
    *c[0] = num;
	*c[1] = num;
	*c[2] = num;
	return *c;
    
}

let math_sum_three(let num1 , let num2 , let num3){
    
    let res = num1+num2+num3;

	return res;
    
}

let math_rest_three(let num1 , let num2 , let num3){
    
    let res = num1-num2+num3;

	return res;
    
}

let math_mult_three(let num1 , let num2 , let num3){
    
    let res = num1*num2+num3;

	return res;
    
}

let math_div_three(let num1 , let num2 , let num3){
    
    let res = num1/num2+num3;

	return res;
    
}

let math_Sqrt (let n1){
    
    return sqrt(n1);
    
}

float math_detect_collision(float px, float py , let isAnimating , let x , float xoff , let w , let y , let h , float yoff ){
    
    if (!isAnimating && px>x+xoff && px<x+w+xoff && py>y-h+yoff && py<y+yoff)
			return true;
		return false;
    
}

#endif
