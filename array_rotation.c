/*

    Hacker Rank -  Cracking the Coding Interview - Arrays: Left Rotation

    Problem URL:
        https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem

    Solution:
        see: array_rotation_HOWTO.txt 

 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define LEFT_SHFIT 0
#define RIGHT_SHIFT 1

void print_result(int *array,int len)
{
    int i=0;
    while(len) {
        len--;
        printf("%d ",array[i++]);
    }
    return;
}

void rotate_array(int *array, const int len,
                  const int rotations, const int shift_direction)
{
    int r;  //Denotes number of rotations
    int l=len; //  
    int i = 0,temp=0,next_i=0;
    int prev = 0;

    /* If  no of shift is exactly half of arryay length,
     * For example: Len = 20, Rotations = 10, then
     * 1st and 11th element will get swapped
     * 2nd and 12th element will get swapped, and so on */
    if(len==rotations*2) {
        l = l/2;
        while(l--) {
            temp = array[i];
            array[i]= array[i+rotations];
            array[i+rotations] = temp;
            i++;
        }
        return;
    }

    /*
      Okay, We're now done wiht handling special case, here
      is the actual algorithm for swapping in place 
    */

     r = (shift_direction == LEFT_SHFIT) ? len-rotations  : rotations;
     l = len;

    /* Begin */
     prev = array[0];
     while(l--) {

        next_i = (i+r)%len;
        temp = array[next_i];
        array[next_i] = prev;
        i=next_i;
        prev = temp;
    }
    return;

}

int solve_puzzle(int *array, int len, int rotations) {
    
    rotations = rotations%len;
    if(rotations) {
        rotate_array(array,len,rotations,LEFT_SHFIT);
    }
    print_result(array,len);
    return 0;
}

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    solve_puzzle(a,n,k);
    printf("\n");
    return 0;
}

