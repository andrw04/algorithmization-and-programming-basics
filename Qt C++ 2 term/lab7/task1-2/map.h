#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include <iostream>
#include <QTreeWidget>

template<class KeyType, class ValueType>
struct Node {
    Node(KeyType key, ValueType text) {
        data = std::make_pair(key, text);
    }

    Node<KeyType, ValueType>* right_child = nullptr;
    Node<KeyType, ValueType>* left_child = nullptr;
    Node<KeyType, ValueType>* parent = nullptr;

    std::string color = "red";

    std::pair<KeyType, ValueType> data;
};

template<class KeyType, class ValueType>
class MAP
{
    Node<KeyType, ValueType>* root = nullptr;


    Node<KeyType, ValueType>* find(Node<KeyType, ValueType>* root, KeyType key)
    {
        if (!root)
            return nullptr;
        if (key == root->data.first)
            return root;
        if (root->left_child)
            find(root->left_child, key);
        if (root->right_child)
            find(root->right_child, key);
    }


    Node<KeyType, ValueType>* RotateRight(Node<KeyType, ValueType>* root)
    {
        Node<KeyType, ValueType>* p = root;
        Node<KeyType, ValueType>* q = p->left_child;
        p->left_child = q->right_child;
        q->right_child = p;

        return q;
    }


    Node<KeyType, ValueType>* RotateLeft(Node<KeyType, ValueType>* root)
    {
        Node<KeyType, ValueType>* q = root;
        Node<KeyType, ValueType>* p = q->right_child;
        q->right_child = p->left_child;
        p->left_child = q;

        return p;
    }


    void SwapColor(Node<KeyType, ValueType>* n)
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


    Node<KeyType, ValueType>* Balance(Node<KeyType, ValueType>* root)
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



    Node<KeyType, ValueType>* AddNode(Node<KeyType, ValueType>* root, Node<KeyType, ValueType>* node)
    {
        if (!root) {
            root = node;
            node->color = "black";
        }
        if (node->data.first < root->data.first)
        {
            if (!root->left_child) {
                root->left_child = node;
                node->parent = root;
            }
            else {
                AddNode(root->left_child, node);
            }
        }
        else if (node->data.first > root->data.first)
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



    Node<KeyType,ValueType>* DeleteNode(Node<KeyType,ValueType> *root,int key) {
            if (root == nullptr)
                return root;

            if (key == root->data.first)
            {
                Node<KeyType,ValueType>* tmp;
                if (root->right_child == nullptr)
                    tmp = root->left_child;
                else {

                    Node<KeyType,ValueType>* ptr = root->right_child;
                    if (ptr->left_child == nullptr) {
                        ptr->left_child = root->left_child;
                        tmp = ptr;
                    }
                    else {

                        Node<KeyType,ValueType>* pmin = ptr->left_child;
                        while (pmin->left_child != nullptr) {
                            ptr = pmin;
                            pmin = ptr->left_child;
                        }
                        ptr->left_child = pmin->right_child;
                        pmin->left_child = root->left_child;
                        pmin->right_child = root->right_child;
                        tmp = pmin;
                    }
                }

                delete root;
                return tmp;
            }
            else if (key < root->data.first)
                root->left_child = DeleteNode(root->left_child, key);
            else
                root->right_child = DeleteNode(root->right_child, key);
            return root;
        }


    void GetNodeArray(Node<KeyType, ValueType>* root, std::vector<Node<KeyType, ValueType>*>& arr)
    {
        if (root->left_child)
            GetNodeArray(root->left_child, arr);
        arr.push_back(root);
        if (root->right_child)
            GetNodeArray(root->right_child, arr);
    }

    void addChilds(Node<KeyType,ValueType>*r,QTreeWidgetItem* itm)
    {
        if (r->left_child)
        {
            QTreeWidgetItem *ch = new QTreeWidgetItem();
            ch->setText(0,QString::number(r->left_child->data.first));
            itm->addChild(ch);
            addChilds(r->left_child, ch);
        }
        if (r->right_child)
        {   QTreeWidgetItem *ch = new QTreeWidgetItem();
            ch->setText(0,QString::number(r->right_child->data.first));
            itm->addChild(ch);
            addChilds(r->right_child, ch);
        }
    }

    void ChangeNode(Node<KeyType,ValueType> *root, KeyType key, ValueType value)
    {
        if(key == root->data.first)
        {
            root->data.second = value;
        }
        if(key < root->data.first && root->left_child != nullptr)
        {
            ChangeNode(root->left_child,key,value);
        }
        if(key > root->data.first && root->right_child != nullptr)
        {
            ChangeNode(root->right_child,key,value);
        }
    }

public:
    MAP(KeyType key, ValueType value)
    {
        root = new Node<KeyType, ValueType>(key, value);
        root->color = "black";
    }
    MAP( )
    {

    }


    bool InsertNode(KeyType key, ValueType value)
    {
        Node<KeyType, ValueType>* t = find(root, key);
        root = AddNode(root, new Node<KeyType, ValueType>(key, value));
        return t != nullptr ? true : false;
    }


    void Erase(KeyType key)
    {
        root = DeleteNode(root, key);
    }


    void clear()
    {
        std::vector<Node<KeyType, ValueType>*> tmp;
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
        p->setText(0,QString::number(root->data.first));
        tree->addTopLevelItem(p);
    }


    bool cont(KeyType key)
    {
        Node<KeyType,ValueType>* t = find(root, key);
        return t == nullptr ? true : false;
    }

    void Change(KeyType key,ValueType val)
    {
        ChangeNode(root,key,val);
    }

};

#endif // MAP_H
