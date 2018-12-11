#ifndef MYAPP_CLOCK_H
#define MYAPP_CLOCK_H


class Clock {
private:
    double deltaTime;
public:
    double getDeltaTime() const;
    void Tick();
};


#endif //MYAPP_CLOCK_H
