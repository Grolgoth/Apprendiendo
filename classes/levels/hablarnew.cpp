#include "hablarnew.h"
#include "gamedelegator.h"

hablarNew::hablarNew(View* view, TTF_Font* font) {
    step = 0;
    backGround = SDL_CreateRGBSurface(SDL_SWSURFACE,view->WINW,view->WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
}

hablarNew::~hablarNew()
{
    //dtor
}
void hablarNew::checkName(std::string name) {
    if (name.size() > 0 && name.size() < 40)
        step++;
    else {
        p.name = "";
        step = 1;
    }
}
void hablarNew::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {
    handleButtons(view, Event, gameDelegator);
    if (step == 0) {
        gameDelegator->getTextRenderers()[0]->render(getResponse(0, nullptr), Event);
        step ++;
    }
    if (step == 1 && !gameDelegator->getTextRenderers()[0]->getRendering())
        step ++;
    if (step == 3) {
        gameDelegator->getTextRenderers()[0]->render(getResponse(2, nullptr), Event);
        step ++;
    }
    if (step == 4 && !gameDelegator->getTextRenderers()[0]->getRendering())
        step4(view, gameDelegator);
    if (step == 6)
        step6(view, gameDelegator, Event);
    if (step == 8 && !gameDelegator->getTextRenderers()[0]->getRendering())
        step8(view, gameDelegator, Event);
    if (Event->eventtype == Event->KEYEVENT) {
        if (Event->getKeyEvent()->getRepeat() && keyrepeatdelay < 1) {
            keyrepeatdelay ++;
            return;
        }
        keyrepeatdelay = 0;
        if(step == 2 && Event->getKeyEvent()->getDown())
            step2(Event, gameDelegator);
        if (step == 7 && Event->getKeyEvent()->getDown() && Event->getKeyEvent()->getKey() == "enter")
            step7(gameDelegator, Event);
        if (step == 9 && Event->getKeyEvent()->getDown() && Event->getKeyEvent()->getKey() == "enter")
            step9(gameDelegator, Event);
    }
}
void hablarNew::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {
    if (step == 5)
        step5(Button);
}
void hablarNew::traits(std::string trait) {
    if (trait == "Soy agradable") p.nice = true;
    if (trait == "Soy leal") p.loyal = true;
    if (trait == "Soy valiente") p.brave = true;
    if (trait == "Soy optimista") p.optimistic = true;
    if (trait == "Soy inteligente") p.intelligent = true;
    if (trait == "Yo hablo mucho") p.talksalot = true;
    if (trait == "Ya estoy aburrido. ¿Qué inquisición es esta?") p.asshole = true;
    if (trait == "Por el amor de Dios, para ya!") p.aggressive = true;
    if (trait == "Cuando despierto, No. Simplemente no.") p.noMorning = true;
    if (trait == "Soy paciente") p.patient = true;
    if (stringContains(trait, "divertid"))
        p.funny = true;
    else if (stringContains(trait, "Soy caótic"))
        p.chaotic = true;
    else if (stringContains(trait, "obstinad"))
        p.stubborn = true;
    else if (stringContains(trait, "deportiv"))
        p.sportive = true;
    else if (stringContains(trait, "Estoy content"))
        p.content = true;
    else if (stringContains(trait, "timid"))
        p.shy = true;
    else if (stringContains(trait, "por supuesto"))
        p.arrogant = true;
}
void hablarNew::personaityTraits(std::vector<std::string>Traits) {
        for (unsigned int i = 0; i < Traits.size(); i++)
            traits(Traits[i]);
}
void hablarNew::hobbies(std::string hobby) {
    if (stringContains(hobby, "playa"))
        p.hobbies[0] = 'p';
    if (stringContains(hobby, "comer"))
        p.hobbies[1] = 'c';
    if (stringContains(hobby, "afuera"))
        p.hobbies[2] = 'e';
    if (stringContains(hobby, "Leer"))
        p.hobbies[3] = 'l';
    if (stringContains(hobby, "gaming"))
        p.hobbies[4] = 'i';
    if (stringContains(hobby, "musica"))
        p.hobbies[5] = 'm';
    if (stringContains(hobby, "Aprender"))
        p.hobbies[6] = 'A';
    if (hobby == "Bailar")
        p.hobbies[7] = 'b';
    if (stringContains(hobby, "Fiestas"))
        p.hobbies[8] = 'f';
    if (stringContains(hobby, "quieres"))
        p.hobbies[9] = 'q';
    if (stringContains(hobby, "sexo"))
        p.hobbies[10] = 'x';
    if (stringContains(hobby, "Ir"))
        p.hobbies[11] = 't';
    if (hobby == "El arte")
        p.hobbies[12] = 'a';
    if (stringContains(hobby, "cosas"))
        p.hobbies[13] = 'o';
}
void hablarNew::step2(event* Event, gameDelegator* gd) {
    if (keyCheck(Event->getKeyEvent()->getKey(), std::vector<std::string>{"enter", "backspace"})) {
            if (Event->getKeyEvent()->getKey() == "enter") {
                checkName(p.name);
                if (step == 1) {
                    gd->getTextRenderers()[0]->render(getResponse(1, nullptr), Event);
                    Event->eventtype = Event->SPECIAL;
                }
            }
            else if (p.name.size() > 0) {
                p.name = p.name.substr(0, p.name.size() - 1);
                gd->getTextRenderers()[0]->writing(p.name);
            }
    }
    else if (step == 2 && Event->getKeyEvent()->getDown()) {
        p.name += written(Event->getKeyEvent()->getKey());
        gd->getTextRenderers()[0]->writing(p.name);
    }
}
void hablarNew::step4(View* view, gameDelegator* gd) {
    SDL_Color color = createColor(160, 80, 4, 255);
    SDL_Surface* tempSurf = TTF_RenderText_Solid(gd->getFonts()[0], "Yo soy...", color);
    SDL_Rect R2; R2.x=(view->WINW-tempSurf->w)/2; R2.y = 2;
    SDL_BlitSurface(tempSurf, NULL, backGround, &R2);
    SDL_FreeSurface(tempSurf);
    buttons.push_back(button(0, 100, view, gd->getFonts()[2], "Un Hombre", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(250, 100, view, gd->getFonts()[2], "Una Mujer", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(500, 100, view, gd->getFonts()[2], "¡No creas que puedes categorizarme!", view->getFilepath() + "img/LB.bmp"));
    step ++;
}
void hablarNew::step5(button* Button) {
    if (Button->getName() == "Un Hombre")
            p.gender = "M";
        else if (Button->getName() == "Una Mujer")
            p.gender = "F";
        else
            p.gender = "N";
    step ++;
}
void hablarNew::step6(View* view, gameDelegator* gd, event* Event) {
    clearButtons();
    viewOffset = 0;
    SDL_FreeSurface(backGround);
    backGround = nullptr;
    scrollBackground(view, true);
    std::string variableNames[2] = {p.name, p.gender};
    gd->getTextRenderers()[0]->render(getResponse(6, variableNames), Event);
    std::vector<std::string> buttonNames = getButtonNames(6, variableNames);
    buttons.push_back(button(true, 10, 10, view, gd->getFonts()[2], buttonNames[0], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 160, view, gd->getFonts()[4], buttonNames[1], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 310, view, gd->getFonts()[4], buttonNames[2], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 460, view, gd->getFonts()[2], buttonNames[3], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 10, view, gd->getFonts()[2], buttonNames[4], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 160, view, gd->getFonts()[2], buttonNames[5], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 310, view, gd->getFonts()[2], buttonNames[6], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 460, view, gd->getFonts()[2], buttonNames[7], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 610, view, gd->getFonts()[2], buttonNames[8], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 610, view, gd->getFonts()[2], buttonNames[9], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 760, view, gd->getFonts()[2], buttonNames[10], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 760, view, gd->getFonts()[2], buttonNames[11], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 910, view, gd->getFonts()[2], buttonNames[12], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 910, view, gd->getFonts()[2], buttonNames[13], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, -1, 1060, view, gd->getFonts()[4], buttonNames[14], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 1210, view, gd->getFonts()[4], buttonNames[15], view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 1210, view, gd->getFonts()[2], buttonNames[16], view->getFilepath() + "img/LB.bmp"));
    step ++;
}
void hablarNew::step7(gameDelegator* gd, event* Event) {
    std::vector<std::string> traits;
    for (unsigned int i=0; i<buttons.size(); i++)
        if(buttons[i].getWasclicked())
            traits.push_back(buttons[i].getName());
    if (traits.size() > 12) {
        p.humble = false;
        gd->getTextRenderers()[0]->render(getResponse(7, &p.gender), Event);
    }
    else if (traits.size() < 4) {
        p.humble = true;
        std::string number = ""; number[0] = (char)(traits.size() + 48);
        gd->getTextRenderers()[0]->render(getResponse(8, &number), Event);
    }
    else {
        clearButtons(true);
        gd->getTextRenderers()[0]->render(getResponse(9, nullptr), Event);
        step ++;
    }
}
void hablarNew::step8(View* view, gameDelegator* gd, event* Event) {
    buttons.push_back(button(true, -1, 10, view, gd->getFonts()[4], "Me gusta la comida, comer, cociner", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 160, view, gd->getFonts()[2], "Caminar, estar afuera", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 310, view, gd->getFonts()[4], "Leer, encontrar nuevos cuentos", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 460, view, gd->getFonts()[4], "La playa. Sí, es un hobby.", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 610, view, gd->getFonts()[2], "Internet, gaming", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 160, view, gd->getFonts()[2], "La musica", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 310, view, gd->getFonts()[4], "Aprender, libros informativos, museos", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 460, view, gd->getFonts()[2], "Bailar", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 610, view, gd->getFonts()[2], "Fiestas, tomar, la vida nocturna", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 760, view, gd->getFonts()[2], "No quieres saber...", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 760, view, gd->getFonts()[4], "El sexo es lo más importante en el mundo.", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 10, 910, view, gd->getFonts()[4], "Ir de compras, mi tarjeta...", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, 420, 910, view, gd->getFonts()[2], "El arte", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(true, -1, 1060, view, gd->getFonts()[4], "Muchas cosas que no están en esta lista", view->getFilepath() + "img/LB.bmp"));
    step ++;
}
void hablarNew::step9(gameDelegator* gd, event* Event) {
    std::vector<std::string> Hobbies;
    for (unsigned int i=0; i<buttons.size(); i++)
        if(buttons[i].getWasclicked())
            Hobbies.push_back(buttons[i].getName());
    if(Hobbies.size() < 3) {
        std::string humble = "false";
        std:: string gender = "a";
        if (p.humble)
            humble = "true";
        if (p.gender == "M")
            gender = "o";
        std::string values[2] =  {humble, gender};
        gd->getTextRenderers()[0]->render(getResponse(10, values), Event);
        p.humble = true;
    }
    else {
        for (unsigned int i=0; i<Hobbies.size(); i++)
            hobbies(Hobbies[i]);
        clearButtons();
        gd->getTextRenderers()[0]->render(getResponse(11, nullptr), Event);
        step ++;
    }
}
