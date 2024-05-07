#ifndef TREE_H
#define TREE_H

#include <QString>

using namespace std;
//14
//8,3,10,1,4,9,11,19,17,25,16,18,23,27

struct Node{
    int data = 0;
    Node *left = 0;
    Node *right = 0;
    int num = 0;
    int x = 356;
    int y;
};

class Tree
{

    int arMean = 0;
public:
    int count = 0;
    Node *root = NULL;

    void init(int x){
        root =new Node; // память под узел
        root->data = x;
        arMean += x;
    }


    Node *addNode(int x, Node *tree, int z, int y, int h) {
        if (tree == NULL) { // Если дерева нет, то формируем корень
            tree =new Node; // память под узел
            tree->data = x;   // поле данных
            tree->num = ++count;
            tree->x = z;
            tree->y = y;
            //tree->x = coorWayX(way);
            //tree->y = coorWayY(way);
            arMean+=x;
        }else  if (x < tree->data){   // условие добавление левого потомка
            //way+='l';
            tree->left = addNode(x,tree->left, z-(h),y+85,h/2);
        }
        else{    // условие добавление правого потомка
            //way+='r';
            tree->right = addNode(x,tree->right, z+(h),y+85,h/2);
        }
        return(tree);
    }

    void deletNodes(Node *tree) {
        if(tree!=NULL) {
            count--;
            arMean -= tree->data;
            deletNodes(tree->left);
            deletNodes(tree->right);
            delete tree;
        }
    }

    void delNodes(int data,Node *tree){

        if (tree != NULL) {
            if (tree->data == data) {deletNodes(tree);tree = NULL; return;}
            if (tree->data > data) {delNodes(data,tree->left); tree->left = NULL;}
            if (tree->data <data) {delNodes(data,tree->right); tree->right = NULL;}
        }
    }


    void showTree(Node *tree) {
        if (tree != NULL) {
            showTree(tree->left);
            printf("%i %i\n", tree->num, tree->data);
            showTree(tree->right);
        }
    }

    double arithMean(){ return arMean/(count+1);}

    void arrNodes(QString a, Node *tree){
        int cnt = 0;
        QString str = "";
        for (int i(1); i < a.size(); i++){
            str+=a[i-1];
            if (a[i]==','){
                addNode(str.toInt(),tree, 356,0,200);
                str.clear();
                i++;
            }
        }
        str+=a[a.size()-1];
        addNode(str.toInt(),tree, 356,0,200);
    }
    Tree(){};
};

#endif // TREE_H
