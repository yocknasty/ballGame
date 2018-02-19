#include "game.h"

namespace Textures{
    enum ID { Landscape, Airplane, Missile};
}
class TextureHolder{
    public:
        void load(Textures::ID id, const std::string& filename);
        sf::Texture& get(Textures::ID id);

    private:
        std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap; 
        sf::Texture mTexture;
    
};

