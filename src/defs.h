/*
Copyright (C) 2015-2019 Parallel Realities

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

#ifndef REVISION
#define REVISION                   0
#endif

#ifndef DATA_DIR
#define DATA_DIR                   ""
#endif

#ifndef FIXED_RESOLUTION
#define FIXED_RESOLUTION           0
#endif

#ifndef AUDIO_FREQUENCY
#define AUDIO_FREQUENCY            44100
#endif

#ifndef AUDIO_CHANNELS
#define AUDIO_CHANNELS             2
#endif

#ifndef AUDIO_CHUNKSIZE
#define AUDIO_CHUNKSIZE            1024
#endif

#ifndef AUDIO_MIX_CHANNELS
#define AUDIO_MIX_CHANNELS         64
#endif

#define _(string) getTranslatedString(string)

#define PI                         3.14159265358979323846
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define CAROLINE(a,b) MIN(a,b)
#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'
#define TO_RAIDANS(angleDegrees) (angleDegrees * PI / 180.0)
#define TO_DEGREES(angleRadians) (angleRadians * 180.0 / PI)

#define SAVE_FILENAME              "game.save"
#define CONFIG_FILENAME            "config.json"

#define SCREEN_WIDTH               1280
#define SCREEN_HEIGHT              720

#define UI_WIDTH                   1280
#define UI_HEIGHT                  720

#define MAX_KEYBOARD_KEYS          350
#define MAX_MOUSE_BUTTONS          6

#define FPS                        60

#define MAX_NAME_LENGTH            32
#define MAX_DESCRIPTION_LENGTH     512
#define MAX_LINE_LENGTH            1024
#define MAX_FILENAME_LENGTH        1024
#define MAX_PATH_LENGTH            4096

#define NUM_TEXTURE_BUCKETS        32
#define NUM_ATLAS_BUCKETS          64

#define MAX_GLYPHS                 400

#define MAX_STARS                  500

#define MAX_CHALLENGES             3

#define MAX_FIGHTER_GUNS           12
#define MAX_TARGET_RANGE           65536
#define MAX_SYSTEM_POWER           100

#define BATTLE_AREA_CELLS          50
#define BATTLE_AREA_WIDTH          (640 * BATTLE_AREA_CELLS)
#define BATTLE_AREA_HEIGHT         (360 * BATTLE_AREA_CELLS)
#define BATTLE_AREA_EDGE           250

#define BF_NONE                    0
#define BF_ENGINE                  (2 << 0)
#define BF_SYSTEM_DAMAGE           (2 << 1)
#define BF_SHIELD_DAMAGE           (2 << 2)
#define BF_EXPLODES                (2 << 3)

#define EF_NONE                    0
#define EF_NO_KILL                 (2 << 0)
#define EF_DISABLED                (2 << 1)
#define EF_IMMORTAL                (2 << 2)
#define EF_MISSION_TARGET          (2 << 3)
#define EF_NO_MT_BOX               (2 << 4)
#define EF_HAS_ROPE                (2 << 5)
#define EF_COLLECTS_ITEMS          (2 << 6)
#define EF_MUST_DISABLE            (2 << 7)
#define EF_RETREATING              (2 << 8)
#define EF_NO_EPIC                 (2 << 9)
#define EF_STATIC                  (2 << 10)
#define EF_TAKES_DAMAGE            (2 << 11)
#define EF_SECONDARY_TARGET        (2 << 12)
#define EF_AI_TARGET               (2 << 13)
#define EF_AI_LEADER               (2 << 14)
#define EF_ROPED_ATTACHED          (2 << 15)
#define EF_NO_KILL_INC             (2 << 16)
#define EF_SHORT_RADAR_RANGE       (2 << 17)
#define EF_NO_PLAYER_TARGET        (2 << 18)
#define EF_AI_IGNORE               (2 << 19)
#define EF_NON_SOLID               (2 << 20)
#define EF_NO_HEALTH_BAR           (2 << 21)
#define EF_FRIENDLY_HEALTH_BAR     (2 << 22)
#define EF_NO_THREAT               (2 << 23)
#define EF_DROPS_ITEMS             (2 << 24)
#define EF_COMMON_FIGHTER          (2 << 25)

#define AIF_NONE                   0
#define AIF_FOLLOWS_PLAYER         (2 << 0)
#define AIF_MOVES_TO_PLAYER        (2 << 1)
#define AIF_UNLIMITED_RANGE        (2 << 2)
#define AIF_COLLECTS_ITEMS         (2 << 3)
#define AIF_TOWS                   (2 << 4)
#define AIF_RETREATS               (2 << 5)
#define AIF_GOAL_JUMPGATE          (2 << 6)
#define AIF_AVOIDS_COMBAT          (2 << 7)
#define AIF_DEFENSIVE              (2 << 8)
#define AIF_MISSILE_BOAT           (2 << 9)
#define AIF_AGGRESSIVE             (2 << 10)
#define AIF_LONG_RANGE_FIRE        (2 << 11)
#define AIF_MOVES_TO_LEADER        (2 << 12)
#define AIF_EVADE                  (2 << 13)
#define AIF_WANDERS                (2 << 14)
#define AIF_COVERS_RETREAT         (2 << 15)
#define AIF_TARGET_FOCUS           (2 << 16)
#define AIF_DROPS_MINES            (2 << 17)
#define AIF_ASSASSIN               (2 << 18)
#define AIF_SUSPICIOUS             (2 << 19)
#define AIF_ZAK_SUSPICIOUS         (2 << 20)
#define AIF_SURRENDERS             (2 << 21)
#define AIF_SURRENDERING           (2 << 22)
#define AIF_SURRENDERED            (2 << 23)

/* player abilities */
#define BOOST_RECHARGE_TIME        (FPS * 7)
#define BOOST_FINISHED_TIME        (FPS * 0.75)
#define ECM_RECHARGE_TIME          (FPS * 7)

#define MB_NORMAL                  0
#define MB_IMPORTANT               1
#define MB_PANDORAN                2

#define SS_NORMAL                  0
#define SS_SOL                     1
#define SS_PANDORAN                2

#define MAX_SUSPICION_LEVEL        1500.0
#define MAX_ZAK_SUSPICION_LEVEL    (FPS * 30)

enum
{
	CONTROL_FIRE,
	CONTROL_ACCELERATE,
	CONTROL_BOOST,
	CONTROL_ECM,
	CONTROL_BRAKE,
	CONTROL_TARGET,
	CONTROL_MISSILE,
	CONTROL_GUNS,
	CONTROL_RADAR,
	CONTROL_PREV_FIGHTER,
	CONTROL_NEXT_FIGHTER,
	CONTROL_SCREENSHOT,
	CONTROL_MAX
};

enum
{
	MD_NONE,
	MD_OK,
	MD_OK_CANCEL
};

enum
{
	ET_FIGHTER,
	ET_ITEM,
	ET_WAYPOINT,
	ET_COMPONENT_GUN,
	ET_COMPONENT_ENGINE,
	ET_COMPONENT,
	ET_CAPITAL_SHIP,
	ET_JUMPGATE,
	ET_MINE,
	ET_SHADOW_MINE
};

enum
{
	TA_LEFT,
	TA_RIGHT,
	TA_CENTER
};

enum
{
	ALIVE_ALIVE,
	ALIVE_DYING,
	ALIVE_DEAD,
	ALIVE_ESCAPED
};

enum
{
	SIDE_NONE,
	SIDE_ALLIES,
	SIDE_TZAC,
	SIDE_PANDORAN,
	SIDE_PIRATE,
	SIDE_MERC,
	SIDE_CSN,
	SIDE_UNF,
	SIDE_MAX
};

enum
{
	BT_NONE,
	BT_PARTICLE,
	BT_PLASMA,
	BT_LASER,
	BT_MAG,
	BT_ROCKET,
	BT_MISSILE,
	BT_MAX
};

enum
{
	DT_ANY,
	DT_NO_SPIN,
	DT_INSTANT,
	DT_SIMPLE
};

enum
{
	EFFECT_POINT,
	EFFECT_LINE,
	EFFECT_TEXTURE,
	EFFECT_HALO,
	EFFECT_ECM
};

enum
{
	SND_PARTICLE,
	SND_PLASMA,
	SND_LASER,
	SND_MAG,
	SND_ARMOUR_HIT,
	SND_SHIELD_HIT,
	SND_SHIELD_BREAK,
	SND_EXPLOSION_1,
	SND_EXPLOSION_2,
	SND_EXPLOSION_3,
	SND_EXPLOSION_4,
	SND_EXPLOSION_5,
	SND_GET_ITEM,
	SND_MISSILE,
	SND_INCOMING,
	SND_SELECT_WEAPON,
	SND_JUMP,
	SND_ECM,
	SND_MAG_HIT,
	SND_POWER_DOWN,
	SND_BOOST,
	SND_RADIO,
	SND_TROPHY,
	SND_MINE_WARNING,
	SND_TIME_WARNING,
	SND_CAP_DEATH,
	SND_GUI_CLICK,
	SND_GUI_SELECT,
	SND_GUI_CLOSE,
	SND_GUI_DENIED,
	SND_ZOOM,
	SND_NEW_OBJECTIVE,
	SND_NO_MISSILES,
	SND_RECHARGED,
	SND_TOW_ROPE,
	SND_OBJECTIVE_COMPLETE,
	SND_OBJECTIVE_FAILED,
	SND_WAYPOINT,
	SND_MAX
};

enum
{
	OS_INCOMPLETE,
	OS_COMPLETE,
	OS_FAILED,
	OS_CONDITION,
	OS_MAX
};

enum
{
	TT_DESTROY,
	TT_DISABLE,
	TT_WAYPOINT,
	TT_ESCAPED,
	TT_ITEM,
	TT_STOLEN,
	TT_MISC
};

enum
{
	MS_START,
	MS_IN_PROGRESS,
	MS_PAUSED,
	MS_COMPLETE,
	MS_FAILED,
	MS_TIME_UP
};

enum
{
	WT_BUTTON,
	WT_IMG_BUTTON,
	WT_SELECT,
	WT_SELECT_BUTTON,
	WT_CONTROL_CONFIG
};

enum
{
	CHALLENGE_ARMOUR,
	CHALLENGE_TIME,
	CHALLENGE_SHOT_ACCURACY,
	CHALLENGE_ROCKET_ACCURACY,
	CHALLENGE_MISSILE_ACCURACY,
	CHALLENGE_NO_LOSSES,
	CHALLENGE_1_LOSS,
	CHALLENGE_LOSSES,
	CHALLENGE_PLAYER_KILLS,
	CHALLENGE_DISABLE,
	CHALLENGE_ITEMS,
	CHALLENGE_PLAYER_ITEMS,
	CHALLENGE_RESCUE,
	CHALLENGE_SURVIVE,
	CHALLENGE_SURRENDER,
	CHALLENGE_WAYPOINTS,
	CHALLENGE_MAX
};

enum
{
	STAT_PERCENT_COMPLETE,
	STAT_MISSIONS_STARTED,
	STAT_MISSIONS_COMPLETED,
	STAT_OPTIONAL_COMPLETED,
	STAT_CHALLENGES_STARTED,
	STAT_CHALLENGES_COMPLETED,
	STAT_SHOTS_FIRED,
	STAT_SHOTS_HIT,
	STAT_SHOT_ACCURACY,
	STAT_ROCKETS_FIRED,
	STAT_ROCKETS_HIT,
	STAT_ROCKET_ACCURACY,
	STAT_MISSILES_FIRED,
	STAT_MISSILES_HIT,
	STAT_MISSILE_ACCURACY,
	STAT_ENEMIES_KILLED,
	STAT_ENEMIES_KILLED_PLAYER,
	STAT_ALLIES_KILLED,
	STAT_PLAYER_KILLED,
	STAT_ENEMIES_DISABLED,
	STAT_ENEMIES_ESCAPED,
	STAT_ECM,
	STAT_BOOST,
	STAT_MISSILES_EVADED,
	STAT_MISSILES_STRUCK,
	STAT_CIVILIANS_RESCUED,
	STAT_CIVILIANS_KILLED,
	STAT_TUG,
	STAT_SHUTTLE,
	STAT_NUM_TOWED,
	STAT_ITEMS_COLLECTED,
	STAT_ITEMS_COLLECTED_PLAYER,
	STAT_WAYPOINTS_VISITED,
	STAT_EPIC_KILL_STREAK,
	STAT_CAPITAL_SHIPS_DESTROYED,
	STAT_CAPITAL_SHIPS_LOST,
	STAT_MINES_DESTROYED,
	STAT_ENEMIES_SURRENDERED,
	/* add stats before here, so as not to mess up the stats screen */
	STAT_TIME,
	STAT_MAX
};

enum
{
	TROPHY_BRONZE,
	TROPHY_SILVER,
	TROPHY_GOLD,
	TROPHY_PLATINUM,
	TROPHY_UNEARNED,
	TROPHY_MAX
};
