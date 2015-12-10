#ifndef PHYSICS___WORLD_H_
#define PHYSICS___WORLD_H_

namespace rlm {
    class PhysicsWorld {
    private:
        b2World world;
    public:
        PhysicsWorld();
        PhysicsWorld(glm::vec2 gravity);
        ~PhysicsWorld();

        void Update(float32 delta, int32 velocityIterations, int32 positionIterations);
        b2World GetB2DWorld();
    };
}

#endif
