#include "physics_world.h"

namespace rlm {
    PhysicsWorld::PhysicsWorld() {
        world = World(b2Vec2(0,-10));
    }

    PhysicsWorld::PhysicsWorld(glm::vec2 gravity) {
        world = World(b2Vec2(gravity.x, gravity.y));
    }

    PhysicsWorld::~PhysicsWorld() {

    }

    PhysicsWorld::Update(float32 delta, int32 velocityIterations, int32 positionIterations) {
        world.Step(delta, velocityIterations, positionIterations);
    }

    PhysicsWorld::GetB2DWorld() {
        return world;
    }
}
