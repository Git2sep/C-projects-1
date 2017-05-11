/* 
 * Project3: 
 * This program calls each of the functions that you implement
 * for this project. It runs the original function and your
 * optimized function.
 * The program performs very basic evaluation of correctness
 * (but you should make sure on your own that your function is
 * equivalent to the one that is given to you). 
 * 
 * author: Joanna Klukowska 
 * 
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "proj3.h"

/////////////////////////////////////////////
//                                         //
// DO NOT MODIFY anything in this file.    //
//                                         //
/////////////////////////////////////////////

int list[LARGER];

void flood_cache () ;

/***********************************************/

int main(int argc, char *argv[])
{

    int i, j, level = -1 ;
    int b, n1, n2; 
    int x,y;
    double d1, d2; 
    long l1, l2;
    
    srand(time(0));
    srand48(time(0));
    
/* level 0 - this is a warmup exercise - it will not be graded*/
    int * B1 = (int * ) malloc ( N*N*sizeof(int) ) ;
    if (!B1) return -1; 
    int * B2 = (int * ) malloc ( N*N*sizeof(int) ) ;
    if (!B2) return -1; 
    for (i = 0; i < N*N; i++) {
        b = rand();
        B1[i] = b;
        B2[i] = b;
    }
    flood_cache(); 
    x =  rand()%N; 
    y =  rand()%N;
    
    n1 = level_0(B1, x, y);
    
    printf("level_0 completed \n" ) ;
    
    n2 = level_0_opt(B2, x, y);

    printf("level_0_opt completed  \n" ) ;
    
    if (n1==n2)    printf("\tlevel_0_opt PASSED\n");
    else printf("\tlevel_0_opt FAILED\n"); 
    
    if ( B1!= 0 ) { free(B1); B1 = 0; } 
    if ( B2!= 0 ) { free(B2); B2 = 0; } 
    

/* level 1 */    

    long * F1 = (long * ) malloc( N*N*sizeof(long) ) ;
    if (!F1) return 0; 
    long * F2 = (long * ) malloc (N*N*sizeof(long) );
    if (!F2) return 0; 

    for (i = 0; i < N*N; i++) {
        F1[i] =  rand();
        F2[i] =  rand();
    }
    x =  rand()%N; 
    
    flood_cache(); 
    l1 = level_1(F1, F2, x);
    
    printf("level_1 completed \n" ) ; 
    
    //attempt to overwrite the memory locations that were used
    //by the original list
    long * stuff = (long*) calloc(LARGER,  sizeof(long) ); 
    if (stuff == 0 ) return 0;
    else free (stuff); 
    
    flood_cache(); 
    l2 = level_1_opt(F1, F2, x);
    
    printf("level_1_opt completed  \n") ;

    if (l1==l2)    printf("\tlevel_1_opt PASSED\n");
    else printf("\tlevel_1_opt FAILED\n"); 
    
    if (F1 != 0 ){  free (F1); F1=0; }
    if (F2 != 0 ){  free (F2); F2=0; }

/* level 2 */    
    
    flood_cache();
    char * c1 =  level_2();
    printf("level_2 completed \n" ) ; 
    
    //attempt to overwrite the memory locations that were used
    //by the original list
    stuff = (long*) calloc(LARGER,  sizeof(long) ); 
    if (stuff == 0 ) return 0;
    else free (stuff); 
    
    flood_cache();
    char * c2 = level_2_opt();
    printf("level_2_opt completed \n" ) ; 
    
    if (c1!=NULL && c2!=NULL && strcmp(c1,c2)==0)    
        printf("\tlevel_2_opt PASSED\n");
    else printf("\tlevel_2_opt FAILED\n"); 
    
    if (c1 != 0 ) { free (c1); c1 = 0; } 
    if (c2 != 0 ) { free (c2); c2 = 0; } 
        
/* level 3 */ 

    x = N*N; 
    int * F = (int * ) malloc( x*sizeof(int) ) ;
    if (!F) return 0; 
    for (i = 0; i < x; i++){
        F[i] =   rand()%2; 
    }
    
    int * F_opt = (int * ) malloc( x*sizeof(int) ) ;
    if (!F_opt) return 0; 
    for (i = 0; i < x; i++){
        F_opt[i] =   F[i]; 
    }
     
    
    flood_cache(); 
    level_3(F, N);
    
    printf("level_3 completed \n" ) ; 
    
    flood_cache(); 
    level_3_opt(F_opt, N);
    
    printf("level_3 completed  \n") ; 
    
    int level3_passed = 1;
    for (i = 0; i < x; i++){
        if (F[i] != F_opt[i]) { 
            level3_passed = 0;
            break; 
        }
    }

    if (level3_passed)    printf("\tlevel_3_opt PASSED\n");
    else printf("\tlevel_3_opt FAILED\n"); 
    
    if (F != 0 ){  free (F); F=0; }
    if (F_opt != 0 ){  free (F_opt); F_opt=0; }
        
/* level 4 */    
    node * head1 = 0;
    node * head2 = 0; 
    
    for (i = 0; i < LARGER; i++)  {
        data s = { drand48(),rand(), rand() } ; 
        addFront (&s, &head1 );
        addFront (&s, &head2 ); 
    }
    
    node * head1_org = head1;
    node * head2_org = head2;
    
    flood_cache();
    level_4( &head1, LARGER ); 

    node * test;
    
    printf("level_4 completed \n" ) ; 
    printf("%lu\n", sizeof(test) );
        
    flood_cache();
    level_4_opt( &head2, LARGER ); 
    
    //attempt to overwrite the memory locations that were used
    //by the original list
    stuff = (long*) calloc(LARGER,  sizeof(long) ); 
    if (stuff == 0 ) return 0;
    else free (stuff); 
    
    
    printf("level_4_opt completed \n" ) ; 
    
    int passed = 1;
    if (head2_org == head2) 
        passed = 0;
    node * h1 = head1;
    node * h2 = head2; 
    for (i = 0; i < LARGER && passed; i++)  {
        if ( (h1->value).n1  != (h2->value).n1 ) {
            passed = 0;
            break;
        }
        if (h1->next != 0 ) {
            h1 = h1->next; 
        }
        else if (i != LARGER-1) {
            passed = 0;
            break;
        }
        if (h2->next != 0 ) {
            h2 = h2->next; 
        }
        else if (i != LARGER-1) {
            passed = 0; 
            break;
        } 
    }
    if (passed )     printf("\tlevel_4_opt PASSED\n");
    else printf("\tlevel_4_opt FAILED\n"); 
    
    if (head1!=0) { free(head1); head1=0; }  
    if (head2!=0) { free(head2); head2=0; }  
    
    
    
}

// Perform an operation that will replace the cache content
// forcing the function to start with an "empty" cache. 
void flood_cache () { 
    int i = 0;
    
    for ( i =0; i < LARGER; i++ ){
        list[i] = rand();     
    }    
}
