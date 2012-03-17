#include <GL/gl.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

Menu::Menu() {
    menus_[MAINMENU] = new Submenu();
    Submenu** mainmenu = menus_ + MAINMENU;
    (*mainmenu)->addButton("RESUME", 1, true);
    (*mainmenu)->addButton("EXIT GAME", 2, false);
    activeMenu_ = 0;
    activeElement_ = (*mainmenu)->buttons[0];
}

int Menu::getActiveMenu() {
    return activeMenu_;
}

bool Menu::handle(const SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_DOWN:
            setSelected(menus_[activeMenu_]->buttons[std::min(
                        activeElement_->getPosition(), 
                        (int) menus_[activeMenu_]->buttons.size() - 1)]);
            break;
        case SDLK_UP:
            setSelected(menus_[activeMenu_]->buttons[std::max(
                        activeElement_->getPosition() - 2, 0)]);
            break;
        case SDLK_SPACE:
            // Resume game
            if (activeElement_->getPosition() == 1)
                return false;
            // Exit game
            else {
                SDL_Event quit;
                quit.type = SDL_QUIT;
                SDL_PushEvent(&quit);
            }
        }
    }
    return true;
}

Submenu* Menu::getMenu(int menu) {
    return menus_[menu];
}

void Menu::setSelected(GuiElement* selected) {
    activeElement_->setSelected(false);
    activeElement_ = selected;
    activeElement_->setSelected(true);
}