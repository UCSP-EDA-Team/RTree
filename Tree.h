#ifndef TREE_H
#define TREE_H

#include "config.h"
#include "Hyperrectangle.h"

template<typename Container>
class Tree
{
private:
    class Node
    {
        friend class Tree;
    private:
        Node * parent;
        size_t level;

        typedef pair<Hyperrectangle, void *> entry;
        vector<entry> entries;
    public:
        Node(Node *parent, size_t level)
        {
            this->parent = parent;
            this->level = level;
        }
    };
    
    Node * head;
    size_t nDimensions;

public:
    Tree(size_t nDimensions)
    {
        this->head = new Node(nullptr,0);
        this->nDimensions = nDimensions;
    }

    bool insert(Hyperrectangle BoundingBox, Container data)
    {
      Node ** s;
      this->chooseLeaf(BoundingBox, data, s);

      if((*s)->entries.size() < CHILDS)add(BoundingBox, data, s);

      //*s = new Node(data);

      return true;
    }

    bool add(Hyperrectangle BoundingBox, Container data, Node** &s)
    {
        (*s)->entries.push_back(make_pair(BoundingBox,(void *)&data));
    }

    bool chooseLeaf(Hyperrectangle BoundingBox, Container data, Node** &s)
    {
        s = &this->head;
        double min;
        size_t use;
        while((*s)->level!=0){
            min = INF;
            use = 0;
            for(int i=0;i<(*s)->entries.size();i++)
                if((*s)->entries[i].first.contain(BoundingBox) < min)
                    use = i;
            s = (Node **)(&(*s)->entries[use].second);;
        }
        return true;
    }

    bool Search(Hyperrectangle BoundingBox)
    {

        Node **s;
        s=&this->head;
        return find(BoundingBox,data,s);


    }

    bool find(Hyperrectangle BoundingBox, Node** &s )
    {

        if ((*s)->level == 0)
        {
            for(int i=0;i<(*s)->entries.size();i++)
            {
                if((*s)->entries[i].first.overlap(BoundingBox))
                {
                    return true;
                }
            }
        }

        for (int i=0;i<(*s)->entries.size();i++)
        {
            if((*s)->entries[i].first.overlap(BoundingBox))
            {
                s=(Node**) (& (*s)->entries[i].second);
                find(BoundingBox,data,s);
            }
        }

        return false;

    }


    
};

#endif // TREE_H
