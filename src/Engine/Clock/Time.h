#ifndef MYAPP_TIME_H
#define MYAPP_TIME_H


class Time {
private:
    double deltaTime;
public:
    double getDeltaTime() const;
    void Tick();
};


#endif //MYAPP_TIME_H
