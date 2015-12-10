#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_

#include <Box2D/Box2D.h>
#include <glm/glm.hpp>
#include "physics_world"

namespace rlm {
    class RigidBody {
    protected:
        b2Body body;
        b2BodyDef bodyDef;
        b2PolygonShape dynamicBox;
        b2FixtureDef fixtureDef;
    public:
        RigidBody(PhysicsWorld world);
        ~RigidBody();

        glm::vec2 GetPos();
        void SetPos(glm::vec2 pos);
    };
}

#endif
