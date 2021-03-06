/*
 * Copyright (C) 2011, 2012 Alexander Berntsen <alexander@plaimi.net>
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "game_graphics_gl.hxx"
#include "game_loop.hxx"

int main(int argc, char *argv[]) {
#if VERBOSE
    printf("LIMBS OFF - verbose version\n\n"
            "feel free to explore our little world.\n"
            "as you will learn, it's not very big.\n"
            "it's supposed to be a fighting/platform\n"
            "game, with a focus on manipulating physics.\n"
            "right now we don't even have interaction.\n"
            "we are trying to fix that. you can help!\n\n"
            "we need programmers, artists, everything.\n"
            "see TODO for what needs to be done, and\n"
            "HACKING for coding style and best practices.\n"
            "check out https://github.com/stiell/limbs-off\n"
            "and https://plaimi.net for more information.\n\n");
    printf("hit alt+enter to enter and leave fullscreen.\n\n");
#endif
    Screen::setVideoMode(1024, 768, 32);
    GameLoop loop;
    int code = loop.run();
#if VERBOSE
    printf("thank you for playing LIMBS OFF.\n");
#endif
    return code;
}
