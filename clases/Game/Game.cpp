
#include "Game.h"

Game::Game() {}


void Game::PlayMusic() {
    Srend->PlayMusic();
}

void Game::UpdateFrame() {

    //Check key inputs
    Input->setKeyPress();

    //Move player x cordinates
    player->Move_x();
    world->Friction();
    Col->IsColliding_X(player);

    //Move player y cordinates
    player->Move_y();

    if (Col->IsFlying(player))
        world->Gravity();


    Col->IsColliding_y(player);
    Col->IsCollidingPlataform(player);
    Input->GetCanJump(player->GetSpeed().y == 0);

    int State = Input->GetCharStatus();
    //Fruits
    if (Col->IsCollecting(player)) {
        Fruits->Delete_fruit();
        Srend->PlaySoundfx("resources/Music/Pick_FX.mp3");
        if (Power_Up == 0) {
            if (Pla != nullptr) {
                player->SetSpdMulti(1);
                player->Set_MaxSpeed(3);
                delete Pla;
                Pla = nullptr;
                Rend->Update_Fx(Pla);
            }
            Pla = new Player_Decorator(player);
            Rend->Update_Fx(Pla);
            Power_Up = 2;
            if (Pla->Get_Type() == 5)
                Time_Stp = true;
        } else {
            Power_Up--;
        }
    }

    if (Pla != nullptr) {
        Pla->Activate_Power();
        Pla->Reduce_Timer();
        if (Pla->Get_Timer()) {
            player->SetSpdMulti(1);
            player->Set_MaxSpeed(3);
            Time_Stp = false;
            delete Pla;
            Pla = nullptr;
            Rend->Update_Fx(Pla);
        }
    }

    //Damage Spikes
    if (Col->Dmg(player) && player->GetInvulnerable() == 0) {
        State = 0;
        player->Change_life(-1);
        player->SetInvulnerable(80);
        Srend->PlaySoundfx("resources/Music/DMG.mp3");
    }

    if (!Time_Stp) {
        for (auto i:Bad_Guys) {
            //Dmg Enemies
            if (Col->Dmg(player, i) && player->GetInvulnerable() == 0) {
                State = 0;
                player->Change_life(-1);
                player->SetInvulnerable(80);
                Srend->PlaySoundfx("resources/Music/DMG.mp3");
            }

            i->move_x();
            Col->IsColliding_X(i);
            i->move_y();
            Col->IsColliding_y(i);
        }
    }

    if (player->GetInvulnerable() != 0) {
        player->LessInv();
    }
    //Draw the result
    Rend->UpdateDrawFrame(State, Time_Stp);
    if (player->Is_alive())
        GoTo = 0;
    else {
        GoTo = 3;
        Won = false;
    }
    if (player->Get_Fruits_left() == 0) {
        GoTo = 3;
        Won = true;
    }
}

void Game::UpdateMusic() {
    Srend->UpdateMusic();
}

void Game::Update_Game() {
    while (GoTo == 0) {
        UpdateFrame();
        if (!Time_Stp)
            UpdateMusic();
    }
}

void Game::On() {
    Reset_Game();
    PlayMusic();
    Update_Game();

}

int Game::Off() {
    Del();
    return GoTo;
}

void Game::Del() {
    delete map;
    delete player;
    delete Srend;
    delete Input;
    delete Col;
    delete world;
    delete Fruits;
    delete fac;
    for (auto i:Bad_Guys) {
        delete i;
    }


}

bool Game::GetWon() {
    return Won;
}

Vector2 Game::GetTime() {
    return player->getTime();
}

void Game::Reset_Game() {
    Time_Stp = false;
    GoTo = 0;
    Power_Up = 2;
    map = new Map("resources/level/Map1.json");
    player = new Character("resources/Player/spritesheet.png", map->ReturnCharPos(),
                           {6, 5, 5, 1, 1, 10, 10, 11, 11, 4, 4});
    Fruits = new Fruit_Vector(*map->Get_Fruits());

    fac = new Enemies_factory();
    fac->Set_Map(map->Get_enemies());
    Bad_Guys = fac->Make_Enemies();

    Rend = new Renderer(map, player, Fruits, &Bad_Guys, Pla);
    Srend = new Sound_Render("resources/Music/Bad_song.mp3");
    Input = new Input_Handler(player, Srend);


    Col = new Collision();
    Col->Load_Vector(map->Return_Floor(), 0);
    Col->Load_Vector(map->Return_Plataform(), 1);
    Col->Load_Vector(map->ReturnTraps(), 2);
    Col->Load_Vector(Fruits->Get_Vec_pointer());

    world = new World(player);
}




