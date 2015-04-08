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
        Object * objects[CHILDS];
        Node * childs[CHILDS];

        size_t level;
    public:
    };
    
    Node * head;

public:
    bool insert(Object data)
    {
      Node ** s;
      if(this->find(data, s))return false;

      //*s = new Node(data);

      return true;
    }

    bool find(Object data, Node** &s)
    {
        s = &this->head;
        double min;
        size_t use;
        while(*s){
            min = INF;
            use = 0;
            for(int i=0;i<CHILDS;i++)
                if((*s)->objects[i]->contain(data) < min)
                    use = i;

            s = &(*s)->childs[use];
        }
        return *s;
    }
    
};

#endif // TREE_H
