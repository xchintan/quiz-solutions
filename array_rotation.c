/*

    Hacker Rank -  Cracking the Coding Interview - Arrays: Left Rotation

    Problem URL:
        https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem

    Solution:
        Well,I've two solutions:
                        A) One doing it right
                        B) Just print the result, the way hackerrank expects.

    Approach B:
        Yeah, let's talk about the plan B first. This is about tricking hackerrank in
        believing that you have solved the problem because hackerrank relies solely
        on the STDIO o/p.

        Print the first portion followed by remaining portion. For example:
        10 20 30 40 50 --- Left shift two times ---->  30 40 50 10 20

        1st Print: 30 40 50 (i.e. array[2] --- array ends)
        2nd Print: 10 20    (From the beginning till array[2])


    Approach A:
        I call this is the right way, shifting array in-space - without the need of any
        temporary memory space - the algorithm time complexity is O(N). It took a while to
        arrive on this solution, I was trying with 'temporary buffer' and memove but that
        solution didn't scale up with million numbers.

        I'm not sure how to explain, anyway here it goes:

        Array:          10 20 30 40 50
        Rotate Left:    2 Times

                Index          0    1   2   3   4
                Value          10  20  30  40  50

    1st Iteration:
        Q:      Where should a[0] go?
        Ans:    At location a[3].
                Okay, take backup of a[3] which is 40
                        and a[3] = a[0]



                Array:          10 20 30 10 50
                Backed up val:  40


    2nd Iteration:
        Q:      What was the prev index we modified?
                Index = 3

        Q:      Where should index 3 go now?
                Ans: at Location a[1]

                Okay, so we have all the info we need
                Take backup of a[1] which  20
                place earlier backed-up val 40 at a[1]

                Array:          10 40 30 10 50
                Backed up:      20

    3rd Iteration:
        Q:       What was the prev index we modified?
                    Index = 1

                    Where should index 1 should go now?
                    Ans: at location a[4]

                    Okay, so we have all the info we have
                    Take backup of a[4] which is 50

                    Array:         10 40 30 10 20
                    Backed up:     50

    And so on..  If you do two more iterations, you will arrive the result.

    Hacker Rank -  Crakcing the Coding Interview - Arrays: Left Rotation

    Problem URL:
        https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
    
    Solution:
        Well,I've two solutions:
                        A) One doing it right 
                        B) Just print the result, the way hackerrank expects.

    Approach B:
       Yeah, let's tak about the plan B first. This is about tricking hackerrank in
       beleiving that you have solved the problem because hackerrank relies solely 
       on the STDIO o/p.
    
       Print the first portion followed by remaining portion. For example:
       10 20 30 40 50 --- Left shift two times ---->  30 40 50 10 20

       1st Print: 30 40 50 (i.e. array[2] --- array ends)
       2nd Print: 10 20    (From the beginning till array[2])

       the problem, because it relies soley
       I took a while to arrive to this solution. I'm doing in-place shift/rotation,
       so there's no space complexity.

    Approach A:
        I call this is the right way, shifting array in-space - without the need of any
        temporary memory space - the algorith time complexity is O(N).
    
        The solution given here mimics the algorithm I'm (trying to) explain here.

        Array:          10 20 30 40 50
        Rotate Left:    2 Times
        
                Index          0    1   2   3   4
                Value          10  20  30  40  50

1st Iteration:  
        Q:      Where should a[0] go?
        Ans:    At location a[3].
                Okay, take backup of a[3] which is 40
                      and a[3] = a[0]

                
        
                Array:          10 20 30 10 50 
                Backed up val:  40
                
        
2nd Iteration:
        Q:      What was the prev index we modified?
                Index = 3

        Q:      Where should index 3 go now?
                Ans: at Location a[1]       

                Okay, so we have all the info we need
                Take backup of a[1] which  20
                place earlier backed-up val 40 at a[1]

                Array:          10 40 30 10 50
                Backed up:      20

3rd Iteration:
        Q:       What was the prev index we modified?
                 Index = 1
        
                 Where should index 1 should go now?
                 Ans: at location a[4] 

                 Okay, so we have all the info we have
                 Take backup of a[4] which is 50

                 Array:         10 40 30 10 20   
                 Backed up:     50

And so on..  If you do two more itrations, you will arrive the result.

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

