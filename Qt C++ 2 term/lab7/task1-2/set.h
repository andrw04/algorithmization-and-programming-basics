#ifndef SET_H
#define SET_H
#include <string>
#include <vector>
#include <QString>
#include <QTreeWidgetItem>

template<class KType>
struct SETNode {
    SETNode(KType key) : _key(key) {

    }
    KType _key;
    SETNode<KType>* right_child = nullptr;
    SETNode<KType>* left_child = nullptr;
    SETNode<KType>* parent = nullptr;

    std::string color = "red";
};

template<class KType>
class SET
{

    SETNode<KType>* root = nullptr;


    SETNode<KType>* find(SETNode<KType>* root, KType key)
    {
        if (!root)
            return nullptr;
        if (key == root->_key)
            return root;
        if (root->left_child)
            find(root->left_child, key);
        if (root->right_child)
            find(root->right_child, key);
    }


    SETNode<KType>* RotateRight(SETNode<KType>* root)
    {
        SETNode<KType>* p = root;
        SETNode<KType>* q = p->left_child;
        p->left_child = q->right_child;
        q->right_child = p;

        return q;
    }


    SETNode<KType>* RotateLeft(SETNode<KType>* root)
    {
        SETNode<KType>* q = root;
        SETNode<KType>* p = q->right_child;
        q->right_child = p->left_child;
        p->left_child = q;

        return p;
    }


    void SwapColor(SETNode<KType>* n)
    {
        if (n->left_child->color == "black")
        {
            n->left_child->color = "red";
        }
        else
        {
            n->left_child->color = "black";
        }
        if (n->right_child->color == "black")
        {
            n->right_child->color = "red";
        }
        else
        {
            n->right_child->color = "black";
        }
    }


    SETNode<KType>* Balance(SETNode<KType>* root)
    {
        if (root != nullptr &&
            root->left_child != nullptr && root->right_child != nullptr &&
            root->right_child->color == "red" && root->left_child->color == "black"
            )
            root = RotateLeft(root);
        if (root != nullptr &&
            root->left_child != nullptr && root->left_child->left_child != nullptr &&
            root->left_child->color == "red" && root->left_child->left_child->color == "red")
            root = RotateRight(root);
        if (root != nullptr &&
            root->left_child != nullptr && root->right_child != nullptr &&
            root->left_child->color == "red" && root->right_child->color == "red")
            SwapColor(root);
        return root;
    }


    SETNode<KType>* AddNode(SETNode<KType>* root, SETNode<KType>* node)
    {
        if (!root) {
            root = node;
            node->color = "black";
        }
        if (node->_key < root->_key)
        {
            if (!root->left_child) {
                root->left_child = node;
                node->parent = root;
            }
            else {
                AddNode(root->left_child, node);
            }
        }
        else if (node->_key > root->_key)
        {
            if (!root->right_child) {
                root->right_child = node;
                node->parent = root;
            }
            else {
                AddNode(root->right_child, node);
            }
        }
        return Balance(root);
    }


    SETNode<KType>* DeleteNode(SETNode<KType>* root, KType key)
    {
        if (!root)
            return root;
        if (key < root->_key)
            root->left_child = DeleteNode(root->left_child, key);
        else if (key > root->_key)
            root->right_child = DeleteNode(root->right_child, key);
        else {
            if (!root->left_child && !root->right_child) {
                delete root;
                root = nullptr;
            }
            else if (!root->left_child) {
                SETNode<KType>* temp = root;
                root = root->right_child;
                delete temp;
            }
            else if (!root->right_child) {
                SETNode<KType>* temp = root;
                root = root->left_child;
                delete temp;
            }
            else {
                SETNode<KType>* temp = root->right_child;
                while (temp->left_child)
                    temp = temp->left_child;
                root->_key = temp->_key;
                root->right_child = DeleteNode(root->right_child, temp->_key);
            }
        }
        return root;
    }


    void GetNodeArray(SETNode<KType>* root, std::vector<SETNode<KType>*>& arr)
    {
        if (root->left_child)
            GetNodeArray(root->left_child, arr);
        arr.push_back(root);
        if (root->right_child)
            GetNodeArray(root->right_child, arr);
    }

    void addChilds(SETNode<KType>*r,QTreeWidgetItem* itm)
    {
        if (r->left_child)
        {
            QTreeWidgetItem *ch = new QTreeWidgetItem();
            ch->setText(0,QString::number(r->left_child->_key));
            itm->addChild(ch);
            addChilds(r->left_child, ch);
        }
        if (r->right_child)
        {   QTreeWidgetItem *ch = new QTreeWidgetItem();
            ch->setText(0,QString::number(r->right_child->_key));
            itm->addChild(ch);
            addChilds(r->right_child, ch);
        }
    }

public:

    SET(KType key)
    {
        root = new SETNode<KType>(key);
        root->color = "black";
    }
    SET()
    {

    }


    bool InsertNode(KType key)
    {
        SETNode<KType>* t = find(root, key);
        root = AddNode(root, new SETNode<KType>(key));
        return t != nullptr ? true : false;
    }


    void Erase(KType key)
    {
        root = DeleteNode(root, key);
    }


    void clear()
    {
        std::vector<SETNode<KType>*> tmp;
        GetNodeArray(root, tmp);
        for (size_t i = 0; i < tmp.size(); i++)
        {
            delete tmp[i];
        }
        root = nullptr;
    }
    void print_tree(QTreeWidget *tree)
    {
        QTreeWidgetItem *p = new QTreeWidgetItem();
        addChilds(root,p);
        p->setText(0,QString::number(root->_key));
        tree->addTopLevelItem(p);
    }


    bool cont(KType key){
        SETNode<KType>* t = find(root, key);
        return t == nullptr ? true : false;
    }

};

#endif // SET_H

