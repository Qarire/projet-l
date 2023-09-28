#pragma once

class Updater {
private:
// ! Singleton
    Updater() {
        stage = Stage.GetInstance();
    }
    static Updater Instance = null;
// ! Singleton

public:
    static Updater GetInstance() {
        if(Instance == null)
            Instance = new Updater();
        return Instance;
    }

    void Update() {//GameTime gameTime) {
    
    }
}