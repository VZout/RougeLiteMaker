#include "physics_world.h"

namespace rlm {
    PhysicsWorld::PhysicsWorld() {
        //world = b2World(b2Vec2(0,-10));
    }

    PhysicsWorld::PhysicsWorld(glm::vec2 gravity) {
        //world = b2World(b2Vec2(gravity.x, gravity.y));
    }

    PhysicsWorld::~PhysicsWorld() {

    }

    void PhysicsWorld::Update(float32 delta, int32 velocityIterations, int32 positionIterations) {
        //world.Step(delta, velocityIterations, positionIterations);
    }

    b2World* PhysicsWorld::GetB2DWorld() {
        return world;
    }
}
