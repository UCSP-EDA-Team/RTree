#ifndef TREE_H
#define TREE_H

#include "config.h"
#include "Rectangle.h"

class Tree
{
private:
    class Node
    {
        friend class Tree;
    private:
        Node * parent;
        size_t level;

        vector<Object> objects;
        vector<Node *> childs;
    public:
        Node(Node *parent, size_t level)
        {
            this->parent = parent;
            this->level = level;
        }
    };
    
    Node * head;

public:
    Tree()
    {
        this->head = new Node(nullptr,0);
    }

    bool insert(Object data)
    {
      Node ** s;
      this->chooseLeaf(data, s);

      if((*s)->objects.size() < CHILDS)add(data, s);

      //*s = new Node(data);

      return true;
    }

    bool add(Object data, Node** &s)
    {
        (*s)->objects.push_back(data);
    }

    bool chooseLeaf(Object data, Node** &s)
    {
        s = &this->head;
        double min;
        size_t use;
        while((*s)->level!=0){
            min = INF;
            use = 0;
            for(int i=0;i<(*s)->objects.size();i++)
                if((*s)->objects[i].contain(data) < min)
                    use = i;

            s = &(*s)->childs[use];
        }
        return true;
    }
    
};

#endif // TREE_H
