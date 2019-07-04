#ifndef TREE_H
#define TREE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);

/**
 * @brief 返回树T中具有关键字X的结点的指针, 不存在则返回NULL
 * 
 * @param X 
 * @param T 
 * @return Position 
 */
Position Find(ElementType X, SearchTree T);

/**
 * @brief 返回树中最小单位的位置
 * 
 * @param T 
 * @return Position 
 */
Position FindMin(SearchTree T);

/**
 * @brief 返回树中最小单位的位置
 * 
 * @param T 
 * @return Position 
 */
Position FindMax(SearchTree T);


SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);


#endif