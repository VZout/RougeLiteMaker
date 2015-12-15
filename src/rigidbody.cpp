#include "rigidbody.h"

namespace rlm {

    RigidBody::RigidBody() {

    }

    RigidBody::RigidBody(PhysicsWorld world) {
        /*
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0.0f, 4.0f);

        body = world.GetB2DWorld()->CreateBody(&bodyDef);

        dynamicBox.SetAsBox(1.0f, 1.0f);

        fixtureDef.shape = &dynamicBox;

        fixtureDef.friction = 0.3f;
        fixtureDef.density = 0.5f;
        fixtureDef.friction = 0.4f;
        fixtureDef.restitution = 0.6f;

        body.CreateFixture(&fixtureDef);
        */
    }

    RigidBody::~RigidBody() {

    }

    glm::vec2 RigidBody::GetPos() {
        return glm::vec2(0,0);
    }

    void RigidBody::SetPos(glm::vec2 pos) {
        //body.position.x = pos.x;
        //body.position.y = pos.y;
    }

}
