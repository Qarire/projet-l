class Drawer {
private:
//! Singleton
    Drawer() {}
    static Drawer* Instance = nullptr;

//! Singleton

    Game* game;

public:
    //! Singleton
    static Drawer* GetInstance() { 
        if(Instance == nullptr)
            Instance = new Updater();
        
        return Instance;
    } 
    //! Singleton

    void Init() {
        game = Game.GetInstance();
    }

    void Draw(dt: float) {
        if(game == nullptr) throw std::bad_alloc("Updater hasn't been initialized");

        throw std::runtime_error("not implemented");        
    }

};