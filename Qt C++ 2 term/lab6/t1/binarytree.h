#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>
#include <QTreeWidgetItem>
#include <vector>

class BinaryTree;
struct Node
{
    Node(std::string text, int key) : _key(key), _text(text)
    {
        left_child = nullptr;
        right_child = nullptr;
    }
    int height = 0;
    Node* left_child;
    Node* right_child;
    int _key;
    std::string _text;
};

class BinaryTree
{
    Node *root;
    void pryamoi_abhod(Node* root, std::string &output) // прямой обход
    {
        output += std::to_string(root->_key) + "->";
        if (root->left_child)
            pryamoi_abhod(root->left_child, output);
        if (root->right_child)
            pryamoi_abhod(root->right_child, output);
    }
    void obratniy_abhod(Node *root,std::string &str) // обратный обход
    {
        if(root->left_child)
            obratniy_abhod(root->left_child,str);
        if(root->right_child)
            obratniy_abhod(root->right_child,str);
        str += std::to_string(root->_key) + "->";

    }
    void symmetric(Node *root, std::string &output) // симметричный обход
    {
        if(root->left_child)
            symmetric(root->left_child,output);
        output += std::to_string(root->_key) + "->";
        if(root->right_child)
            symmetric(root->right_child, output);
    }
    void addChilds(Node*r,QTreeWidgetItem* itm)
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
    Node* delete_node(Node *root,int key) {
        if (root == NULL)
            return root;

        if (key == root->_key)
        {
            Node* tmp;
            if (root->right_child == NULL)
                tmp = root->left_child;
            else {

                Node* ptr = root->right_child;
                if (ptr->left_child == NULL) {
                    ptr->left_child = root->left_child;
                    tmp = ptr;
                }
                else {

                    Node* pmin = ptr->left_child;
                    while (pmin->left_child != NULL) {
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
        else if (key < root->_key)
            root->left_child = delete_node(root->left_child, key);
        else
            root->right_child = delete_node(root->right_child, key);
        return root;
    }
    void storeBSTNodes(Node* r, std::vector<Node*>& nodes)
    {
        if (r == NULL)
            return;


        storeBSTNodes(r->left_child, nodes);
        nodes.push_back(r);
        storeBSTNodes(r->right_child, nodes);
    }

    Node* buildTreeUtil(std::vector<Node*>& nodes, int start,
        int end)
    {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        Node* r = nodes[mid];

        r->left_child = buildTreeUtil(nodes, start, mid - 1);
        r->right_child = buildTreeUtil(nodes, mid + 1, end);

        return r;
    }

    Node* buildTree(Node* r)
    {
        std::vector<Node*> nodes;
        storeBSTNodes(r, nodes);
        int n = nodes.size();
        return buildTreeUtil(nodes, 0, n - 1);
    }



public:
    BinaryTree()
    {
        root = nullptr;
    }
    /*void add_node(std::string text, int key) // добавить узел
    {
        if (!root)
        {
            root = new Node(text, key);
            return;
        }
        else
        {
            Node* tmp = root;
            while (tmp != nullptr)
            {
                if (key < tmp->_key)
                {
                    if (tmp->left_child == nullptr)
                    {
                        tmp->left_child = new Node(text, key);
                        return;
                    }
                    else
                    {
                        tmp = tmp->left_child;
                    }
                }
                else
                {
                    if (tmp->right_child == nullptr)
                    {
                        tmp->right_child = new Node(text, key);
                        return;
                    }
                    else
                    {
                        tmp = tmp->right_child;
                    }
                }
            }
            tmp = new Node(text, key);
        }
    }*/
    unsigned char height(Node* p)
    {
        return p?p->height:0;
    }
    int bfactor(Node* p)
    {
        return height(p->right_child)-height(p->left_child);
    }

    void fixheight(Node* p)
    {
        unsigned char hl = height(p->left_child);
        unsigned char hr = height(p->right_child);
        p->height = (hl>hr?hl:hr)+1;
    }
    Node* rotateright(Node* p) // правый поворот вокруг p
    {
        Node* q = p->left_child;
        p->left_child = q->right_child;
        q->right_child = p;
        fixheight(p);
        fixheight(q);
        return q;
    }
    Node* rotateleft(Node* q) // левый поворот вокруг q
    {
        Node* p = q->right_child;
        q->right_child = p->left_child;
        p->left_child = q;
        fixheight(q);
        fixheight(p);
        return p;
    }
    Node* balance(Node* p) // балансировка узла p
    {
        fixheight(p);
        if( bfactor(p)==2 )
        {
            if( bfactor(p->right_child) < 0 )
                p->right_child = rotateright(p->right_child);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->left_child) > 0  )
                p->left_child = rotateleft(p->left_child);
            return rotateright(p);
        }
        return p; // балансировка не нужна
    }
    Node* insert(Node* p,std::string str, int k) // вставка ключа k в дерево с корнем p
    {
        if( !p ) return new Node(str,k);
        if( k < p->_key )
            p->left_child = insert(p->left_child,str,k);
        else
            p->right_child = insert(p->right_child,str,k);
        return balance(p);
    }

    std::string print(int key) // принт
    {
        Node *tmp = root;
        while (tmp != nullptr)
        {
            if (tmp->_key == key)
            {
                return tmp->_text;
            }
            if (key < tmp->_key)
                tmp = tmp->left_child;
            else
                tmp = tmp->right_child;
        }
        return "Key is not found";
    }
    std::string preorder() // прямой
    {
        std::string str;
        pryamoi_abhod(root,str);
        str.pop_back();
        str.pop_back();
        return str;
    }
    std::string postorder() // обратный
    {
        std::string str;
        obratniy_abhod(root,str);
        str.pop_back();
        str.pop_back();
        return str;
    }
    std::string increase() // по возрастанию ключа
    {
        std::string str;
        symmetric(root,str);
        str.pop_back();
        str.pop_back();
        return str;
    }
    void print_tree(QTreeWidget *tree)
    {
        QTreeWidgetItem *p = new QTreeWidgetItem();
        addChilds(root,p);
        p->setText(0,QString::number(root->_key));
        tree->addTopLevelItem(p);
    }
    void remove(int key)
    {
        root = delete_node(root, key);
    }
    void balance()
    {
        root = buildTree(root);
    }
    std::string individual_task()
    {
        std::vector<Node*> nodes;
        storeBSTNodes(root, nodes);
        int mid = (0 + nodes.size() - 1) / 2;
        //Node *tmp = nodes[mid];
        return std::to_string(nodes[mid]->_key);
    }
    void add_node(std::string str, int key)
    {
        root = insert(root,str, key);
    }



};

#endif // BINARYTREE_H
