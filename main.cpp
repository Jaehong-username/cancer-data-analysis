
//What is the worst-case Big-O of the insert()algorithm for the AVL tree? Explain.
//The worst case Big-O of insert() algorithm for AVL tree is O(log n). n is the total number of nodes in the AVL tree.
//The AVL Tree is a self-balancing binary search tree. So the worst case scnario is when the tree has to be traversed from the root to the leaf
//which is bounded by the height of the AVL tree. The height of the AVL tree is log n.
//After inserting the new node, balancing the AVL tree is O(1).

// What is the worst-case Big-O of the printInOrder()algorithm for the AVL tree? Explain.
//The worst case Big-O of printInOrder() algorithm for AVL tree is O(n). n is the total number of nodes in the AVL tree.
//because to print every node in order, it must visit each node exactly at once recursively using in-order traversal method.
//This results in worst case time complexity of O(n).

// What is the worst-case Big-O of the findMax()algorithm for the AVL tree? Explain.
//The worst case Big-O of findMax() algorithm for AVL tree is O(log n). n is the total number of nodes in the AVL tree.
//The AVL tree is a self-balancing binary search tree. And, the max node is always at the rightmost leaf node in the AVL tree,
//since it satisfies BST tree requirements. Therefore, it is the height of the AVL tree bounded by log n
//in order to traverse down all the way to the max node from the root node, resulting in worst case time complexity of O(log n).



#include "AVLTree.h"

int main(void)
{
    cout << "\n\n~~~~~All~~~~~\n" << endl;
    ifstream fileStreamAll;
    fileStreamAll.open("allcancerdata2018.csv");
    AVLTree<CancerData> avlTreeAll;
    avlTreeAll.buildAVLTree(fileStreamAll);

    //CancerData dataToRemove("Cyprus", 250.8);
    //CancerData dataToRemove("Sweden", 294.7);
    //CancerData dataToRemove("UK", 319.2);
    //CancerData dataToRemove2("South Korea", 313.5);
    //CancerData dataToRemove1("Israel", 233.6);
    //avlTreeAll.remove(dataToRemove1);
    //avlTreeAll.remove(dataToRemove2);
    avlTreeAll.printInOrder();
    fileStreamAll.close();

    cout << "\n\n~~~~~Men~~~~~\n" << endl;
    ifstream fileStreamMen;
    fileStreamMen.open("mencancerdata2018.csv");
    AVLTree<CancerData> avlTreeMen;
    avlTreeMen.buildAVLTree(fileStreamMen);
    avlTreeMen.printInOrder();
    fileStreamMen.close();

    cout << "\n\n~~~~~Women~~~~~\n" << endl;
    ifstream fileStreamWomen;
    fileStreamWomen.open("womencancerdata2018.csv");
    AVLTree<CancerData> avlTreeWomen;
    avlTreeWomen.buildAVLTree(fileStreamWomen);
    avlTreeWomen.printInOrder();
    fileStreamWomen.close();

    //FindMin and Max function returns the pointer tho the root
    cout << "\n\nHighest and Lowest Records:\n" << endl;
    cout << "All: #1. " << avlTreeAll.findMin()->getData().getCountryName() 
         << ". " << avlTreeAll.findMin()->getData().getCancerRate() << endl;
    cout << "Men: #1. " << avlTreeMen.findMin()->getData().getCountryName()
        << ". " << avlTreeMen.findMin()->getData().getCancerRate() << endl;
    cout << "Women: #1. " << avlTreeWomen.findMin()->getData().getCountryName()
        << ". " << avlTreeWomen.findMin()->getData().getCancerRate() << endl;
    cout << "All: #50. " << avlTreeAll.findMax()->getData().getCountryName()
        << ". " << avlTreeAll.findMax()->getData().getCancerRate() << endl;
    cout << "Men: #50. " << avlTreeMen.findMax()->getData().getCountryName()
        << ". " << avlTreeMen.findMax()->getData().getCancerRate() << endl;
    cout << "Women: #50. " << avlTreeWomen.findMax()->getData().getCountryName()
        << ". " << avlTreeWomen.findMax()->getData().getCancerRate() << endl << endl;

    return 0;
}