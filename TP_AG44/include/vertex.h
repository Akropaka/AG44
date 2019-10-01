#ifndef VERTEX_H
#define VERTEX_H


class vertex
{
    public:
        vertex();
        vertex(int id, int x, int y);
        virtual ~vertex();
        int id;
        int x,y;
    protected:
};

#endif // VERTEX_H
