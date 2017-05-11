
#ifndef _PROJECT3_H_
#define _PROJECT3_H_

/* If you wish to use different definitions
 * of the following structures, provide new
 * definitions (do not remove  or modify 
 * the existing ones). Make sure that any alternative 
 * structure definitions are equivalent to the
 * ones below.
 */

typedef struct data_ { 
    double d;
    int n1; 
    int n2;
} data; 


typedef struct {
    char c[2];
} cc; 


typedef struct {
    float f1;
    int n1; 
    char c1;
    double f2;
    int n2;  
    char c2;
} data_2;

//this is to optimize the strucutre's space in memory  
//by placing data fields in decreasing memory size, thus
//minimizing the padding done by the compiler.
typedef struct {
    
    double f2;
    float f1;
    int n1;
    int n2;
    char c1;
    char c2;

} data_opt_2;



typedef struct node_ { 
    data value;
    struct node_ * next; 
} node; 



/* DO NOT modify anything below this line */

#define SMALL   64
#define N        1024
#define DIM     512
#define DIM2    1024
#define LARGE   10000
#define LARGER  50000

int level_0( int * B, int x, int y );

int level_0_opt( int * B, int x, int y );

long level_1(long * B, long * A, int x); 

long level_1_opt(long * B, long * A, int x);

char * level_2();

char * level_2_opt();

void level_3 (int *A, int n);

void level_3_opt (int *A, int n);

void addFront(data * s,  node ** head);

void level_4( node** head, int length); 

void level_4_opt(node** head, int length);



#endif 
