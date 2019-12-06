#include <iostream>
#include "src/bTree.cpp"

using namespace std;

template<class T>
void logDebugging( bTree<T> & theTree ){
    cout << ";;;;Debugging:\n";
    cout << "height: " << theTree.getHeight() << "\n" ;
    cout << "root size: " << theTree.getRootSize() << "\n";
    cout << "amount of element: " << theTree.size() << "\n";
    cout << "count of root size linearly: " << theTree.countRootSize() << "\n";
    theTree.printPreorder() ;
    theTree.printInorder();
}

template<class T>
void testRemove1(bTree<T> & theTree4 ){
    theTree4.insert(10);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(10);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(100);
    theTree4.insert(200);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(10);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(100);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(100);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(200);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(200);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(150);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    ///second type of testing
    std::cout << "&&&&&&&&&&&&&&&&&second type of testing\n";
    theTree4.remove(100);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(100);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(200);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(200);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(150);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(150);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(170);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(200);
    theTree4.printPreorder();
    theTree4.printInorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(130);
    theTree4.printPreorder();
    theTree4.printInorder();
    cout << theTree4.getHeight() << "\n";
    cout << "root size: " << theTree4.getRootSize() << "\n";
    theTree4.remove(170);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    cout << "root size: " << theTree4.getRootSize() << "\n";
    theTree4.remove(150);
    theTree4.printPreorder();
    cout << theTree4.getHeight()<< "\n";
    cout << "root size: " << theTree4.getRootSize() << "\n";
    //cout << theTree4.getHeight() << "\n";
    theTree4.printInorder();
    theTree4.insert(0);
    theTree4.printPreorder();
    cout << theTree4.getHeight()<< "\n";
    theTree4.insert(50);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(0);
    theTree4.printPreorder();
    cout  << "height: " << theTree4.getHeight() << "\n";
    cout << "rootSize: " << theTree4.getRootSize() << "\n";
    theTree4.printPreorder();
    theTree4.insert(180);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.remove(50);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(110);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    theTree4.insert(120);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    cout << theTree4.getRootSize() << "\n";
    ///special case
    /*theTree4.remove(11);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    cout << theTree4.getRootSize() << "\n";*/
    /*theTree4.remove(10);
    theTree4.printPreorder();
    cout << theTree4.getHeight() << "\n";
    cout << theTree4.getRootSize() << "\n";*/
    ///special case 2
    /*theTree4.remove(12);
    theTree4.printPreorder();
    cout <<  theTree4.getHeight() << "\n";
    cout << theTree4.getRootSize() << "\n";*/
    ///weird not found, but apparently working
    /*theTree4.remove(13);
    cout <<  theTree4.getHeight() << "\n";
    cout << theTree4.getRootSize() << "\n";
    theTree4.printPreorder();*/
    /*theTree4.remove(18);
    theTree4.printPreorder();
    cout << "height: " << theTree4.getHeight() << "\n";
    cout << "root size: " << theTree4.getRootSize() << "\n";*/
    theTree4.insert(300);
    cout << "height: " << theTree4.getHeight() << "\n" ;
    cout << "root size: " << theTree4.getRootSize() << "\n";
    theTree4.printPreorder() ;
    theTree4.remove(300);
    logDebugging(theTree4);
    theTree4.insert(300);
    logDebugging(theTree4);
    theTree4.insert(125);
    logDebugging(theTree4);
    theTree4.remove(120);
    logDebugging(theTree4);
    theTree4.insert(120);
    logDebugging(theTree4);
    theTree4.remove(125);
    logDebugging(theTree4);
    theTree4.insert(125);
    logDebugging(theTree4);
    theTree4.insert(95);
    logDebugging(theTree4);
    theTree4.remove(110);
    logDebugging(theTree4);
    theTree4.insert(123);
    logDebugging(theTree4);
    theTree4.insert(129);
    logDebugging(theTree4);
    theTree4.remove(95);
    logDebugging(theTree4);
    theTree4.insert(95);
    logDebugging(theTree4);
    theTree4.remove(125);
    logDebugging(theTree4);
    theTree4.insert(140);
    logDebugging(theTree4);
    theTree4.insert(150);
    logDebugging(theTree4);
    theTree4.remove(150);
    logDebugging(theTree4);
    theTree4.remove(95);
    logDebugging(theTree4);
    theTree4.remove(300);
    logDebugging(theTree4);
    theTree4.remove(120);
    logDebugging(theTree4);
    theTree4.remove(180);
    logDebugging(theTree4);
    theTree4.insert(180);
    logDebugging(theTree4);
    theTree4.printInorder();
    theTree4.remove(130);
    logDebugging(theTree4);
    theTree4.remove(129);
    logDebugging(theTree4);
    theTree4.remove(140);
    logDebugging(theTree4);
    theTree4.remove(100);
    logDebugging(theTree4);
    theTree4.remove(180);
    logDebugging(theTree4);
    theTree4.remove(13);
    logDebugging(theTree4);
    theTree4.remove(123);
}
void testRemove2(bTree<int>&theTree9){
    theTree9.insert(4);
    logDebugging(theTree9);
    theTree9.remove(4);
    logDebugging(theTree9);
    theTree9.insert(4);
    theTree9.insert(5);
    theTree9.insert(8);
    theTree9.insert(25);
    logDebugging(theTree9);
    theTree9.insert(12);
    logDebugging(theTree9);
    ///working
    theTree9.remove(8);
    logDebugging(theTree9);
    theTree9.insert(8);
    logDebugging(theTree9);
    ///working
    theTree9.remove(12);
    logDebugging(theTree9);
    theTree9.insert(12);
    logDebugging(theTree9);
    ///working
    theTree9.remove(5);
    logDebugging(theTree9);
    theTree9.insert(5);
    logDebugging(theTree9);
    ///working
    theTree9.remove(25);
    logDebugging(theTree9);
    theTree9.insert(25);
    logDebugging(theTree9);
    ///working
    theTree9.remove(4);
    logDebugging(theTree9);
    theTree9.insert(4);
    logDebugging(theTree9);
    ///2nd part
    theTree9.insert(3);
    theTree9.insert(0);
    logDebugging(theTree9);
    theTree9.remove(0);
    logDebugging(theTree9);
    theTree9.insert(0);
    logDebugging(theTree9);
    theTree9.remove(3);
    logDebugging(theTree9);
    theTree9.insert(3);
    logDebugging(theTree9);
    theTree9.insert(6);
    logDebugging(theTree9);
    ///3rd part
    ///works
    /*theTree9.remove(0);
    logDebugging(theTree9);*/
    ///works
    /*theTree9.remove(3);
    logDebugging(theTree9);*/
    ///works
    /*theTree9.remove(5);
    logDebugging(theTree9);*/
    ///works
    /*theTree9.remove(6);
    logDebugging(theTree9);*/
    ///works
    /*theTree9.remove(12);
    logDebugging(theTree9);*/
    ///works
    /*theTree9.remove(25);
    logDebugging(theTree9);*/
    ///works
    /*theTree9.remove(4);
    logDebugging(theTree9);*/
    ///works
    /*theTree9.remove(8);
    logDebugging(theTree9);*/
    ///4th part
    theTree9.insert(30);
    logDebugging(theTree9);
    theTree9.insert(7);
    theTree9.insert(9);
    logDebugging(theTree9);
    theTree9.insert(60);
    logDebugging(theTree9);
    ///works
    /*theTree9.remove(12);
    logDebugging(theTree9);*/
    theTree9.insert(28);
    theTree9.insert(2);
    theTree9.insert(10);
    theTree9.insert(45);
    logDebugging(theTree9);
    theTree9.insert(40);
    logDebugging(theTree9);
    theTree9.insert(29);
    logDebugging(theTree9);
    theTree9.insert(24);
    logDebugging(theTree9);
    theTree9.insert(75);
    logDebugging(theTree9);
    theTree9.insert(80);
    logDebugging(theTree9);
    theTree9.insert(11);
    logDebugging(theTree9);
    ///final testing
    ///working
    /*theTree9.remove(11);
    logDebugging(theTree9);*/
    ///working
    /*theTree9.remove(8);
    logDebugging(theTree9);*/
    ///working
    /*theTree9.remove(4);
    logDebugging(theTree9);*/
    ///working
    /*theTree9.remove(12);
    logDebugging(theTree9);*/
    ///working
    /*theTree9.remove(9);
    logDebugging(theTree9);*/
    ///working
    /*theTree9.remove(24);
    logDebugging(theTree9);*/
    ///5th part
    theTree9.remove(11);
    theTree9.remove(6);
    theTree9.remove(4);
    logDebugging(theTree9);
    theTree9.remove(2);
    logDebugging(theTree9);
}

int main()
{
    ///b tree with order 1
    /*bTree<int> theTree(1) ;
    theTree.insert(3);
    theTree.printPreorder();
    theTree.insert(1);
    theTree.printPreorder();
    theTree.insert(5);
    theTree.printPreorder();
    theTree.insert(8);
    theTree.printPreorder();
    theTree.insert(7);
    theTree.printPreorder();
    cout << theTree.getHeight() << "\n" ;
    theTree.insert(0);
    theTree.printPreorder();
    cout << theTree.getHeight () << "\n";
    theTree.insert(4);
    cout << theTree.getHeight() << "\n" ;
    theTree.printPreorder();
    theTree.insert(6);
    cout << theTree.getHeight () << "\n";
    theTree.printPreorder();*/
    //theTree.printInorder();
    //theTree.printPosorder();
    ///b tree with order 2
    /*bTree<int> theTree2(2);
    theTree2.insert(30);
    theTree2.printPreorder();
    theTree2.insert(10);
    theTree2.printPreorder();
    theTree2.insert(50);
    theTree2.printPreorder();
    theTree2.insert(80);
    theTree2.printPreorder();
    theTree2.insert(70);
    theTree2.printPreorder();
    cout << theTree2.getHeight() << "\n" ;
    theTree2.insert(0);
    theTree2.printPreorder();
    cout << theTree2.getHeight () << "\n";
    theTree2.insert(40);
    cout << theTree2.getHeight() << "\n" ;
    theTree2.printPreorder();
    theTree2.insert(60);
    cout << theTree2.getHeight () << "\n";
    theTree2.printPreorder();
    theTree2.insert(20);
    cout << theTree2.getHeight() << "\n";
    theTree2.printPreorder();
    theTree2.insert(46);
    theTree2.insert(43);
    theTree2.insert(45);
    cout << theTree2.getHeight() << "\n";
    theTree2.printPreorder();
    theTree2.insert(90);
    theTree2.insert(100);
    cout << theTree2.getHeight() << "\n";
    theTree2.printPreorder();
    theTree2.insert(48);
    theTree2.insert(47);
    theTree2.insert(49);
    cout << theTree2.getHeight() << "\n";
    theTree2.printPreorder();
    cout << "inserted successfully?" << theTree2.insert(60) << "\n";
    theTree2.printPreorder();*/
    /*bTree<int> theTree3(2);
    theTree3.insert(4);
    theTree3.insert(25);
    theTree3.insert(5);
    theTree3.insert(8);
    theTree3.insert(12);
    theTree3.insert(3);
    theTree3.insert(0);
    theTree3.insert(6);
    theTree3.insert(30);
    theTree3.insert(7);
    theTree3.insert(9);
    theTree3.insert(11);
    theTree3.insert(60);
    theTree3.insert(28);
    theTree3.insert(2);
    theTree3.insert(10);
    theTree3.insert(45);
    theTree3.insert(40);
    theTree3.insert(29);
    theTree3.insert(24);
    theTree3.insert(75);
    theTree3.insert(80);
    theTree3.printPreorder();
    cout << theTree3.getHeight()<< "\n";
    theTree3.remove(90);*/
    //theTree2.printInorder();
    ///testing remove of order 1
    /*bTree<int> theTree4(1);
    testRemove1(theTree4);
    testRemove1(theTree4);*/
    ///testing remove of order 2
    bTree<int> theTree9(2);
    testRemove2(theTree9);
    //theTree4.printInorder();
    ///until here is important
    /*bTree<int> theTree8 ;
    theTree8.insert(10);
    cout << theTree8.getRootSize() << "\n";
    theTree8.insert(12);
    cout << theTree8.getRootSize() << "\n";
    theTree8.insert(13);
    theTree8.remove(12);
    cout << theTree8.getRootSize() << "\n";*/
    ///theTree4.remove(15);
    ///testing for small test case
    /*bTree<int> theTree6;
    theTree6.insert(10);
    theTree6.insert(13);
    theTree6.insert(15);
    theTree6.printPreorder();
    cout << theTree6.getHeight() << "\n";
    theTree6.remove(15);
    theTree6.printPreorder();
    cout << theTree6.getHeight() << "\n";*/
    ///testing remove with order 1
    /*bTree<int> theTree5;
    theTree5.insert(10);
    theTree5.insert(15);
    theTree5.insert(17);
    theTree5.insert(13);
    theTree5.printPreorder();
    cout << theTree5.getHeight() << "\n";
    theTree5.remove(17);
    theTree5.printPreorder();
    cout << theTree5.getHeight() << "\n";*/
    return 0;
}
