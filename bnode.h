/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Joshua and Brooklyn
 ************************************************************************/

#pragma once

#include <iostream>  // for OFSTREAM
#include <cassert>

/*****************************************************************
 * BNODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BNode
{
public:
   // 
   // Construct
   //
   BNode() : data(0), pLeft(nullptr), pRight(nullptr), pParent(nullptr) {}

   BNode(const T& t) : data(0), pLeft(nullptr), pRight(nullptr), pParent(nullptr)
   {
      
   }
   BNode(T&& t) : data(0), pLeft(nullptr), pRight(nullptr), pParent(nullptr)
   {
      
   }

   //
   // Data
   //
   BNode <T>* pLeft;
   BNode <T>* pRight;
   BNode <T>* pParent;
   T data;
};

/*******************************************************************
 * SIZE BTREE
 * Return the size of a b-tree under the current node
 *******************************************************************/
template <class T>
inline size_t size(const BNode <T> * p)
{
   return 0;
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T> * pNode, BNode <T> * pAdd)
{

}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
inline void addRight (BNode <T> * pNode, BNode <T> * pAdd)
{

}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft (BNode <T> * pNode, const T & t)
{

}

template <class T>
inline void addLeft(BNode <T>* pNode, T && t)
{

}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
void addRight (BNode <T> * pNode, const T & t)
{

}

template <class T>
void addRight(BNode <T>* pNode, T && t)
{

}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
template <class T>
void clear(BNode <T> * & pThis)
{
    pThis = nullptr;
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(BNode <T>*& pLHS, BNode <T>*& pRHS)
{
    pRHS = nullptr;
    pLHS = nullptr;
}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
template <class T>
BNode <T> * copy(const BNode <T> * pSrc)
{
    return 0;
}

/**********************************************
 * assign
 * copy the values from pSrc onto pDest preserving
 * as many of the nodes as possible.
 *********************************************/
template <class T>
void assign(BNode <T> * & pDest, const BNode <T>* pSrc)
{
    // If source is empty just clear the destination 
    if (pSrc == nullptr)
    {
        clear(pDest);
        pDest = nullptr;
        return;
    }

    // If source is not empty 

    // Create a destination if there is none
    if (pDest == nullptr)
    {
        pDest = new BNode<T>;
    }

    // Assign data 
    pDest->data = pSrc->data;

    //Debugging 
    std::cout << "Assigning node with data: " << pDest->data << std::endl;

    // Recursively assign
    assign(pDest->pLeft, pSrc->pLeft);
    assign(pDest->pRight, pSrc->pRight);

    // Pointer to parent 
    if (pDest->pRight != nullptr)
        pDest->pRight->pParent = pDest;
    if (pDest->pLeft != nullptr)
        pDest->pLeft->pParent = pDest;
}
