//
// Created by Martin on 20/04/2020.
//

#include "Renderer.h"
#include <vector>

Renderer::Renderer(Map *Mp, Character *Ch, Fruit_Vector *Vec, std::vector<Entity *> *Ene) {
    Level = Mp;
    Chara = Ch;
    Fruits = Vec;
    Enemies = Ene;
    Life = new Entity("../resources/level/spritesheet_Heart.png", {60, 40}, {1, 1, 1}, {20, 20});


    Entities = new All_entity();
    Entities->Add_entity(Life);
    Entities->Add_entity(Vec->Get_Vec_pointer());
    Entities->Add_entity(Chara);
    Entities->Add_entity(Enemies);
    Ani_Creator.Create(Entities->Get_Entities());
    Vec->Set_fruit_type();


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
    auto nombre{"Spikes"};
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

    //Set character state
    Chara->Set_Animation(State);

    //draws Life Amount
    Life->Set_Animation(3 - Chara->Get_life_Num());
    frameCounter ++;
    if (frameCounter >= 1) {
        frameCounter = 0;
        // Comienzo a dibujar
        BeginDrawing();
        ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

        //draw_Map();
        draw_Map();

        //DrawText
        DrawText("Points: ", 20, 20, 20, BLACK);
        DrawText(Chara->GetPoints().c_str(), 89, 20, 20, BLACK);
        DrawText("life: ", 20, 40, 20, BLACK);

        //Draws all entities
        Fruits->Call_Animator();
        Chara->Animate();
        Life->Animate();

        for (auto i: *Enemies) {
            i->Animate();
        }

        // Finalizo el dibujado
        EndMode2D();
        EndDrawing();
    }
}

