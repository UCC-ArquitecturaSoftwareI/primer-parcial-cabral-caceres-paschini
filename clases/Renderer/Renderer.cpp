//
// Created by Martin on 20/04/2020.
//

#include "Renderer.h"


Renderer::Renderer(Map *Mp, Player *Ch) {
    Level = Mp;
    Character = Ch;
    Playani = new Animation(Character->getFilePathText(), Character->getMaxCol());
    camZoom.zoom = 1.5f;

}

void Renderer::draw_Map() {

    tson::Map test = Level->getMap();
    Rectangle rec;
    rec.x = 0.0f;
    rec.y = 0.0f;
    rec.height = Level->getMap().getTileSize().x;
    rec.width = Level->getMap().getTileSize().y;

    int firstID = Level->getMapTileset()->getFirstgid();
    int columns = Level->getMapTileset()->getColumns();
    int margin = Level->getMapTileset()->getMargin();
    int space = Level->getMapTileset()->getSpacing();

    auto &c = Level->getMap().getBackgroundColor();
    ClearBackground({c.r, c.g, c.b, c.a});

    for (auto nombre: {"Back", "Front"}) {
        tson::Layer *layer = test.getLayer(nombre);
        for (auto&[pos, tile] : layer->getTileData()) {

            if (tile != nullptr) {
                Vector2 position = {(float) std::get<0>(pos) * (Level->getMap()).getTileSize().x,
                                    (float) std::get<1>(pos) * (Level->getMap()).getTileSize().y};

                int baseTilePosition = (tile->getId() - firstID);

                int tileModX = (baseTilePosition % columns);
                int currentRow = (baseTilePosition / columns);
                int offsetx = tileModX * ((Level->getMap()).getTileSize().x + space) + margin;
                int offsety = currentRow * ((Level->getMap()).getTileSize().y + space) + margin;

                rec.x = offsetx;
                rec.y = offsety;
                DrawTextureRec(Level->getMapText(), rec, position, WHITE);
            }
        }
    }
}


void Renderer::UpdateDrawFrame(int State) {


    // Comienzo a dibujar
    BeginDrawing();
    //BeginMode2D(camZoom);
    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

    //draw_Map();
    draw_Map();
    DrawText("Beta ", 20, 20, 40, WHITE);

    //DrawCharacter
    Playani->setCurrentRow(State);
    Playani->Animate(Character->getPlayerPos());

    // Finalizo el dibujado
    EndDrawing();
}

