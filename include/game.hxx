/*
 * Copyright (C) 2011, 2012, 2013 Alexander Berntsen <alexander@plaimi.net>
 * Copyright (C) 2011, 2012 Stian Ellingsen <stian@plaimi.net>
 *
 * This file is part of Limbs Off.
 *
 * Limbs Off is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Limbs Off is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Limbs Off.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GAME_HXX_
#define GAME_HXX_

#include "game_graphics_gl.hxx"
#include "game_physics.hxx"
#include "player.hxx"
#include "screen_element.hxx"

class Game: public EventHandler {
public:
    /** Initialise the game. */
    Game(Screen* screen, int numPlayers, int numCPUs);
    virtual ~Game();
    /** Handle input. */
    bool handle(const SDL_Event& event);
    /** Create objects. */
    void conceive();
    /** Main game loop. */
    void update(phys_t dt);
    void updateCamera(GLfloat dt);
    void draw();
private:
    Game(const Game&);
    Game& operator=(const Game&);
    /** Max player characters. */
    static const int _MAX_PC;
    /** Max planets. */
    static const int _MAX_PLAN;
    /** Planet colour. */
    static const float _COL_PLANET[];
    /** Planet gravity "mass". */
    static const phys_t _GM;
    /** Orbit radius. */
    static const phys_t _R;
    /** Orbit speed. */
    static const phys_t _S;
    /** Planet radius. */
    static const phys_t _PR;
    /** Number of players. */
    int numPlayers_;
    /** Number of AIs. */
    int numCPUs_;
    std::vector<AstroBody*> planets_;
    BackgroundModifier* backgroundModifier_;
    Camera* camera_;
    std::vector<Character*> characters_;
    std::vector<CharacterGraphic*> characterGraphics_;
    ColorModifier* planetColour_;
    GameUniverse* universe_;
    GLuint tex_;
    GraphicFixture* planetFixture_;
    Material* matCharBody_, * matCharHead_, * matCharLimbs_,
        * matCharLimbsOff_, * matPlanet_;
    std::vector<Label*> massIndicatorLabels_;
    std::vector<MassIndicator*> massIndicators_;
    std::vector<MassIndicatorGraphic*> massIndicatorGfx_;
    Circle<phys_t>* planetCircle_;
    std::vector<Player*> players_;
    std::vector<PositionModifier*> massIndicatorPosMods_;
    Screen* screen_;
    StackGraphic* scene_, * foreground_;
    Sprite* backgroundSprite_;
    TestDisk* planetDisk_;
};

#endif /* GAME_HXX_ */
