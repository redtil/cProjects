//
//  main.c
//  makePictures
//
//  Created by Rediet Tilahun Desta on 4/30/16.
//  Copyright © 2016 Rediet Tilahun Desta. All rights reserved.
//

#include <stdio.h>

void square(){
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= 10; ++j){
            if((i==0) || (j==0) || (i==10) || (j==10))
               printf("*");
            else
                printf(" ");
            if(j==10)
                printf("\n");
           
        }
    }
}
void oval(){
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= 10; ++j){
            if((i==0 || i==10) && (j>=4) && (j<=6))
                printf("*");
            else if((j==0 || j==10) && (i>=2) && (i<=8))
                printf("*");
            else if((i==1 || i==9) && (j==2 || j==8))
                printf("*");
            else
                printf(" ");
            if(j==10)
                printf("\n");
            
        }
    }
}
void arrow(){
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= 4; ++j){
            if(j==2)
                printf("*");
            else if((i==1 || i==2) && (j==1 || j==3))
                printf("*");
            else if((i==2) && (j==0|| j==4))
                printf("*");
            else
                printf(" ");
            if(j==4)
                printf("\n");
        }
    }
}

void diamond(){
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= 10; ++j){
            if((i+j==5) || (i+j==15) || (j-i==5) || (i-j==5))
                printf("*");
            else
                printf(" ");
            if(j==10)
                printf("\n");
        }
    }
}


int main() {
    square();
    oval();
    arrow();
    diamond();
    return 0;
}
