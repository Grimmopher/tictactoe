#ifndef MYAPP_RENDERER_H
#define MYAPP_RENDERER_H


class Renderer {
private:
    int lastBlock;
    int currentBlock;
    void HighlightBlock(int block, bool highlight);
    int CheckInput(int currentBlock);
public:
    Renderer();

    void Render();

    virtual ~Renderer();
};


#endif //MYAPP_RENDERER_H
