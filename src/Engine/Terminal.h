#ifndef MYAPP_RENDERER_H
#define MYAPP_RENDERER_H


class Terminal {
private:
    int lastBlock;
    int currentBlock;
    void HighlightBlock(int block, bool highlight);
    int CheckInput(int currentBlock);
public:
    Terminal();

    void Render();

    virtual ~Terminal();
};


#endif //MYAPP_RENDERER_H
