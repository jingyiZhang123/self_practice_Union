
#include "union5.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

extern UnionFind5_p UnionFind5_Init(int n);
extern int UnionFind5_QuickFind(UnionFind5_p uf, int target);
extern bool UnionFind5_IsConnected(UnionFind5_p uf, int a, int b);
extern void UnionFind5_UnionElems(UnionFind5_p uf, int a, int b);
extern void UnionFind5_Destruct(UnionFind5_p uf);

/**************************************
 *                                    *
 * Public functions                   *
 *                                    *
 **************************************/

UnionFind5_p UnionFind5_Init(int n){
    UnionFind5_p new_uf = malloc(sizeof(UnionFind5_t));
    assert(new_uf != NULL);

    new_uf->count = n;
    new_uf->parent = malloc(sizeof(int) * n);
    new_uf->rank = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        new_uf->parent[i] = i;
        new_uf->rank[i] = 1;
    }

    return new_uf;
}

int UnionFind5_QuickFind(UnionFind5_p uf, int target){
    assert(target >= 0 && target < uf->count);
    while (target != uf->parent[target]){
        uf->parent[target] = uf->parent[uf->parent[target]];
        target = uf->parent[target];
    }
    return target;

    // version 2: slower than above because of recursion
    /* if ( target != uf->parent[target]) */
    /*     uf->parent[target] = UnionFind5_QuickFind(uf, uf->parent[target]); */

    /* return uf->parent[target]; */

}

bool UnionFind5_IsConnected(UnionFind5_p uf, int a, int b){
    return UnionFind5_QuickFind(uf, a) == UnionFind5_QuickFind(uf, b);
}

void UnionFind5_UnionElems(UnionFind5_p uf, int a, int b){
    int aRoot = UnionFind5_QuickFind(uf, a);
    int bRoot = UnionFind5_QuickFind(uf, b);
    if(aRoot == bRoot)
        return;

    if(uf->rank[aRoot] < uf->rank[bRoot])
        uf->parent[aRoot] = bRoot;
    else if (uf->rank[bRoot] < uf->rank[aRoot])
        uf->parent[bRoot] = aRoot;
    else{
        uf->parent[aRoot] = bRoot;
        uf->rank[bRoot] += 1;
    }
    return;

}

void UnionFind5_Destruct(UnionFind5_p uf){
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

/**************************************
 *                                    *
 * Private functions                   *
 *                                    *
 **************************************/
