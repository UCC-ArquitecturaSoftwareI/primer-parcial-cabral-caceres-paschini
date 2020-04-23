//
// Created by Martin on 20/04/2020.
//

#include "Renderer.h"


Renderer::Renderer(Map *Mp, Player *Ch) {
    Level = Mp;
    Character = Ch;
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

    for (auto nombre: {"Background", "Floor"}) {
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

void Renderer::draw_Character() {

}

static void UpdateDrawFrame() {

    // siempre hay que reproducir la musica que esta actualmente

    // Verifico Entradas de eventos.
    if (IsKeyDown(KEY_RIGHT)) player.move_x(2.0f);
    if (IsKeyDown(KEY_LEFT)) player.move_x(-2.0f);
    if (IsKeyDown(KEY_UP)) player.jump_y();



    // Comienzo a dibujar
    BeginDrawing();
    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco


    // Dibujo todos los elementos del juego.
    draw_Character();
    draw_Map();
    DrawText("Start", 20, 20, 40, LIGHTGRAY);

    // Finalizo el dibujado
    EndDrawing();
}