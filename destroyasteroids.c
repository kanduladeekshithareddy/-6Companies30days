//
//  main.c
//  helloworld
//
//  Created by Deekshitha Reddy on 1/19/23.
//  Copyright (c) 2023 Deekshitha Reddy. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize){
    while(asteroidsSize>0){
        int t;
        int mindiff=1000000;
        int diff;
        for (int i=0;i<asteroidsSize ;i++){
            diff=mass-asteroids[i];
            if (mindiff>=diff && diff>=0){
                mindiff=diff;
                t=i;
            }
        }
        if (mindiff==1000000 && diff<0){
            return false;
        }
        else{
            mass=mass +asteroids[t];
        }
        int p=asteroids[t];
        asteroids[t]=asteroids[asteroidsSize-1];
        asteroids[asteroidsSize-1]=p;
        asteroidsSize--;
    }
    return true;
}int main(int argc, const char * argv[]) {
    int mass=10;
    int arr[5]={3,9,19,5,21};
    int size=5;
    if (asteroidsDestroyed(mass, &arr, size)){
        printf("asteroids destroyed");
    }
    else{
        printf("planet destroyed");
    }
}
