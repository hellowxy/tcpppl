#ifndef LUKE_STRING_ITERATOR_H
#define LUKE_STRING_ITERATOR_H
#include"LukeString.h"
class LukeStringIterator
{
    public:
        void next(){m_index++;}
        LukeString::Cref get(){return m_ls[m_index];}
        bool is_past_end(){ return m_index == m_ls.rep->sz;}
        LukeStringIterator(LukeString& ls):m_ls(ls), m_index(0)
        {}
    private:
        LukeString& m_ls;
        int m_index;
        

};

#endif