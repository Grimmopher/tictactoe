#include <memory>

#include <iostream>
#include "Engine/Engine.h"

int main() {
    auto engine = std::make_unique<Engine>();
    engine->Init();
    return 0;
}