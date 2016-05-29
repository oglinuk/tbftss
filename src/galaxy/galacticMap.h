/*
Copyright (C) 2015-2016 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "../common.h"

#define SHOW_GALAXY				0
#define SHOW_STAR_SYSTEM		1
#define SHOW_MENU				2
#define SHOW_OPTIONS			3
#define SHOW_STATS				4
#define SHOW_TROPHIES			5

extern void drawText(int x, int y, int size, int align, SDL_Color c, const char *format, ...);
extern void initBattle(void);
extern void loadMission(char *filename);
extern SDL_Texture *getTexture(char *filename);
extern void startSectionTransition(void);
extern void endSectionTransition(void);
extern void blit(SDL_Texture *t, int x, int y, int centered);
extern int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
extern void drawCircle(int cx, int cy, int radius, int r, int g, int b, int a);
extern void playMusic(char *filename, int loop);
extern void stopMusic(void);
extern void doStars(float dx, float dy);
extern void drawStars(void);
extern void limitTextWidth(int width);
extern void drawBackground(SDL_Texture *texture);
extern void initBackground(void);
extern void scrollBackground(float x, float y);
extern void drawWidgets(char *groupName);
extern void doWidgets(void);
extern Widget *getWidget(const char *name, const char *group);
extern void selectWidget(const char *name, const char *group);
extern void initTitle(void);
extern void drawOptions(void);
extern void initOptions(void (*returnFromOptions)(void));
extern void drawStats(void);
extern void playSound(int id);
extern void blitRotated(SDL_Texture *texture, int x, int y, float angle);
extern void initStatsDisplay(void);
extern void updateAllMissions(void);
extern StarSystem *getStarSystem(char *name);
extern void showOKDialog(void (*callback)(void), const char *format, ...);
extern char *getTranslatedString(char *string);
extern void clearInput(void);
extern void doTrophyAlerts(void);
extern void drawTrophyAlert(void);
extern void awardCampaignTrophies(void);
extern void awardStatsTrophies(void);
extern void initTrophiesDisplay(void);
extern void drawTrophies(void);
extern void doTrophies(void);

extern App app;
extern Colors colors;
extern Game game;
