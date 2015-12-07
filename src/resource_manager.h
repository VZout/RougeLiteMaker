#ifndef RESOURCE___MANAGER_
#define RESOURCE___MANAGER_

#include <vector>
#include "texture.h"
#include "util.h"

namespace rlm {
    class ResourceManager {
    private:
        std::vector<std::vector<Texture*>> textures;
        std::vector<const char*> textureGroupNames;
        //std::vector<Texture*> textures;

    public:
        ResourceManager();
        ~ResourceManager();

        void CreateTextureGroup(const char* name, unsigned int id);
        void LoadTexture(const char* path, const char* unique_name, unsigned int texture_group);
        Texture* GetTexture(const char* unique_name, unsigned int texture_group);
    };
}

#endif
