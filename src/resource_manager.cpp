#include "resource_manager.h"

namespace rlm {
    ResourceManager::ResourceManager() {
        CreateTextureGroup("persistant_textures", 0);
    }

    ResourceManager::~ResourceManager() {

    }

    void ResourceManager::CreateTextureGroup(const char* name, unsigned int id) {
        std::vector<const char*>::iterator name_iterator = textureGroupNames.begin();
        std::vector<std::vector<Texture*>>::iterator group_iterator = textures.begin();

        std::vector<Texture*> newGroup;

        //TODO should check if texture group already exists. And if it doescreatepopup.
        textureGroupNames.insert(name_iterator + id, name);
        textures.insert(group_iterator + id, newGroup);
    }

    void ResourceManager::LoadTexture(const char* path, const char* unique_name, unsigned int texture_group) {
        Texture* texture = new Texture(path, unique_name);
        textures[texture_group].push_back(texture);
    }

    Texture* ResourceManager::GetTexture(const char* unique_name, unsigned int texture_group) {
        for(unsigned int i = 0; i < textures[texture_group].size(); i++) {
            if(textures[texture_group][i]->unique_name == unique_name) {
                return textures[texture_group][i];
            }
        }
    }
}
