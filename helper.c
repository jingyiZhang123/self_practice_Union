#include "helper.h"
#include "union1.h"
#include "union2.h"
#include "union3.h"
#include "union4.h"
#include "union5.h"


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>


extern void testUF1(int n);
extern void testUF2(int n);
extern void testUF3(int n);
extern void testUF4(int n);
extern void testUF5(int n);


void testUF1(int n){
    srand(time(NULL));

    UnionFind1_p uf = UnionFind1_Init(n);

    clock_t t1, t2;
    t1 = clock();

    for (int i = 0; i < n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind1_UnionElems(uf, a, b);
    }
    for (int i=0; i<n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind1_IsConnected(uf, a, b);
    }
    t2 = clock();

    float diff = ((float)(t2 - t1) / 1000000.0F );

    printf("%s: %f seconds. Size: %d\n", "UnionFind1", diff, n);
    UnionFind1_Destruct(uf);

}


void testUF2(int n){
    srand(time(NULL));

    UnionFind2_p uf = UnionFind2_Init(n);

    clock_t t1, t2;
    t1 = clock();

    for (int i = 0; i < n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind2_UnionElems(uf, a, b);
    }
    for (int i=0; i<n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind2_IsConnected(uf, a, b);
    }
    t2 = clock();

    float diff = ((float)(t2 - t1) / 1000000.0F );

    printf("%s: %f seconds. Size: %d\n", "UnionFind2", diff, n);
    UnionFind2_Destruct(uf);
}


void testUF3(int n){
    srand(time(NULL));

    UnionFind3_p uf = UnionFind3_Init(n);

    clock_t t1, t2;
    t1 = clock();

    for (int i = 0; i < n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind3_UnionElems(uf, a, b);
    }
    for (int i=0; i<n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind3_IsConnected(uf, a, b);
    }
    t2 = clock();

    float diff = ((float)(t2 - t1) / 1000000.0F );

    printf("%s: %f seconds. Size: %d\n", "UnionFind3", diff, n);
    UnionFind3_Destruct(uf);
}

void testUF4(int n){
    srand(time(NULL));

    UnionFind4_p uf = UnionFind4_Init(n);

    clock_t t1, t2;
    t1 = clock();

    for (int i = 0; i < n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind4_UnionElems(uf, a, b);
    }
    for (int i=0; i<n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind4_IsConnected(uf, a, b);
    }
    t2 = clock();

    float diff = ((float)(t2 - t1) / 1000000.0F );

    printf("%s: %f seconds. Size: %d\n", "UnionFind4", diff, n);
    UnionFind4_Destruct(uf);
}


void testUF5(int n){
    srand(time(NULL));

    UnionFind5_p uf = UnionFind5_Init(n);

    clock_t t1, t2;
    t1 = clock();

    for (int i = 0; i < n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind5_UnionElems(uf, a, b);
    }
    for (int i=0; i<n; i++) {
        int a = rand()%n;
        int b = rand()%n;
        UnionFind5_IsConnected(uf, a, b);
    }
    t2 = clock();

    float diff = ((float)(t2 - t1) / 1000000.0F );

    printf("%s: %f seconds. Size: %d\n", "UnionFind5", diff, n);
    UnionFind5_Destruct(uf);
}
