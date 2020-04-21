//
// Created by Martin on 20/04/2020.
//

#include "Renderer.h"

#include <utility>

Renderer::Renderer(Map &level, Player *&Character) {

}

void Renderer::draw_Map() {
    Rectangle rec;
    rec.x = 0.0f;
    rec.y = 0.0f;
    rec.height = Level.getMap().getTileSize().x;
    rec.width = Level.getMap().getTileSize().y;

    int firstID = Level.getMapTileset()->getFirstgid();
    int columns = Level.getMapTileset()->getColumns();
    int margin = Level.getMapTileset()->getMargin();
    int space = Level.getMapTileset()->getSpacing();

    //auto &c = map.getBackgroundColor();
    //ClearBackground({c.r, c.g, c.b, c.a});

    for (auto nombre: {"Background", "Floor"}) {
        auto *layer = Level.getMap().getLayer(nombre);
        for (auto&[pos, tile] : layer->getTileData()) {

            if (tile != nullptr) {
                Vector2 position = {(float) std::get<0>(pos) * (Level.getMap()).getTileSize().x,
                                    (float) std::get<1>(pos) * (Level.getMap()).getTileSize().y};

                int baseTilePosition = (tile->getId() - firstID);

                int tileModX = (baseTilePosition % columns);
                int currentRow = (baseTilePosition / columns);
                int offsetx = tileModX * ((Level.getMap()).getTileSize().x + space) + margin;
                int offsety = currentRow * ((Level.getMap()).getTileSize().y + space) + margin;

                rec.x = offsetx;
                rec.y = offsety;
                DrawTextureRec(Level.getMapText(), rec, position, WHITE);
            }
        }
    }
}

void Renderer::draw_Character() {
        DrawTexture(Character->getPlayer(), Character->getPlayerPos().x - Character->getPlayer().width/2, Character->getPlayerPos().y- Character->getPlayer().height/2, WHITE);
}
