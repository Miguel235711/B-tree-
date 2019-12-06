#include "bTree.h"
#include "bTreeNode.cpp"

template<class T>
bTree<T>::bTree()
{
    //ctor
}

template<class T>
bTree<T>::bTree(int minNodes){
    this->minNodes=minNodes;
}

template<class T>
bTree<T>::~bTree()
{
    //dtor
}
template<class T>
bool bTree<T>::insert(const T & val){
    if(!root){
        ///empty tree
        root = new bTreeNode<T>(val);
        return true;
    }
    //std::cout << "insert with special function\n";
    return insertF(root,val,NULL,NULL,NULL,NULL);
}
template<class T>
void bTree<T>::fixInsertion(bTreeNode<T>*bNode,bTreeNode<T>*bBefore,node<T>*left,node<T>*right){
    std::cout << "*fixInsertion()\n";
    //std::cout << "bNode->front()->val: " << bNode->front()->val << " bNode->front()->next->val: " <<  (bNode->front()->next?bNode->front()->next->val:INT_MIN) << " bNode->back()->val " << bNode->back()->val << " bNode->size() " << bNode->size() << " is bBefore NULL ? " << (bBefore?"NO":"YES") << "\n";
    node<T>*middle=bNode->front();
    node<T>* before = NULL;
    for(int i = 0 ; i < minNodes ; i ++ ){
        if(!middle->next){
            std::cout << "error in fixing insertion\n";
            return;
        }
        before = middle ;
        middle = middle -> next ;
    }
    ///split in two halves and insert middle in between left and right, use bNode for leftside and create new bNdoe for right side
    //std::cout << "middle->val: " << middle->val << "before: " << before -> val << "\n";
    bTreeNode<T>* rightBNode = new bTreeNode<T>(middle->next,bNode->back(),minNodes,middle->rightSon);
    bNode->setBack(before);
    bNode->setSize(minNodes);
    middle->rightSon = rightBNode;
    before->next = NULL;
    if(!bBefore){
        ///create new root
        root = new bTreeNode<T>(middle,middle,1,bNode);
        middle->next = NULL;
    }else{
        if(left){
            ///between
            left->next = middle ;
        }else{
            ///middle will be next front
            ///problem when bBefore is NULL
            bBefore->setFront(middle);
        }
        if(!right){
            ///middle will be next back
            ///problem when bBefore is NULL
            bBefore->setBack(middle);
        }
        middle->next = right ;
        bBefore->setSize(bBefore->size()+1);
        //std::cout << "new size of bnode that adopted node: " << bBefore->size() << "\n";
    }
}
template<class T>
bool bTree<T>::insertF(bTreeNode<T>*bNode,const T & val,bTreeNode<T>*bBefore,node<T>*left,node<T>*right,bTreeNode<T>*bBeforeOfBefore){
    ///implement
    //std::cout << "pure insertF call()\n" ;
    if(!bNode){
        //std::cout << "****bNode is null front value of bBefore: " << bBefore->front() -> val << "back value of bBefore: " << bBefore->back()->val << "\n";
        ///manage insertion from the bBefore leave
        if(!bBefore){
            //std::cout << "error in insertion of btree";
            return false;
        }
        ///insert here
        bBefore->setSize(bBefore->size()+1);
        //std::cout << "***new size of this leaf: " << bBefore->size() << "\n";
        node<T>* newNode = new node<T>(val);
        if(bBefore->front()->val>val){
            ///insert in front
            newNode->next = bBefore->front();
            bBefore->setFront(newNode);
        }else{
            ///search until finding appropriate place
            node<T>* lastNode = bBefore->front();
            //std::cout << "bBefore->front(): " << bBefore -> front() << "\n";
            bool  inserted = false ;
            for(node<T>*nav = bBefore->front()->next ; nav ; nav = nav->next){
                if(nav->val>val){
                    ///insert node here
                    lastNode->next = newNode;
                    newNode->next = nav ;
                    inserted = true;
                    break;
                }
                lastNode = nav ;
            }
            if(!inserted){
                ///default case of last child
                //std::cout << "bBefore->back(): " << bBefore -> back() -> val << "\n";
                bBefore->back()->next = newNode;
                bBefore->setBack(newNode);
                //std::cout << "front and back: " << bBefore->front()->val << " " << bBefore ->back()->val << "\n";
            }
        }
        ///fix insertion if necessary
        if(bBefore->size()>minNodes*2){
            //std::cout << "---fixing when bNode is NULL";
            fixInsertion(bBefore,bBeforeOfBefore,left,right);
        }
        return true;
    }
    std::cout << " insertF() bNode->front->value: " << bNode->front()->val<<"\n";
    //std::cout << "front value of bNode: " << bNode->front() -> val << "back value of bNode: " << bNode->back()->val << "\n";
    bool result = false ;
    if(bNode->front()->val>val){
        ///go to leftest child
        return insertF(bNode->leftestSon(),val,bNode,bNode->leftestSon()?NULL:left,bNode->leftestSon()?bNode->front():right,bBefore);
    }else if(bNode->front()->val<val){
        node<T>*lastNav = bNode->front();
        bool done = false ;
        for(node<T>*nav = bNode->front()->next; nav ; nav = nav->next){
            if(nav->val>val){
                result = insertF(lastNav->rightSon,val,bNode,lastNav->rightSon?lastNav:left,lastNav->rightSon?nav:right,bBefore);
                done = true;
                break;
            }else if(nav->val==val){
                ///repeated one
                return false ;
            }
            lastNav = nav ;
        }
        ///default case of last child
        if(!done){
            result = insertF(bNode->back()->rightSon,val,bNode,bNode->back()->rightSon?lastNav:left,bNode->back()->rightSon?NULL:right,bBefore);
        }
    }else{
        ///case when bNode->front()->val == val
        ///repeated
        return false ;
    }
    if(bNode->size()>minNodes*2){
        fixInsertion(bNode,bBefore,left,right);
    }
    return result ;
}
template<class T>
void bTree<T>::printPreorder(){
    std::cout << "printPreorder:\n";
    if(root&&root->front()&&root->front()->next){
        std::cout << "root->front->next is no null\n";
        std::cout << "ok0: " << root->front()->val << "\n";
    }
    if(root){
        if(root->back())
            std::cout << "back: " << root->back()->val << "\n";
        if(root->front())
            std::cout << "front: " << root->front() -> val << "\n";
    }
    if(root && root->front() && root->front()->rightSon && root->front()->rightSon->front() && root->front()->rightSon->front()->val){
        std::cout << "ok: " << root->front()->rightSon->front()->val << "\n";
    }
    if(root && root->leftestSon() && root->leftestSon()->front()){
        std::cout << "ok2: " << root -> leftestSon() -> front() -> val << "\n";
    }
    if(root && root->front() && root->front()->rightSon && root->front()->rightSon->front()){
        std::cout << "ok3: " << root->front()->rightSon->front()->val << "\n";
    }
    if(root && root->front() && root->front()->next){
        std::cout << "satan1: " << root->front()->next->val << "\n";
        if(root->front()->next->next){
            std::cout << "satan2: " << root->front()->next->next->val << "\n";
            if(root->front()->next->next->next){
                std::cout << "satan3: " << root->front()->next->next->next->val << "\n";
            }
        }
    }
    printOrder(root,pre);
    std::cout << "\n";
}
template<class T>
void bTree<T>::printInorder(){
    std::cout << "printInorder:\n";
    printOrder(root,in);
    std::cout << "\n";
}
template<class T>
void bTree<T>::printPosorder(){
    std::cout << "printPosorder:\n";
    printOrder(root,pos);
    std::cout << "\n";
}
template<class T>
void bTree<T>::printOrder(bTreeNode<T>*bNode,const ord & order){
    if(!bNode)///base case
        return ;
    if(order==pre){
        std::cout << bNode->front()->val<< " " ;
        /*if(bNode->front()->next){
            std::cout << "what the: " << bNode->front()->next->val << "\n";
        }
        if(bNode->front()->rightSon){
            std::cout << "what the: " << bNode->front()->rightSon->front()->val << "\n";
        }*/
    }
    printOrder(bNode->leftestSon(),order);
    for(node<T>*nav = bNode->front();nav;nav = nav->next ){
        if(order==in||(order==pre&&nav!=bNode->front())){
            std::cout << nav->val << " " ;
        }
        printOrder(nav->rightSon,order);
        if(order==pos){
            std::cout << nav -> val << " " ;
        }
    }
}
template<class T>
int bTree<T>::getHeight(){
    return getHeightF(root);
}
template<class T>
int bTree<T>::getHeightF(bTreeNode<T>*bNode){
    if(!bNode)
        return 0 ;
    int maxLevel = getHeightF(bNode->leftestSon());
    for(node<T>*nav = bNode->front() ; nav ; nav = nav -> next ){
        maxLevel = getHeightF(nav->rightSon);
    }
    return maxLevel + 1 ;
}
///delete methods
template<class T>
bool bTree<T>::remove(const T & val){///false if element does not exist
    //std::cout << "is root NULL?: " << (root?"NO":"YES") << "\n";
    /*if(val==15){
        std::cout << "-*-*master remove()" << root->front()->rightSon->front()->val<<"\n";
        std::cout << "size: " << root->size() << "\n";
        std::cout << "is root->back()->val" << root->back()->val << "\n";
        std::cout << "master remove enclosed-*-*\n";
    }*/
    if(root)
        return removeF(root,NULL,val,NULL,NULL,NULL,NULL);
    return false ; ///bTree is empty
}
template <class T>
void bTree<T>::deleteInLeaf(bTreeNode<T>*bNode,node<T>*left,node<T>*nodeToDelete){
    bNode->setSize(bNode->size()-1);
    ///not sure about order 1
    if(left){
        left->next = nodeToDelete->next;
        if(!nodeToDelete->next){
            ///make left as new back
            bNode->setBack(left);
        }
    }else{
        ///nodeToDelete is the leftest one
        std::cout << "nodeToDelete is the leftest one\n";
        bNode->setFront(nodeToDelete->next);
        if(!nodeToDelete->next){
            ///this bNode will be empty
            std::cout << "this bNode will be empty\n";
            if(bNode==root){
                std::cout << "especial case when tree empties completely\n";
                ///special case when the tree empties completely
                delete bNode ;
                root = NULL ;
            }
            bNode->setBack(NULL);
        }
    }
    delete nodeToDelete ; ///dangerous
}
template <class T>
T bTree<T>::getLeftest(bTreeNode<T>*bNode){
    if(bNode->leftestSon())
        return getLeftest(bNode->leftestSon());
    return bNode->front()->val;
}
template<class T>
void bTree<T>::handleRemove(bTreeNode<T>*bNode,node<T>*left,node<T>*nodeToDelete){
    if(bNode->leftestSon()){std::cout << "$$$$damn size: " << bNode->size() << "\n";
        ///internal node
        std::cout << "internal node\n";
        T inorderSuccesor = getLeftest(nodeToDelete->rightSon);
        std::cout << "inorderSuccesor: " << inorderSuccesor << "\n";
        std::cout << "root: " << root->front()->rightSon->front()->val << "\n";
        removeF(root,NULL,inorderSuccesor,NULL,NULL,NULL,NULL);///delete this leaf node
        std::cout << "root: " << root->front()->val << "\n";
        nodeToDelete->val = inorderSuccesor ;
    }else{
        ///leaf node
        ///by default erase this node
        std::cout << "delete leaf node:\n";
        deleteInLeaf(bNode,left,nodeToDelete);
    }
}
template<class T>
void bTree<T>::fixDeletion(bTreeNode<T>*bNode,bTreeNode<T>*parentBNode,bTreeNode<T>*leftBNode,bTreeNode<T>*rightBNode,node<T>*leftParentNode,node<T>*parentNode){
    std::cout << "fixDeletion() function\n";
    if(!parentBNode){
        std::cout << " ### parentBNode is null\n";
    }else{
        std::cout << " ### parentBNode is no null\n";
    }
    if(leftBNode && leftBNode->size()>minNodes){
        ///rotation with leftBNode (leftBNode->back()) , parentNode and bNode (bNode->front())
        ///take before back() of leftBNode
        ///not sure
        std::cout << "rotate to right:\n";
        if(!parentBNode){
            std::cout << "parentBNode is null\n";
        }
        leftBNode->setSize(leftBNode->size()-1);
        node<T>* before = NULL;
        for(node<T>*nav = leftBNode->front() ; nav != leftBNode->back(); nav = nav->next){
            before = nav ;
        }
        node<T>*leftBNodeBack = leftBNode->back();
        /*if(!leftParentNode){
            std::cout << "leftParent node is null\n";
        }*/
        if(leftParentNode){
            leftParentNode->next = leftBNodeBack;
        }else{
            parentBNode->setFront(leftBNodeBack);
        }
        if(!parentNode->next){
            std::cout << "!!!! ";
            std::cout << parentBNode->size()<< "\n";
            parentBNode->setBack(leftBNodeBack);
        }
        leftBNodeBack->next = parentNode->next ;
        before->next = NULL ;
        leftBNode->setBack(before);
        //leftBNode->setSize(leftBNode->size()-1);
        //std::cout << "bNode->front()->val: " << bNode->front()->val << "\n";
        parentNode->next = bNode->front();
        //std::cout << "ljlk.jfk.\n";
        //std::cout << "parentNode->next->val: " << parentNode->next->val << "\n";
        bNode->setFront(parentNode);
        if(!bNode->back())
            bNode->setBack(parentNode);
        parentNode->rightSon = bNode->leftestSon();
        bNode->setLeftestSon(leftBNodeBack->rightSon) ;
        bNode->setSize(bNode->size()+1);
        leftBNodeBack->rightSon = bNode ;
        //std::cout << "leftNode->back()->val: " << leftBNode->back()->val <<"\n";
        //std::cout << "bNode->back()->val: " << bNode->front()->next->val << "\n";
    }else if(rightBNode && rightBNode->size() > minNodes){
        std::cout << "rotate to left:\n";
        //std::cout << "%%%%%" << bNode->size() << "\n";
        node<T>*parentNodeAux = parentNode ? parentNode : parentBNode->front();
        node<T>*parentNodeNext = parentNode?parentNode->next : parentBNode->front()->next;
        //std::cout << "%%%%%%" << "parentNodeAux: " << parentNodeAux->val << " parentNodeNext: " << parentNodeNext->val << "\n";
        //std::cout << "%%%%% rightBNode->front()->val: " << rightBNode -> back() ->val << "\n";
        if(!parentBNode){
            std::cout << "((((((((((((((((parentBNode is null\n";
        }
        if(!rightBNode){
            std::cout << ")))))))))))rightBNode is null\n";
        }
        if(!leftBNode){
            std::cout<< ")))))))))))))))leftBNode is null\n";
        }
        std::cout << "...\n";
        rightBNode->setSize(rightBNode->size()-1);
        //std::cout << "rightBNode->size(): " << rightBNode->size() << "\n";
        node<T>*rightBNodeFront = rightBNode->front();
        /*if(!leftParentNode){
            std::cout << "leftParent node is null\n";
        }*/
        std::cout << "is leftParentNode null ?: " << (leftParentNode?"NO":"YES") << "\n";
        if(parentNode){
            parentNode->next = rightBNodeFront;
        }else{
            parentBNode->setFront(rightBNodeFront);
        }
        //std::cout << "parentBNode->size(): " << parentBNode ->size() << "\n" ;
        //std::cout << "parentBNode->front()->next->val: " << parentBNode->front()->next->val << "\n" ;
        //printOrder(parentBNode,pre);
        if(parentNodeAux){
            std::cout << "parentNodeAux is no null\n";
        }
        if(!parentNodeNext){
            std::cout << "!!!! ";
            std::cout << parentBNode->size()<< "\n";
            parentBNode->setBack(rightBNodeFront);
        }else{
            std::cout << "problems here:\n";
        }
        rightBNode->setFront(rightBNodeFront->next);
        rightBNodeFront->next = parentNodeNext ;
        //std::cout << "what" << << "\n";

        //std::cout << "parentNodeNext->val" << parentNodeNext->val << "\n";
        //leftBNode->setSize(leftBNode->size()-1);
        //std::cout << "bNode->front()->val: " << bNode->front()->val << "\n";
        //std::cout << "w\n";
        std::cout << "YYYYYYYYY\n";
        if(bNode->back()){
            std::cout << "======bNode->back() is no null\n";
        }
        if(bNode->back()){
            bNode->back()->next =parentNodeAux;
        }else{
            bNode->setBack(parentNodeAux);
        }
        //std::cout << "ljlk.jfk.\n";
        //std::cout << "parentNode->next->val: " << parentNode->next->val << "\n";
        bNode->setBack(parentNodeAux);
        if(!bNode->front())
            bNode->setFront(parentNodeAux);
        parentNodeAux->rightSon = bNode->leftestSon();
        parentNodeAux->next = NULL;///fixes problem
        bNode->setLeftestSon(rightBNodeFront->rightSon);///ultra dangerous
        bNode->setSize(bNode->size()+1);
        rightBNodeFront->rightSon = rightBNode ;
        //std::cout << "results ====: "  << parentBNode->front()->val << parentBNode->front()->rightSon->front()->val << "\n";
        std::cout << "wht\n";
        //std::cout << "super weird problem:\n";
        printOrder(parentBNode,pre);
        //printOrder(rightBNode,pre);
    }else{
        ///merge
        std::cout << "gonna merge:\n";
        parentBNode->setSize(parentBNode->size()-1);
        if(leftBNode){ ///Probably BUGS
            ///merge leftBNode with bNode
            ///bNode will be destroyed
            std::cout << "merge leftBNode with bNode\n";
            std::cout << "leftBNode->size: " << leftBNode->size() << " bNode->size: " << bNode->size() << "\n";
            leftBNode->back()->next = parentNode ;
            std::cout << "parentNode->val: " << parentNode->val << "\n";
            leftBNode->setBack(parentNode);
            std::cout << "jlkjd:\n";
            std::cout << ")))))weird parentNode" << parentNode ->val << "\n";
            ///weird special case beginning
            if(parentNode==parentBNode->back()){
                parentBNode->setBack(leftParentNode);
            }
            ///weird special ending
            if(leftParentNode){
                leftParentNode->next = parentNode->next ;
            }else{
                std::cout << "leftParentNode is null\n";
                parentBNode->setFront(parentNode->next);
                if(!parentNode->next){
                    parentBNode->setBack(NULL);
                    if(parentBNode==root){
                        std::cout << "$$$$damn size: " << root->size() << "\n";
                        std::cout << "decreasing in height by one in leftBNode case: ";
                        root = leftBNode;
                    }
                }
            }
            if(bNode->front()){
                leftBNode->setBack(bNode->front());
            }
            //std::cout << "%%%%parentNode->val: " << bNode->leftestSon()->front()->val << "\n";
            parentNode->next = bNode->front() ;
            //std::cout << parentNode->next->val << "\n";
            //leftBNode->back()->rightSon = bNode->leftestSon(); Unsure !!!!!! if it is ok to erase
            //leftBNode->setBack(bNode->back());
            parentNode->rightSon = bNode->leftestSon();///important
            leftBNode->setSize(leftBNode->size()+bNode->size()+1);
            std::cout << "IMPORTANT size: " << leftBNode->size()<<"\n";
            //std::cout << "#$#$#!!!!" << leftBNode->front()->next->next->rightSon->front()->val << " : " << parentNode->rightSon->front()->val << "\n";
            delete bNode ; ///dangerous for other methods!!!
        }else{
            ///merge rightBNode with bNode
            node<T>*parentNodeNext = parentBNode->front() ;
            std::cout << "parentNodeNext: " << parentNodeNext ->val << "\n" ;
            std::cout << "gonna merge rightBNode with bNode\n";
            ///beware of case when this is merge and parentBNode gets empty because it is root
            ///rightBNode will be destroyed
            if(bNode->back()){
                //std::cout << "!!!! bNode->back()->value: " << bNode->back()->val << "\n";
                bNode->back()->next = parentNodeNext ;///fixing
                //std::cout << "parentNodeNext->val: " << parentNodeNext->val << "\n" ;
                //std::cout << bNode->size() << " " << bNode->front()->val << "\n";
            }else{
                ///case when bNode is empty
                std::cout << "case when bNode is empty\n";
                bNode->setFront(parentNodeNext);
            }
            std::cout << "is ParentBNode null ? " << (parentBNode?"NO":"YES") << "\n";
            std::cout << "is ParentNode null ? " << (parentNode?"NO":"YES") << "\n";
            parentBNode->setFront(parentNodeNext->next);
            if(!parentNodeNext->next){///sign that bParentNode is getting empty
                std::cout << "bParentNode is getting empty:\n";
                parentBNode->setBack(NULL);
                if(parentBNode==root){
                    ///fix root
                    std::cout << "decreasing in height by one!!!\n";
                    root = bNode ;
                }
            }
            std::cout << "***rightBNode->front(): " << rightBNode->front() -> val << " *** is rightBNode->back null ? :" << (rightBNode->back()?"NO":"YES") << "\n";
            parentNodeNext->next = rightBNode->front();
            parentNodeNext->rightSon = rightBNode->leftestSon();///important !!!!!
            bNode->setBack(rightBNode->back());
            bNode->setSize(bNode->size()+rightBNode->size()+1);
            std::cout << " -- is bNode->back() null ? " << (bNode->back()?"NO":"YES") << "is bNode->front() null ?: " << (bNode->front()?"NO":"YES") << " is bNode->back() null?: " <<  (bNode->back()?"NO":"YES") << "\n";
            std::cout << " bNode->front()->val:  " << bNode->front()->val << " bNode->back()->val: " << bNode->back()->val << " is bNode->back()->next null: " << (bNode->back()->next?"NO":"YES")<< "\n";
            delete rightBNode;
        }
    }
}
template<class T>
bool bTree<T>::removeF(bTreeNode<T>*bNode,bTreeNode<T>*parentBNode,const T & val,bTreeNode<T>*leftBNode,bTreeNode<T>*rightBNode,node<T>*leftParentNode,node<T>*parentNode){
    std::cout << "pure call to removeF() " << "val: " << val << "\n";
    bool bNodeisNoRoot = (bNode!=root);
    if(!bNode){
        std::cout << "value not found\n";
        return false ; ///value was not found
    }
    std::cout << "inside removeF() " << val << "\n";
    bool result = false ;
    if(bNode->front()->val>val){
        ///go to leftest child
        std::cout << "같같같같같같같컂o to the leftest child:\n";
        std::cout << "3#####"<<"is bNode->front()->rightSon null?" << (bNode->front()->rightSon?"NO":"YES") << "\n";
        /*if(bNode->front()->rightSon){
            std::cout << ":::;;bNode->front()->rightSon->val: " << bNode->front()->rightSon->front()->->val << "\n";
        }*/
        result = removeF(bNode->leftestSon(),bNode,val,NULL,bNode->front()->rightSon,NULL,NULL);
    }else if(bNode->front()->val==val){
        ///element found erase
        std::cout << "element found as front() of linked list, check which case from here\n";
        handleRemove(bNode,NULL,bNode->front());
        result = true;
    }else{
        std::cout << "try until nav>= val or none at all:\n";
        ///try until nav >= val or none at all
        node<T>*last = bNode->front(),*lastOfLast = NULL;
        bool done = false ;
        for(node<T>*nav = bNode->front()->next ; nav ; nav = nav -> next ){
            if(nav->val==val){
                ///element found, erase
                std::cout << "element found, check which case from here\n";
                handleRemove(bNode,last,nav);
                result = true;
                done = true;
                break;
            }else if(nav->val > val ) {
                ///especial with leftestSon()
                std::cout << "////special with leftestSon1:\n";
                result = removeF(last->rightSon,bNode,val,lastOfLast?lastOfLast->rightSon:bNode->leftestSon(),nav->rightSon,lastOfLast,last);
                done = true;
                break;
            }
            lastOfLast = last ;
            last = nav ;
        }
        ///not found, therefore go to the rightson of bNode->back()
        std::cout << "not found, therefore go the the rightson of bNode->back():\n";
        if(!done)
            ///special with leftestSon
            std::cout << "><<<<<special with leftestSon2:\n";
            //std::cout << "wtf: " << bNode->back()->rightSon->front() ? << "\n";
            result = removeF(bNode->back()->rightSon,bNode,val,lastOfLast?lastOfLast->rightSon:bNode->leftestSon(),NULL,lastOfLast,bNode->back());
    }
    if(bNodeisNoRoot&&bNode->size()<minNodes){
        std::cout << "gonna call fixDeletion()\n";
        std::cout << "is bNode->back() NULL?" << (!bNode->back()?"YES":"NO") << "is bNode->front() NULL? " << (!bNode->front()?"YES":"NO") <<"\n" ;
        fixDeletion(bNode,parentBNode,leftBNode,rightBNode,leftParentNode,parentNode);///IMPLEMENT!!!
    }
    return result ;
}
template<class T>
int bTree<T>::getRootSize(){
    return root?root->size():INT_MAX;
}
template<class T>
int bTree<T>::size(){
    return sizeF(root);
}
template<class T>
int bTree<T>::sizeF(bTreeNode<T>*bNode){
    if(!bNode)
        return 0 ;
    int elements = sizeF(bNode->leftestSon());
    for(node<T>*nav = bNode->front() ; nav ; nav = nav -> next ){
        elements += sizeF(nav->rightSon)+1;
    }
    return elements ;
}
template<class T>
int bTree<T>::countRootSize(){
    if(!root||!root->front())
        return 0 ;
    int ans = 0 ;
    for(node<T>*nav = root->front() ; nav ; nav = nav -> next ){
        ans++;
    }
    return ans;
}
