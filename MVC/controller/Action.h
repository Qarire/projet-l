#pragma once

class Action {

    public:
        float lastFor;
        float chrono;
        bool isRunning;

    private:

        Action(float lastfor, float chrono, bool run);
        ~Action();
        float getLastFor() const;
        float getChrono() const;

        void Update(float dt);

}