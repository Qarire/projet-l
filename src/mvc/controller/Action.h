#pragma once

class Action {

    private:
        float lastFor;
        float chrono;
        bool isRunning;

    public:
        Action(float lastfor, float chrono, bool run);
        ~Action() {};
        float getLastFor() const;
        float getChrono() const;

        void Update(float dt);

};