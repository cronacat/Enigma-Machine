#pragma once

class UserInput {
    UserInput(){}

public:
    enum Action { ENC, DEC };

    Action getUserAction();

    // Singleton
    static UserInput& Instance() {
        static UserInput uI;
        return           uI;
    }

};

