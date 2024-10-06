#pragma once

#include "AVLNode.h"


template <class T>
class AVLTree
{
public:
    

    AVLTree() : pRoot{ nullptr }, howManyDeleted{0} //this way is faster!!
    {
    }

    ~AVLTree(); //destructor for AVL Tree

    AVLTree(const AVLNode<T>& other); //semicolon!!

    bool isEmpty();

    //User interface
    int height(AVLNode<T>* pRootNode); //returns the height of the node or -1 if nullptrz`
    void insert(T& data); //insert data into the tree.
    void remove(T& data); //remove the matching data from the tree
    void buildAVLTree(ifstream& fileStream);
    void clear(void);
    AVLNode<T>*& findMin(void);
    AVLNode<T>*& findMax(void);
    void printInOrder(void) const;
 
    //Getter:
    AVLNode<T>*& getpRoot(void);

    void setpRoot(AVLNode<T>* pRoot);

private:
    AVLNode<T>* pRoot;
    int howManyDeleted;
    AVLNode<T> *cloneTree(AVLNode<T> *pRootSrc);
    void clear(AVLNode<T>* pRoot); // remove all nodes from the tree.
    AVLNode<T>*& findMin(AVLNode<T>*& pRoot);
    AVLNode<T>*& findMax(AVLNode<T>*& pRoot);
    void printInOrder(AVLNode<T>* pRoot) const; //const keyword the tree must not be modified at all costs

    void insert(T& data, AVLNode<T>*& pRoot); //insert data into the tree.
    void remove(T& data, AVLNode<T>*& pRoot); //remove the matching data from the tree

    void balanceTree(AVLNode<T>*& pRoot);
    void rotateWithLeftChild(AVLNode<T>*& pRootNode);
    void rotateWithRightChild(AVLNode<T>*& pRootNode);
    
};


template <class T>
  AVLTree<T>::~AVLTree()
{
    this->clear();
    cout << "AVL Tree Destructor completed!" << endl;
}

template<class T>
  AVLTree<T>::AVLTree(const AVLNode<T>& other) : pRoot(nullptr)
{
    this->pRoot = cloneTree(other);
}


template <class T>
  bool AVLTree<T>::isEmpty()
{
    if (this->pRoot == nullptr)
        return 1; // 1 represents true
    else
        return 0; //0 represents false

    //return this->pRoot == nullptr; shortcut!!
}


//Reference!!!
template<class T>
  AVLNode<T>* AVLTree<T>::cloneTree(AVLNode<T>* pRootSrc)
{
    if (pRootSrc == nullptr)
    {
        return nullptr;
    }
    
    else
    {
        return new AVLNode<T>(pRootSrc->getData(), 
                              cloneTree(pRootSrc->getpLeft()), 
                              cloneTree(pRootSrc->getpRight()), 
                              pRootSrc->getHeightAVLNode());
    }
}


//Reference Power Point slide: Balanced Binary Search Trees: AVL Trees and Splay Trees
template <class T>
  int AVLTree<T>::height(AVLNode<T>* pRootNode)
{
    //ANother way of calculating the height for each node
    //if (pRootNode == nullptr)
    //    return -1;
    //else
    //{
    //    // post traversal method going down untill nullptr of the leaf node. and return -1
    //    int leftHeight = height(pRootNode->getpLeft());
    //    int rightHeight = height(pRootNode->getpRight());
    //    return std::max(leftHeight, rightHeight) + 1; //then the leaft node height will be 0
    //}

    return pRootNode == nullptr ? -1 : pRootNode->getHeightAVLNode();
}

template <class T>
  void AVLTree<T>::insert(T& data)
{
    insert(data, pRoot); //make sure to put the arguments in the right order
    //otherwise you will get an error saying that no overloaded function could convert all the argument types
}

template <class T>
  void AVLTree<T>::remove(T& data)
{
    this->remove(data, this->pRoot); //make sure to put the arguments in the right order
    //otherwise you will get an error saying that no overloaded function could convert all the argument types
}

template <class T>
  void AVLTree<T>::buildAVLTree(ifstream& fileStream)
{
    if (fileStream.is_open()) //make sure to put ()! for a function otherwise you will get an error non-stnadard syntax &
    {                         //To create a pointer to member
        string tempLine;
        string tempCountryName;
        string tempCancerRate;

        while (std::getline(fileStream, tempLine)) //copies each line until \n or eof
        {
            std::stringstream tempLineStream(tempLine);

            std::getline(tempLineStream, tempCountryName, ','); //Country Name
            std::getline(tempLineStream, tempCancerRate, ','); //Cancer rate

            //tempCountryName, tempCancerRate
            //Creating a copy of data object and a node that goes into three based on parsed data
            T data(tempCountryName, std::stof(tempCancerRate)); //T will be replaced with CancerData class.
            AVLNode<T> avlNode(data);

            //Inserting the node into AVL Tree;
            insert(data); //public function should pass in node instead should be data
        }

        
    }

    else
        cout << "THe csv filestream is not opened! Please double check " << endl;
}

template <class T>
  void AVLTree<T>::clear(void)
{
    this->clear(this->pRoot);
}

template <class T>
  void AVLTree<T>::clear(AVLNode<T>* pRoot)
{
    if (pRoot != nullptr)
    {
        clear(pRoot->getpLeft()); //cannot access the private member without using the get function
        clear(pRoot->getpRight()); //change the return type of get function from & to *&
        delete pRoot;
    }
}

template <class T>
AVLNode<T>* &AVLTree<T>::findMin(void)
{
    //cout << "print the data from the node\n"
    //     << pRoot->getData()->getCancerRate();
    return findMin(pRoot);
}

template <class T>
AVLNode<T>* &AVLTree<T>::findMax(void)
{
    return findMax(pRoot);
}

template <class T>
  void AVLTree<T>::printInOrder(void) const
{
    printInOrder(pRoot);
}

template <class T> //error: *& pRoot!! needs to be passed in!!! Not just * pointer!
AVLNode<T>*& AVLTree<T>::findMin(AVLNode<T>*& pRoot)
{
    //cout << "print the data from the node\n"
    //     << pRoot->getData().getCancerRate();
    if (pRoot->getpLeft() != nullptr)
    {
        return findMin(pRoot->getpLeft());
    }

    else
        return pRoot; //return to the pointer to thhe min node
    
    /*if(pRoot != nullptr)
    {
        AVLNode<T> *pCur = pRoot;
    
        while(pCur->getpLeft() != nullptr)
        {
            pCur = pCur->getpLeft();
        }
    
        //once out of the while loop it is a min node
        return pCur;
    }*/
    
    
}

template <class T>
AVLNode<T>*& AVLTree<T>::findMax(AVLNode<T>*& pRoot)
{   
    if (pRoot->getpRight() != nullptr)
    {
        return findMax(pRoot->getpRight());
    }

    else
        return pRoot; //return to the pointer to thhe max node
    
    /*if(pRoot != nullptr)
    {
        AVLNode<T> *pCur = pRoot;
    
        while(pCur->getpRight() != nullptr)
        {
            pCur = pCur->getpRight();
        }
    
        //once out of the while loop it is a min node
        return pCur;
    } */
    
    
}

template <class T> //From highest to lowest! getpRight() first and getpLeft()
  void AVLTree<T>::printInOrder(AVLNode<T>* pRoot) const
{
    static int order = 1;
    //int order = 1;
    if (pRoot != nullptr) //make sure to put this if statement!!!!!
    {
        //int order = 1;
        printInOrder(pRoot->getpRight());    //must get rid of this keyword otherwise it will only print the first row!!
        cout << "All: #"<< order << ". " << pRoot->getData().getCountryName() << ". " << pRoot->getData().getCancerRate() << endl;
        (order == (50 - howManyDeleted)) ? order = 1 : ++order;
        
        printInOrder(pRoot->getpLeft());
    }
    
    
}

//internal node: node that has at least one child node.
template<class T>
  void AVLTree<T>::balanceTree(AVLNode<T>*& pRoot)
{
    if (pRoot == nullptr)
        return;
    //if child node height imbalance is more than one, it defies the AVL tree property.
    if ( height(pRoot->getpLeft()) - height(pRoot->getpRight()) > 1)
    {
        //this case ensure violation of left left case
        if (height(pRoot->getpLeft()->getpLeft()) >= height(pRoot->getpLeft()->getpRight())) //case 1 violation
        {
            rotateWithLeftChild(pRoot);
        }

        else //case 2 violations   double roations are needed
        {
            rotateWithRightChild(pRoot->getpLeft());
            rotateWithLeftChild(pRoot);
        }
    }

    else if(height(pRoot->getpRight()) - height(pRoot->getpLeft()) > 1)
    {
        //case 4 violiation
        //this case ensure violation of right right case
        if (height(pRoot->getpRight()->getpRight()) >= height(pRoot->getpRight()->getpLeft())) //case 1 violation
        {
            rotateWithRightChild(pRoot);
        }

        else //case 3 violations  double roations are needed
        {
            rotateWithLeftChild(pRoot->getpRight());
            rotateWithRightChild(pRoot);
            
        }

    }
    
    //updating the height!!
    pRoot->setHeightAVLNode(std::max( height(pRoot->getpLeft()), height(pRoot->getpRight()) ) + 1);
}

template <class T>
  void AVLTree<T>::rotateWithLeftChild(AVLNode<T>*& pRootNode)
{
    AVLNode<T>* targetNode = pRootNode->getpLeft(); //assigns a new pointer to the left child of the pRootNode
    pRootNode->setpLeft(targetNode->getpRight());
    targetNode->setpRight(pRootNode);
    
    //Next let's update the height
    //original pRoot node first!
    pRootNode->setHeightAVLNode( std::max( height(pRootNode->getpLeft()), height(pRootNode->getpRight()) ) + 1 );
    //Then let's update the targetNode height
    targetNode->setHeightAVLNode(std::max(height(targetNode->getpLeft()), height(pRootNode)) + 1);
    pRootNode = targetNode; //relink the origianl pRootnode to the target node.
}

template <class T>
  void AVLTree<T>::rotateWithRightChild(AVLNode<T>*& pRootNode)
{
    AVLNode<T>* targetNode = pRootNode->getpRight(); //assigns a new pointer to the left child of the pRootNode
    pRootNode->setpRight(targetNode->getpLeft());
    targetNode->setpLeft(pRootNode);

    //Next let's update the height
    //original pRoot node first!
    pRootNode->setHeightAVLNode(std::max(height(pRootNode->getpRight()), height(pRootNode->getpLeft())) + 1);
    //Then let's update the targetNode height
    targetNode->setHeightAVLNode(std::max(height(targetNode->getpRight()), height(pRootNode)) + 1);
    pRootNode = targetNode; //relink the origianl pRootnode to the target node.
}



template <class T>
  AVLNode<T>*& AVLTree<T>::getpRoot(void)
{
    return pRoot;
}

template<class T>
  void AVLTree<T>::setpRoot(AVLNode<T>* pRoot)
{
    this->pRoot = pRoot;
}



template <class T>
  void AVLTree<T>::insert(T& data, AVLNode<T>*& pRoot)
{
    if (pRoot == nullptr)
    {
        pRoot = new AVLNode<T>(data); //make sure to put <T> otherwise cannot invoke the constructor
        pRoot->setHeightAVLNode(height(pRoot));
    }

    else
    {
        if (data.getCancerRate() < pRoot->getData().getCancerRate()) //goes to the left subtree
        {
            if (pRoot->getpLeft() != nullptr)
            {
                insert(data, pRoot->getpLeft());
            }

            else
            {
                pRoot->setpLeft(new AVLNode<T>(data));
                //pRoot->setHeightAVLNode(height(pRoot));
            }
        }

        else if (data.getCancerRate() > pRoot->getData().getCancerRate()) //inserts it into the right subtree
        {
            if (pRoot->getpRight() != nullptr)
            {
                insert(data, pRoot->getpRight());
            }

            else
            {
                pRoot->setpRight(new AVLNode<T>(data));
                //pRoot->setHeightAVLNode(height(pRoot));
            }
        }

        else //cancer rate duplicate!!
        {
            if (data.getCountryName() < pRoot->getData().getCountryName())
            {
                if (pRoot->getpLeft() != nullptr)
                {
                    insert(data, pRoot->getpLeft());
                }

                else
                {
                    pRoot->setpLeft(new AVLNode<T>(data));
                }
            }

            else if (data.getCountryName() > pRoot->getData().getCountryName())
            {
                if (pRoot->getpRight() != nullptr)
                {
                    insert(data, pRoot->getpRight());
                }

                else
                {
                    pRoot->setpRight(new AVLNode<T>(data));
                }

            }

        }
    }

    balanceTree(pRoot);
}


//source: https://users.cs.fiu.edu/%7Eweiss/dsaa_c%2B%2B4/code/AvlTree.h
//assuming there are no duplicates
template <class T>
  void AVLTree<T>::remove(T& data, AVLNode<T>*& pRoot)
{
    if (pRoot == nullptr)
    {
        cout << "The tree is empty. Nothing to remove!" << endl;
        return;
    }

    //assuming that data has not found the match either keep going downward to the left subtree or right subtree
    if (data.getCancerRate() < pRoot->getData().getCancerRate())
    {
        remove(data, pRoot->getpLeft());
    }

    else if (data.getCancerRate() > pRoot->getData().getCancerRate())
    {
        remove(data, pRoot->getpRight());
    }

    //assuming that we found the data match!!!

    //Case1: the node to be delted has no childs (easy case)
    else if (data.getCancerRate() == pRoot->getData().getCancerRate() && pRoot->getpLeft() == nullptr
        && /*this->*/pRoot->getpRight() == nullptr)
    {
        
        delete pRoot;
        pRoot = nullptr;
        
        ++howManyDeleted;
    }
    
    //Case2: If the node has both left and right subtrees
    else if (data.getCancerRate() == pRoot->getData().getCancerRate() && pRoot->getpLeft() != nullptr
        && pRoot->getpRight() != nullptr)
    {
        
        pRoot->getData().setCancerRate(findMin(pRoot->getpRight())->getData().getCancerRate());
        pRoot->getData().setCountryName(findMin(pRoot->getpRight())->getData().getCountryName());

        remove(pRoot->getData(), pRoot->getpRight());
        
        ++howManyDeleted;
    }
    //case 3: has only one subtree either left or right
    else
    {
        
        AVLNode<T>* deletingNode = pRoot; //have another pointer to the pRoot
        //cout << "Deleting the node: " << pRoot->getData().getCountryName() << ". " << pRoot->getData().getCancerRate() << endl;
                                         //getData() will get a class object which is not a ptr. so use the dot operator
        //Relink the pointer to the root node since we are deleting the node
        if (pRoot->getpLeft() != nullptr)
            pRoot = pRoot->getpLeft();
        else
            pRoot = pRoot->getpRight();

        //SHort cut: from https://users.cs.fiu.edu/%7Eweiss/dsaa_c%2B%2B4/code/AvlTree.h remove function
        //pRoot = (pRoot->getpLeft()) ? pRoot->getpLeft() : pRoot->getpRight();


        //deleting the target Node
        delete deletingNode;
        //deletingNode->setpRoot(nullptr); I found an error!!!
        deletingNode->setpLeft(nullptr);
        deletingNode->setpRight(nullptr);

        ++howManyDeleted;
    }

    //After the deleting the tree let's balance the tree!
    balanceTree(pRoot);
}

//Need function overloading for < > ==  !
template <class T>
bool operator<(const T& lhs, const T& rhs) 
{
    return lhs < rhs;
}

template <class T>
bool operator>(const T& lhs, const T& rhs)
{
    return lhs > rhs;
}

template <class T>
bool operator==(const T& lhs, const T& rhs)
{
    return lhs == rhs;
}
