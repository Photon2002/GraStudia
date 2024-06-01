#include <SFML/Graphics.hpp>

class KolizjaMapy : public sf::Drawable, public sf::Transformable
{
	public:
		std::vector<sf::RectangleShape> ListaObiektowKolizyjnych;
		bool kolizja(sf::Vector2u tileSize, std::vector<int> collisionData, unsigned int width, unsigned int height);
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
};