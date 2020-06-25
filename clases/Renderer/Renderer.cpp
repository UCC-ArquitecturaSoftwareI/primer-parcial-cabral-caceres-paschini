#include "Renderer.h"
#include <vector>

Renderer::Renderer(Map *Mp, Character *Ch, Fruit_Vector *Vec, std::vector<Enemies *> *Ene, Player_Decorator *Pla) {
    Level = Mp;
    Chara = Ch;
    Fruits = Vec;
    Bad_Guys = Ene;
    Dec = Pla;

    Life = new Entity("../resources/level/spritesheet_Heart.png", {60, 40}, {1, 1, 1}, {20, 20});

    Background = LoadTexture("../resources/level/Back_Game.png");

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
    Interface.LoadPlayer(Chara);
}

void Renderer::draw_Map() {

    scrollingBack -= 0.5f;
    if (scrollingBack <= -Background.width * 2) scrollingBack = 0;

    DrawTextureEx(Background, (Vector2) {-400 + scrollingBack, -300}, 0.0f, 2.0f, WHITE);
    DrawTextureEx(Background, (Vector2) {-400 + Background.width * 2 + scrollingBack, -300}, 0.0f, 2.0f, WHITE);

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

    for (auto nombre: {"Front"}) {
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


void Renderer::UpdateDrawFrame(int State, bool Time_Stp) {

    //Set character state

    if (Chara->GetInvulnerable() != 0)
        Chara->Set_Animation(0);
    else
        Chara->Set_Animation(State);


    if (Chara->Get_life_Num() > 0)
        Life->Set_Animation(3 - Chara->Get_life_Num());

    //draws Life Amount
    BeginDrawing();


    if (frameCounter != 2) {

        frameCounter = 0;
        // Comienzo a dibujar

        ClearBackground(WHITE); // Limpio la pantalla con blanco
        BeginMode2D(camZoom);

        camZoom.target = {Chara->Get_Entity_Pos().x, Chara->Get_Entity_Pos().y};


        //Draws all entities
        draw_Map();
        Chara->Animate();
        if (Dec != nullptr)
            Dec->DrawFx();

        if (Time_Stp) {
            Fruits->Call_Animator_Still();
            for (auto i: *Bad_Guys) {
                i->Animate_Still();
            }
        } else{
            Fruits->Call_Animator();
            for (auto i: *Bad_Guys) {
                i->Animate();
            }
        }
        EndMode2D();


        // Finalizo el dibujado
    } else frameCounter++;
    Interface.DrawGui(Fruits->Get_Amount(), Time_Stp);
    Life->Animate();
    EndDrawing();
}

void Renderer::Update_Fx(Player_Decorator *Pl) {
    Dec = Pl;
}

