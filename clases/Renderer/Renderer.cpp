//
// Created by Martin on 20/04/2020.
//

#include "Renderer.h"
#include <vector>

Renderer::Renderer(Map *Mp, Character *Ch, Fruit_Vector *Vec, std::vector<Enemies *> *Ene) {
    Level = Mp;
    Chara = Ch;
    Fruits = Vec;
    Bad_Guys = Ene;
    Life = new Entity("../resources/level/spritesheet_Heart.png", {60, 40}, {1, 1, 1}, {20, 20});

    Entities = new All_entity();
    Entities->Add_entity(Life);
    Entities->Add_entity(Fruits->Get_Vec_pointer());
    Entities->Add_entity(Chara);
    Entities->Add_entity(Bad_Guys);

    Ani_Creator.Create(Entities->Get_Entities());
    Vec->Set_fruit_type();


    camZoom.target = (Vector2) {Chara->Get_Entity_Pos().x, Chara->Get_Entity_Pos().y};
    camZoom.offset = (Vector2) {1104 / 2, 688 / 2};
    camZoom.rotation = 0.0f;
    camZoom.zoom = 1.5f;
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
    if (State == 0)
        Char_DMG = 80;

    Chara->Set_Animation(0);

    if (Char_DMG == -1)
        Chara->Set_Animation(State);
    else
        Char_DMG--;


    Life->Set_Animation(3 - Chara->Get_life_Num());

    //draws Life Amount
    BeginDrawing();

    if (frameCounter != 2) {

        frameCounter = 0;
        // Comienzo a dibujar

        ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

        BeginMode2D(camZoom);
        camZoom.target = {Chara->Get_Entity_Pos().x, Chara->Get_Entity_Pos().y};
        draw_Map();

        //Draws all entities
        Fruits->Call_Animator();
        Chara->Animate();
        for (auto i: *Bad_Guys) {
            i->Animate();
        }
        EndMode2D();

        Life->Animate();

        // Finalizo el dibujado
    } else frameCounter++;
    Interface.DrawGui(Fruits->Get_Amount());
    Life->Animate();
    EndDrawing();
}

