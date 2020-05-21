//
// Created by Martin on 20/04/2020.
//

#include "Renderer.h"
#include <vector>



Renderer::Renderer(Map *Mp, Character *Ch) {
    Level = Mp;
    Chara = Ch;
    camZoom.zoom = 1.5f;
    Ani_Creator.Create(Ch);

}

void Renderer::draw_Map() {

    tson::Map test = Level->getMap();
    Rectangle rec;
    rec.x = 0.0f;
    rec.y = 0.0f;
    rec.height = Level->getMap().getTileSize().x;
    rec.width = Level->getMap().getTileSize().y;

    int firstID = Level->getMapTileset().front()->getFirstgid();
    int columns = Level->getMapTileset().front()->getColumns();
    int margin = Level->getMapTileset().front()->getMargin();
    int space = Level->getMapTileset().front()->getSpacing();

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
                DrawTextureRec(Level->getMapText().front(), rec, position, WHITE);
            }
        }
    }
    auto nombre {"Spikes"};
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
            DrawTextureRec(Level->getMapText().back(), rec, position, WHITE);
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
    DrawText("Stable 1.4 ", 20, 20, 20, WHITE);

    //DrawCharacter
    Chara->GetAni()->setCurrentRow(State);
    Chara->GetAni()->Animate(Chara->Get_Entity_Pos());

    // Finalizo el dibujado
    EndMode2D();
    EndDrawing();
}

