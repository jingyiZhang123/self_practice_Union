
#include "union4.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

extern UnionFind4_p UnionFind4_Init(int n);
extern int UnionFind4_QuickFind(UnionFind4_p uf, int target);
extern bool UnionFind4_IsConnected(UnionFind4_p uf, int a, int b);
extern void UnionFind4_UnionElems(UnionFind4_p uf, int a, int b);
extern void UnionFind4_Destruct(UnionFind4_p uf);

/**************************************
 *                                    *
 * Public functions                   *
 *                                    *
 **************************************/

UnionFind4_p UnionFind4_Init(int n){
    UnionFind4_p new_uf = malloc(sizeof(UnionFind4_t));
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

int UnionFind4_QuickFind(UnionFind4_p uf, int target){
    assert(target >= 0 && target < uf->count);
    while (target != uf->parent[target])
        target = uf->parent[target];

    return target;
}

bool UnionFind4_IsConnected(UnionFind4_p uf, int a, int b){
    return UnionFind4_QuickFind(uf, a) == UnionFind4_QuickFind(uf, b);
}

void UnionFind4_UnionElems(UnionFind4_p uf, int a, int b){
    int aRoot = UnionFind4_QuickFind(uf, a);
    int bRoot = UnionFind4_QuickFind(uf, b);
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

void UnionFind4_Destruct(UnionFind4_p uf){
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

/**************************************
 *                                    *
 * Private functions                   *
 *                                    *
 **************************************/
