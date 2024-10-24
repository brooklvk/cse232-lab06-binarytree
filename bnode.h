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
 *    Joshua Sooaemalelagi and Brooklyn Sowards,
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


    /*
	* data wasnt init, changed pointers from this to a nullptr.
    */
    BNode()
		: data(T()), pLeft(nullptr), pRight(nullptr), pParent(nullptr)
    {
    }
    BNode(const T& t)
        : data(t), pLeft(nullptr), pRight(nullptr), pParent(nullptr)
    {
    }
    BNode(T&& t)
        : data(std::move(t)), pLeft(nullptr), pRight(nullptr), pParent(nullptr)
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
inline size_t size(const BNode <T>* p)
{
    if (!p)
        return 0;
    return 1 + size(p->pLeft) + size(p->pRight);
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T>* pNode, BNode <T>* pAdd)
{
    if (pNode)
    {
        pNode->pLeft = pAdd;
        if (pAdd)
            pAdd->pParent = pNode;
    }
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
inline void addRight(BNode <T>* pNode, BNode <T>* pAdd)
{
    if (pNode)
    {
        pNode->pRight = pAdd;
        if (pAdd)
            pAdd->pParent = pNode;
    }
}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T>* pNode, const T& t)
{
    if (pNode)
    {
        BNode<T>* pAdd = new BNode<T>(t);
        pNode->pLeft = pAdd;
        pAdd->pParent = pNode;
    }
}

template <class T>
inline void addLeft(BNode <T>* pNode, T&& t)
{
    if (pNode)
    {
        BNode<T>* pAdd = new BNode<T>(std::move(t));
        pNode->pLeft = pAdd;
        pAdd->pParent = pNode;
    }
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
void addRight(BNode <T>* pNode, const T& t)
{
    if (pNode)
    {
        BNode<T>* pAdd = new BNode<T>(t);
        pNode->pRight = pAdd;
        pAdd->pParent = pNode;
    }
}

template <class T>
void addRight(BNode <T>* pNode, T&& t)
{
    if (pNode)
    {
        BNode<T>* pAdd = new BNode<T>(std::move(t));
        pNode->pRight = pAdd;
        pAdd->pParent = pNode;
    }
}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
template <class T>
void clear(BNode <T> * & pThis)
{
	if (pThis) // if pThis is not already nothing, delete it all
    {
        clear(pThis->pLeft);
        clear(pThis->pRight);
        delete pThis;
        pThis = nullptr;
    }
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(BNode <T>*& pLHS, BNode <T>*& pRHS)
{
    BNode<T>* tempSwaper = pLHS;
    pLHS = pRHS;
    pRHS = tempSwaper;
}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
template <class T>
BNode <T> * copy(const BNode <T> * pSrc)
{
    if (!pSrc) // check empty first always
        return nullptr;

    BNode<T>* pCopy = new BNode<T>(pSrc->data);

    pCopy->pLeft = copy(pSrc->pLeft); // copy left
    if (pCopy->pLeft)
        pCopy->pLeft->pParent = pCopy;

	pCopy->pRight = copy(pSrc->pRight); // copy right
    if (pCopy->pRight)
        pCopy->pRight->pParent = pCopy;

	return pCopy; // send back the copy
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
