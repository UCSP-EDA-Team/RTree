#ifndef TREE_H
#define TREE_H

#include "config.h"
#include "Hyperrectangle.h"

template<typename Container>
class Tree
{
private:
    typedef pair<Hyperrectangle, void *> entry;
    typedef vector<entry> aentry;
    class Node
    {
        friend class Tree;
    private:
        Node * parent;
        size_t level;


        aentry entries;
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
      Node * s;
      this->chooseLeaf(BoundingBox, data, s);

      if(s->entries.size() < CHILDS)add(BoundingBox, data, s);

      //*s = new Node(data);

      return true;
    }

    bool add(Hyperrectangle BoundingBox, Container data, Node* &s)
    {
        s->entries.push_back(make_pair(BoundingBox,(void *)&data));
    }

    bool chooseLeaf(Hyperrectangle BoundingBox, Container data, Node* &s)
    {
        s = this->head;
        double min;
        size_t use;
        while(s->level!=0){
            min = INF;
            use = 0;
            for(int i=0;i<s->entries.size();i++)
                if(s->entries[i].first.contain(BoundingBox) < min)
                    use = i;
            s = static_cast<Node *>(s->entries[use].second);
        }
        return true;
    }

<<<<<<< Updated upstream
<<<<<<< Updated upstream
    Hyperrectangle Adjust(Node * & s)
    {
        points mbr_points=s->entries[0].first.vertices;

        mbr_points[0].first;

        for (std::vector< pair<Hyperrectangle, void *> >::iterator i = ++(s->entries.begin()); i != s->entries.end(); ++i)
        {
            for (size_t j=0;j<nDimensions;j++ )
            {
                if((mbr_points[j].first)>((*i).first.vertices[j].first))
                {
                    mbr_points[j].first=(*i).first.vertices[j].first;
                }
                if((mbr_points[j].second)<((*i).first.vertices[j].second))
                {
                    mbr_points[j].second=(*i).first.vertices[j].second;
                }
            }

        }
        return Hyperrectangle(mbr_points);
    }


    size_t IdxNode(Node * &parent, Node * &child)
    {
        for (size_t n_idx;n_idx<parent->entries.size();n_idx++)
        {
            if (parent->entries[n_idx].second == child)
            {
                return n_idx;
            }
        }
    }

    void AdjustTree(Node ** & l,Node ** & splitted)
    {
        Node ** n= &(*l);
        if ((*n) == this->head)
        {
            return;
        }

        Node ** parent = &((*n)->parent);
        size_t n_idx=IdxNode(*parent,*n);
        (*parent)->entries[n_idx].first=Adjust(*n);
        if (splitted != NULL)
        {
            if ((*splitted)->entries.size()< 4 /* (4 es un numero que puse cualquiera pero debe ser: M-1)*/ )
            {
                typename Node::entry new_entry;
                Node ** sp_parent =&((*splitted)->parent);
                new_entry.second=(void*)(*splitted);
                new_entry.first=(*sp_parent)->entries[idxNode(*sp_parent,*splitted)].first;
                (*parent)->entries.push_back(new_entry);
                return AdjustTree(parent,NULL);

            }
            else
            {
                /*Set {Parent, Parent’} = SplitNode (Parent, Splitted)
                 *return AdjustTree(parent,Parent');
                 */
            }
        }
        else
        {
            return AdjustTree(parent, NULL);
        }


    }

    bool Search(Hyperrectangle BoundingBox)
    {

        Node **s;
        s=&this->head;
        return find(BoundingBox,s);


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
                find(BoundingBox,s);
            }
        }

        return false;

    }


=======
=======
>>>>>>> Stashed changes
    bool split(Node * &l, Node *&ll, aentry g)
    {

    }

    void pickSeeds(aentry block, int &e1, int &e2 )
    {
        double d = INF;
        double tmp;
        for(int i=0;i<block.size();i++)
        {
            for(int j=i;j<block.size();i++)
            {
                tmp = block[i].first.contain(block[j].first) - block[i].first.area() - block[j].first.area() ;
                if(d > (tmp))
                {
                    e1 = i;
                    e2 = j;
                    d = tmp;
                }
            }
        }
    }
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
    
};

#endif // TREE_H
